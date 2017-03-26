#include <bits/stdc++.h>

using namespace std;

int isMajority(int arr[], int n, int x)
{
    int lo = 0;
    int hi = n-1;
    int mid;
    int c = 0;
    while(lo < hi){
        mid = (hi + lo)/2;
        if(arr[mid] == x){
                c++;
            for(int i = mid-1; i >= 0; i--){
                if(arr[i] == x)
                    c++;
                else
                    break;
            }
            for(int i = mid + 1; i < n; i++){
                if(arr[i] == x)
                    c++;
                else
                    break;
            }
            break;
        }
        if(arr[mid] < x){
            lo = mid;
        }
        if(arr[mid] > x){
            hi = mid;
        }
    }

    return c;
}

int main()
{
    int arr[] = {1, 1, 1, 4,4 ,4,4, 4, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 4;

    if(isMajority(arr, n, x) > (n/2))
        cout<<"TRUE";
    else
        cout<<"FALSE";

    return 0;
}
