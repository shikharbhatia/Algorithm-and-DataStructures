#include <bits/stdc++.h>

using namespace std;

void findPair(int arr[] ,int n, int diff){
    int i, j, result;
    int num;

    sort(arr, arr+n);

    for(i = 0; i < n; i++){

        num = diff + arr[i];

        result = binary_search(arr, arr+n, num);

        if(result > 0){
            //cout<<result<<endl;
            cout<<"found"<<endl;
        }
    }

}
int main()
{
    int arr[] = {90, 70, 20, 80, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 10;
    findPair(arr, n, diff);
    return 0;
}
