//incorrect solution...
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

long long int arr[100005];
long long int dp[100005];

long long int foo(long long int n){
    if(dp[n] != 0)
        return dp[n];
    if(n == 1)
        return (dp[n]=1);
    if(arr[n-1] > arr[n-2])
        return (dp[n]=(1 + foo(n-1)));
    else if(arr[n-1] <= arr[n-2])
        return (dp[n]=foo(n-1)-1);
}

int main() {
    long long int i, n, sum = 0;

    cin >> n;

    memset(dp, 0, sizeof(dp));

    for(i = 0; i < n; i++)
        cin >> arr[i];

    long long int x = foo(n);

    for(i = 1; i <= n; i++){
        cout<<dp[i]<<" ";
        sum+=dp[i];
    }
    cout<<sum<<endl;

    return 0;
}
