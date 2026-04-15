//BOJ 14003 가장 긴 증가하는 부분 수열 5 (LIS NlogN)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ar[1000000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> ar[i];
    }
    vector<int> v;
    vector<int> ans;
    vector<int> dp(n);
    for (int i = 0; i<n; i++){
        int idx = lower_bound(v.begin(), v.end(), ar[i]) - v.begin();
        dp[i] = idx;
        if (v.begin() + idx == v.end())
            v.push_back(ar[i]);
        else
            v[idx] = ar[i];
    }
    int s = v.size();
    for (int i = n-1; i>=0 && s>0; i--){
        if (dp[i] == s-1){
            s--;
            ans.push_back(ar[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto&i: ans)
        cout << i << ' ';
    return 0;
}
