#include <iostream>
#include <string>
#include "reverse_integer.h"

int main() {
    char16_t utf16[] = u"hello";
    char utf8[] = u8"你好";
    char32_t utf32[] = U"hello equals \u4F60\u597D\u554A";

    std::cout << sizeof(char16_t);
    std::cout << sizeof(utf8) << " " << utf8 << std::endl;
    std::cout << sizeof(utf16) << " " << utf16 << std::endl;
    std::cout << sizeof(utf32) << " " << utf32 << std::endl;

    std::string ss = "";
    Solution s;
    std::cout << s.reverse(0x7FFFFFFF);
    return 0;
}
