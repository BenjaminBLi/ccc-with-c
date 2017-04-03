#include <bits/stdc++.h>
using namespace std;

int n, m, c, milk[1000000], tot, tmp;
string line;
stringstream ss;
bool poss(int cap){
    int tot = 0, cur = 0;
    for(int i = 0; i < n; i++) {
        if(milk[i] > cap) return false;
        if(cur + milk[i] > cap) cur = 0;
        if(cur == 0) tot++;
        cur += milk[i];
        if(tot > m) return false;
    }
    return true;
}

int bisect(){
    int lo = 0, hi = tot, mid;
    while(hi-lo > 0){
        if(poss(hi)){
            hi = lo + (hi-lo)/2;
        }else{
            lo = hi;
            hi = hi+hi/2;
        }
    }
    return hi+1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &n, &m) != EOF){
        tot = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &milk[i]);
            tot += milk[i];
        }
        int ret = bisect();
        //cout << poss(6) << endl;
        printf("%d\n", bisect());
    }
    return 0;
}
