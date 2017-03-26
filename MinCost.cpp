#include <bits/stdc++.h>

using namespace std;

int main(){
    int cost[105][105];

    int i, j, m, n;

    cin >> m;
    cin >> n;

    int dp[m+1][n+1];

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];

    for(i = 1; i <= m; i++){
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    for(j = 1; j <= n; j++){
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }

    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            dp[i][j] = cost[i][j] + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }
    cout<<dp[m][n]<<endl;

    return 0;
}
