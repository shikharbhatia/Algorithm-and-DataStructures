#include <bits/stdc++.h>

using namespace std;

void MaxOfSubarray(int arr[], int n, int k)
{
    int mx = arr[0];
    int index = 0;
    int i, j;
    int m;
    for(i = 1; i < k; i++){
        if(arr[i] > mx){
            mx = arr[i];
            index = i;
        }
    }
    cout<<mx<<" ";
    for(i = 1; i < n-k+1; i++){
        for(j = i; j < i+k; j++) {
            if(index >= i && index < i+k){
                if(arr[i+k-1] >= mx){
                    mx = arr[i+k-1];
                    index = i+k-1;
                }
            }
            else {
                mx = arr[j];
                index = j;
                if(arr[j] > mx){
                    mx = arr[j];
                    //mx = m;
                    index = j;
                }

            }
        }
        cout<<mx<<" ";
    }
}
int main()
{
    int arr[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    MaxOfSubarray(arr, n, k);

    return 0;
}

