#include <bits/stdc++.h>

using namespace std;

int dp[105];
int MinJumps(int arr[], int start, int end){
    if(dp[start] != -1)
        return dp[start];

    if(start == end)
        return 0;

    if(arr[start] == 0)
        return INT_MAX;

    int mn = INT_MAX;

    for(int i = start+1; i <= end && i <= (start+arr[start]); i++){
        int jumps = MinJumps(arr, i, end);

        if(jumps != INT_MAX && jumps+1 < mn)
            mn = jumps+1;
    }
    return (dp[start]=mn);
}
int main(){
    int t;

    cin >> t;

    while(t--){
        memset(dp, -1, sizeof(dp));
        int arr[10000];
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int ans = MinJumps(arr,0, n-1);
        if(ans != INT_MAX)
           cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
