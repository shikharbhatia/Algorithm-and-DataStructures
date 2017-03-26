#include <bits/stdc++.h>

using namespace std;
long long int  dp[100];
long long int  count(long long int  n){
    if(dp[n] != -1)
        return dp[n];
    if(n < 4){
        return (dp[n] = 1);
    }
    return (dp[n] = count(n-1) + count(n-4));
}
int  main(){
    long long int  t;
    long long int  n;

    cin >> t;

    while(t--){
        memset(dp, -1, sizeof(dp));

        cin >> n;

        long long int  ans = count(n);

        cout<<ans<<endl;
    }
    return 0;

}
