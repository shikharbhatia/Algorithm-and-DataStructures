#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>&dp, string arr){
    int i;
    int check = arr[0] - '0';

    if(check % 2 == 0)
        dp[0] = 1;
    else
        dp[1] = 0;

    for(i = 1; i < arr.size(); i++){
        check = arr[i]-'0';
        if(check %2 == 0){
            dp[i] = dp[i-1]+1;
        }
        else{
            dp[i] = dp[i-1];
        }
    }
}
int main(){
    int i;
    int x;


    string arr;

    cin >> arr;
    int n = arr.length();
    vector<int>dp(arr.length());

    solve(dp, arr);

    cout<<dp[n-1]<<" ";

    for(i = 1; i < n; i++){
        cout<<dp[n-1]-dp[i-1]<<" ";
    }

    return 0;
}
