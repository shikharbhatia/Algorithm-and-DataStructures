#include <bits/stdc++.h>

using namespace std;

struct suffix {
    int index;
    char *suff;
};
int suffixIdx[105];

bool mycomp(struct suffix a, struct suffix  b){
    return (strcmp(a.suff, b.suff) < 0? 1 : 0);
}
void buildSuffix(char txt\[], int n){
    struct suffix suffixes[n];

    for(int i = 0; i < n; i++){
        suffixes[i].index = i;
        suffixes[i].suff = txt+i;
    }

    sort(suffixes, suffixes+n, mycomp);

    for(int i = 0; i < n; i++){
        suffixIdx[i] = suffixes[i].index;
    }
}

void searchSuffix(char txt[], char pat[], int n){
    int mid;
    int l = 0;
    int r = n-1;
    int m = strlen(pat);

    while(l <= r){
        mid = (l+r)/2;

        int res = strncmp(pat, txt + suffixIdx[mid], m);

        if(res == 0){
            cout<<suffixIdx[mid];
            return;
        }
        if(res < 0){
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout<<"not found";
}
int main(){

    char txt[] = "banana";  // text
    char pat[] = "nan";

    int n = strlen(txt);

    buildSuffix(txt, n);

    searchSuffix(txt, pat, n);

    return 0;
}
