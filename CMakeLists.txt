cmake_minimum_required(VERSION 3.5)
project(deer)

set(CMAKE_CXX_STANDARD 14)
aux_source_directory(src SOURCE_FILES)

<<<<<<< HEAD
set(SOURCE_FILES src/two_sum.h.h src/add_two_numbers.h src/main.cpp "src/longest_substring_without_repeating_characters.h" src/median_of_two_sorted_arrays.h src/longest_palindromic_substring.h src/reverse_integer.h src/string_to_integer.h src/palindrome_number.h src/regular_expression_matching.h src/three_sum_closest.h)
=======
>>>>>>> origin/master
add_executable(deer ${SOURCE_FILES})