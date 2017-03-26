#include <bits/stdc++.h>

using namespace std;

long long int dp[1007];

long long int yoyo(long long int n){
    if(dp[n] != -1)
        return dp[n]%1000000007;
    if(n <= 1)
        return (dp[n] = n);
    return (dp[n] = (yoyo(n-1) + yoyo(n-2))%1000000007);
}
int  main(){
    long long int t;
    long long int n;
    long long int ans;

    cin >> t;

    while(t--){
        cin >> n;

        memset(dp, -1, sizeof(dp));

        ans = yoyo(n+1);
        ans = ans % 1000000007;
        cout<<ans<<endl;
    }
    return 0;
}
