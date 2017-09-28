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

int G, e, t;

int main(){
    double ans = 1.0;
    scanf("%d", &G);
    fori(a, 0, G){
        scanf("%d %d", &e, &t);
        e = t-e;
        ans *= 1.0*e/t;
    }
    printf("%.6lf", ans);
    return 0;
}