#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int s1, s2, i, j;
        int flag;

        cin >> s1;
        cin >> s2;

        char a[s1 + 2];
        char b[s2 + 2];
        int dp[s1+1][s2+1];

        for(i = 0; i < s1; i++)
            cin >> a[i];
        for(i = 0; i < s2; i++)
            cin >> b[i];

        for(i = 0; i <= s1; i++){
            for(j = 0; j <= s2; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;

                else if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout<<dp[s1][s2]<<endl;
    }
    return 0;
}
