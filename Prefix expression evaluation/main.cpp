#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

fstream fin("input.txt"), fout("output.txt", ios::out | ios::trunc);

int the_stoi(string str) {
    stringstream ss;
    int temp;

    ss << str;
    ss >> temp;

    return temp;
}

int main() {
    vector<string> words;
    string line;
    getline(fin, line);
    
    while (line != ".") {
        // expression parsing
        int pos = line.find(' ', 0);
        bool error = false;
        while (pos != string::npos) {
            words.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(' ', 0);
        }
        if (line.size() != 0) {
            words.push_back(line.substr(0, string::npos));
        }

        stack<int> numbers;
        int left, right;
        for (int i = words.size() - 1; i >= 0; i--) {
            error = false;
            if (words[i] == "*") {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    left = numbers.top();
                    numbers.pop();
                }
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    right = numbers.top();
                    numbers.pop();
                }
                numbers.push(left * right);
            }
            else if (words[i] == "/") {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    left = numbers.top();
                    numbers.pop();
                }
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    right = numbers.top();
                    numbers.pop();
                }
                numbers.push(left / right);
            }
            else if (words[i] == "+") {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    left = numbers.top();
                    numbers.pop();
                }
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    right = numbers.top();
                    numbers.pop();
                }
                numbers.push(left + right);
            }
            else if (words[i] == "-") {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    left = numbers.top();
                    numbers.pop();
                }
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    right = numbers.top();
                    numbers.pop();
                }
                numbers.push(left - right);
            }
            else if (words[i] == "%") {
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    left = numbers.top();
                    numbers.pop();
                }
                if (numbers.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    right = numbers.top();
                    numbers.pop();
                }
                numbers.push(left % right);
            }
            else {
                numbers.push(the_stoi(words[i]));
            }
            // cout << words[i] << '\n';
            // cout << left << ' ' << right << '\n';
            // if (!numbers.empty()) cout << "top: " << numbers.top() << '\n';
            // cout << "-----------\n";
        }

        // for (auto x : words) {
        //     fout << x << ' ';
        // }
        // fout << '\n';
        int ans;
        if (!numbers.empty()) ans = numbers.top();
        numbers.pop();

        if (error || !numbers.empty()) {
            fout << "illegal\n";
        }
        else {
            fout << ans << '\n';
        }

        words.clear();
        getline(fin, line);
    }

    return 0;
}