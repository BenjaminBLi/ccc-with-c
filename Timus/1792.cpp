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

int i, m[8];

int main(){
  for(int i = 1; i < 8; i++) scanf("%d", m+i);
  for(i=1;i<9;i++){
     if(((m[2]+m[3]+m[4])%2==m[5])&&((m[1]+m[3]+m[4])%2==m[6])&&((m[1]+m[2]+m[4])%2==m[7]))
        break;
     else {
       m[i]=(!m[i]);
       m[i-1]=(!m[i-1]);
     }
  }

  for(i=1;i<8;i++) printf("%d ",m[i]);
  return 0;
}

