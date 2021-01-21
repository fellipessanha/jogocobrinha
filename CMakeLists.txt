cmake_minimum_required(VERSION 3.19.2)

# set the project name
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Curses REQUIRED)

include_directories(
  include
  ${CURSES_INCLUDE_DIR}
)

# add the executable
add_executable(${PROJECT_NAME} src/main.cc src/snake.cc src/fruit.cc)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})