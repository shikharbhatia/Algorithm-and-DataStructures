#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int W){
    if(n == 0 || W == 0){
        return 0;
    }

    if(wt[n-1] > W){
        return knapsack(wt, val, n-1, W);
    }

    return max(knapsack(wt, val, n-1, W), val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]));
}
int main(){
    int n;
    int i;
    int W;
    int wt[1000];
    int val[1000];

    cin >> W;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> wt[i];
        cin >> val[i];
    }

    int ans = knapsack(wt, val, n, W);

    cout<<ans<<endl;
}
