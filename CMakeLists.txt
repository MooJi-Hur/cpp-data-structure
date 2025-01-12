cmake_minimum_required(VERSION 3.27)
project(cpp-data-structure)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories("/usr/local/include")

# Find all folders containing main.cpp directly in section-01
file(GLOB UINT_MAIN_FILES "${CMAKE_SOURCE_DIR}/*/*/main.cpp")

foreach(MAIN_FILE ${UINT_MAIN_FILES})
    # Extract folder and target names
    get_filename_component(CHAPTER_DIR ${MAIN_FILE} DIRECTORY)
    get_filename_component(UNIT_NAME ${CHAPTER_DIR} NAME)

    # Gather all source files in the directory
    file(GLOB PROBLEMS_SRC_FILES "${CHAPTER_DIR}/*.cpp")

    # Create an executable for each problem
    add_executable(${UNIT_NAME} ${PROBLEMS_SRC_FILES})

    # Set output directory for the executable
    set_target_properties(${UNIT_NAME} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${UNIT_NAME})

    # Enable debug symbols
    target_compile_options(${UNIT_NAME} PRIVATE -g)

    # Custom target for running with input and output redirection
    add_custom_target(${UNIT_NAME}_run
        COMMAND ${CMAKE_BINARY_DIR}/bin/${UNIT_NAME}/${UNIT_NAME} < ${CHAPTER_DIR}/input.txt > ${CHAPTER_DIR}/output.txt
        DEPENDS ${UNIT_NAME}
        WORKING_DIRECTORY ${CHAPTER_DIR}
        COMMENT "Running ${UNIT_NAME} with redirected input and output"
    )
endforeach()
