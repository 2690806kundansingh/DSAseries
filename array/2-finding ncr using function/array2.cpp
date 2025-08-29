#include <iostream>
using namespace std;

int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int ncr(int n, int r) {
    int numer = fact(n);
    int deno = fact(r) * fact(n - r); // ✅ correct denominator
    return numer / deno;
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << "Answer is " << ncr(n, r) << endl;
    return 0;
}
