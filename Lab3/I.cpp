#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can(const vector<long long>& a, int k, long long x){
    int blocks = 1;
    long long sum = 0;
    for(int i =0; i < a.size(); i++){
        if(sum + a[i] <= x){
            sum += a[i];
        }
        else{
            blocks++;
            sum = a[i];
        }
    }
    return blocks <= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long left = 0;
    long long right = 0;
    for(int i = 0; i < n; i++){
        left = max(left, a[i]);
        right += a[i];
    }
    while(left < right){
        long long mid = left + (right - left) / 2;
        if(can(a, k, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left;
}