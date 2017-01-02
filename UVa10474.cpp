#include <bits/stdc++.h>
using namespace std;

int Q, N, arr[10001];


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cnt = 1;
    while(scanf("%d %d", &N, &Q) && !(N == 0 && Q == 0)){
        printf("CASE# %d:\n", cnt++);
        for(int i = 0; i < N; i++)scanf("%d", &arr[i]);
        sort(arr, arr+N);
        for(int i = 0; i < Q; i++){
            int t; scanf("%d", &t);
            int tmp = lower_bound(arr, arr + N, t)-arr;
            if(arr[tmp] != t) printf("%d not found\n", t);
            else printf("%d found at %d\n", t, tmp+1);
        }
    }
    return 0;
}
