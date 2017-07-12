#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    scanf("%d %d", &n, &k);
    int cnt = 1;
    printf("%d\n", (n-1)/k*2 + min((n-1)%k, 2));
    for(int i = 0; i < k; i++){
        printf("1 %d\n", ++cnt);
    }
    for(cnt++; cnt <= n; cnt++){
        printf("%d %d\n", cnt-k, cnt);
    }

    return 0;
}
