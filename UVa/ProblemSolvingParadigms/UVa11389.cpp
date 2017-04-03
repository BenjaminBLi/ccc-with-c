#include <bits/stdc++.h>
using namespace std;

int n, d, r, m[100], e[100], total, curr;
int main(){
    for(;scanf("%d %d %d", &n, &d, &r) && n|d|r;){
        for(int i = 0; i < n; i++) scanf("%d", &m[i]);
        for(int i = 0; i < n; i++) scanf("%d", &e[i]);
        sort(m, m+n);
        sort(e, e+n);
        total = 0;
        for(int i =0 ; i < n; i++){
            curr = m[i]+e[n-1-i];
            if(curr > d) total += (curr-d)*r;
        }
        printf("%d\n", total);
    }
    return 0;
}
