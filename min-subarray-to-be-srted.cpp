#include <bits/stdc++.h>

using namespace std;

void myfunction(int arr[], int n)
{
    int s;
    int e;
    int i,j;

    for(i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            s = i;
            break;
        }
    }
    for(j = n-1; j > 0; j--) {
        if(arr[j] < arr[j-1]) {
            e = j;
            break;
        }
    }
    int mn = INT_MAX;
    int mx = - (INT_MAX);

    for(i = s; i <= e; i++){
        if(arr[i] < mn){
            mn = arr[i];
        }
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    for(i = 0; i < s; i++){
        if(arr[i] > mn){
            s = i;
        }
    }

    for(i = e+1; i < n; i++) {
        if(arr[i] < mx){
            e = i;
        }
    }

    cout<<"start = "<<s<<endl;
    cout<<"ending = "<<e<<endl;
}
int main()
{
    int arr[] = {0, 1, 15, 25, 6, -1, 7, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    myfunction(arr, n);

    return 0;
}
