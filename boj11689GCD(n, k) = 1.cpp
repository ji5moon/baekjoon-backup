//BOJ 11689 GCD(n, k) = 1 (오일러 파이 함수)
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int isP[1000000];

int main() {
    long long n;
    cin >> n;
    long long ans = n;
    long long sq = sqrt(n);
    for (long long i = 2; i <= sq; i++){
        if(!(n%i)){
            ans = ans / i *(i-1);
        }
        while (!(n%i)){
            n/=i;
        }
    }
    if(n!=1){
        ans = ans / n*(n-1);
    }
    cout << ans;
    return 0;
}
