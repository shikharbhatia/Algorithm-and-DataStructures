#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int i, j, k;

    cin >> t;

    while(t--){
        string s;
        int mxlen = 1;
        int strt = 0;

        cin >> s;

        int n = s.length();

        bool dp[n+1][n+1];

        memset(dp, 0, sizeof(dp));

        for(i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(mxlen < 2){
                    strt = i;
                    mxlen = 2;
                }
            }
        }

        for(k = 3; k <= n; k++){
            for(i = 0; i < n-k+1; i++){
                j = i+k-1;

                if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    if(k > mxlen){
                        strt = i;
                        mxlen = k;
                    }
                }
            }
        }
        int d = (strt+mxlen)-1;
        for(int y = strt; y <= d; y++){
            cout<<s[y];
        }
        cout<<endl;
    }
    return 0;
}
