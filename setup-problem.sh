#!/bin/bash

# Check if a problem number is provided as an argument
if [ $# -ne 3 ]; then
  echo "Usage: $0 <section_name> <problem_index> <problem_number>"
  exit 1
fi

# Define the problem number and create the folder for the problem
SECTION_NAME=$1
PROBLEM_INDEX=$2
PROBLEM_NUMBER=$3
mkdir -p "$SECTION_NAME/$PROBLEM_INDEX-$PROBLEM_NUMBER"

# Change directory to the problem folder
cd "$SECTION_NAME/$PROBLEM_INDEX-$PROBLEM_NUMBER"

# Create the Main.cc file
cat > main.cpp <<EOL
/*
 * Problem: $PROBLEM_NUMBER
 * URL: https://www.acmicpc.net/problem/$PROBLEM_NUMBER
 */

// #include "timer.h"

/** === Timing ===
Insert the following timer functions
at the beginning and end of the code block.
auto start = startTimer();
stopTimer(start);
*/


// Add include files and namespaces.


// Add your code.




EOL

# Create README and I/O files
touch README.md input.txt output.txt 

echo "Setup completed for BOJ Problem #$PROBLEM_NUMBER"

echo "Fill the input file with the necessary data."
echo "You can check the execution results in the output file."
