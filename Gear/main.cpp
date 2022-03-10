#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    double p;
    cin >> p;
    p = p / 100 + 1;
    // cout << p << '\n';

    vector<double> _a, _b;
    _a.resize(a);
    for (int i = 0; i < a; i++) {
        cin >> _a[i];
    }
    _b.resize(b);
    for (int i = 0; i < b; i++) {
        cin >> _b[i];
    }
    vector<double> pairs;

    double current, big, small, ta, ba;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            pairs.push_back(_a[i] / _b[j]);
        }
    }
    sort(pairs.begin(), pairs.end());
    for (int i = 0; i < pairs.size() - 1; i++) {
        if (pairs[i + 1] / pairs[i] > p) {
            cout << "Time to change gears!\n";
            return 0;
        }
    }

    cout << "Ride on!\n";

    return 0;
}