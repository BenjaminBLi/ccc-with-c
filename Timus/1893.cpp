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

int pos;
char ch;

int main(){
  scanf("%d %c", &pos, &ch);
  int id;
  if(pos <= 2){
    //premium class
    if(ch == 'A' || ch == 'D') id = 1;
    else id = 0;
  }else if(pos < 21){
    //business class
    if(ch == 'A' || ch == 'F') id = 1;
    else id = 0;
  }else{
    //sad class
    if(ch == 'A' || ch == 'K') id = 1;
    else if(ch == 'C' || ch == 'D' || ch == 'G' || ch == 'H') id = 0;
    else id = 2;
  }
  
  if(id == 0) cout << "aisle" << endl;
  else if(id == 1) cout << "window" << endl;
  else cout << "neither" << endl;
  return 0;
}

