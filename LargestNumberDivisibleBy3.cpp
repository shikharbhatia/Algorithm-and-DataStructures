#include <bits/stdc++.h>

using namespace std;

bool mycomp(int a, int b){
    return (a>b);
}

void printLargest(queue <int> q0, queue <int> q1, queue <int> q2, int n){
    int arr[n];
    int k = 0;

    while(!q0.empty()){
        arr[k++] = q0.front();
        q0.pop();
    }
    while(!q1.empty()){
        arr[k++] = q1.front();
        q1.pop();
    }
    while(!q2.empty()){
        arr[k++] = q2.front();
        q2.pop();
    }
    sort(arr, arr+k, mycomp);

    for(int i = 0; i < k; i++)
        cout<<arr[i];
}

void largestMultiple(int arr[], int n){

    int i;

    queue <int> q0;
    queue <int> q1;
    queue <int> q2;

    sort(arr, arr+n);

    for(i = 0; i < n; i++){
        if((arr[i] % 3) == 0)
            q0.push(arr[i]);

        if((arr[i] % 3) == 1)
            q1.push(arr[i]);

        if((arr[i] % 3) == 2)
            q2.push(arr[i]);
    }
    int sum = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
    }

    int temp = sum % 3;

    if(temp == 1){
        if(!q1.empty())
            q1.pop();
        else{
            q2.pop();
            q2.pop();
        }
    }
    else if(temp == 2)
        if(!q2.empty())
            q2.pop();
        else{
            q1.pop();
            q1.pop();
        }
    printLargest(q0, q1, q2, n);
}
int main(){

    int arr[] =  {8, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    largestMultiple(arr, n);

    return 0;
}
