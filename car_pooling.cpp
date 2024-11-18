#include <bits/stdc++.h>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity) {
    // Init
    int current_passengers = 0;
    
    // Simplify
    vector<int> simplify_trips(1001, 0);
    for (auto trip: trips) {
        simplify_trips[trip[1]] += trip[0];
        simplify_trips[trip[2]] -= trip[0];
    }
    
    // Start the trips!
    for (int i=0; i<simplify_trips.size(); ++i) {
        current_passengers += simplify_trips[i];
        
        if (current_passengers > capacity) return false; 
    }
    
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> trips(n, vector<int>(3));
    for(int i = 0; i < n; i++) cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
    int capacity;
    cin >> capacity;
    cout << carPooling(trips, capacity) << endl;
    return 0;
}
