#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
int pval[1010];

class TwoDogsOnATree {
public:
    int maximalXorSum(vector <int> p, vector <int> w){
        memset(pval, 0, sizeof(pval));
        int N = w.size();
        rfori(i, N-1, 0) pval[p[i]] = pval[i]^w[i];

    }
};