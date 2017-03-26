#include <bits/stdc++.h>

using namespace std;

int fixedpt(int arr[], int n)
{
    //modified binary search

    int lo = 0;
    int hi = n-1;
    int mid;
    while(lo < hi) {
        mid = (hi+lo)/2;
        if(arr[lo] == lo)
            return lo;
        if(arr[hi] == hi)
            return hi;
        if(arr[mid] == mid)
            return mid;
        if(arr[mid] < mid)
            lo = mid+1;
        if(arr[mid] > mid)
            hi = mid-1;
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,3,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = fixedpt(arr, n);

    if(ans != (-1)){
        cout<<"yes"<<endl;
        cout<<ans<<endl;
    }
    else
        cout<<"no";

    return 0;
}
