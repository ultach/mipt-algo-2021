#include "iostream"
#include "vector"
 
using ll = long long;
 
 
long long sumOfMinPrimeDivisors(long long n) {
 
    std::vector<int> v(n + 1, 0);
    for (ll i = 2; i * i <= n; ++i) {
        if (v[i] == 0) {
            for (ll j = i; i * j <= n; ++j) {
                if (v[i * j] == 0) {
                    v[i * j] = i;
                }
            }
        }
    }
 
    ll res = 0;
    for (auto i: v) {
        res += i;
    }
 
    return res;
}
 
int main() {
    int n;
    std::cin >> n;
    std::cout << sumOfMinPrimeDivisors(n);
    return 0;
}


