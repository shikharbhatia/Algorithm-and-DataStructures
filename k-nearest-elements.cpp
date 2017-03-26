#include <bits/stdc++.h>

using namespace std;

void printKclosest(int arr[], int x, int k, int n){

    int *idx = lower_bound(arr, arr+n, x);
    int cnt = 0;

    int l = idx - arr;
    l--;
    int r = l + 2;

    while(l >= 0 && r < n && cnt < k){
        if((x - arr[l]) <= (arr[r] - x))
            cout << arr[l--]<<" ";
        else
            cout << arr[r++]<<" ";
        cnt++;
    }

    while(cnt < k && l >= 0){
        cout << arr[l--]<<" ";
        cnt++;
    }
    while(cnt < k && r < n){
        cout << arr[r++]<<" ";
        cnt++;
    }
}
int main() {
    int arr[] ={12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 35, k = 4;

    printKclosest(arr, x, 4, n);

    return 0;
}
