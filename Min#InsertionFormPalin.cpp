// Problem Statement: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
        int n = str.length();
        string B = string(str.rbegin(), str.rend());
        return  n - LCS(str, B, n, n);
    }

    int LCS(string a, string b, int m, int n) {
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
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends