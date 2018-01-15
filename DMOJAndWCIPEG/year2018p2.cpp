#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 100010;
bool prime[MAXN];

void gen(){
  prime[0] = prime[1] = true;
  fori(i, 2, MAXN){
    if(!prime[i]){
      for(int j = i<<1; j < MAXN; j += i){
        prime[j] = true;
      }
    }
  }
}

int n;

int main(){
  gen();
  scanf("%d", &n);
  int cnt = 0;
  fori(i, 0, n){
    int x;
    scanf("%d", &x);
    if(!prime[x]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

