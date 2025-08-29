#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOccurrences(const string &s) {
    vector<int> lastseen(3, -1);
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        lastseen[s[i] - 'a'] = i;

        if (lastseen[0] != -1) {
            cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
        }
    }

    return cnt;
}

int main() {
    string s = "bbacba";
    cout << countOccurrences(s) << endl;
    return 0;
}
