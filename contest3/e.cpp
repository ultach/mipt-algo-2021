#include <iostream>
 
#define m 1000000007
using ll = long long;
 
const int N = (int) 1e6 + 6;
 
int fpm(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return fpm((ll) a * a % m, b >> 1) * (ll) (b & 1 ? a : 1) % m;
}
 
int a[N], f[N], inv[N];
 
int comb(int n, int k) {
    if (n == k || k == 0) return 1;
    return f[n] * (ll) inv[k] % m * inv[n - k] % m;
}
 
int nums(int n, int k) {
    ll res = 0;
    for (int sz = 0; sz <= k; ++sz) {
        int ways = comb(k, sz) * (ll) fpm(sz, n) % m;
        if ((sz ^ k) & 1) {
            res = res - ways + m;
        } else {
            res = res + ways;
        }
        while (res >= m) res -= m;
        while (res < 0) res += m;
    }
    return (ll) inv[k] * res % m;
}
 
ll mod(ll a) {
    return (a%m + m) % m;
}
 
ll mul(ll a, ll b) {
    a = mod(a);
    b = mod(b);
    return ((ll) a  * (ll) b) % m;
}
 
int main() {
    for (int i = 0; i < N; ++i) {
        f[i] = (i == 0 ? 1 : f[i - 1] * (ll) i % m);
        inv[i] = fpm(f[i], m - 2);
    }
    
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += a[j];
        sum %= m;
    }
 
    const auto ans = mul((mul(nums(n - 1, k), (n + k - 1)) + nums(n - 1, k - 1)), sum);
    std::cout << ans << std::endl;
}


