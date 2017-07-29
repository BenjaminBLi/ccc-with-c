#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, ld[200], rd[200];
bool ldc[200], rdc[200];
bitset<int> cover;
set<int> lds, rds;

class board {
public:
    int recurse(int left, int cnt){
        if(left == 0) return cnt;
        int best = 0x3f3f3f;
        for(int l : lds){
            if(!ldc[l]){
                ldc[l] = true;
                best = min(best, recurse(left-ld[l], cnt+1));
                ldc[l] = false;
            }
        }
        for(int r : rds){
            if(!rdc[r]){
                rdc[r] = true;
                best = min(best, recurse(left-rd[r], cnt+1));
                rdc[r] = false;
            }
        }
        return best;
    }
    void solve(std::istream& in, std::ostream& out) {
        in >> n;
        fori(i, 0, 200) ld[i] = rd[i] = 0;
        fori(i, 0, n){
            int x, y;
            in >> x >> y;
            ld[x-y+n-1]++;
            rd[x+y]++;
            lds.insert(x-y+n-1);
            rds.insert(x+y);
        }
        out << recurse(n, 0) << "\n";
    }
};
