#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) cin >> piles[i];
    int h;
    cin >> h;
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int k = left + (right - left) / 2;
        int hours = 0;
        for (int i = 0; i < n; i++) {
            hours += (piles[i] + k - 1) / k;
        }
        if (hours <= h) {
            right = k;
        } else {
            left = k + 1;
        }
    }
    cout << left << endl;
    return 0;
}