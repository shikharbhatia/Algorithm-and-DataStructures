#include <bits/stdc++.h>

using namespace std;

int MaxIndexDiff(int arr[], int n)
{
    int lmin[n];
    int rmax[n];
    int i;
    int j;

    lmin[0] = arr[0];

    for(i = 1; i < n; i++){
        lmin[i] = min(lmin[i-1], arr[i]);
    }
    rmax[n-1] = arr[n-1];
    for(j = n-2; j>=0; j--){
        rmax[j] = max(rmax[j+1], arr[j]);
    }

    i = j = 0;
    int maxdiff = -1;
    while(i < n && j < n){
        if(lmin[i] < rmax[j]){
            maxdiff = max(maxdiff, j-i);
            j++;
        }
        else
            i++;
    }
    return maxdiff;
}

int main()
{

    int arr[] = {9, 2, 3, 4, 5, 6 ,7, 8, 18, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<MaxIndexDiff(arr, n);

    return 0;
}
