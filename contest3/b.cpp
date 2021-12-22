<<<<<<< HEAD
#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

vector<int> sieve(int n) {
    vector<int> primes;

    vector<int> mind(n);
    for (int i = 2; i < n; ++i) {
        mind[i] = i;
    }

    for (int k = 2; k < n; ++k) {
        if (mind[k] == k) {
            primes.push_back(k);
        }
        for (auto p: primes) {
            if (p * k <= n && p <= mind[k]) {
                mind[p * k] = p;
            }
        }
    }
 
    for (const auto &p: primes) {
        mind[p] = 0;
    }

    return mind;
}

int sum(const vector<int> &vec) {
    int res = 0;
    for (const auto &item: vec) {
        res += item;
    }
    return res;
}


int main() {
    int n;
    cin >> n;

    const auto mind = sieve(n + 1);

    std::cout << sum(mind) << std::endl;
    return 0;
}
