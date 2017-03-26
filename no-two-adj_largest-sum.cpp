#include <bits/stdc++.h>

using namespace std;

int maximum_sum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for(i = 1; i < n; i++){
        excl_new = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_new;
    }
    cout<<endl<<endl;
    return max(incl, excl);
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_sum = maximum_sum(arr, n);

    cout<<max_sum;

    return 0;
}
