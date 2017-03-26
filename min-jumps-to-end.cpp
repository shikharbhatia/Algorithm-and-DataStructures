#include <bits/stdc++.h>

using namespace std;

int MinJumps(int arr[], int n)
{
    int i;
    int j;
    int T[n];
    T[0] = 0;
    for(i=1; i < n; i++)
        T[i] = INT_MAX;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++){
            if(i <= j+arr[j]) {
                T[i] = min(T[i], T[j]+1);
            }
        }
    }
    return T[n-1];
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = MinJumps(arr, n);

    cout<<ans;

    return 0;
}
