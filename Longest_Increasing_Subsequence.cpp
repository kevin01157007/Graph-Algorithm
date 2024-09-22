#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr)
{
    if (arr.empty()) return 0;

    vector<int> lis;
    for (int x : arr)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Length of lis is " << lis(arr);
    return 0;
}