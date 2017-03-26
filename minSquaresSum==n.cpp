#include <bits/stdc++.h>

using namespace std;

int getMinSq(int n){
    int i, ans;
    if(n <= 3)
        return n;
    for(i = 1; i < (sqrt(n)+1); i++){
        if(i*i > n)
            break;
        ans = min(ans, 1+getMinSq(n - (i*i)));
    }
    return ans;
}
int main(){
    int n;

    cin >> n;

    cout<<getMinSq(n);

    return 0;
}
