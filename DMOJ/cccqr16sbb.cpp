#include <bits/stdc++.h>
#define fori(i, N) for(int i = 0; i < N; i++)
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, x, y;
map<ii, int> id;
vii xs, ys;

int main(){
    scanf("%d", &N);
    for(int i= 0; i < N; i++){
        scanf("%d %d", &x, &y);
        xs.push_back(ii(x, y));
        ys.push_back(ii(y, x));
        id[ii(x, y)] = i;
    }
    sort(xs.begin(), xs.end()); sort(ys.begin(), ys.end());
    int minx, maxx, miny, maxy, cy;
    int idx;
    long long cnt = 0;
    fori(i, N){

        x = xs[i].first; y = xs[i].second;
        //printf("POINT: (%d, %d)\n", x, y);
        auto iter = lower_bound(xs.begin(), xs.end(), ii(x, -(1<<30)));
        cy = lower_bound(ys.begin(), ys.end(), ii(y, x)) - ys.begin();
        idx = iter-xs.begin();
        //if(iter != xs.end()) printf("first[%d]: (%d, %d)\n\n", idx, xs[idx].first, xs[idx].second);
        if(idx == i || iter == xs.end() || xs[idx].first != x) continue;
        minx = i-idx;

        iter = lower_bound(xs.begin(), xs.end(), ii(x, (1<<30)));
        idx = iter-xs.begin()-1;
        //if(iter != xs.end()) printf("second[%d]: (%d, %d)\n\n", idx, xs[idx].first, xs[idx].second);
        if(idx == i || iter == xs.end() || xs[idx].first != x) continue;
        maxx = idx-i;

        iter = lower_bound(ys.begin(), ys.end(), ii(y, -(1<<30)));
        idx = iter-ys.begin();
        //if(iter != ys.end()) printf("third[%d]: (%d, %d)\n", idx, ys[idx].second, ys[idx].first);
        if(iter == ys.end() || (ys[idx].first == y && ys[idx].second == x) || ys[idx].first != y) continue;
        miny = cy-idx;
        //printf("POINT: (%d, %d)\n\n", x, y);
        iter = lower_bound(ys.begin(), ys.end(), ii(y, (1<<30)));
        idx = iter-ys.begin()-1;
        //cout << idx << endl;
        //if(iter != xs.end()) printf("fourth[%d]: (%d, %d)\n\n", idx, ys[idx].second, ys[idx].first);
        if(iter == ys.end() || (ys[idx].first == y && ys[idx].second == x) || ys[idx].first != y) continue;
        maxy = idx-cy;
        //printf("POINT: (%d, %d)\n", x, y);
        //printf("maxx: %d, minx: %d, maxy:%d, miny:%d \n", maxx, minx, maxy, miny);
        cnt += 2LL*maxx*minx*maxy*miny;
    }
    cout << cnt << endl;
    //cout << "FINISHED" << endl;
    return 0;
}
