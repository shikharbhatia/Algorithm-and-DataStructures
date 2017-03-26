#include <bits/stdc++.h>

using namespace std;

void LargestSubarray(int arr[], int n)
{
    int i, j, len = 0;
    int c_z = 0;
    int c_o = 0;
    int s,e;

    for(i = 0; i < n; i++){
            c_z = c_o = 0;
        for(j = i; j < n; j++){
            if(arr[j] == 0)
                c_z++;
            if(arr[j] == 1)
                c_o++;
            if(c_z == c_o && (j-i) >= len) {
                len = j-i;
                s = i;
                e = j;
            }
        }
    }
   /* if(c_z == 0 || c_o == 0){
        cout<<"no subarray";
        return;
    }*/
    cout<<s<<" "<<e<<endl;
}
int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    LargestSubarray(arr, n);

    return 0;
}
