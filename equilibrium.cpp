#include <bits/stdc++.h>

using namespace std;

int equilibrium(int arr[], int n);

int main()
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = equilibrium(arr, n);
    if(ans != (-1))
        cout<<"Equilibrium Element = "<<arr[ans];
    else
        cout<<"no equilibrium point";
    return 0;
}

int equilibrium(int arr[], int n)
{
    int i = 0;
    int j = n-1;
    int lsum = 0;
    int rsum = 0;

    while(i < j){
        lsum += arr[i];
        rsum += arr[j];

        if(lsum == rsum && (j == (i+2))){
            return (i+1);
        }
        i++;
        j--;
    }
    return -1;
}
