#include <bits/stdc++.h>

using namespace std;

int isSubarray(int ar1[], int ar2[], int m, int n)
{
    sort(ar1, ar1+m);
    sort(ar2, ar2+n);

    int i,j;
    int c = 0;
    i = 0;
    j = 0;
    while(i < m && j < n){
        if(ar1[i] == ar2[j]){
            c++;
            i++;
            j++;
        }
        if(ar1[i] > ar2[j])
            j++;
        if(ar1[i] < ar2[j])
            i++;
    }
    if(c == n || c==m)
        return 1;
}
int main()
{
    int ar1[] = {19, 5};
    int m = sizeof(ar1)/sizeof(ar1[0]);

    int ar2[] = {10, 5, 2, 23, 19};
    int n = sizeof(ar2)/sizeof(ar2[0]);

    int ans = isSubarray(ar1, ar2, m, n);

    if(ans == 1)
        cout<<"true";
    else
        cout<<"false";

    return 0;
}
