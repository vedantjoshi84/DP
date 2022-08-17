// Problem Statement: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(t, -1, sizeof(t));
        return solve(arr, 1, N-1);
    }
    int solve(int arr[], int i, int j) {
        if(i>=j) {
            return 0;
        }

        if(t[i][j]!=-1) {
            return t[i][j];
        }

        int mn = INT_MAX;
        for(int k=i; k<j; k++) {
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            if(temp_ans < mn) {
                mn = temp_ans;
            }
        }
        return t[i][j] = mn;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends