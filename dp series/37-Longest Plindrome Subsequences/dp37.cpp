// Longest Palondrome Subsequences
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string a, string b)
    {

        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == a[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s)
    {
        string revstr = 0;
        reverse(revstr.begin(),revstr.end());
        int ans =solve(s,revstr);
        return ans;
    }
};
