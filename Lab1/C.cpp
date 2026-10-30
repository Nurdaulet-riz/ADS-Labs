#include <iostream>
#include <string>
using namespace std;
string prime(long long a){
    string res;
    if(a <= 1){
        return "NO";
    }
    
    for(int i = 2; i * i < a; i++){
        if(a % i == 0){
            return "NO";
        }
    }
    return "";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a;
    cin >> a;
    cout << prime(a);
    return 0;
}