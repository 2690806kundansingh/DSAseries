#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for (int i = 0; i < 30; i++) {
            if (ans == n) {
                return true;
            }
            if (ans < INT_MAX / 2)
                ans = ans * 2; // ✅ Added missing semicolon
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (sol.isPowerOfTwo(n))
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " is NOT a power of 2" << endl;

    return 0;
}
