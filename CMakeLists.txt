cmake_minimum_required(VERSION 3.10)
include_directories("C:/CUnit-2.1-2/CUnit/Headers/")
link_directories("C:/CUnit-2.1-2/CUnit/Sources.libs/")

# Set the project name
project(TicTacToe)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Add the executable for the game
add_executable(TicTacToeGame main.c game.c)

# Add the executable for the tests and link to the CUnit library
add_executable(TicTacToeTest test_game.c game.c)
target_link_libraries(TicTacToeTest "C:/CUnit-2.1-2/CUnit/Sources/.libs/libcunit.a")
