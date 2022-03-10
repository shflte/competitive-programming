#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stack<char> stk;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            stk.push(str[i]);
        }
        else if (stk.empty()) {
            continue;
        }
        else {
            stk.pop();
        }
    }

    vector<char> vec;
    int stksize = stk.size();
    vec.resize(stksize);

    for (int i = 0; i < stksize; i++) {
        vec[stksize - i - 1] = stk.top();
        stk.pop();
    }

    for (auto x : vec) cout << x;

    cout << '\n';

    return 0;
}