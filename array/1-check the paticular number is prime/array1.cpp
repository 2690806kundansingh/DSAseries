#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;      // 2 is prime
    if (n % 2 == 0) return false; // remove evens quickly

    for (int i = 3; i <= sqrt(n); i += 2) { // skip even numbers
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (isPrime(n))
        cout << "is a prime number" << endl;
    else
        cout << "it is not prime number" << endl;
}
