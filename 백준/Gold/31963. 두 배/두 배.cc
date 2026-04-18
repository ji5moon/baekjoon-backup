#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    vector<long long>v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        v.push_back(u);
    }
    long long ans = 0;
    vector<int>cnt(n, 0);
    for (int i = 1; i < n; i++) {
            int tmp = ceil((double)log2((double)v[i - 1] / v[i])) + cnt[i-1];
            if (tmp > 0) {
                cnt[i] = tmp;
                ans += cnt[i];
         }
    }
    cout << ans;
}