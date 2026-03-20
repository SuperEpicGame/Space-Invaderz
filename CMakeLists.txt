cmake_minimum_required(VERSION 3.20)
project(MySDLApp C)

set(CMAKE_C_STANDARD 11)

# IMPORTANT: point to your SDL3 install
set(SDL3_DIR "D:/SDL/SDL3/cmake/") #Min directory

find_package(SDL3 REQUIRED)

add_executable(my_app main.c player.c)

target_link_libraries(my_app PRIVATE SDL3::SDL3)