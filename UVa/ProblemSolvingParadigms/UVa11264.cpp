#include <bits/stdc++.h>
using namespace std;
int T, n, cnt;
long long c[1000], curr;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &n);
        for(int i =0 ; i < n; i++) scanf("%lld", &c[i]);
        curr = 1; cnt= 2;
        for(int i = 1; i < n-1; i++){
            if(curr + c[i] >= c[i+1]) continue;
            curr += c[i];
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
