#include <bits/stdc++.h>

using namespace std;

int median_merge(int ar1[], int ar2[], int m, int n){
    int check;
    int i, j;
    int k = 0;
    int temp[m+n];

    i = j = 0;
    check = m+n;

    while(i<m && j<n && k <= ((m+n)/2)){
        if(ar1[i] <= ar2[j]){
            temp[k++] = ar1[i];
            i++;
        }
        if(ar1[i] >= ar2[j]){
            temp[k++] = ar2[j];
            j++;
        }
    }
    while(i < m && k <= ((m+n)/2 + 1)){
        temp[k++] = ar1[i];
        i++;
    }
    while(j < n && k <= ((m+n)/2 + 1)){
        temp[k++] = ar2[j];
        j++;
    }

    if(check % 2 == 0){
        check = temp[k-1]+temp[k-2];
        return check/2;
    }
    else{
        return temp[k-2];
    }
}
int main(){
    int ar1[] = {5, 8, 10, 20};
    int ar2[] = {900};

    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);

    int median = median_merge(ar1, ar2, m, n);

    cout<<median<<endl;

    return 0;
}
