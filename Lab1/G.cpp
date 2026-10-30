#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);

    string n;
    cin >> n;
   
    stack<char> l;
    for(int i = 0; i < n.size(); i ++){
        if(!l.empty() && l.top() == n[i]){
            l.pop();
        }
        else{
        l.push(n[i]);
        }
    }
    if(l.empty()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}