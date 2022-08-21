// Problem Statement: https://www.interviewbit.com/problems/scramble-string/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool solve(string a, string b) {
    if(a.compare(b) == 0) {
        return true;
    }

    if(a.length() <= 1) {
        return false;
    }

    string key = a;
    key.push_back(' ');
    key.append(b);

    if(mp.find(key)!= mp.end()) {
        return mp[key];
    }

    int n = a.length();
    bool flag = false;

    for(int i=1;i<n;i++) {
        if( ((solve(a.substr(0, i), b.substr(n-i, i))) && (solve(a.substr(i, n-i), b.substr(0, n-i)))) || ((solve(a.substr(0, i), b.substr(0, i))) && (solve(a.substr(i, n-i), b.substr(i, n-i)))) ) {
            flag = true;
            break;
        }
    }

    return mp[key] = flag;
}

int isScramble(const string A, const string B) {
    int alen = A.length();
    int blen = B.length();

    if(alen!=blen) {
        return false;
    }

    if(alen==0 && blen==0) {
        return true;
    }

    return solve(A, B);
}
