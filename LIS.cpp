#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,j, t;
    int n;
    int arr[1000];
    int lis[1000];

    cin >> t;

    while(t--){
        cin >> n;

        for(i = 0; i < n; i++){
            cin >> arr[i];
            lis[i] = 1;
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < i; j++){
                if(arr[i] > arr[j] && lis[i] < (lis[j]+1)){
                    lis[i] = 1 + lis[j];
                }
            }
        }
        int mx = lis[0];
        for(i = 1; i < n; i++){
            if(lis[i] > mx){
                mx = lis[i];
            }
        }
        cout << mx<<endl;
    }
    return 0;
}
