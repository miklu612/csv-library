
# Firstly make the tests
if ! make build; then
    echo "Failed to compile"
    make clean
    exit 1
fi



if ./test_1; then echo "Test 1 : Passed"; else echo "Test 1 : Failed"; fi
if ./test_2; then echo "Test 2 : Passed"; else echo "Test 2 : Failed"; fi
if ./test_3; then echo "Test 3 : Passed"; else echo "Test 3 : Failed"; fi
if ./test_4; then echo "Test 4 : Passed"; else echo "Test 4 : Failed"; fi
if ./test_5; then echo "Test 5 : Passed"; else echo "Test 5 : Failed"; fi
if ./test_6; then echo "Test 6 : Passed"; else echo "Test 6 : Failed"; fi


make clean
