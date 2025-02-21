cmake_minimum_required(VERSION 3.10)
project(Ponging VERSION 0.1.0)

set(CMAKE_GENERATOR "MinGW Makefiles" CACHE STRING "Generator for CMake")
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

include_directories("src")

file(GLOB_RECURSE cpp_files ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE header_files
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.hpp
)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

message(STATUS "SDL2_FOUND: ${SDL2_FOUND}")
message(STATUS "SDL2_INCLUDE_DIRS: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2_LIBRARIES: ${SDL2_LIBRARIES}")
message(STATUS "SDL2_LIBRARY_DIRS: ${SDL2_LIBRARY_DIRS}")

add_executable(Ponging ${PROJECT_SOURCE_DIR}/app/main.cpp ${cpp_files})

target_link_libraries(Ponging
    PRIVATE
    ${SDL2_LIBRARIES}
    SDL2_ttf::SDL2_ttf
)

#if (WIN32)
#    add_custom_command(
#        TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        $<TARGET_FILE:SDL2::SDL2>
#        $<TARGET_FILE_DIR:${PROJECT_NAME}>
#        VERBATIM
#    )
#endif()