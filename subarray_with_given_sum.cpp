#include <bits/stdc++.h>

using namespace std;

struct val {
    int s;
    int e;
};

struct val SubArraySum(int arr[], int n, int sum)
{
    int i;
    int j;
    int curr_sum = 0;
    int temp_s, temp_e;
    struct val pt;
    temp_s = -1;

    if(sum == 0) {
        for(i = 0; i < n; i++){
            if(arr[i] == 0){
                pt.s = pt.e = i;
                return pt;
            }
        }
    }
    if(sum == 0){
        pt.s = pt.e = -1;
        return pt;
    }

    for(i = 0; i < n; i++){
       curr_sum = curr_sum + arr[i];
         if(curr_sum >= sum){
            temp_s = 0;
            temp_e= i;
            break;
        }
    }
    if(sum == curr_sum){
                pt.s = 0;
                pt.e = i;
                return pt;
    }

    for(i = 1; i < n; i++){
            curr_sum = curr_sum - arr[i-1];

            if(curr_sum > sum){
                curr_sum = curr_sum - arr[temp_e];
                temp_e=temp_e - 1;
            }
            if(curr_sum < sum){
                curr_sum = curr_sum + arr[temp_e + 1];
                temp_e = temp_e + 1;
            }
            if(curr_sum == sum){
                pt.s = i;
                pt.e = temp_e;
                return pt;
            }

    }
    pt.s = -1;
    pt.e = -1;

    return pt;
}
int main()
{
    int arr[] = {15, 2, 0, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;

    struct val ans = SubArraySum(arr, n, sum);

    if(ans.s == -1 || ans.e == -1){
            cout<<ans.s<<" "<<ans.e;
            cout<<"NO";
    }
    else {
        cout<<ans.s<<" "<<ans.e;
    }
    return 0;
}
