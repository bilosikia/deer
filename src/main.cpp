#include <iostream>
#include "palindrome_number.h"

int main() {
    Solution s;
    std::cout << s.isPalindrome(1000021) << std::endl;
    std::cout << s.isPalindrome(1) << std::endl;
    std::cout << s.isPalindrome(12) << std::endl;
    std::cout << s.isPalindrome(121) << std::endl;
    std::cout << s.isPalindrome(123421) << std::endl;
    std::cout << s.isPalindrome(2412) << std::endl;
    return 0;
}
