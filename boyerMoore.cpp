#include <bits/stdc++.h>

using namespace std;

int helper[256];

void buildBad(string pat, int len){
    int i;

    for(i = 0; i < 256; i++){
        helper[i] = len;
    }
    for(i = 0; i < len; i++){
        helper[pat[i]] = len-i-1;
    }
}
int boyermoore(string txt, string pat){
    int n = txt.length();
    int m = pat.length();

    if(n < m){
        return -1;
    }
    int shift = m-1;

    buildBad(pat, m);

    while(shift < n){
        int txt_it = shift;
        int pat_it = m-1;

        while(pat_it >= 0 && pat[pat_it] == txt[txt_it]){
            txt_it--;
            pat_it--;
        }

        if(pat_it < 0){
            return txt_it+1;
        }
        else
            shift += helper[txt[shift]];
    }
}
int main(){
    string txt, pat;

    cin >> txt;
    cin >> pat;

   cout<<boyermoore(txt, pat);

    return 0;
}
