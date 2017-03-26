#include <bits/stdc++.h>

using namespace std;

void tripletSorted(int arr[], int n)
{
    int i,j,smaller[n], greater[n], index;
    int min = 0;
    int max = n-1;

    smaller[0] = -1;

    for(i = 1; i < n; i++) {
        if(arr[i] < arr[min]){
            min = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = min;
    }

    greater[n-1] = -1;

    for(i = n-2; i >= 0; i--){
        if(arr[i] > arr[max]){
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }
    for(i = 0; i < n; i++){
        if(smaller[i] != -1 && greater[i] != -1){
            index = i;
            break;
        }
    }
    cout<<arr[smaller[index]]<<" "<<arr[index]<<" "<<arr[greater[index]];
}
int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    tripletSorted(arr, n);

    return 0;
}
