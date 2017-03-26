#include <bits/stdc++.h>

using namespace std;

int maxdivide(int a, int b){
    while(a%b == 0)
        a=a/b;
    return a;
}
bool isUgly(int x){
    x = maxdivide(x, 2);
    x = maxdivide(x, 3);
    x = maxdivide(x, 5);

    if(x == 1)
        return true;
    return false;
}
int main(){
    int t;
    int n;

    cin >> t;

    while(t--){
        cin >> n;
        int i = 1;
        int count = 1;

        while(count != n){
            i++;
            if(isUgly(i))
                count++;
        }
        int ans = i;
        cout<<ans<<endl;
    }
    return 0;
}
