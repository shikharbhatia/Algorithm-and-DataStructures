#include <bits/stdc++.h>

using namespace std;

long long int fun(long long int n){
    long long int s = 0;
    long long int r;
    while(n != 0){
        s += n;
        if(n >= 10){
            r = n%10;
            s += r;
            n = n/10;
        }
        else
            break;
    }
    return s;
}
int main(){
    long long int n;

    cin >> n;

    long long int sum = fun(n);

    cout<<sum<<endl;

    return 0;
}
