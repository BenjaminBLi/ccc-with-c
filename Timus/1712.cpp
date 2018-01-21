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

bool mat[4][4], tmp[4][4];
char a[4][4];

void rot(){
  fori(i, 0, 4) fori(j, 0, 4) tmp[i][j] = mat[i][j];
  fori(i, 0, 4) fori(j, 0, 4) mat[i][j] = tmp[4-j-1][i];
}

void prnt(){
  fori(i, 0, 4) fori(j, 0, 4) if(mat[i][j]) putchar(a[i][j]);
}

char ch;

int main(){
  fori(i, 0, 4) fori(j, 0, 4){
    scanf(" %c", &ch);
    if(ch != '.') mat[i][j] = true;
  }

  fori(i, 0, 4) fori(j, 0, 4) scanf(" %c", &a[i][j]);

  fori(i, 0, 4){
    prnt(); 
    rot();
  }
  return 0;
}

