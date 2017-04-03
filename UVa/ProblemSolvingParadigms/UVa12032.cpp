#include <bits/stdc++.h>
using namespace std;

int T, n, arr[100000];

bool simul(int k){
    int h = 0;
    for(int i = 0; i < n; i++){
        //printf("%d %d\n", arr[i]-h, k);
        if(k < arr[i]-h) return false;
        if(arr[i]-h == k) k--;
        h = arr[i];
    }
    return true;
}

int bisect(){
    int lo = 0, hi = 10000000, mid;
    while(lo < hi){
        mid = (hi+lo)>>1;
        //printf("%d %d %d\n", lo, mid, hi);
        if(simul(mid)) {
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    return lo;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        //cout << simul(99);
        printf("Case %d: %d\n", t, bisect());
    }
    return 0;
}
