#include <iostream>
using namespace std;
bool isprime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int count = 0;
    int number = 1;
    while(count < n){
        number++;
        if(isprime(number)){
            count++;
        }
    }
    cout << number; 
    return 0;
}