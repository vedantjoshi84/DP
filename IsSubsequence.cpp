// Problem Statement: https://leetcode.com/problems/is-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int lcs = LCS(s, t, m, n);

        if(lcs == m) {
            return true;
        }
        return false;
    }

    int LCS(string a, string b, int m, int n)
    {
        int t[m+1][n+1];
        for(int i=0;i<m+1;i++) {
            for(int j=0;j<n+1;j++) {
                if(i==0 || j==0) {
                    t[i][j] = 0;
                }
            }
        }
        for(int i=1;i<m+1;i++) {
            for(int j=1;j<n+1;j++) {
                if(a[i-1] == b[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        return t[m][n];
    }
};