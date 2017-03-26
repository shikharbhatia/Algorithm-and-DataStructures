#include <bits/stdc++.h>

using namespace std;

int dp[105][50005];

int isSubset1(int arr[], int n, int s){
    if(dp[n][s]!=-1)
        return dp[n][s];
    if(s == 0) {
        dp[n][s] = 1;
        return 1;
    }

    if((s != 0) && (n == 0)) {
       dp[n][s] = 0;
        return 0;
    }

    if(arr[n-1] > s) {
            dp[n][s] = isSubset1(arr, n-1, s);
        return dp[n][s];
    }
        dp[n][s] = isSubset1(arr, n-1, s);
        dp[n][s] = dp[n][s] || isSubset1(arr, n-1, s-arr[n-1]);

    return dp[n][s];
}




int findPartition(int arr[], int n){
    int i;
    int sum = 0;

    for(i = 0; i < n; i++){
        sum += arr[i];
    }

    if(sum % 2 != 0)
        return 0;
    else
        return isSubset1(arr ,n, sum/2);
}
int main(){
    int t;
    int n;
    int i;
    int arr[1005];

    cin >> t;

    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n;

        for(i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(findPartition(arr, n))
            cout<<"Can be divided into two subsets of equal sum"<<endl;
        else
            cout<<"Cannot be divided into two subsets of equal sum"<<endl;

    }
    return 0;
}
