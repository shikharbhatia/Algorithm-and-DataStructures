#include<bits/stdc++.h>

using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[],  int yMove[]);

bool isSafe(int x, int y, int sol[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

bool solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0;

    if(solveKTUtil(0,0,1,sol,xMove,yMove) == true){
        printSolution(sol);
        return true;
    }
    else{
        cout<<"no sol";
        return false;
    }
}
int solveKTUtil(int x, int y, int movei, int sol[][8], int xMove[], int yMove[]){
    if(movei == (N*N)){
        return true;
    }
    int next_x, next_y, k;

    for(k = 0; k < 8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x,next_y,sol)){
            sol[next_x][next_y] = movei;
            if(solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove)){
                return true;
            }
            else
                sol[next_x][next_y] = -1;
        }
    }
    return false;
}
int main()
{
    solveKT();
    return 0;
}
