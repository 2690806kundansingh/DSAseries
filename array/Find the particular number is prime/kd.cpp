#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false; // 0 and 1 are not prime numbers
        if (n == 2) return true;  // 2 is the only even prime number

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    int num;
    
    cout << "Enter a number: ";
    cin >> num;

    if (obj.isPrime(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}
