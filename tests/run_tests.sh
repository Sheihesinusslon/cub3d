#!/bin/bash

# cub3D smoke tests
# Usage: bash tests/run_tests.sh  (run from project root)

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
# Test 1 — project compiles cleanly
# ---------------------------------------------------------------------------
echo -e "\n${YLW}--- Build ---${RST}"
make re --no-print-directory > /dev/null 2>&1
if [ $? -eq 0 ] && [ -x "$BIN" ]; then
    pass "make re produces executable"
else
    fail "make re failed or binary not found"
fi

# ---------------------------------------------------------------------------
# Test 2 — no arguments: must exit with non-zero and print usage/error
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
# Test 3 — valid map: must exit 0 (smoke only, no rendering yet)
# ---------------------------------------------------------------------------
echo -e "\n${YLW}--- Valid map (smoke) ---${RST}"
$BIN maps/valid.cub > /dev/null 2>&1
if [ $? -eq 0 ]; then
    pass "valid map exits 0"
else
    fail "valid map should exit 0"
fi

# ---------------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------------
echo ""
echo -e "Results: ${GRN}${PASS} passed${RST}, ${RED}${FAIL} failed${RST}"
[ $FAIL -eq 0 ] && exit 0 || exit 1
