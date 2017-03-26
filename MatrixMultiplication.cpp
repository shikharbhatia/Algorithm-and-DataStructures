#include <bits/stdc++.h>

using namespace std;

int MatrixMul(int arr[], int start, int end){
    if(start == end){
        return 0;
    }
    int k, mn = INT_MAX, c;

    for(k = start; k < end; k++){
        c = MatrixMul(arr, start, k)+MatrixMul(arr, k+1, end)+arr[start-1]*arr[k]*arr[end];
        if(c < mn)
            mn = c;
    }
    return mn;
}
int main(){
    int arr[1000];
    int n;
    int i;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout<<MatrixMul(arr, 1, n-1);
}
