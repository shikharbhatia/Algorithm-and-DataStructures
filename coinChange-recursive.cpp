#include <bits/stdc++.h>

using namespace std;

int coinChange(int denomination[], int m, int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m <= 0 && n > 0)
        return 0;

    return coinChange(denomination, m-1, n) + coinChange(denomination, m, n-denomination[m-1]);
}
int main(){
    int denomination[1000];
    int m;
    int n;
    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++)
        cin>>denomination[i];

    int ans = coinChange(denomination, m, n);

    cout<<ans<<endl;

    return 0;
}
