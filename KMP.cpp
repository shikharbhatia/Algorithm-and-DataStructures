#include <bits/stdc++.h>

using namespace std;

void buildLps(int lps[],char pat[], int n){
    lps[0] = 0;
    int i, j;

    i = 1;
    j = 0;

    while(i < n){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else if(pat[i] != pat[j]){
            if(j > 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char txt[], char pat[]){
    int m = strlen(txt);
    int n = strlen(pat);
    int i = 0, j = 0;

    int lps[n];

    buildLps(lps,pat, n);

    while(i < m){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == n){
            cout<<"found at = "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i < m && pat[j] != txt[i]){
            if(j > 0){
                j = lps[j-1];
            }
            else
                i++;
        }
    }
}


int main(){
    char txt[105];
    char pat[105];

    cin.getline(txt, sizeof(txt));  //includes spaces in the input string
    cin.getline(pat, sizeof(pat));

    kmp(txt, pat);

    return 0;
}
