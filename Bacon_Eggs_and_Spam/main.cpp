// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string line, food, name;
    unordered_map<string, vector<string> > food_name;
    cin >> n;
    while (n != 0) {
        cin.get();

        for (int i = 0; i < n; i++) {
            getline(cin, line);
            istringstream iss(line);
            getline(iss, name, ' ');
            while (getline(iss, food, ' ')) {
                food_name[food].push_back(name);
            }
        }

        vector<string> keys;
        for (auto x : food_name) {
            keys.push_back(x.first);
        }
        sort(keys.begin(), keys.end());

        for (auto x : keys) {
            sort(food_name[x].begin(), food_name[x].end());
            cout << x << ' ';
            for (auto y : food_name[x]) {
                cout << y << ' ';
                y.clear();
            }
            cout << '\n';
        }
        cout << '\n';

        food_name.clear();
        cin >> n;
    }

    return 0;
}

/*
12 12
.##########.
#..........#
#..#...##..#
#.##..#..#.#
#......#.#.#
#....#..#..#
#...#.#....#
#..#...#...#
.#..#.#....#
#....#.....#
#.........#.
.#########..
*/