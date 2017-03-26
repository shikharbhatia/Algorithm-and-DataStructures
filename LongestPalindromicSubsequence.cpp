#include <bits/stdc++.h>

using namespace std;

int longPalinSubseq(char str[]){
    int i;
    int j;
    int cl;
    int n = strlen(str);
    int dp[n+1][n+1];

    for(i = 0; i < n; i++)
        dp[i][i] = 1;

    for(cl = 2; cl <= n; cl++){
        for(i = 0; i < n-cl+1; i++){
            j = i+cl-1;

            if(str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if(str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1]+ 2;
            }
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
int main(){
    char str[1000];
    int i;

    scanf("%s", str);

    int ans = longPalinSubseq(str);

    cout << ans << endl;

    return 0;
}
