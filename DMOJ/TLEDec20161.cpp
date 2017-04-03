#include <bits/stdc++.h>
using namespace std;
int a, b, c;
double tc, tb;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    tb = b;
    tc = c;
    cout << (a*(1+tb/tc));
    return 0;
}
