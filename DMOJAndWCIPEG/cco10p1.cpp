#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int D, w[1010], F, T;

vi adj[1010];

int main(){
    scanf("%d", &D);
    fori(i, 0, D) scanf("%d", w+i);
    scanf("%d", &F);
    fori(i, 0, F){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
    }
    scanf("%d", &T);


    return 0;
}