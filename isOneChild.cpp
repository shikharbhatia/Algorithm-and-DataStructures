#include <bits/stdc++.h>

using namespace std;

bool isOneChild(int arr[], int n){
    int i;
    int a;
    int b;

    for(i = 0; i < n-1; i++){
        a = arr[i] - arr[i+1];
        b = arr[i] - arr[n-1];

        if(a*b < 0)
            return 0;
    }
    return 1;
}
int main(){
    int arr[] = {20, 10, 11, 13, 12};
    int n = sizeof(arr)/sizeof(int);

    bool ans = isOneChild(arr, n);
    if(ans)
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}
