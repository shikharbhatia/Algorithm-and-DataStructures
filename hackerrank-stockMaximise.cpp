#include <bits/stdc++.h>

using namespace std;

long long int arr[50005];

long long int fun(long long int arr[], long long int n){
    long long int i;
    long long int j;

    long long int mx = 0, profit = 0;

    for(i = n-1; i >= 0; i--){
        mx = max(mx, arr[i]);
        profit += mx-arr[i];
    }
    return profit;
}
int main(){
    long long int t;
    long long int n, i, j;

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> arr[i];

        cout<<fun(arr, n)<<endl;
    }
     return 0;
}
