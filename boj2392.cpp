//BOJ 2392 다각형의 분할
#include <iostream>
#include <algorithm>
using namespace std;
long long ar[1010];
long long sq[1010];

int main() {
    ar[0] = 1;
    ar[1] = 1;
    ar[2] = 2;
    ar[3] = 5;
    sq[0] = 1;
    sq[2] = 1;
    int n;
    cin >> n;
    n-=2;
    for (int i = 4; i<=n; i++){
        if (!ar[i]){
            for (int k = 0; k < i; k++){
                ar[i] += ar[k]* ar[i-1-k];
                ar[i]%=1000000000;
            }
        }
    }
    cout << ar[n] << "\n";
    if(n%2){
        cout << 0 << "\n";
        return 0;
    }
    n+=2;
    for (int i = 4; i<=n; i+=2){
        for (int k = 3; k<=i; k+=2){
            for (int j = k+1; j<=i; j+=2){
                sq[i] += ((sq[k-1] *sq[j-k+1])% 1000000000 ) * sq[i + 2 - j];
                sq[i] %=1000000000;
            }
        }
    }
    cout << sq[n];
    
    return 0;
}
