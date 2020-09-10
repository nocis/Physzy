# Target name

STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(target CURRENT_FOLDER)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Sources
file(GLOB sources
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build executable
add_executable(${target}
        ${sources})

# Project options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compile options
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_definitions(-D_USE_MATH_DEFINES) # for M_PI
endif ()

target_compile_options(${target}
        PRIVATE

        PUBLIC
        ${DEFAULT_COMPILE_OPTIONS}

        INTERFACE
        )
target_compile_definitions(${target}
        PRIVATE
        RESOURCES_DIR="${RESOURCES_DIR}"
        )

# Link libraries
target_link_libraries(${target}
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        engine)