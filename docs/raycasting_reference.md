# Raycasting Theory Reference — cub3D

> Sources: [Lode's Tutorial Parts I–IV](https://lodev.org/cgtutor/raycasting.html)

---

## 1. Core Idea

The map is a 2D integer grid. For every **vertical screen column** `x`, cast one ray from the player position into the map. When the ray hits a wall, compute the perpendicular distance and derive the wall stripe height to draw. No calculation is done per pixel horizontally — only per column.

---

## 2. Camera Model

### Vectors (no Euler angles needed)

| Symbol | Description |
|--------|-------------|
| `pos` | Player position `(posX, posY)` in map units (float) |
| `dir` | Direction vector `(dirX, dirY)`, length ≈ 1 |
| `plane` | Camera plane vector `(planeX, planeY)`, ⊥ to `dir` |

`dir` and `plane` must stay **perpendicular** at all times. Their ratio sets the **FOV**:

```
FOV = 2 · atan(|plane| / |dir|)
```

With `|dir| = 1`, `|plane| = 0.66` → FOV ≈ 66° (good default for FPS).

### Ray direction per column

For screen column `x` (0 … W−1):

```
cameraX = 2·x / W − 1          // maps [0,W) → [−1, +1]

rayDir = dir + plane · cameraX
       = (dirX + planeX·cameraX,
          dirY + planeY·cameraX)
```

The leftmost ray is `dir − plane`, the rightmost is `dir + plane`.

---

## 3. DDA (Digital Differential Analysis)

DDA steps the ray exactly one grid cell at a time — guaranteed to detect every wall.

### Setup

```c
mapX = (int)posX;    // current grid cell
mapY = (int)posY;

// distance to travel to cross one full cell in each axis
deltaDistX = fabs(1.0 / rayDirX);   // = |rayDir| / |rayDirX|, but |rayDir| cancels
deltaDistY = fabs(1.0 / rayDirY);   // (only ratio matters)
```

> **Why `1/rayDir`?** The hypotenuse formed by stepping 1 unit in X has length √(1 + (rayDirY/rayDirX)²) = |rayDir|/|rayDirX|. Since only the ratio between `deltaDistX` and `deltaDistY` matters, divide by |rayDir| → `|1/rayDirX|`.

### Initial side distances (distance to first grid line)

```c
if (rayDirX < 0) { stepX = -1; sideDistX = (posX - mapX)       * deltaDistX; }
else             { stepX = +1; sideDistX = (mapX + 1.0 - posX) * deltaDistX; }

if (rayDirY < 0) { stepY = -1; sideDistY = (posY - mapY)       * deltaDistY; }
else             { stepY = +1; sideDistY = (mapY + 1.0 - posY) * deltaDistY; }
```

### DDA loop

```c
while (!hit) {
    if (sideDistX < sideDistY) { sideDistX += deltaDistX; mapX += stepX; side = 0; }
    else                       { sideDistY += deltaDistY; mapY += stepY; side = 1; }
    if (map[mapX][mapY] > 0) hit = 1;
}
```

`side == 0` → ray hit a vertical (N/S) wall boundary  
`side == 1` → ray hit a horizontal (E/W) wall boundary

---

## 4. Perpendicular Wall Distance

**Never use Euclidean distance** — it causes the fish-eye effect (curved walls).  
Use the **perpendicular distance to the camera plane** instead:

```c
if (side == 0) perpWallDist = sideDistX - deltaDistX;
else           perpWallDist = sideDistY - deltaDistY;
```

**Why this formula?** After the DDA loop, `sideDistX` is `deltaDistX` further than needed (we overshot into the wall). Subtracting `deltaDistX` steps back to the wall surface. The result equals the projection of the hit point onto the player's look direction, which gives a flat (fish-eye-free) projection.

---

## 5. Wall Stripe Height & Drawing

```c
lineHeight = (int)(SCREEN_H / perpWallDist);

drawStart = -lineHeight / 2 + SCREEN_H / 2;  // clamp to 0
drawEnd   =  lineHeight / 2 + SCREEN_H / 2;  // clamp to SCREEN_H − 1
```

Shading: **Y-side walls** (`side == 1`) are rendered darker for visual depth.

---

## 6. Texture Mapping (Walls)

### Which X column of the texture?

```c
// exact hit point on wall surface (fractional part = position within cell)
if (side == 0) wallX = posY + perpWallDist * rayDirY;
else           wallX = posX + perpWallDist * rayDirX;
wallX -= floor(wallX);                        // keep fractional part only

int texX = (int)(wallX * TEX_W);

// flip to keep texture orientation consistent
if (side == 0 && rayDirX > 0) texX = TEX_W - texX - 1;
if (side == 1 && rayDirY < 0) texX = TEX_W - texX - 1;
```

### Stepping through Y (affine — correct for vertical walls)

```c
double step   = (double)TEX_H / lineHeight;          // texels per screen pixel
double texPos = (drawStart - SCREEN_H/2 + lineHeight/2) * step;  // starting texel

for (int y = drawStart; y < drawEnd; y++) {
    int texY = (int)texPos & (TEX_H - 1);   // mask handles overflow
    texPos += step;
    color = texture[texY * TEX_W + texX];
    if (side == 1) color = (color >> 1) & 0x7F7F7F;  // darken
    buffer[y][x] = color;
}
```

### Texture selection (cub3D)

Map the hit direction to the correct texture:

| Condition | Wall face |
|-----------|-----------|
| `side == 0 && rayDirX > 0` | West (`WE`) |
| `side == 0 && rayDirX < 0` | East (`EA`) |
| `side == 1 && rayDirY > 0` | North (`NO`) |
| `side == 1 && rayDirY < 0` | South (`SO`) |

---

## 7. Floor & Ceiling Rendering (Scanline Method)

Floors and ceilings are rendered **scanline by scanline** (horizontal), before the walls overwrite the middle band.

For each row `y` below the horizon:

```c
// rays at left/right edges of screen
float rayDirX0 = dirX - planeX,  rayDirY0 = dirY - planeY;
float rayDirX1 = dirX + planeX,  rayDirY1 = dirY + planeY;

int   p = y - SCREEN_H / 2;           // pixels below horizon
float posZ = 0.5f * SCREEN_H;         // camera height
float rowDist = posZ / p;             // world distance to this floor row

// step vector: world units per screen pixel (horizontal)
float floorStepX = rowDist * (rayDirX1 - rayDirX0) / SCREEN_W;
float floorStepY = rowDist * (rayDirY1 - rayDirY0) / SCREEN_W;

// world position of leftmost pixel in this row
float floorX = posX + rowDist * rayDirX0;
float floorY = posY + rowDist * rayDirY0;

for (int x = 0; x < SCREEN_W; x++) {
    int cellX = (int)floorX,  cellY = (int)floorY;
    int tx = (int)(TEX_W * (floorX - cellX)) & (TEX_W - 1);
    int ty = (int)(TEX_H * (floorY - cellY)) & (TEX_H - 1);
    floorX += floorStepX;
    floorY += floorStepY;

    buffer[y][x]              = floorTexture[ty * TEX_W + tx];  // floor
    buffer[SCREEN_H-y-1][x]  = ceilTexture [ty * TEX_W + tx];  // ceiling (symmetric)
}
```

> **Why `rowDist = posZ / p`?**  
> The camera is at height `posZ = 0.5·H`. The ray reaches the floor after traveling `posZ` units vertically and `posZ/p` units horizontally (similar triangles: at the camera plane, vertical travel is `p` for horizontal travel `1`).

In **cub3D**, floor and ceiling are solid colors (not textured), so this loop reduces to a single `memset` / color fill per half.

---

## 8. Player Movement & Rotation

### Translation (per frame)

```c
// moveSpeed = frameTime * units_per_second (e.g. 5.0)
if (key_up)   { posX += dirX * moveSpeed; posY += dirY * moveSpeed; }
if (key_down) { posX -= dirX * moveSpeed; posY -= dirY * moveSpeed; }
```

Collision detection: check `map[(int)(posX ± dirX·step)][(int)posY]` and `map[(int)posX][(int)(posY ± dirY·step)]` separately — allows sliding along walls.

### Rotation (rotation matrix, per frame)

```
rotSpeed = frameTime * radians_per_second (e.g. 3.0)

[ cos θ  −sin θ ] · [dirX]   [dirX']
[ sin θ   cos θ ]   [dirY] = [dirY']
```

```c
double oldDirX = dirX;
dirX   = dirX   * cos(rot) - dirY   * sin(rot);
dirY   = oldDirX* sin(rot) + dirY   * cos(rot);

double oldPlaneX = planeX;
planeX = planeX * cos(rot) - planeY * sin(rot);
planeY = oldPlaneX*sin(rot)+ planeY * cos(rot);
```

Both `dir` **and** `plane` must be rotated together to preserve perpendicularity and FOV.

---

## 9. Sprite Rendering (Part III — bonus for cub3D)

1. **Store ZBuffer**: `ZBuffer[x] = perpWallDist` for each column after wall casting.
2. **Sort sprites** far-to-close (by squared distance — no `sqrt` needed).
3. **Project** sprite to camera space using the inverse 2×2 camera matrix:

```
invDet = 1.0 / (planeX·dirY − dirX·planeY)

transformX =  invDet · ( dirY·spriteRelX −  dirX·spriteRelY)  // horizontal
transformY =  invDet · (−planeY·spriteRelX + planeX·spriteRelY) // depth (Z)
```

4. **Screen position**: `spriteScreenX = (W/2) * (1 + transformX / transformY)`
5. **Size**: `spriteH = spriteW = |H / transformY|`
6. **Draw** column by column; skip if `transformY ≤ 0` (behind camera) or `transformY ≥ ZBuffer[stripe]` (behind wall).
7. **Invisible color**: skip pixels where `(color & 0x00FFFFFF) == 0`.

---

## 10. cub3D Map File Format (`.cub`)

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 220,100,0        # floor RGB
C 225,30,0         # ceiling RGB

111111
100001
1000N1             # N/S/E/W = player start position and direction
100001
111111
```

Rules:
- Map must be **enclosed** (all edges are walls — no open boundary)
- Only `0` (empty), `1` (wall), and one player token (`N`/`S`/`E`/`W`) allowed
- Player token sets initial `dir` and `plane` vectors

| Token | `dir` | `plane` |
|-------|-------|---------|
| `N` | `(0, −1)` | `(0.66, 0)` |
| `S` | `(0, +1)` | `(−0.66, 0)` |
| `E` | `(+1, 0)` | `(0, 0.66)` |
| `W` | `(−1, 0)` | `(0, −0.66)` |

---

## 11. Quick Reference: Variable Names

| Variable | Meaning |
|----------|---------|
| `posX, posY` | Player world position |
| `dirX, dirY` | Player direction unit vector |
| `planeX, planeY` | Camera plane vector (⊥ to dir) |
| `cameraX` | Column position in camera space: `[−1, +1]` |
| `rayDirX/Y` | Direction of the current ray |
| `mapX, mapY` | Current grid cell of the ray |
| `deltaDistX/Y` | Ray length to cross one full cell in X or Y |
| `sideDistX/Y` | Ray length to next X or Y grid boundary |
| `stepX, stepY` | ±1, DDA step direction |
| `side` | 0 = vertical wall (N/S), 1 = horizontal wall (E/W) |
| `perpWallDist` | Camera-plane distance to hit point (fish-eye-free) |
| `lineHeight` | Pixel height of wall stripe = `H / perpWallDist` |
| `wallX` | Fractional hit position along wall face → texture X |
| `texX, texY` | Texture coordinates |
| `ZBuffer[x]` | Per-column depth (for sprite occlusion) |

---

## 12. Frame Loop Order

```
1. Fill floor & ceiling (solid color or scanline texture)
2. Wall casting loop (for each column x):
   a. Compute rayDir
   b. DDA to find hit
   c. Compute perpWallDist → lineHeight
   d. Compute wallX → texX
   e. Draw vertical stripe with texture stepping
   f. Store ZBuffer[x]
3. Sort sprites far-to-close
4. Draw sprites (check ZBuffer per column)
5. Present buffer, clear, handle input
```

---

## 13. Common Pitfalls

| Problem | Cause | Fix |
|---------|-------|-----|
| Fish-eye distortion | Using Euclidean distance | Use `perpWallDist = sideDist - deltaDist` |
| Skewed world | `plane` not ⊥ to `dir` | Always rotate both together |
| Texture flicker | Wrong `texX` orientation | Flip `texX` based on `side` and ray direction |
| Division by zero | `rayDirX` or `rayDirY` == 0 | Use `1e30` (or IEEE Infinity) for `deltaDist` |
| Wall bleeding through map edges | No closed-map validation | Validate all map borders are `1` on parse |
| Sprite seen behind you | No `transformY > 0` guard | Skip sprite if `transformY ≤ 0` |
