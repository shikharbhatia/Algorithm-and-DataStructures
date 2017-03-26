#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string s){
    map<char, int> mp;

    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }

    for(int i = 0; i < s.length(); i++){
        if(mp[s[i]]%2 != 0)
            return false;
    }
    return true;
}


int main(){
    string s;
    int t;
    cin >> t;

    while(t--){
        cin >> s;
        if(isBalanced(s))
            return 1;
        else
            return -1;
    }
    return 0;
}
