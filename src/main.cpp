#include <iostream>
#include "regular_expression_matching.h"

int main() {
    Solution s;
//    std::cout << s.isMatch("aa","a") << std::endl;
//    std::cout << s.isMatch("aa","aa") << std::endl;
//    std::cout << s.isMatch("aaa","aa") << std::endl;
//    std::cout << s.isMatch("aa", "a*") << std::endl;
//    std::cout << s.isMatch("aa", ".*") << std::endl;
//    std::cout << s.isMatch("ab", ".*") << std::endl;
    std::cout << s.isMatch("aab", "c*a*b") << std::endl;
    std::cout << s.isMatch("aaa", "ab*ac*a") << std::endl;
    std::cout << s.isMatch("a", "ab*") << std::endl;
    std::cout << s.isMatch("aaa", "ab*a") << std::endl;
    std::cout << s.isMatch("ab", ".*..") << std::endl;

    return 0;
}
