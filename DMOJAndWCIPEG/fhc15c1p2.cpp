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

const int MAXN = 100000;
int T, n;
string strs[MAXN];

struct node{
  node *nxt[26];
  node(){fori(i, 0, 26) nxt[i] = NULL;}
};
node *root = new node();

void reset(node* &c){
  fori(i, 0, 26) if(c->nxt[i]) reset(c->nxt[i]);
  free(c);
}

int inst(string a){
  int ans = 0, pre = 1;
  node *curr = root;
  for(char c : a){
    ans += pre;
    int idx = c-'a';
    if(curr->nxt[idx] == NULL) curr->nxt[idx] = new node(), pre = 0;
    curr = curr->nxt[idx];
  }
  return ans;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  fori(t, 1, T+1){
    cin >> n;
    reset(root);
    root = new node();
    int ans = 0;
    fori(i, 0, n){
      cin >> strs[i];
      ans += inst(strs[i]);
    }
    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}

