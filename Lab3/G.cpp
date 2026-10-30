#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool can(const vector<double>& a, long long k, double len){
    long long pieces = 0;
    for(int i = 0; i < a.size(); i++){
        pieces += (long long)(a[i] / len);
        if(pieces >= k){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<double> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    double left = 0;
    double right = *max_element(a.begin(), a.end());
    for(int i = 0; i < 100; i++){
        double mid = left + (right - left) / 2;
        if(can(a, k, mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << fixed << setprecision(9) << left <<'\n';
    return 0;
}