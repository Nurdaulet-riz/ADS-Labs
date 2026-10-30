#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool can(const vector<pair<long long, long long>>& a, int k, long long L){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        long long x2 = a[i].first;
        long long y2 = a[i].second;
        if(x2 < L && y2 < L){
            cnt++;
        }
    }
    return cnt >= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> a(n);
    long long right = 0;
    for(int i = 0; i < n; i++){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x2, y2};
        right = max(right, max(x2, y2));
    }
    long long left = 0;
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
    return 0;
}