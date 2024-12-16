#include <bits/stdc++.h>
using namespace std;

// 深度優先搜索函數
void dfs(int x, const vector<vector<int>> &con, vector<bool> &mark, int &a, int &b) {
    if (mark[x]) { // 如果節點已經被標記，則返回
        return;
    }
    mark[x] = true; // 標記當前節點
    ++a; // 計算節點數量
    b += con[x].size(); // 計算邊的數量
    for (int y : con[x]) { // 遍歷相鄰節點
        dfs(y, con, mark, a, b); // 遞歸調用
    }
}

// 計算完全連通分量的數量
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> con(n); // 建立鄰接表
    for (const auto& e : edges) { // 遍歷所有邊
        con[e[0]].push_back(e[1]); // 添加邊到鄰接表
        con[e[1]].push_back(e[0]); // 添加反向邊
    }
    vector<bool> mark(n); // 標記訪問過的節點
    int r = 0; // 完全連通分量的計數
    for (int i = 0; i < n; ++i) { // 遍歷所有節點
        if (!mark[i]) { // 如果節點未被訪問
            int x = 0, y = 0; // 初始化節點和邊的計數
            dfs(i, con, mark, x, y); // 執行深度優先搜索
            r += x * (x - 1) == y; // 判斷是否為完全連通分量
        }
    }
    return r; // 返回結果
}

int main() {
    int n, len;
    cin >> n >> len; // 輸入節點數和邊數
    vector<vector<int>> edges(len); // 邊的列表
    for (int i = 0; i < len; ++i) {
        int x, y;
        cin >> x >> y; // 輸入每條邊
        edges[i] = {x, y}; // 添加到邊的列表
    }
    cout << countCompleteComponents(n, edges) << endl; // 輸出結果
    return 0;
}