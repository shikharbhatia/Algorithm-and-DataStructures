#include <bits/stdc++.h>

using namespace std;

int maxProfit(int price[], int n){
    int profit[n+1];
    int i;
    memset(profit, 0, sizeof(profit));

    int mxprice = price[n-1];

    for(i = n-2; i >= 0; i--){
        if(price[i] > mxprice)
            mxprice = price[i];
        profit[i] = max(profit[i+1], mxprice-price[i]);
    }
    int mnprice = price[0];

    for(i = 1; i < n; i++){
        if(price[i] < mnprice)
            mnprice = price[i];
        profit[i] = max(profit[i-1], profit[i]+ price[i]-mnprice);
    }
    return profit[n-1];
}
int main(){
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);

    cout << "Maximum Profit = " << maxProfit(price, n);

    return 0;
}
