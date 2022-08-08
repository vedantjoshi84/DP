// Problem Statement: https://leetcode.com/problems/target-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Handle test cases like:
    // 1. arr: [1]                  => same as 6.
    //    diff/target: 2
    //    o/p: 0
    // 2. arr: [1]
    //    diff/target: 1
    //    o/p: 1
    // 3. arr: [1000]
    //    diff/target: -1000
    //    o/p: 1
    // 4. arr: [1000]
    //    diff/target: 1000
    //    o/p: 1
    // 5. arr: [1, 2, 1]
    //    diff/target: 0
    //    o/p: 2
    // 6. arr: [7, 9, 3, 8, 0, 2, 4, 8, 3, 9]      =>   (arrSum + diff) is odd, return 0
    //    diff/target: 0
    //    o/p: 0
    // 7. arr: [100]                      =>  for the else condition
    //    diff/target: -200
    //    o/p: 0


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        int subset_sum = (target + sum);
        if(subset_sum % 2 != 0) {
            return 0;
        }
        else {
            if(subset_sum/2 < 0)
                return 0;
            return countOfSubsetSum(nums, n, subset_sum/2);
        }
    }

    int countOfSubsetSum(vector<int>& arr, int n, int sum) {
        int t[n+1][sum+1];
        t[0][0] = 1;
        for(int i=1;i<sum+1;i++)
            t[0][i] = 0;

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
};