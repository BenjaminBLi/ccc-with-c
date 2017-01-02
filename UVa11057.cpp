
#include <bits/stdc++.h>
using namespace std;

int N, arr[10005], M, b1, b2, diff;

int bfind(int t){
    int lo = 0, hi = N-1, mid;
    while(lo != hi){
        mid = (lo+hi)/2;
        if(arr[mid] < t) lo = mid+1;
        else hi = mid;
    }
    if(arr[lo] == t) return lo;
    return -1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &N) != EOF){
        for(int i =0 ; i < N; i++) scanf("%d", &arr[i]);
        sort(arr, arr+N);
        scanf("%d", &M);
        diff = 1<<30;
        for(int i = 1; i < N; i++){
            int t1 = arr[i], t2 = M-arr[i];
            if(bfind(t2) != -1 && abs(t1-t2) < diff){
                b1 = max(t1, t2); b2 = min(t1, t2);
                diff = abs(t1-t2);
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", b2, b1);
    }
    return 0;
}
