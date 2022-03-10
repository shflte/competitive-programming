#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <queue>

using namespace std;

int main() {
    long long T, n, l, sum, temp;

    cin >> T;
    for (int i = 0; i < T; i++) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        sum = 0;

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> l;
            pq.push(l);
        }

        while (!(pq.size() == 1)) {
            temp = pq.top();
            pq.pop();
            temp += pq.top(); 
            pq.pop();

            pq.push(temp);
            sum += temp;
        }

        cout << sum << '\n';
    }
    
    return 0;
}