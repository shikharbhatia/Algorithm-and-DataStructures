#include <bits/stdc++.h>

using namespace std;

int foo(int i, int j){
    if(j <= i+2)
        return 1;
    int res;
    for(int k = i+1; k < j; i++){
        // cout<<1<<endl;
        res = foo(i, k)*foo(k+1, j);
    }
    return res;
}

int main(){
    int n = 3;
    cout<<foo(0, 5);
    return 0;
}
