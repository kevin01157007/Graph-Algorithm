#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> prime_factor(k);
    for (int i = 0; i < k; i++) cin >> prime_factor[i];

    vector<long> ugly_numbers(n);
    ugly_numbers[0] = 1;
    vector<int> indices(k, 0);
    vector<long> next_multiples = prime_factor;

    for (int i = 1; i < n; i++) {
        long next_ugly = *min_element(next_multiples.begin(), next_multiples.end());
        ugly_numbers[i] = next_ugly;

        for (int j = 0; j < k; j++) {
            if (next_ugly == next_multiples[j]) {
                indices[j]++;
                next_multiples[j] = ugly_numbers[indices[j]] * prime_factor[j];
            }
        }
    }

    cout << ugly_numbers[n - 1] << endl;
    return 0;
}