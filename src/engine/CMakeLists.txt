set(target engine)

# Define
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Sources
file(GLOB header_dir
        ${root_dir}/include/${target})

file(GLOB headers
        ${header_dir}/*.h
        ${header_dir}/detail/*.h)

file(GLOB_RECURSE sources
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Custom-build event
#set(engine_header_gen_py ${root_dir}/scripts/header_gen.py)
#add_custom_command(
#        COMMAND python ${engine_header_gen_py}
#        DEPENDS ${headers}
#        OUTPUT ${root_dir}/include/engine.h
#)
#add_custom_target(engine_header_gen_py ALL
#        DEPENDS ${root_dir}/include/engine.h)

# Build library
add_library(${target}
        ${sources})
#add_dependencies(${target} engine_header_gen_py)

# Project options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compile options
target_compile_options(${target}
        PRIVATE
        ${DEFAULT_COMPILE_OPTIONS}

        PUBLIC

        INTERFACE
        )

target_link_libraries(${target}
        PRIVATE

        PUBLIC
        stdc++fs
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        ${DEFAULT_LIBRARIES}

        INTERFACE
        )

# Includes
target_include_directories(${target}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty

        PUBLIC

        INTERFACE
        $<BUILD_INTERFACE:${header_dir}>
        $<INSTALL_INTERFACE:include>
        )

# Install
install(TARGETS ${target} DESTINATION lib EXPORT ${target}_Export)
install(DIRECTORY ${header_dir} DESTINATION include)
install(EXPORT ${target}_Export
        DESTINATION lib/cmake/${target}
        FILE ${target}Config.cmake
        )