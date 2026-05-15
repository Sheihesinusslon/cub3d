#!/bin/bash

# cub3D master test runner
# Usage: ./run_tests.sh  (from tests/) or bash tests/run_tests.sh (from project root)
cd "$(dirname "$0")/.."

TESTS_DIR=tests
RED='\033[0;31m'
GRN='\033[0;32m'
YLW='\033[0;33m'
RST='\033[0m'

PASS=0
FAIL=0
BIN=./cub3d

pass() { echo -e "${GRN}[PASS]${RST} $1"; PASS=$((PASS + 1)); }
fail() { echo -e "${RED}[FAIL]${RST} $1"; FAIL=$((FAIL + 1)); }

# ---------------------------------------------------------------------------
# Build
# ---------------------------------------------------------------------------
echo -e "\n${YLW}--- Build ---${RST}"
make re --no-print-directory > /dev/null 2>&1
if [ $? -eq 0 ] && [ -x "$BIN" ]; then
    pass "make re produces executable"
else
    fail "make re failed or binary not found"
    echo -e "\nResults: ${GRN}${PASS} passed${RST}, ${RED}${FAIL} failed${RST}"
    exit 1
fi

# ---------------------------------------------------------------------------
# Argument validation
# ---------------------------------------------------------------------------
echo -e "\n${YLW}--- Argument validation ---${RST}"
$BIN > /dev/null 2>&1
if [ $? -ne 0 ]; then
    pass "no arguments exits with error (non-zero)"
else
    fail "no arguments should exit non-zero"
fi

$BIN arg1 arg2 > /dev/null 2>&1
if [ $? -ne 0 ]; then
    pass "too many arguments exits with error (non-zero)"
else
    fail "too many arguments should exit non-zero"
fi

# ---------------------------------------------------------------------------
# Valid maps
# ---------------------------------------------------------------------------
echo ""
bash "$TESTS_DIR/test_valid_maps.sh"
VALID_FAIL=$?

# ---------------------------------------------------------------------------
# Invalid maps
# ---------------------------------------------------------------------------
echo ""
bash "$TESTS_DIR/test_invalid_maps.sh"
INVALID_FAIL=$?

# ---------------------------------------------------------------------------
# Tally sub-script results into master counters
# ---------------------------------------------------------------------------
TOTAL_FAIL=$((FAIL + VALID_FAIL + INVALID_FAIL))
TOTAL_PASS=$PASS
# Count passes from sub-scripts by re-running them silently and parsing output
valid_counts=$(bash "$TESTS_DIR/test_valid_maps.sh" 2>/dev/null | grep -E "passed|failed" | tail -1)
invalid_counts=$(bash "$TESTS_DIR/test_invalid_maps.sh" 2>/dev/null | grep -E "passed|failed" | tail -1)

echo ""
echo -e "${YLW}=== Summary ===${RST}"
echo -e "  Build & args:  ${GRN}${PASS} passed${RST}, ${RED}${FAIL} failed${RST}"
echo -e "  Valid maps:    $valid_counts"
echo -e "  Invalid maps:  $invalid_counts"
echo ""
[ $TOTAL_FAIL -eq 0 ] && echo -e "${GRN}All tests passed!${RST}" || echo -e "${RED}Some tests failed.${RST}"
[ $TOTAL_FAIL -eq 0 ] && exit 0 || exit 1
