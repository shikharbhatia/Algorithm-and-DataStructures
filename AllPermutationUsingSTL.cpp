//USING STL...

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;
    cout<<endl;
    sort(s.begin(), s.end());
    cout<<s<<endl;
    while(next_permutation(s.begin(), s.end())){
        cout<<s<<endl;

    }

    return 0;
}
