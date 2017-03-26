//dp by memoisation. . .

#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int egg(int n, int k){
    int i;

    if(k == 1 || k == 0){
        return k;
    }
    if(n == 1){
        return k;
    }
    if(dp[n][k] != -1)
        return (1+dp[n][k]);

    dp[n][k] = INT_MAX;

    for(i = 1; i <= k; i++){
        int res = max(egg(n, k-i), egg(n-1, i-1));
        if(res < dp[n][k])
            dp[n][k] = res;
    }
    return (1+dp[n][k]);        // addition of 1 is accounting for the current drop.
}
int main(){
    int t;
    int n;
    int k;

    cin >> t;

    while(t--){
        cin >> n;
        cin >> k;

        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                dp[i][j] = -1;

        int ans = egg(n, k);

        cout<<ans<<endl;
    }
    return 0;
}
