#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n;
    int i,j;

    cin >> t;

     while(t--){
        cin >> n;
        vector<vector<int> >shops(n, vector<int>(3));

        for(i = 0; i < n; i++){
            for(j = 0; j < 3; j++){
                cin >> shops[i][j];
            }
        }
        vector<vector<int> >dp(n, vector<int>(3));

        for(j = 0; j < 3; j++){
            dp[0][j] = shops[0][j];
        }

        for(i = 1; i < n; i++){
            for(j = 0; j < 3; j++){
                dp[i][0] = min(dp[i-1][1], dp[i-1][2])+shops[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][2])+shops[i][1];
                dp[i][2] = min(dp[i-1][0], dp[i-1][1])+shops[i][2];
            }
        }
         cout<<min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2])<<endl;
     }
     return 0;
}
