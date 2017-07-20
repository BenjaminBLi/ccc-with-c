#include "bits/stdc++.h"
using namespace std;

int a, b, best;
set<int> factors;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
void gen(int x){
    factors.clear();
    for(int i = 1; i*i <= x; i++){
        if(x%i == 0) factors.insert(i), factors.insert(x/i);
    }
}

int main(){
    scanf("%d %d", &a, &b);
    int best = gcd(a, b), x = a, y = b;
    if(best == 1) y = a+1;

    for(int i = a; i < b; i++) {
        gen(i);
        for (int f : factors) {
            int c = b/f;
            if(f > best && c*f > i) {
                best = f;
                x = i;
                y = c*f;
            }
        }
    }

    cout << x << " " << y<< endl;

    return 0;
}
