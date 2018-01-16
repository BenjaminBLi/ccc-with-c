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

int a;

bool check(int a){
  int ft = a, st = a/1000;
  int pt1 = 0, pt2 = 0;
  fori(i, 0, 3){
    pt1 += ft%10;
    ft /= 10;
    pt2 += st%10;
    st /= 10;
  }
  return pt1 == pt2;
}

int main(){
  cin >> a;
  if(check(a-1) || check(a+1)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

