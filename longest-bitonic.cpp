#include <bits/stdc++.h>

using namespace std;

int LongestBitonic(int arr[], int n)
{
    int i;
    int j;
    int mx = 0;
    int c;
    int index;

    if(n==1)
        return 1;
    for(i = 0; i < n; i++){
        c = 0;
        for(j = i+1; j <= n-1; j++){
            if(((arr[j-1] <= arr[j]) && (arr[j] <= arr[j+1])) || ((arr[j-1] <= arr[j])&& (arr[j] >= arr[j+1]))){
                c++;
            }
        }
        if(c > mx){
            mx = c;
            index = i;
        }
    }
    for(i = index; i < index+ mx; i++){
        cout<<arr[i]<<" ";
    }
    return mx;

}

int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = LongestBitonic(arr, n);
    cout<<endl;
    cout<<ans;
}
