#include <bits/stdc++.h>

using namespace std;

char s1[1005], s2[1005];;

int sumDig(int n){
    int s = 0,d;

    while(n != 0){
        d = n%10;
        s += d;
        n = n/10;
    }
    return s;
}
int main(){
    int n;
    int sum;
    int init;
    int endd;
    int c = 0;
    int i;

    cin >> n;
    cin >> sum;

    for(i = 0 ; i < n; i++){
        if(i == (n-1)){
            strcat(s1, "1");
            strcat(s2, "9");
        }
        else{
            strcat(s1, "0");
            strcat(s2, "9");
        }
    }

    reverse(s1, s1+n);

    init = atoi(s1);
    endd = atoi(s2);

    cout<<init<<" "<<endd<<endl;
    for(i = init; i <= endd; i++){
        if(sumDig(i) == sum){
            c++;
        }
    }

    cout<<c<<endl;

    return 0;
}
