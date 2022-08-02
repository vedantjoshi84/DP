#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++) {
            sum += arr[i];
        }
        if(sum%2!=0) {
            return false;
        }
        else {
            return subsetSum(N, arr, sum/2);
        }
    }

    bool subsetSum(int N, int arr[], int sum) {
        bool t[N+1][sum+1];
        for(int i=0;i<N+1;i++) {
            for(int j=0;j<sum+1;j++) {
                if(i==0) {
                    t[i][j] = false;
                }
                if(j==0) {
                    t[i][j] = true;
                }
            }
        }
        for(int i=1;i<N+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(arr[i-1] <= j) {
                    t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[N][sum];
    }
};