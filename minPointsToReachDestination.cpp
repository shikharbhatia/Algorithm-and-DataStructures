#include <bits/stdc++.h>

using namespace std;

int minPts(int arr[][50], int m, int n){
    int i, j;
    int dp[m+1][n+1];
    int temp;

    if(arr[m-1][n-1] > 0)
       dp[m-1][n-1] = 1;
    else
        dp[m-1][n-1] = abs(arr[m-1][n-1])+1;

    for(i = m-2; i >= 0; i--){
        dp[i][n-1] = max(dp[i+1][n-1] - arr[i][n-1], 1);
    }
    for(j = n-2; j >= 0; j--){
        dp[m-1][j] = max(dp[m-1][j-1] - arr[m-1][j], 1);
    }

    for(i = m-2; i >= 0; i--){
        for(j = n-2; j >= 0; j--){
            temp = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(temp - arr[i][j], 1);
        }
    }
    return dp[0][0];
}
int main(){
    int t;
    int m;
    int n;
    int i, j;
    int arr[50][50];

    cin >> t;

    while(t--){
        cin >> m;
        cin >> n;

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        int ans = minPts(arr, m, n);
        cout<<ans<<endl;
    }
    return 0;
}
