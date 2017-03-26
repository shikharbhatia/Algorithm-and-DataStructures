#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int foo(int arr[], int n, int k){

    if(n <=0 || k == 0)
        return 0;
    if(arr[n-1] > k){
        return foo(arr, n-1, k);
    }

    return max(arr[n-1]+ foo(arr, n, k-arr[n-1]), foo(arr, n-1, k));

}
int main() {
    int i, t;
    int n;
    int k;
    int arr[2001];

    cin >> t;

    while(t--){

        cin >> n;
        cin >> k;

        for(i = 0; i < n; i++)
            cin >> arr[i];

        cout<<foo(arr, n, k)<<endl;
    }
    return 0;
}
