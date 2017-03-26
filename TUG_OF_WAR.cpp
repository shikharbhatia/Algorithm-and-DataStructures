#include <bits/stdc++.h>

using namespace std;

void TOWUTIL(vector<int>arr, int n, vector<bool>curr_elem,int selected, vector<bool>&sol, int *mn_diff, int sum, int curr_sum, int curr_pos){
    if(curr_pos == n)
        return;

    if((n/2-selected) > (n-curr_pos))
        return;

    TOWUTIL(arr, n, curr_elem, selected, sol, mn_diff, sum, curr_sum, curr_pos+1);

    selected++;
    curr_sum += arr[curr_pos];
    curr_elem[curr_pos] = true;

    if(selected == n/2){
        if(abs(curr_sum - sum/2) < (*mn_diff)){
            *mn_diff = abs(curr_sum - sum/2);
            for(int i = 0; i < n; i++){
                sol[i] = curr_elem[i];
            }
        }
    }
    else{
       TOWUTIL(arr, n, curr_elem, selected, sol, mn_diff, sum, curr_sum, curr_pos+1);
    }
    curr_elem[curr_pos] = false;
}
void TOW(vector<int> arr){
    int n = arr.size();

    int sum = 0;
    int mn_diff = INT_MAX;

    vector<bool>curr_elem(n, false);
    vector<bool>sol(n, false);

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    TOWUTIL(arr, n, curr_elem, 0,sol, &mn_diff, sum, 0, 0);

    for(int i = 0; i < n; i++){
        if(sol[i] == true)
            cout<<arr[i]<<" ";
    }
    cout<<endl;

     for(int i = 0; i < n; i++){
        if(sol[i] == false)
            cout<<arr[i]<<" ";
    }

}
int main(){
    int n;

    cin >> n;

    vector<int>arr(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    TOW(arr);

    return 0;
}
