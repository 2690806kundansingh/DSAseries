#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int characterReplacement(string s, int k) {
    int l = 0, r = 0, maxlen = 0, maxf = 0;
    int hash[26] = {0};

    while (r < s.size()) {
        hash[s[r] - 'A']++;  // Update frequency of current character
        maxf = max(maxf, hash[s[r] - 'A']); 

        // If window size - max frequency > k, shrink the window
        if ((r - l + 1) - maxf > k) {
            hash[s[l] - 'A']--;  // Reduce count of left character
            l++;  // Move left pointer
        }

        // Update max length
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    
    return maxlen;
}

int main() {
    string s = "AABABBA";
    int k = 2;
    cout << "Longest repeating character replacement: " << characterReplacement(s, k) << endl;
    return 0;
}
