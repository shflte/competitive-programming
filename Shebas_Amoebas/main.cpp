#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void elim(int i, int j, vector<vector<bool> > &table) {
    table[i][j] = false;
    vector<vector<int> > dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto x : dir) {
        if (i + x[0] < 0 || j + x[1] < 0 || i + x[0] > table.size() || j + x[1] > table[0].size()) continue;
        else if (table[i + x[0]][j + x[1]]) {
            elim(i + x[0], j + x[1], table);
            break;
        }
    }

    return;
}

int main() {
    int m, n, count = 0;
    char t;
    vector<vector<bool> > table;
    vector<bool> temp;

    cin >> m >> n;
    table.resize(m, temp);

    for (int i = 0; i < m; i++) {
        table[i].resize(n, false);
        for (int j = 0; j < n; j++) {
            cin >> t;
            table[i][j] = t == '#';
        }
    }

    // for (auto x : table) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j]) {
                elim(i, j, table);
                count++;
            }
        }
    }

    // for (auto x : table) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << count << '\n';

    return 0;
}