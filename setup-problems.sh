#!/bin/bash

# Check if a problem number is provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <problem_number>"
  exit 1
fi

# Define the problem number and create the folder for the problem
PROBLEM_NUMBER=$1
PROBLEM_FOLDER="$PROBLEM_NUMBER"
mkdir -p "$PROBLEM_FOLDER"

# Change directory to the problem folder
cd "$PROBLEM_FOLDER"

# Create the Main.cc file
cat > main.cpp <<EOL
/*
 * Problem: $PROBLEM_NUMBER
 * URL: https://www.acmicpc.net/problem/$PROBLEM_NUMBER
 */

// Add include files and namespaces.

#ifndef ONLINE_JUDGE
#include <chrono>
#include <fstream>
using namespace chrono;

#endif

int main() {
// === File I/O and Timing ===
#ifndef ONLINE_JUDGE
  auto start = high_resolution_clock::now();

  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");

  if (inputFile && outputFile) {
    cin.rdbuf(inputFile.rdbuf());
    cout.rdbuf(outputFile.rdbuf());
  } else {
    cerr << "Error: Could not open files." << endl;
    return 1;
  }
#endif

// Add your code.

// === Timing ===
#ifndef ONLINE_JUDGE
  auto end = high_resolution_clock::now();
  clog << "Time: " << duration_cast<milliseconds>(end - start).count() << "ms "
       << endl;
#endif

  return 0;
}

EOL

# Create input.txt and output.txt files
touch input.txt output.txt

echo "Setup completed for BOJ Problem #$PROBLEM_NUMBER"

echo "Fill the input file with the necessary data."
echo "You can check the execution results in the output file."
