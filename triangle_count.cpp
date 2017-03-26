#include <bits/stdc++.h>

using namespace std;

bool myfunction(int i, int j){
    return i > j;
}
int triangle_count(int arr[], int n){
    sort(arr, arr+n, myfunction);
    int i,j, k;
    int c = 0;

    for(k = 0; k < n-2; k++){
        i = k+1;
        for(j = i+1; j < n; j++){
            if((arr[i] + arr[j]) > arr[k])
                c++;
        }
    }
    return c;
}
int main(){

    int arr[] = {4, 6, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = triangle_count(arr, n);

    cout<<ans<<endl;

    return 0;

}
