#include <bits/stdc++.h>

using namespace std;

int cutrod(int price[], int n){
    int i;
    if(n == 0){
        return 0;
    }
    if(n == 1)
        return price[0];

    int mx = INT_MIN;

    for(i = 0; i < n; i++){
        int res = price[i] + cutrod(price, n-i-1);
        if(res > mx)
            mx = res;
    }
    return mx;
}
int main(){
    int n;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    n = sizeof(price)/sizeof(price[0]);

    cout<<cutrod(price, n)<<endl;

    return 0;
}
