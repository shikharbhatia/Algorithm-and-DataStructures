#include <bits/stdc++.h>

using namespace std;

int part(int arr[], int l, int r){
    int i = l;
    int x = arr[r];
    int j;

    for(j = l; j <= r-1; j++){
        if(arr[j] <= x){
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k){
    if(k >0 && k <= (r-l+1)){
        int p = part(arr, l, r);

        if((p-l) == (k-1))
            return arr[p];
        if((p-l) > k-1)
            return kthSmallest(arr, l, p-1, k);

        return kthSmallest(arr, p+1,r, k-(p-l)-1);
    }
    return INT_MAX;
}

int main(){

    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);

    return 0;
}
