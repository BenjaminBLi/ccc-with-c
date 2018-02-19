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

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    if(k < sqrt(n)){
        puts("-1");
        return 0;
    }

    int groups = n/k;


    int bnd = k;
    fori(i, 0, groups){
        rfori(j, bnd, bnd-k+1)
            printf("%d ", j);
        bnd += k;
    }
    bnd -= k-1;

    rfori(i, n, bnd) printf("%d ", i);

    cout<<endl;


    return 0;
}

