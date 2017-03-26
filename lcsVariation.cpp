#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2){
    int dp[100][100];
    int i, j;
    for(i = 0; i <= s1.length(); i++){
        for(j = 0; j <= s2.length(); j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}

int foo(string s1, string s2){
    int len1 = s1.length();
    int len2 = s2.length();

    int len_lcss = lcs(s1, s2);

    return (len1 + len2 - len_lcss);
}

int main(){
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout<<foo(s1, s2);

    return 0;
}
