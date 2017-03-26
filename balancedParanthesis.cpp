#include <bits/stdc++.h>

using namespace std;

bool isSame(char a, char b){
    if(a == '(' && b == ')')
        return true;
    if(a == '{' && b == '}')
        return true;
    if(a == '[' && b == ']')
        return true;
    return false;
}

bool isBalanced(char exp[], int len){
    stack<char> s;

    int i = 0;
    char temp;
    while(i < len){
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            s.push(exp[i]);
        else if((exp[i] == '}' || exp[i] == ')' || exp[i] == ']')){
            if(s.empty())
                return false;
            temp = s.top();
            s.pop();
            if(!isSame(temp, exp[i]))
                return false;
        }
        i++;
    }
    if(s.empty())
        return true;
    else
        return false;
}

int main(){
    char exp[100] = "()";

    int len = strlen(exp);

    if(isBalanced(exp, len))
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}
