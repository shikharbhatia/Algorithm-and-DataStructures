#include<bits/stdc++.h>

using namespace std;

int utilitySum(int *st, int low, int high, int qs, int qe, int pos){
    if(qs <= low && qe >= high)
        return st[pos];
    if(high < qs || low > qe)
        return 0;
    int mid = (low+high)/2;
    return utilitySum(st, low, mid, qs, qe, 2*pos+1) + utilitySum(st, mid+1, high, qs, qe, 2*pos+2);
}
int getSum(int *st, int n, int s, int e){
    return utilitySum(st, 0, n-1, s, e, 0);
}

int utilityST(int arr[], int *st, int low, int high, int pos){
    if(low == high){
        st[pos] = arr[low];
        return arr[low];
    }
    int mid = (low + high)/2;

    st[pos] = utilityST(arr, st, low, mid, 2*pos + 1) + utilityST(arr, st, mid+1, high, 2*pos + 2);

    return st[pos];
}
int *constructST(int arr[], int n){
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    utilityST(arr, st, 0, n-1, 0);
    return st;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructST(arr, n);

    cout<<getSum(st, n, 2,3);

    return 0;
}
