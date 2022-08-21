// Problem Statement: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[501][501];
    int palindromicPartition(string str)
    {
        // code here
        memset(t, -1, sizeof(t));
        return solve(str, 0, str.length()-1);
    }

    int solve(string s, int i, int j) {
        if(i >= j) {
            return 0;
        }

        if(isPalindrome(s, i, j) == true) {
            return 0;
        }

        int mn = INT_MAX;
        for(int k=i; k<=j-1;k++) {
            int left = 0, right = 0;
            if(t[i][k] != -1) {
                left = t[i][k];
            }
            else {
                left = solve(s, i, k);
                t[i][k] = left;
            }

            if(t[k+1][j] != - 1) {
                right = t[k+1][j];
            }
            else {
                right = solve(s, k+1, j);
                t[k+1][j] = right;
            }

            int temp = 1 + left + right;
            if(temp < mn) {
                mn = temp;
            }
        }
        return t[i][j] = mn;
    }

    bool isPalindrome(string s, int i, int j) {
        if(i==j) return true;
        if(i > j) return true;

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends