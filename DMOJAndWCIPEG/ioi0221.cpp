#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int N, S, T[10010], F[10010], memo[10010], Q[10005];

class ioi0221 {
public:
    double func(int a, int b){
        return (double)(memo[a] - memo[b]) / (T[a]-T[b]);
    }

    void solve(std::istream &in, std::ostream &out) {
        in >> N >> S;
        memo[0] = 0x3f;
        fori(i, 1, N + 1) {
            T[i] = F[i] = 0;
            memo[i] = 0x3f;
            in >> T[i] >> F[i];
        }
        rfori(i, N, 1) T[i] += T[i + 1], F[i] += F[i + 1];
        memset(memo, 0x3f, sizeof(memo));
        memo[N + 1] = 0;
        int f = 0, r = 0; Q[0] = N+1;
        rfori(i, N, 1){
            while(f < r && func(Q[f], Q[f+1]) <= F[i]) f++;
            memo[i] = memo[Q[f]] + (T[i]-T[Q[f]]+S) * F[i];
            while(f < r && func(Q[r-1], Q[r]) >= func(Q[r], i)) r--;
            Q[++r] = i;
        }
        out << memo[1] << "\n";
    }
};


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ioi0221 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
