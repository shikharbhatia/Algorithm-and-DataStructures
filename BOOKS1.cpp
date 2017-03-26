#include <bits/stdc++.h>

using namespace std;

bool check(long long int arr[], long long int l, long long int h, long long int midVal, int k){
    long long int s = 0;
    long long int cnt = 0;
    long long int i = l;

    for(i = l; i < h; i++){
        s += arr[i];
        if(s > midVal && (i < h)){
            cnt++;
            s = 0;
            i--;
        }
    }
    if(cnt <= (k-1)){
        return true;
    }
    else
        return false;
}

void print(long long int arr[], long long int l, long long int h, long long int midVal){
    long long int i;
    long long int s = 0, cnt=0;
    for(i = l; i < h; i++){
        s += arr[i];
        if(s > midVal && (i < h)){
            cnt++;
            s = 0;
            i--;
            cout << "/ ";
            continue;
        }
        cout << arr[i]<<" ";
    }

}
int main(){
    int t;
    int i, m, k;
    long long int l, h, mid;
    long long int arr[1000];
    long long int sum = 0;
    cin >> t;

    while(t--){
        cin >> m;
        cin >> k;

        for(i = 0; i < m; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        l = 0;
        h = sum;

        while(l < h ){
            mid = l + (h-l)/2;

            if(check(arr, 0, m, mid, k) == false){
                l = mid+1;
            }
            else
                h = mid;
        }
        //cout << l;
        print(arr, 0, m, l);
    }
    return 0;
}
