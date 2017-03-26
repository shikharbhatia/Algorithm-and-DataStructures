//sexy..

#include <bits/stdc++.h>

using namespace std;

int yoyo(int n){
    int i;
    int a[100];
    int b[100];

    a[0] = b[0] = 1;

    for(i = 1; i < n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1]+b[n-1];

}
int main(){
    int t;
    int n;

    cin >> t;

    while(t--){
        cin >> n;

        int ans = yoyo(n);

        cout<<ans<<endl;
    }
    return 0;
}
