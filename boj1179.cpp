//BOJ 1179 마지막 요세푸스 문제
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    if (k == 1){
        cout << n;
        return 0;
    }
    long long a = 1;
    while(1){
        long long x = (a-ans-1)/(k-1)+1;
        if(a+x>n){
            ans+= (n-a)*k;
            break;
        }
        ans = (ans+k*x)%(a+x);//한번에
        a+=x;
    }
    cout << ans + 1;
    return 0;
}
