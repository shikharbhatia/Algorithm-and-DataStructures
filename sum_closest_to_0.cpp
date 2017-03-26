#include <bits/stdc++.h>

using namespace std;

void sum_close_to_zero(int arr[], int n)
{
    sort(arr, arr+n);

    int start = 0;
    int last = n-1;
    int index1;
    int index2;
    int minSum = 9999;
    int curr_sum = 0;
    while(start < last){
        curr_sum = arr[start] + arr[last];
        if(abs(curr_sum) <= minSum) {
            minSum = abs(curr_sum);
            index1 = arr[start];
            index2 = arr[last];
        }
        if(curr_sum == 0)
            break;
        if(curr_sum < 0){
            start++;
        }
        if(curr_sum > 0) {
            last--;
        }

    }
    cout<<index1<<" "<<index2;
}
int main()
{
    int arr[] = {-500, -2, 8, 500};
    int n = sizeof(arr)/sizeof(arr[0]);

    sum_close_to_zero(arr, n);

    return 0;
}

