#!/bin/bash

# 작업 경로 설정
TARGET_DIR="/usr/local/include/bits"
TARGET_FILE="${TARGET_DIR}/stdc++.h"

# 디렉토리 생성
echo "Creating directory: $TARGET_DIR"
mkdir -p "$TARGET_DIR"

# 파일 생성 및 내용 작성
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

// C++
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

# 완료 메시지
if [ -f "$TARGET_FILE" ]; then
    echo "File created successfully at: $TARGET_FILE"
else
    echo "Failed to create file."
    exit 1
fi

mkdir -p ".vscode"

cd ".vscode"
cat > tasks.json <<EOL
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: clang++ build active file",
            "command": "/usr/bin/clang++",
            "args": [
                "-std=c++17",
                "-stdlib=libc++",
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                "-g",
                "\${file}",
                "-o",
                "\${fileDirname}/\${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "\${fileDirname}"
            },
            "problemMatcher": [
                "\$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
}
EOL

cat > settings.json <<EOL
{
    "files.autoSave": "onFocusChange",
    "editor.formatOnSave": true,
    "editor.defaultFormatter": "ms-vscode.cpptools",
    "C_Cpp.default.compilerPath": "/usr/bin/clang++",
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.intelliSenseMode": "macos-clang-x64",
    "C_Cpp.clang_format_fallbackStyle": "google"
}

EOL

cat > extensions.json <<EOL
{
    "recommendations": [
        "ms-vscode.cpptools",
        "ms-vscode.cpptools-extension-pack"
    ]
}

EOL

cat > launch.json <<EOL
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C/C++: clang++ build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: clang++ build active file"
        }
    ]
}

EOL

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

echo "Setup completed."
echo "Please install the recommanded extensions and verify your c++ compiler path, e.g. 'which clang++'."
echo "To set up a specific problem, run the setup-vscode.sh with the problem number, e.g. './setup-vscode.sh 1001'."
