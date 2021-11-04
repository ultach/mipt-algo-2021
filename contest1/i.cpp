#include <iostream>
#include <vector>
#include <string>
#include <cassert>


std::vector<int> StringToZ(const std::string &txt) {
    const int txt_size = txt.size();
    std::vector<int> z(txt_size, 0);
    int left = 0;
    int right = 0;
    for (int i = 1; i < txt_size; ++i) {
        int shift = (i <= right) ? std::min(z[i - left], right - i + 1) : 0;
        while (shift + i < txt_size && txt[i + shift] == txt[shift]) {
            ++shift;
        }
        z[i] = shift;
        if (shift + i - 1 > right) {
            left = i;
            right = shift + i - 1;
        }
    }
    return z;
}


int main() {

    std::string s;
    std::cin >> s;

    std::vector<int> z = StringToZ(s);

    for (int i: z) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}


