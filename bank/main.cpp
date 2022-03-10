#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <queue>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int N, T, a, b, count, sum;
    vector<pair<int, int> > v;
    vector<int> m;

    cin >> N >> T;
    m.resize(T + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);

    for (auto x : v) {
        count = x.second;
        while (count != -1) {
            if (m[count] != 0) {
                count--;
            }
            else {
                m[count] = x.first;
                break;
            }
        }
    }

    sum = 0; 
    for (auto x : m) {
        sum += x;
    }

    cout << sum << '\n';
    
    return 0;
}