#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int count = 1;
    vector<int> buns;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (n--) {
        string command;
        cin >> command;

        if (command == "DIOU") {
            int x;
            cin >> x;
            buns.push_back(x);
            if (minHeap.empty() || x > minHeap.top()) {  // Added check for empty minHeap
                minHeap.push(x);
            } else {
                maxHeap.push(x);
            }
        } else if (command == "MUMIMUMI" || command == "<3DONGDONG") {
            if (count <= 0 || count > buns.size()) {
                cout << "BAONU" << endl;
            } else {
                while (minHeap.size() > count) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
                while (minHeap.size() < count && !maxHeap.empty()) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
                cout << minHeap.top() << endl;
            }
            if (command == "MUMIMUMI") {
                count++;
            } else {
                count--;
            }
        }
    }

    return 0;
}