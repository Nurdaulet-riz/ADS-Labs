#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    long long left = 0;
    long long right = n - 1;
    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(a[mid] == k){
            cout << "Yes";
            return 0;
        }
        else if(a[mid] < k){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << "No";
    return 0;
}