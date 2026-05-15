#!/bin/bash
# Tests for invalid maps: binary must print "Error\n", exit non-zero, no leaks.
# Run from project root.

RED='\033[0;31m'
GRN='\033[0;32m'
YLW='\033[0;33m'
RST='\033[0m'

PASS=0
FAIL=0
BIN=./cub3d

pass() { echo -e "  ${GRN}[PASS]${RST} $1"; PASS=$((PASS + 1)); }
fail() { echo -e "  ${RED}[FAIL]${RST} $1"; FAIL=$((FAIL + 1)); }

run_invalid() {
	local map="$1"
	local name
	name=$(basename "$map")

	out=$("$BIN" "$map" 2>&1)
	code=$?

	if [ $code -eq 0 ]; then
		fail "$name — expected non-zero exit, got 0"
		return
	fi
	if ! echo "$out" | grep -q "^Error$"; then
		fail "$name — expected 'Error' in output, got: $out"
		return
	fi

	vg=$(valgrind --leak-check=full --error-exitcode=1 \
		--suppressions=tests/mlx.supp \
		"$BIN" "$map" 2>&1)
	if echo "$vg" | grep -q "ERROR SUMMARY: 0 errors"; then
		pass "$name — Error + non-zero exit + no leaks"
	else
		fail "$name — memory leak detected"
		echo "$vg" | grep -E "definitely|indirectly|ERROR SUMMARY" | sed 's/^/    /'
	fi
}

echo -e "${YLW}--- Invalid maps ---${RST}"

# .cub files in invalid_maps/
for f in maps/invalid_maps/*.cub; do
	run_invalid "$f"
done

# wrong extension file
run_invalid "maps/invalid_maps/no_extension.txt"

echo ""
echo -e "  Invalid map results: ${GRN}${PASS} passed${RST}, ${RED}${FAIL} failed${RST}"
exit $FAIL
