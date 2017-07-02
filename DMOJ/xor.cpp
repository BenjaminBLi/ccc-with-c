#include <bits/stdc++.h>
using namespace std;

int T, s, f;

int main(){
    //scanf("%d", &T);
    s = 2;
    f = 12;
    int a = s;
    for(int i = s; i <= f; i++){
        a ^= i;
        cout << a << endl;
    }

    return 0;
}
