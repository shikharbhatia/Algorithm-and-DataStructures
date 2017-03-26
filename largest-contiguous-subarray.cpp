#include <bits/stdc++.h>

using namespace std;

bool isMaj(int arr[], int e, int size);
int candidate_key(int arr[], int n);

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int elem = candidate_key(arr, n);

    if(isMaj(arr, elem, n)){
        cout<<"yo";
        cout<<elem;
    }
    else{
        cout<<"oh, no"<<endl;
        cout<<elem;
    }
    return 0;
}
int candidate_key(int arr[], int n)
{
    int curr, max;
    int i;
    curr = 0;
    max = 0;

    for(i = 0; i < n; i++){
        curr = curr + arr[i];
        if(curr < 0)
            curr = 0;
        if(curr > max)
            max = curr;
    }
    return max;
}
bool isMaj(int arr[], int elem, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == elem)
            count++;
    }
    if(count > (n/2))
        return true;
    else
        return false;
}
