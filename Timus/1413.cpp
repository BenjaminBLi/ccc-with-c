#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
#define SQ2 0.7071067811865475244
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

double shift[2][9] = { {-SQ2,0,SQ2,-1,0,1,-SQ2,0,SQ2} , {-SQ2,-1,-SQ2,0,0,0,SQ2,1,SQ2} }; 
int main(){
  double x = 0.0,y = 0.0;
	
  char c;
  while(scanf("%c",&c) != EOF){
    if(c == '\n' || c == '0')
      break;
    x += shift[0][c-'0'-1];
    y += shift[1][c-'0'-1];
  }
  printf("%.10lf %.10lf",x,y);
  return 0;
}
