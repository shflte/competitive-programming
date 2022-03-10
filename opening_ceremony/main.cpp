#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    vector<int> vec;
    cin >> n;
    vec.resize(n + 1);

    for (int i = 1; i < n + 1; i++) {
        cin >> vec[i];
    }

    sort(vec.begin() + 1, vec.begin() + n + 1, cmp);

    int sum = n;
    for (int i = 1; i < n + 1; i++) {
        sum = min(sum, i + vec[i + 1]);
    }

    cout << sum << '\n';

    return 0;
}