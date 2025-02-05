cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the compiler
set(CMAKE_CXX_COMPILER g++)

# Set build directory
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${BUILD_DIR})

# Source files
set(SOURCES main.cpp data.cpp display.cpp)
set(HEADERS data.h display.h)

# Define the executable
add_executable(app ${SOURCES})

# Set output directory
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# Custom commands
add_custom_target(run
    COMMAND ${BUILD_DIR}/app
    DEPENDS app
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(clean
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${BUILD_DIR}/*.o ${BUILD_DIR}/app
    COMMENT "Cleaning build files"
)

add_custom_target(test
    COMMAND echo "nah id win"
    COMMENT "Running test command"
)
