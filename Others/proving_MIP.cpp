#include <bits/stdc++.h>
using namespace std;

// compute nCr using multiplicative formula, safe for moderate n (64-bit)
long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r); // use symmetry
    long long res = 1;
    for (long long k = 1; k <= r; ++k) {
        // Multiply before dividing to maintain integer arithmetic but avoid fraction:
        // res = res * (n - r + k) / k; perform division at each step
        res = res * (n - r + k) / k;
    }
    return res;
}

// permutations nPr = n! / (n-r)! computed multiplicatively
long long nPr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    long long res = 1;
    for (long long k = 0; k < r; ++k)
        res *= (n - k);
    return res;
}

int main() {
    cout << "C(5,3) = " << nCr(5,3) << '\n'; // 10
    cout << "P(5,3) = " << nPr(5,3) << '\n'; // 60
    return 0;
}
