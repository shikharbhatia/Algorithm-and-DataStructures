#include <bits/stdc++.h>

using namespace std;

int minCoins(int coins[], int m, int V)
{
   if (V == 0) return 0;

   int res = INT_MAX;

    for (int i = 0; i < m; i++){
        if (coins[i] <= V) {
            res = min(res, 1 + minCoins(coins, m, V-coins[i]));
        }
   }
   return res;
}
int main(){
    int n;
    int c = 0;

    cin >> n;

    int arr[] =  {9, 6, 5, 1};
    int m = sizeof(arr)/sizeof(arr[0]);

    cout<<minCoins(arr, m, n);
}
