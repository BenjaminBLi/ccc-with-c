#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = (int)st; i < (int)en; i++)
#define rfori(i, en, st) for(int i = (int)st; i >= (int)en; i--)
#define MAXN 1000010
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int N, ft[MAXN], idRate[MAXN], rateId[MAXN], idxRate[MAXN], type[MAXN], X[MAXN], R[MAXN];
vector<int> rs, xs;
unordered_map<int, int> idKey, keyId, rateIdx;

int q(int k) {
    int pos = 0, cnt = 0;
    rfori(i, 0, 20){
        pos += (1<<i);
        if(pos >= MAXN || cnt + ft[pos] >= k) pos -= (1<<i);
        else cnt += ft[pos];
    }
    return pos+1;
}

void upd(int k, int v) {
    for (; k < (int) MAXN; k += (k&(-k))) {
        ft[k] += v;
    }
}

int main() {
    scanf("%d", &N);
    char ch;
    fori(i, 0, N) {
        scanf(" %c %d", &ch, X + i);
        if (ch != 'Q') {
            scanf("%d", R + i);
            type[i] = ch == 'N' ? 0 : 1;
            rs.pb(R[i]);
            xs.pb(X[i]);
        } else
            type[i] = 3;
    }
    sort(rs.begin(), rs.end());
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int cnt = 0;
    fori(i, 0, xs.size()) {
        keyId[xs[i]] = ++cnt;
        idKey[cnt] = xs[i];
    }
    cnt = 0;
    rfori(i, 0, rs.size()-1) {
        rateIdx[rs[i]] = ++cnt;
        idxRate[cnt] = rs[i];
    }
    int cx, cr;
    fori(i, 0, N){
        if(type[i] == 0){
            cx = X[i], cr = R[i];
            idRate[keyId[cx]] = rateIdx[cr];
            rateId[rateIdx[cr]] = keyId[cx];
            upd(rateIdx[cr], 1);
        }else if(type[i] == 1){
            cx = X[i], cr = R[i];
            upd(idRate[keyId[cx]], -1);
            idRate[keyId[cx]] = rateIdx[cr];
            rateId[rateIdx[cr]] = keyId[cx];
            upd(rateIdx[cr], 1);
        }else{
            printf("%d\n", idKey[rateId[q(X[i])]]);
        }
    }
    return 0;
}
