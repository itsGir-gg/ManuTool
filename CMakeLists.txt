cmake_minimum_required(VERSION 3.15)
project(ManuToolMinimal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ManuToolMinimal src/main.cpp)

if (WIN32) add_custom_command(TARGET ManuToolMinimal POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Assets $<TARGET_FILE_DIR:ManuToolMinimal>/Assets ) endif(

if (WIN32)
    target_compile_definitions(ManuToolMinimal PRIVATE -DUNICODE -D_UNICODE)
    target_link_libraries(ManuToolMinimal PRIVATE user32 gdi32 comctl32)
endif()