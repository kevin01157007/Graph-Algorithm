#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int i = 0, j = 0, sum = 0, ans = INT_MAX;
    while(j < n){
        sum += arr[j];
        while(sum >= target){
            ans = min(ans, j - i + 1);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    if(ans == INT_MAX) 
        cout << 0 << endl;
    else 
        cout << ans << endl;
    return 0;
}