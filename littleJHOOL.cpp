#include <bits/stdc++.h>

using namespace std;

int ways(int n){
    if(n == 0)
        return 0;
    if(n < 0)
        return 999999;

    int res = 1 + min(ways(n-10), ways(n-12));

    return res;
}
int main(){
    int t;
    int n;

    cin >> t;

    while(t--){
        cin >> n;

        int ans = ways(n);
        if(ans > n)
            cout<<"-1"<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}
