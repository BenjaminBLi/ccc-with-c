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

const int MAXN = 310;
int n, dst[MAXN], cnt = 0;
map<string, int> id;
vi adj[MAXN];
bool vis[MAXN];
string c[3];

int main(){
  scanf("%d", &n);
  fori(i, 0, MAXN) dst[i] = 1<<30;
  //id["Isenbaev"] = cnt++;

  while(n--){
    fori(i, 0, 3) {
      cin >> c[i];
      if(id.count(c[i]) == 0) id[c[i]] = cnt++;
    }
    fori(i, 0, 3){
      int j = (i+1)%3;
      adj[id[c[i]]].pb(id[c[j]]);
      adj[id[c[j]]].pb(id[c[i]]);
    }
  }

  if(id.count("Isenbaev") != 0){
    queue<int> q;
    int st = id["Isenbaev"];
    vis[st] = true;
    dst[st] = 0;
    q.push(st);
    while(q.size()){
      int u = q.front(); q.pop();

      for(int v : adj[u]){
        if(vis[v]) continue;
        vis[v] = true;
        q.push(v);
        dst[v] = dst[u]+1;
      }
    }
  }

  for(auto it : id){
    cout << it.f << " ";
    if(dst[it.s] != (1<<30)) cout << dst[it.s] << "\n";
    else cout << "undefined" << "\n";
  }
  

  return 0;
}

