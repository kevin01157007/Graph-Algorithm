#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> houses(n);
    for(int i = 0; i < n; i++) cin >> houses[i];
    vector<int> heaters(m);
    for(int i = 0; i < m; i++) cin >> heaters[i];

    int min_radius = 0;

    for(int i = 0; i < n; i++){
        int min_dist = INT_MAX;
        for(int j = 0; j < m; j++){
            min_dist = min(min_dist, abs(houses[i] - heaters[j]));
        }
        min_radius = max(min_radius, min_dist);
    }
    cout << min_radius << endl;
    return 0;
}
