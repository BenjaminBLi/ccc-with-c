#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<long double, ll> ii;
typedef vector<ii> vii;
struct plane{
    ll id, s, e, i;
    long double m;
};
ll MAXX, N, Q, K, id, L, R, rL, rR, tot, sparse[2000][13][2010];
long double p, tmp;
plane ps[2000];
vector<vii> intersects;
map<int, int> m;

/**
 * first dimension of the table is the plane
 * second dimension is the sum at intersect number x
*/

long double getSlope(int idx){
    return (ps[idx].e-ps[idx].s)*1.0L/MAXX;
}

long double fInt(int id1, int id2){
    p = (ps[id2].s-ps[id1].s)/(ps[id1].m-ps[id2].m);
    if(p > 0 && p < 1.0L*MAXX)
        return p;
    return -1;
}
bool comp(ii s, ii o){
    if(fabs(s.first-o.first) < 1e-8)
        return s.second < o.second;
    return s.first < o.first;
}

bool compP(plane s, plane o){
    return s.s < o.s;
}

void findIntersects(int idx){
    fori(i, N){
        if(i == idx)
            intersects[idx].push_back(ii(0, sparse[idx][0][0]));
        else{
            tmp = fInt(i, idx);
            if(tmp != -1)
                intersects[idx].push_back(ii(tmp, ps[i].m > ps[idx].m ? ps[i].i : -ps[i].i));
        }
    }
    sort(intersects[idx].begin(), intersects[idx].end(), comp);
}

void gen(){
    fori(idx, N){
        findIntersects(idx);
        for(int i = 1; i < (int) intersects[idx].size(); i++)
            sparse[idx][0][i] = sparse[idx][0][i-1]+intersects[idx][i].second;
        for(int i = 1; i < 13; i++)
            for(int j = 0; j + (1<<(i-1)) < N; j++)
                sparse[idx][i][j] = max(sparse[idx][i-1][j], sparse[idx][i-1][j+(1<<(i-1))]);
    }
}

ll query(int id, int L, int R){
    int level = log2(R-L);
    return max(sparse[id][level][L], sparse[id][level][R-(1<<level)+1]);
}

int main(){
    //freopen("in.txt", "r", stdin);
    memset(sparse, -1, sizeof(sparse));
    scanf("%lld %lld %lld %lld", &MAXX, &K, &N, &Q);
    intersects.assign(N, vii());
    fori(i, N){
        scanf("%lld %lld %lld", &ps[i].s, &ps[i].e, &ps[i].i);
        tot += ps[i].i;
        ps[i].id = i;
        ps[i].m = getSlope(i);
        m[i] = 0;
    }
    sort(ps, ps+N, compP);
    fori(i, N){
        tot -= ps[i].i;
        sparse[i][0][0] = tot;
        m[ps[i].id] = i;
    }
    gen();
    for(int q = 0; q < Q;q++){
        scanf("%lld %lld", &id, &L);
        id = m[id-1];
        R = L+K;
        auto iter1 = upper_bound(intersects[id].begin(), intersects[id].end(), ii(1.0*L, 1e18+1));
        rL = iter1 - intersects[id].begin()-1;
        iter1 = upper_bound(intersects[id].begin(), intersects[id].end(), ii(1.0*R, 1e18+1));
        rR = iter1 - intersects[id].begin()-1;
        printf("%lld\n", query(id, rL, rR));
    }
    return 0;
}
