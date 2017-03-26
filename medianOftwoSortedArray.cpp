#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int i;

    int t;

    cin >> t;

    while(t--){
    cin >> n;

    int a[n], b[n];
    int merged[2*n];

    for(i = 0; i < n; i++){
        cin >> a[i];
    }

    for(i = 0; i < n; i++){
        cin >> b[i];
    }

    int j, k = 0;

    i = j =0;

    while(i < n && j < n){
        if(a[i] <= b[j]){
            merged[k++] = a[i];
            i++;
        }
        if(a[i] > b[j]){
            merged[k++] = b[j];
            j++;
        }
    }

    while(i < n){
        merged[k++] = a[i++];
    }
    while(j < n){
        merged[k++] = b[j++];
    }

    cout<<merged[n-1]+merged[n]<<endl;
    }
    return 0;
}
