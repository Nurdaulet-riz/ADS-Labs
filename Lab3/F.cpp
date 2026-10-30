#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can(const vector<long long>& a, long long x, long long y){
    long long h = 0;
    for(int i = 0; i < a.size(); i++){
        h += (a[i] + y - 1) / y;
        if(h > x){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long left = 1;
    long long right = *max_element(a.begin(), a.end());
    while(left < right){
        long long mid = left + (right - left) / 2;
        if(can(a, x, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}