#include <bits/stdc++.h>

using namespace std;

int ceilingNumber(int arr[], int n, int x)
{
    int lo = 0;
    int hi = n-1;
    int mid;

    while(lo < hi){

        if(arr[hi] < x){
            cout<<"D.N.E"<<endl;
            return -1;
        }
        if(arr[lo] > x)
            return lo;

        mid = (lo+hi)/2;

        if(arr[mid] == x)
            return mid;

        if(arr[mid] < x){
            if(((mid+1) <= hi) && arr[mid+1] >= x)
                return (mid+1);
            else
                lo = mid + 1;
        }
        if(arr[mid] > x) {
            if(((mid-1)>= lo) && (x >= arr[mid-1]))
                return (mid);
            else
                hi = mid-1;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;

    int ceil_ans = ceilingNumber(arr, n, x);

    cout<<"Ceiling = "<<arr[ceil_ans];

    return 0;
}
