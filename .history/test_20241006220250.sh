#!/bin/bash

# Compile the program
echo "Compiling the program..."
make forky

# Run tests for pattern 1
echo "Running tests for pattern 1..."
./forky 1 5 > test_output_pattern1.txt
echo "Pattern 1 test with 5 things complete. Output saved to test_output_pattern1.txt."

# Run tests for pattern 2
echo "Running tests for pattern 2..."
./forky 2 5 > test_output_pattern2.txt
echo "Pattern 2 test with 5 things complete. Output saved to test_output_pattern2.txt."

# Run tests for pattern 3
echo "Running tests for pattern 3..."
./forky 3 7 > test_output_pattern3.txt
echo "Pattern 3 test with 7 things complete. Output saved to test_output_pattern3.txt."

# Display test results
echo ""
echo "---- Test Results ----"
echo "Pattern 1 Output:"
cat test_output_pattern1.txt
echo ""
echo "Pattern 2 Output:"
cat test_output_pattern2.txt
echo ""
echo "Pattern 3 Output:"
cat test_output_pattern3.txt

echo ""
echo "Tests completed."
