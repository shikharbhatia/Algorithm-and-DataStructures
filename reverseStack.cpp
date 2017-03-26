#include <bits/stdc++.h>

using namespace std;

void insertbottom(int temp, stack<int>&s){
    if(s.empty()){
        s.push(temp);
    }
    else{
        int x = s.top();
        s.pop();
        insertbottom(temp, s);
        s.push(x);
    }
}
void reversestack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reversestack(s);

    insertbottom(temp, s);
}
int main(){
    stack<int>s;

    for(int i = 0; i < 5; i++){
        s.push(i);
    }
    cout<<endl;
    reversestack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;

}
