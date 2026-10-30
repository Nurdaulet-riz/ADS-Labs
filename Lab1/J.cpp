#include <iostream>
#include <deque>
using namespace std;

int main() {
    const int n = 5;

    deque<int> boris;
    deque<int> nursik;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        boris.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nursik.push_back(x);
    }

    int moves = 0;

    while (!boris.empty() && !nursik.empty()) {
        int b = boris.front();
        int n = nursik.front();

        boris.pop_front();
        nursik.pop_front();

        moves++;

        bool borisWins;

        if (b == 0 && n == 9)
            borisWins = true;
        else if (b == 9 && n == 0)
            borisWins = false;
        else
            borisWins = b > n;

        if (borisWins) {
            boris.push_back(b);
            boris.push_back(n);
        }
        else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
    }

    if (boris.empty())
        cout << "Nursik " << moves;
    else
        cout << "Boris " << moves;
}