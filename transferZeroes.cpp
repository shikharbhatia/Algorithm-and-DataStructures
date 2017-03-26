#include <bits/stdc++.h>

using namespace std;

void pushZerosToEnd(int arr[], int n)
{
    int c = 0;
    int i;
    for(i = 0 ; i < n; i++)
    {
        if(arr[i] != 0)
        {
            arr[c++] = arr[i];
        }
    }
    while(c < n)
    {
        arr[c++] = 0;
    }
}
int main()
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZerosToEnd(arr, n);

    cout << "Array after pushing all zeros to end of array :\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
