#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    vector<char> a;
    vector<char> b;
    string A;
    string B;
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++){
        if(A[i] != '#'){
            a.push_back(A[i]);
        }
        else if(!a.empty()){
            a.pop_back();
        }
    }
    for(int i = 0; i < B.size(); i++){
        if(B[i] != '#'){
            b.push_back(B[i]);
        }
        else if(!b.empty()){
            b.pop_back();
        }
    }
sort(a.begin(), a.end());
sort(b.begin(), b.end());

if (a == b) {
    cout << "Yes";
}
else{
    cout << "No";
}
    return 0;
}