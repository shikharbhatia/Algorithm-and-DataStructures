#include <bits/stdc++.h>

using namespace std;

int countOnes(int arr[], int l, int r){
    r++;
    sort(arr, arr+r);

    int *x = upper_bound(arr, arr+r, 0);

    int c = r - (x-arr);

    return c;
}
int main(){
    int arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Count of 1's in given array is " << countOnes(arr, 0, n-1);

    return 0;
}
