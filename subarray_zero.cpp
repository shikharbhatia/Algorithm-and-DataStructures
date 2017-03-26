#include <bits/stdc++.h>

using namespace std;

void SubarrayZeroSum(int arr[], int n){
    int i,j;
    int t[n][n];
    t[0][0] = arr[0];

    for(i = 1; i < n; i++){
        t[0][i] = t[0][i-1]+ arr[i];
        if(arr[i] == 0){
            cout<<i<<" "<<i;
        }
    }
    for(i = 1; i < n; i++){
        t[i][0] = -(INT_MAX);
    }

    for(i = 1; i < n; i++){
        for(j = i+1; j < n ;j++){
            t[i][j] = t[i-1][j] - t[i-1][i-1];
            if(t[i][j] == 0){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    SubarrayZeroSum(arr, n);

    return 0;
}
