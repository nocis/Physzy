cmake_minimum_required(VERSION 3.5)
project(Physzy)


# Useful paths
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# SDL 2
find_package(SDL2 REQUIRED)
if(SDL_FOUND)
    message("SDL Found")
endif()
include_directories(${SDL2_INCLUDE_DIRS})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

if(NOT WIN32)
    # OpenGL
    find_package(OpenGL REQUIRED)
    if(OPENGL_FOUND)
        message("OpenGL Found")
    endif()
    include_directories(${OPENGL_INCLUDE_DIRS})

    # Threads
    find_package(Threads REQUIRED)
endif()

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
    message("GLEW Found")
endif()
include_directories(${GLEW_INCLUDE_DIRS})


set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
#set(RESOURCES_OBJS
#        ${RESOURCES_DIR}/bunny.obj
#        ${RESOURCES_DIR}/cube.obj
#        ${RESOURCES_DIR}/cup.obj
#        ${RESOURCES_DIR}/dragon.obj)
#set(unzip_py ${CMAKE_CURRENT_SOURCE_DIR}/scripts/unzip.py)
#add_custom_command(
#        COMMAND python ${unzip_py} ${RESOURCES_DIR}/resources.zip ${RESOURCES_DIR}
#        DEPENDS ${headers}
#        OUTPUT ${RESOURCES_OBJS})
#add_custom_target(unzip_py ALL
#        DEPENDS ${RESOURCES_OBJS})



include_directories("src")
include_directories("externals/")
include_directories("externals/glm/")
include_directories(src/examples)

add_subdirectory(src/engine)
add_subdirectory(src/examples/fluid1)

#file(GLOB_RECURSE srcs src/*.cpp src/*.h)
#add_executable(tinyrender ${srcs})

#if(WIN32)
#    target_link_libraries(tinyrender ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} SDL2::SDL2 SDL2::SDL2main)
#elseif(APPLE)
#    target_link_libraries(tinyrender ${Boost_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES})
#else()
#    target_link_libraries(tinyrender stdc++fs ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#endif()
