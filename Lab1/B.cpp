#include <iostream>
using namespace std;
long long func(long long a, long long n, long long m){
    a %= m;
    long long res = 1 % m;
    while(n > 0){
        if(n % 2 == 1){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        n /= 2;
    }

    return res;



}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, n, m;
    cin >> a >> n >> m;
    cout << func(a, n, m) << "\n";
    return 0;
}