//backtracking method

#include <bits/stdc++.h>

using namespace std;

void permute(string s, int l, int r){
    int i;

    if(l == r){
        cout<<s<<endl;                      //O(N)
        return;
    }
    else {
        for(i = l; i <= r; i++){
            swap(s[l], s[i]);
            permute(s, l+1, r);         //FOR LOOP AND PERMUTE IS TAKING O(N!)
            swap(s[l], s[i]);
        }
    }
}
int main(){
    string s;

    cin >> s;

    permute(s, 0, s.length() - 1);

    return 0;
}
