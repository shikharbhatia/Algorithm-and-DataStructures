#include <bits/stdc++.h>

using namespace std;

map<string, int>mp;
void foo(string s, int i, int j){
    if(j < i+1){
        return;
    }
    if(mp.find(s.substr(i, j-i+1)) == mp.end()){
        mp[s.substr(i, j-i+1)] = 1;
        cout<<s.substr(i, j-i+1)<<endl;
    }
    foo(s, i+1, j);
    foo(s, i, j-1);
    foo(s, i+1, j-1);
}
int main(){
    string s;

    cin >> s;

    foo(s, 0, s.length()-1);

    return 0;
}
