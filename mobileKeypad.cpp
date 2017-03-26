#include <bits/stdc++.h>

using namespace std;

int row[] = {0, 0, 0, -1, 1};
int col[] = {0, -1, 1, 0, 0};

int getCountUtil(char keypad[4][3], int n, int i, int j){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    int move = 0, ro, co, total=0;

    for(move = 0; move < 5; move++){
        ro = i + row[move];
        co = j + col[move];

        if(ro >= 0 && ro <= 3 && co >= 0 && co <= 2 && keypad[ro][co] != '*' && keypad[ro][co] != '#'){
            total += getCountUtil(keypad, n-1, ro, co);
        }
    }
    return total;
}
int getCount(char keypad[4][3], int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 10;
    int i,j, totalCount = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            if(keypad[i][j] != '*' && keypad[i][j] != '#')
                totalCount += getCountUtil(keypad, n, i, j);
        }
    }
    return totalCount;
}
int main(){

    char keypad[4][3] = {{'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'},
                         {'*','0','#'}};

    int n;

    cin >> n;

    cout<<getCount(keypad, n)<<endl;

    return 0;
}
