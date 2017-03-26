//this program implements the complete heap sort using stl

#include <bits/stdc++.h>

using namespace std;
bool mycomp(int a, int b){
    return (a>b);
}
int main(){
    int n, x;
    cin >> n;

    vector <int> v;
    vector <int> :: iterator it;

    for(int i = 1; i <= n; i++){
        cin >> x;
        v.push_back(x);
    }
    // min heap
    make_heap(v.begin(), v.end(), mycomp);

    for(int i = 1; i <= n; i++){
        cout << v.front()<<" ";
        pop_heap (v.begin(),v.end(), mycomp); v.pop_back();
    }

    // this can be used directly for heap sort

   /* sort_heap(v.begin(), v.end());

    for(it = v.begin(); it != v.end(); it++){
        cout << *it<<" ";
    }*/

    return 0;

}
