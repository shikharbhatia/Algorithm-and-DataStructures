#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

long long int arr[1000000];
long long int dp[10000][10000];
long long int maxSeq(long long int arr[], long long int n){
    long long int i, j, k;
    for(i = 0; i < n; i++){
        dp[i][i] = arr[i];
    }
    for(k = 2; k <= n; k++){
        for(i = 0; i < n-k+1; i++){
            j = i+k-1;
            dp[i][j] = max(dp[i][j-1], dp[i][j-1] + arr[j]);
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
    }

    return dp[0][n-1];
}
long long int maxSub(long long int arr[],long long int n){
    long long int i;
    long long int curr = arr[0];
    long long int mx = arr[0];

    for(i = 1; i < n; i++){
        curr = max(curr+arr[i], arr[i]);
        mx = max(mx, curr);
    }
    return mx;
}

int main() {
    long long int t;
    long long int n, i;

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++){
            cin >> arr[i];
        }

       long long int mx_sub = maxSub(arr, n);
       long long int mx_seq = maxSeq(arr, n);

        cout<<mx_sub<<" "<<mx_seq<<endl;
    }
    return 0;
}
