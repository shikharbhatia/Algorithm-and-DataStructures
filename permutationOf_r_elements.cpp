#include <bits/stdc++.h>

using namespace std;
void Combination(int arr[], int data[], int s, int e, int index, int r){
    if(index == r){
        for(int j = 0; j < r; j++){
            cout<<data[j];
        }
        cout<<endl;
        return;
    }
    int i;

    for(i = s; i <= e && e-i+1 >= r-index; i++){
        data[index] = arr[i];
        Combination(arr, data, i+1, e, index+1, r);
    }
}

void printCombination(int arr[], int n, int r){
    int data[r];
    Combination(arr, data, 0, n-1, 0, r);

}


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int r = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    printCombination(arr, n, r);
}
