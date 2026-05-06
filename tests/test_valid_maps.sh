#!/bin/bash
# Tests for valid maps: binary must exit 0 and produce no leaks.
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

run_valid() {
	local map="$1"
	local name
	name=$(basename "$map")

	out=$("$BIN" "$map" 2>&1)
	code=$?
	if [ $code -ne 0 ]; then
		fail "$name — expected exit 0, got $code  ($out)"
		return
	fi

	vg=$(valgrind --leak-check=full --error-exitcode=1 \
		--suppressions=tests/mlx.supp \
		"$BIN" "$map" 2>&1)
	if echo "$vg" | grep -q "ERROR SUMMARY: 0 errors"; then
		pass "$name — exit 0 + no leaks"
	else
		fail "$name — memory leak detected"
		echo "$vg" | grep -E "definitely|indirectly|ERROR SUMMARY" | sed 's/^/    /'
	fi
}

echo -e "${YLW}--- Valid maps ---${RST}"
for f in maps/valid_maps/*.cub; do
	run_valid "$f"
done

echo ""
echo -e "  Valid map results: ${GRN}${PASS} passed${RST}, ${RED}${FAIL} failed${RST}"
exit $FAIL
