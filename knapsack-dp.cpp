#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int i, w;
    int W;
    int wt[1000];
    int val[1000];
    int dp[100][100];

    cin >> W;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> wt[i];
        cin >> val[i];
    }

    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w){
                dp[i][w] = max((val[i-1] + dp[i-1][w-wt[i-1]]), dp[i-1][w]);
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    cout<<dp[n][W]<<endl;

    return 0;
}
