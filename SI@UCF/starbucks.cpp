#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int f, c, m;

int main(){
    scanf("%d %d %d", &f, &c, &m);
    int nF = m/f;
    int nC = m/c;

    long long cnt = 0;

    for(int i = 0; i <= nF; i++){
        if((m-i*f)%c == 0) cnt++;
    }

    printf("%lld\n", cnt);

    return 0;
}
