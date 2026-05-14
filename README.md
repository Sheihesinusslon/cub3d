*This project has been created as part of the 42 curriculum by jmarques, ngusev.*

# Cub3D

Cub3D is a simple 3D graphics project inspired by the classic game Wolfenstein 3D. The goal of the project is to create a first-person perspective inside a maze using the raycasting technique.

The program is developed in C using the MiniLibX graphics library. The player can move through the map, rotate the camera, and interact with the environment rendered in real time.

## Main Features

- First-person 3D visualization
- Raycasting engine
- Wall textures
- Keyboard movement and camera rotation
- Custom map parsing from .cub files
- Collision detection
- Floor and ceiling colors
- Real-time rendering

## Technologies Used

- Language: C
- Graphics Library: MiniLibX
- Algorithms: Raycasting, vector math, texture mapping

## Project Structure
```text
src
├── bonus
│   ├── door_interact_bonus.c
│   ├── door_state_bonus.c
│   ├── door_texture_parse_bonus.c
│   ├── door_texture_render_bonus.c
│   ├── door_tiles_bonus.c
│   └── map_store_bonus.c
├── game
│   ├── hooks.c
│   ├── player_aux.c
│   ├── player.c
│   ├── raycaster.c
│   ├── ray_draw.c
│   ├── render.c
│   ├── textures.c
│   └── window.c
├── input
│   ├── check_map.c
│   ├── checks.c
│   ├── map_store.c
│   ├── parse_color.c
│   ├── parse_cub.c
│   ├── parse_line.c
│   ├── parse_texture.c
│   └── read_map.c
├── main.c
└── utils
    ├── bonus_utils2.c
    ├── bonus_utils.c
    ├── free.c
    └── parsing.c
include
├── cub3d_base.h
├── cub3d_bonus.h
├── cub3d.h
└── defines.h
```
## Instructions
git clone https://github.com/Sheihesinusslon/cub3d.git
cd cub3d

## Compile and Run

There are two versions of the program, the mandatory part and the bonus part. The bonus part adds wall collision, a minimap, open and close doors and the ability to rotate the view by moving the mouse.

To compile the mandatory part, cd into the cloned directory and:
- make

To compile the bonus part, cd into the cloned directory and:
- make bonus

To run the program:
- ./cub3d <path/to/map.cub>

The program takes a map file as an argument. Maps are available in the maps directory. There are good maps which the program should run smoothly with, and bad maps which the program should reject. For example:

- `./cub3d maps/valid_maps/subject.cub` should run.
- `./cub3d maps/invalid_maps/no_map.cub` should print an error and abort.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `E`: open/close door (bonus only)
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse

## Testing

The project includes automated shell scripts to test both valid maps and error handling.

### Run valid map tests

```bash
./tests/run_tests.sh
```
This script launches a series of valid .cub maps to verify:

- Map parsing
- Texture loading
- Player initialization
- Rendering behavior
- General game stability

```bash
./tests/test_errors.sh
```
This script checks invalid configurations and map errors such as:
- Invalid map format
- Missing textures
- Incorrect colors
- Open mapsInvalid characters
- Parsing failures

If the scripts are not executable, run:

```bash
chmod +x tests/run_tests.sh
chmod +x tests/test_errors.sh
```
