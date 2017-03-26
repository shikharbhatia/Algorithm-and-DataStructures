#include <bits/stdc++.h>

using namespace std;

long long int SumOfDigit(long long int n){
    long long int s = 0;
    while(n > 0){
        long long int d = n%10;
        s += d;
        n = n/10;
    }
    return s;
}
int main(){
    long long int t;
    cin >> t;
while(t--){
    long long int sum, n, c=0;
    cin >> n;
    cin >> sum;

    long long int start = pow(10, n-1);
    long long int end = pow(10, n);

    for(long long int i = start; i < end; i++){
        if(SumOfDigit(i) == sum)
            c++;
    }
    if(c == 0)
        cout<<"-1"<<endl;
    else
        cout<<c%1000000007<<endl;
}
    return 0;
}
