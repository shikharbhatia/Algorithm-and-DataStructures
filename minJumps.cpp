#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <stdio.h>
#include <string.h>
#include <limits.h>

using namespace std;

int dp[100][100];

int minJumps(int arr[], int l, int h){
    int i;
    if(dp[l][h] != -1)
        return dp[l][h];
    if(l == h)
        return 0;
    if(arr[l] == 0){
        return -1;
    }
    int mn = INT_MAX;

    for(i = l+1; i <=h && i <= (l + arr[l]); i++){
        int jumps = minJumps(arr, i, h);
        if(jumps != -1 && mn > (jumps+1))
            mn = jumps+1;
    }
    return (dp[l][h] = mn);
}
int main(){
    int t;
    int n;
    int arr[105];
    int i, j;

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> arr[i];
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                dp[i][j] = -1;

        int ans = minJumps(arr,0, n-1);

        cout<<ans<<endl;

    }
}
