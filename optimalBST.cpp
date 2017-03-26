#include <bits/stdc++.h>

using namespace std;

int dp[100][100];
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int opt(int freq[], int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(j < i)
        return (dp[i][j]=0);
    if(j==i)
        return (dp[i][j]=freq[i]);

    int fsum = sum(freq, i, j);
    int mn = INT_MAX;

    for(int k = i; k <= j; k++){
        int cost = opt(freq, i, k-1) + opt(freq, k+1, j);
        if(cost < mn)
            mn = cost;
    }
    return (dp[i][j]=mn+fsum);

}
int optimalSearchTree(int keys[], int freq[], int n){
    return opt(freq, 0, n-1);
}
int main(){
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", optimalSearchTree(keys, freq, n));

    return 0;
}
