cmake_minimum_required(VERSION 3.7)
project(deer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/two_sum.h.h src/add_two_numbers.h src/main.cpp "src/longest_substring_without_repeating_characters.h" src/median_of_two_sorted_arrays.h src/longest_palindromic_substring.h src/reverse_integer.h src/string_to_integer.h src/palindrome_number.h)
add_executable(deer ${SOURCE_FILES})