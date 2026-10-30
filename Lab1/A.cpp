#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    while(b != 0){
        long long rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";

    return 0;
}