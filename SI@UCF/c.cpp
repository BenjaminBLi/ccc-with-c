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

ll A, B, C, D, E, M;

class c {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T;
        in >> T;
        T++;
        fori(t, 1, T){
            in >> A >> B >> C >> D >> E >> M;
            ll sum = A+B+C+D+E;
            if(sum >= M) out << "Case #" << t << ": 0\n";
            else if(sum <= 0) out << "Case #" << t << ": -1\n";
            else{
                int i = 0;
                for(;sum < M;i++){
                    sum <<= 1;
                }
                out << "Case #" << t << ": " << i << "\n";
            }
        }
    }
};
