
#!/bin/bash

NAME=./cub3d
MAP_DIR=maps/invalid_maps

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

TOTAL=0
PASSED=0

run_test()
{
	FILE=$1
	TOTAL=$((TOTAL + 1))

	OUTPUT=$(mktemp)

	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--quiet \
		$NAME "$FILE" > "$OUTPUT" 2>&1

	STATUS=$?

	echo "${BLUE}========================================${NC}"
	echo "${YELLOW}Test:${NC} $(basename "$FILE")"
	echo

	cat "$OUTPUT"
	echo

	if grep -q "Error" "$OUTPUT" \
		&& [ $STATUS -ne 0 ] \
		&& ! grep -q "definitely lost: [1-9]" "$OUTPUT"; then
		echo "${GREEN}[PASS]${NC}"
		PASSED=$((PASSED + 1))
	else
		echo "${RED}[FAIL]${NC}"
	fi

	echo "${BLUE}========================================${NC}"
	echo

	rm -f "$OUTPUT"
}

echo "${YELLOW}Running cub3d invalid map tests...${NC}"
echo

for file in "$MAP_DIR"/*.cub
do
	[ -f "$file" ] && run_test "$file"
done

echo
printf "Passed %d/%d tests\n" "$PASSED" "$TOTAL"

if [ $PASSED -eq $TOTAL ]; then
	echo "${GREEN}All tests passed!${NC}"
	exit 0
else
	echo "${RED}Some tests failed!${NC}"
	exit 1
fi
