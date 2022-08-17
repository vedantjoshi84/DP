// Problem Statement: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int m = A.length();
        string B = string(A.rbegin(), A.rend());
        return LPS(A, B, m, m);
    }

    int LPS(string a, string b, int m, int n) {
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
	                t[i][j] = max(t[i-1][j], t[i][j-1]);
	            }
	        }
	    }
	    return t[m][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}

// } Driver Code Ends