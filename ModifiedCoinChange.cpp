#include <bits/stdc++.h>

using namespace std;

int dp[10000];
int minCoins(int coins[], int m, int V){
    if(dp[V] != -1)
        return dp[V];
    if(V == 0)
        return 0;
    int res = INT_MAX;
    int temp;
    for(int i = 0; i < m; i++){
        if(coins[i] <= V)
            temp = minCoins(coins, m, V-coins[i]);
            if(temp != INT_MAX)
                res = min(res, 1 + temp);
    }
    return (dp[V] = res);
}
int main(){
    memset(dp, -1, sizeof(dp));
    int coins[] =  {9, 6, 5, 7};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "<< minCoins(coins, m, V);
    return 0;
}
