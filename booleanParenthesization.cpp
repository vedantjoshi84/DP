// Problem Statement: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// https://www.youtube.com/watch?v=Ybi6o-XV4lw

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    int countWays(int N, string S){
        // code here
        return solve(S, 0, S.length()-1, true);
    }

    int solve(string s, int i, int j, bool isTrue) {
        if(i>j) {
            return 0;
        }
        if(i==j) {
            if(isTrue == true) {
                return s[i]=='T';
            }
            else {
                return s[i]=='F';
            }
        }

        string temp = to_string(i);
        temp.push_back(' ');
        temp.append( to_string(j) );
        temp.push_back(' ');
        temp.append(to_string(isTrue));

        if(mp.find(temp) != mp.end()) {
            return mp[temp]%1003;
        }

        int ans = 0;
        for(int k=i+1;k<=j-1;k=k+2) {
            int lT = solve(s, i, k-1, true);
            int lF = solve(s, i, k-1, false);
            int rT = solve(s, k+1, j, true);
            int rF = solve(s, k+1, j, false);

            if(s[k] == '&') {
                if(isTrue == true) {
                    ans = (ans + (lT*rT))%1003;
                }
                else {
                    ans = (ans + (lT*rF) + (lF*rT) + (lF*rF))%1003;
                }
            }

            else if(s[k] == '|') {
                if(isTrue == true) {
                    ans = (ans + (lT*rT) + (lF*rT) + (lT*rF))%1003;
                }
                else {
                    ans = (ans + (lF*rF))%1003;
                }
            }

            else if(s[k] == '^') {
                if(isTrue == true) {
                    ans = (ans + (lF*rT) + (lT*rF))%1003;
                }
                else {
                    ans = (ans + (lT*rT) + (lF*rF))%1003;
                }
            }
        }
        return mp[temp] = ans%1003;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends