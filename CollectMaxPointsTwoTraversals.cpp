#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y1, int y2, int R, int C){
    if(x >= 0 && x < R && y1 >=0 &&y1 < C && y2 >=0 && y2 < C);
        return true;
    return false;
}
int util(int arr[][100], int m, int n, int x, int y1, int y2){
    int temp, ans;
    if(!isValid(x, y1, y2, m, n))
        return INT_MIN;
    if((x==m-1) && (y1 == 0) && (y2 == n-1))
        return (arr[x][y1]+ arr[x][y2]);
    if(y1 == y2)
        temp = arr[x][y1];
    else
        temp = arr[x][y1]+ arr[x][y2];

    ans = max(ans, temp + util(arr, m, n, x+1, y1, y2-1));
    ans = max(ans, temp + util(arr, m, n, x+1, y1, y2+1));
    ans = max(ans, temp + util(arr, m, n, x+1, y1, y2));

    ans = max(ans, temp + util(arr, m, n, x+1, y1-1, y2));
    ans = max(ans, temp + util(arr, m, n, x+1, y1-1, y2-1));
    ans = max(ans, temp + util(arr, m, n, x+1, y1-1, y2+1));

    ans = max(ans, temp + util(arr, m, n, x+1, y1+1, y2));
    ans = max(ans, temp + util(arr, m, n, x+1, y1+1, y2-1));
    ans = max(ans, temp + util(arr, m, n, x+1, y1+1, y2+1));

    return ans;
}

int maxPt(int arr[][100], int m, int n){
    return util(arr, m, n, 0, 0, n-1);
}

int main(){
    int m, n, arr[100][100];
    int i, j;

    cin >> m;
    cin >> n;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    cout<<maxPt(arr, m, n);
}
