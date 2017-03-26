#include <bits/stdc++.h>

using namespace std;

int dp[1000];
int getCount(int n){
    if(dp[n] != -1)
        return dp[n];
    if(n < 4)
        return n;
    int res = n;

    for(int i = 1; i <= n; i++){
        int  x = i*i;
        if(x > n)
            break;
        else{
            res = min(res, 1 + getCount(n-x));
        }
    }
    return (dp[n] = res);
}
int main(){
    memset(dp, -1, sizeof(dp));
    cout<<getCount(6);

    return 0;
}
