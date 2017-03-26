#include <bits/stdc++.h>

using namespace std;

//kadane's algorithm

int maxSum(int arr[], int n){
    int curr_sum = arr[0];
    int max_end = arr[0];
    int i;
    for(i = 1; i < n; i++){
        curr_sum = max(curr_sum+arr[i], arr[i]);
        max_end = max(max_end, curr_sum);
    }
    return max_end;
}
int main(){
    int t;
    int i;
    int n;
    int arr[105];

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> arr[i];

        int ans = maxSum(arr, n);

        cout<<ans<<endl;
    }
}
