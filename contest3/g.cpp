#include <vector>
#include <complex>
#include <iostream>
 
const double PI = acos(-1);
using Complex = std::complex<double> ;
 
void fft(std::vector<Complex> &a, bool invert) {
    int n = a.size();
 
    for (int i = 1, k = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; k & bit; bit >>= 1)
            k ^= bit;
        k ^= bit;
 
        if (i < k)
            std::swap(a[i], a[k]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; ++j) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (auto &x: a)
            x /= n;
    }
}
 
std::vector<int> multiplyPolynoms(std::vector<int> const &a, std::vector<int> const &b) {
    std::vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < int(a.size()) + int(b.size()))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = int(round(fa[i].real()));
    return result;
}
 
std::vector<int> readArray() {
    int n;
    std::cin >> n;
    std::vector<int> array(n + 1);
    for (int k = 0; k < n + 1; ++k) {
        std::cin >> array[k];
    }
    return array;
}
 
void printArray(const std::vector<int> &a) {
    std::cout << a.size() << " ";
    for (int k = 0; k < a.size(); ++k) {
        std::cout << a[k] << " ";
    }
    std::cout << std::endl;
}
 
int main() {
    auto a = readArray();
    auto b = readArray();
    auto c = multiplyPolynoms(a, b);
//    printArray(c);
    int n = (a.size() - 1) + (b.size() - 1);
    std::cout << n << " ";
    for (int k = 0; k < n + 1; ++k) {
        std::cout << c[k] << " ";
    }
    std::cout << std::endl;
    return 0;
}


