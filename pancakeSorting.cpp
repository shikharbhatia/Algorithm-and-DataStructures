// pancake sorting

#include <bits/stdc++.h>

using namespace std;

void flip(int arr[], int i){    //reversal of array

    int start = 0;

    while(start < i){
        swap(arr[i], arr[start]);
        start++;
        i--;
    }
}

int findmax(int arr[], int n){
    int mx = arr[0];
    int index = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] > mx){
            mx = arr[i];
            index = i;
        }
    }
    return index;
}

int pancakeSort(int arr[], int n){
    int curr_size;

    for(curr_size = n; curr_size > 1; curr_size--){

        int mi = findmax(arr, curr_size);

        if(mi != curr_size-1){
            flip(arr, mi);
            flip(arr, curr_size-1);
        }
    }
}
int main()
{
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    pancakeSort(arr, n);

    for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";}
}
