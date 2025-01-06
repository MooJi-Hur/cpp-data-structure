#!/bin/bash

# Check if a problem number is provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <problem_number>"
  exit 1
fi

# Define the problem number and create the folder for the problem
PROBLEM_NUMBER=$1
PROBLEM_FOLDER="problem-set"
mkdir -p "$PROBLEM_FOLDER/$PROBLEM_NUMBER"

# Change directory to the problem folder
cd "$PROBLEM_FOLDER"

# Create the Main.cc file
cat > main.cpp <<EOL
/*
 * Problem: $PROBLEM_NUMBER
 * URL: https://www.acmicpc.net/problem/$PROBLEM_NUMBER
 */

#include "timer.h"

/** === Timing ===
Insert the following timer functions
at the beginning and end of the code block.
auto start = startTimer();
stopTimer(start);
*/


// Add include files and namespaces.


// Add your code.




EOL

# Create input.txt and output.txt files
touch input.txt output.txt

echo "Setup completed for BOJ Problem #$PROBLEM_NUMBER"

echo "Fill the input file with the necessary data."
echo "You can check the execution results in the output file."
