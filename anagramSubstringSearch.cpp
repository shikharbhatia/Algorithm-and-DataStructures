#include <bits/stdc++.h>

using namespace std;

int anagramSearch(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    int i, j, flag = 0;
    int c = 0;

    int hash_txt[256], hash_pat[256];

    memset(hash_pat, 0, sizeof(hash_pat));

    for(i = 0; i < m; i++){
        hash_pat[pat[i]]++;
    }
    for(i = 0; i <= n-m; i++){
        flag = 0;
        memset(hash_txt, 0, sizeof(hash_txt));
        for(j = i; j < (i+m); j++){
            hash_txt[txt[j]]++;
        }
        for(j = 0; j < m; j++){
            if(hash_pat[pat[j]] != hash_txt[pat[j]]){
                flag = 1;
            }
        }
        if(!flag){
            c++;
        }
    }
    return c;
}
int main(){
    string txt, pat;
    int t;
    cin >> t;
    while(t--){
        cin >> txt;
        cin >> pat;

        cout<<anagramSearch(txt, pat)<<endl;
    }
    return 0;
}
