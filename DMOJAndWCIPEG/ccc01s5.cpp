#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

int m, n, mn;
string A[40], B[40];
vi curr, ans;
bool found = false;

inline bool check(){
    string a = "", b = "";
    for(int c : curr) a += A[c], b += B[c];
    if(a.size() != b.size() || a.size() == 0 || b.size() == 0) return false;
    fori(i, 0, a.size()) if(a[i] != b[i]) return false;
    return true;
}

void gen(int idx){
    if(idx == m) return;
    if(found) return;
    if(check()){
        found = true;
        ans = curr;
        return;
    }

    fori(i, 0, n){
        curr.pb(i);
        gen(idx+1);
        curr.pop_back();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;

    fori(i, 0, n)
        cin >> A[i];

    fori(i, 0, n)
        cin >> B[i];

    gen(0);
    if(ans.size() == 0){
        cout << "No solution.\n";
    }else{
        cout << ans.size() << "\n";
        for(int i : ans) cout << i+1 << "\n";
    }

    return 0;
}

