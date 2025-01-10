#!/bin/bash

# Check if folder names are provided.
if [ $# -ne 2 ]; then
  echo "Usage: $0 <section_name> <chapter_name>"
  exit 1
fi

# Define folder names.
SECTION_NAME=$1
CHAPTER_NAME=$2

# Create folders.
mkdir -p "$SECTION_NAME/$CHAPTER_NAME"

# Change directory to chapter folder.
cd "$SECTION_NAME/$CHAPTER_NAME"

# Create the Main.cpp file
touch main.cpp input.txt output.txt README.md

echo "Setup completed for $SECTION_NAME/$CHAPTER_NAME."

