//BOJ 5615 아파트 임대 (밀러라빈)
#include <iostream>
using namespace std;
int ar[4] = {2,3, 5, 7};
unsigned long long pow(unsigned long long x, long long y, long long mod);
bool isprime(long long n, int a){
    if (n<2)
        return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    if (a>=n) return true;
    
    if (!(n%a)) return false;
    
    int s = 0;
    long long d = n-1;
    while(!(d % 2) ){
        d/=2;
        s++;
    }
    unsigned long long x = pow(a, d, n);
    if (x == 1 || x== n-1)
        return true;
    for (int i = 0; i<s-1; i++){
        x = pow(x, 2, n);
        if (x == n-1)
            return true;
    }
    return false;
}
unsigned long long pow(unsigned long long x,long long  y, long long mod){
    unsigned long long r = 1;
    x%=mod;
    while (y){
        if (y%2){
            r = (r*x)%mod;
        }
        y/=2;
        x = (x*x)%mod;
    }
    return r;
}
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i<n; i++){
        long long x;
        cin >> x;
        x = 2*x+1;
        for(int j = 0; j<=3; j++){
            if (!isprime(x, ar[j])){
                cnt++;
                break;
            }
        }
    }
    cout << n-cnt;
    return 0;
}
