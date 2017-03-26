#include <bits/stdc++.h>

using namespace std;

int triplet(int arr[], int n, int sum)
{
    int k;
    int i,j,curr_sum = 0;

    sort(arr, arr+n);
    for(k = 0; k < n-2; k++){
        i = k+1;
        j = n-1;
        while(i < j){
            curr_sum = arr[k]+arr[i]+arr[j];

            if(curr_sum == sum){
                cout<<arr[k]<<" "<<arr[i]<<" "<<arr[j]<<endl;
                return 1;
            }
            if(curr_sum < sum){
                i++;
            }
            if(curr_sum > sum){
                j--;
            }
        }
    }

    return -1;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 22;

    int r = triplet(arr, n, sum);

    if(r < 0)
        cout<<"D.N.E";
    else {
        cout<<"Yes, It exists";
    }
}
