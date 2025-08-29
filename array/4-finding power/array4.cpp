#include <iostream>
using namespace std;

int power(int a, int b) {
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        ans = ans * a;
    }
    return ans;
}

int main() {
    int a, b;
    cout << "Enter base and exponent: ";
    cin >> a >> b;
    int ans = power(a, b);
    cout << a << " raised to the power " << b << " is: " << ans << endl;
    return 0;
}
