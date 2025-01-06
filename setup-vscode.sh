#!/bin/bash

# Set the target directory and file path
TARGET_DIR="/usr/local/include/bits"
TARGET_FILE="${TARGET_DIR}/stdc++.h"

# Create the target directory if it doesn't exist
echo "Creating directory: $TARGET_DIR"
mkdir -p "$TARGET_DIR"

# Create the file and write standard C/C++ headers
echo "Creating and writing to file: $TARGET_FILE"
cat > "$TARGET_FILE" << EOF
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++ Standard Library headers
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
EOF

# Check if the file was created successfully
if [ -f "$TARGET_FILE" ]; then
    echo "File created successfully at: $TARGET_FILE"
else
    echo "Failed to create file."
    exit 1
fi

# Create .vscode directory
mkdir -p ".vscode"
cd ".vscode"

# Create the VSCode settings file
cat > settings.json <<EOL
{
    "files.associations": {
        "*.h": "cpp",
        "iostream": "cpp",
        "set": "cpp"
    },
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "editor.formatOnSave": true,
    "cmake.cmakePath": "cmake",
    "C_Cpp.clang_format_style": "file",
    "C_Cpp.clang_format_fallbackStyle": "Google",
    "cmake.buildDirectory": "\${workspaceFolder}/out/build/default",
    "cmake.generator": "Unix Makefiles",
    "cmake.configureArgs": [
        "-DCMAKE_C_COMPILER=/usr/bin/clang",
        "-DCMAKE_CXX_COMPILER=/usr/bin/clang++"
    ],
    "cmake.debugConfig": {
        "type": "lldb",
        "request": "launch",
        "program": "\${command:cmake.launchTargetPath}",
        "args": [],
        "stopAtEntry": false,
        "cwd": "\${workspaceFolder}",
        "environment": [],
        "externalConsole": false,
        "setupCommands": [
            {
                "description": "Enable pretty-printing for lldb",
                "text": "settings set target.max-children-count 256",
                "ignoreFailures": true
            }
        ]
    }
}
EOL

# Create the VSCode extensions file
cat > extensions.json <<EOL
{
    "recommendations": [
        "ms-vscode.cpptools",
        "ms-vscode.cpptools-extension-pack"
    ]
}
EOL

# Create the VSCode launch configuration file
cat > launch.json <<EOL
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug cpp-data-structure Project",
            "type": "cppdbg",
            "request": "launch",
            "program": "\${workspaceFolder}/out/build/Clang 16.0.0 x86_64-apple-darwin24.0.0/bin/\${input:executableName}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "\${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "CMake Build",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "miDebuggerPath": "/usr/bin/lldb"
        }
    ],
    "inputs": [
        {
            "id": "executableName",
            "type": "promptString",
            "description": "Enter the executable name (e.g., sction-00/02-01-mainBasic)"
        }
    ]
}
EOL

# Create the VSCode IntelliSense configuration file
cat > c_cpp_properties.json <<EOL
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "\${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "cStandard": "c17",
            "compilerPath": "/usr/bin/clang++",
            "intelliSenseMode": "macos-clang-x64",
            "cppStandard": "c++17"
        }
    ],
    "version": 4
}
EOL

# Final setup completion message
echo "Setup completed successfully."
echo "Please install the recommended extensions and verify your C++ compiler path (e.g., 'which clang++')."