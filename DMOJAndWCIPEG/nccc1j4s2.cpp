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

const int MAXN = 40;
int n;
char a[MAXN][MAXN];
set<int> freq;

int main(){
    scanf("%d", &n);
    fori(i, 0, n) fori(j, 0, n) scanf(" %c", &a[i][j]);
    
    bool latin = true;
    fori(r, 0, n){
        freq.clear();
        fori(i, 0, n) freq.insert(a[r][i]);
        latin &= freq.size() == n;
        freq.clear();
        fori(i, 0, n) freq.insert(a[i][r]);
        latin &= freq.size() == n;
    }

    bool reduced = true;
    fori(i, 0, n-1) reduced &= a[i][0] < a[i+1][0]; 
    fori(i, 0, n-1) reduced &= a[0][i] < a[0][i+1]; 

    if(reduced && latin){
        puts("Reduced");
        return 0;
    }


    if(latin){
        puts("Latin");
        return 0;
    }

    puts("No");

    return 0;
}

