#include <bits/stdc++.h>

using namespace std;

int kadane(int arr[], int n){
    int i;
    int curr_sum = arr[0];
    int total_sum = arr[0];

    for(i = 1; i < n; i++){
        curr_sum = max(arr[i], curr_sum+arr[i]);
        total_sum = max(total_sum, curr_sum);
    }
    return total_sum;
}

int modified(int arr[], int n){
    int i;
    int max_wrap = 0;

    int max_kadane = kadane(arr, n);

    for(i = 0; i < n; i++){
        max_wrap = max_wrap + arr[i];
        arr[i] = -arr[i];
    }
    max_wrap = max_wrap + kadane(arr, n);

    return max(max_wrap, max_kadane);
}

int main(){
    int arr[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = modified(arr, n);

    cout<<ans<<endl;

    return 0;
}
