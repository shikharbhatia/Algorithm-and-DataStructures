#include <bits/stdc++.h>

using namespace std;

int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

bool isValid(int i, int j){
    if(i < 0 || j < 0 || i >= 3 || j >= 3)
        return 0;
    return 1;
}
bool isAdj(char prev, char curr){
    return (curr-prev == 1);
}
int getlen(char mat[][3], int i, int j, int prev){
    if(!isValid(i, j) || !isAdj(prev, mat[i][j]))
        return 0;

    int ans = 0;

    for(int k = 0; k < 8; k++){
        ans = max(ans, 1+getlen(mat, i+x[k], j+y[k], mat[i][j]));
    }
    return ans;
}

int main(){
    char mat[3][3] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};
    int row = 3;
    int col = 3;

    char src = 'a';

    int i, j, k, ans = 0;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] == src){
                for(k = 0; k < 8; k++){
                    ans = max(ans, 1+ getlen(mat, i+x[k], j+y[k], src));
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
