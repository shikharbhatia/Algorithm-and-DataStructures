#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n;
    int i;
    int j;

    int arr[1005];
    int dp[1005];

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(i = 0; i < n; i++){
            dp[i] = arr[i];
        }

        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                if(arr[i] > arr[j] && (dp[i] < dp[j]+arr[i])){
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
        int mx = dp[0];
        for(i = 1; i < n; i++){
            if(dp[i] > mx)
                mx = dp[i];
        }
        cout<<mx<<endl;
    }
    return 0;
}
