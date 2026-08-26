#!/bin/bash

echo "======================================"
echo "       EASYFIND AUTOMATED TESTS"
echo "======================================"

echo ""
echo "[1] Compilation"

make re > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "KO - Compilation failed"
    exit 1
fi

echo "OK - Compilation successful"

echo ""
echo "[2] Running program"

./easyfind > test_output.txt 2>&1

if [ $? -ne 0 ]; then
    echo "KO - Program crashed"
    cat test_output.txt
    rm -f test_output.txt
    exit 1
fi

echo "OK - Program executed"

echo ""
echo "[3] Checking results"

# Vector: first occurrence of 20
if grep -q "Find 20: 20" test_output.txt && \
   grep -q "Index: 1" test_output.txt; then
    echo "OK - Vector finds first occurrence"
else
    echo "KO - Vector first occurrence test"
fi

# Vector: first element
if grep -q "Find first element (10): 10" test_output.txt; then
    echo "OK - Vector first element"
else
    echo "KO - Vector first element"
fi

# Vector: last element
if grep -q "Find last element (40): 40" test_output.txt; then
    echo "OK - Vector last element"
else
    echo "KO - Vector last element"
fi

# Empty vector
if grep -q "EMPTY VECTOR TEST" test_output.txt && \
   grep -q "Error: Cannot find!" test_output.txt; then
    echo "OK - Empty vector throws exception"
else
    echo "KO - Empty vector test"
fi

# List: find existing value
if grep -q "Find 2: 2" test_output.txt; then
    echo "OK - List finds value"
else
    echo "KO - List find test"
fi

# Deque: find existing value
if grep -q "Find 20: 20" test_output.txt; then
    echo "OK - Deque finds value"
else
    echo "KO - Deque find test"
fi

echo ""
echo "======================================"
echo "             TEST COMPLETE"
echo "======================================"

rm -f test_output.txt