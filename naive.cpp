#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string txt;
    string pat;
    int i, j;

    cin >> t;

    while(t--){
        cin >> txt;
        cin >> pat;

        int flag = 0;
        int flag2 = 0;

        for(i = 0; i < txt.length(); i++){
            flag = 0;
            for(j = 0; j < pat.length(); j++){
                if(txt[i+j] != pat[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                flag2 = 1;
                cout<<"found"<<endl;
                break;
            }
        }
        if(flag2 == 0){
                cout<<"not found"<<endl;
        }
    }
    return 0;
}
