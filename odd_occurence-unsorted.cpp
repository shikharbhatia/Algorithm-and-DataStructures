#include <bits/stdc++.h>

using namespace std;

void OddOccurrences(int arr[], int n)
{
    int i, setbit;
    int sum = arr[0];
    int t1 = 0;
    int t2 = 0;

    for(i = 1; i < n; i++)
        sum = sum ^ arr[i];

    setbit = sum & ~(sum-1);

    for(i = 0; i < n; i++){
        if(arr[i] & setbit)
            t1 = t1 ^ arr[i];
        else
            t2 = t2^arr[i];
    }
    cout<<t1<<" "<<t2<<endl;
}
int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    OddOccurrences(arr, n);

    return 0;
}

