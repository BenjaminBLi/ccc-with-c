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

map<string, int> cnt;
map<string, int> cost;
string name, phone;

int main(){
  fori(i, 0, 6){
    getline(cin, name);
    getline(cin, phone);
    int c;
    cin >> c;
    getline(cin, name);
    cnt[phone]++;
    if(cost.count(phone) == 0) cost[phone] = c;
    cost[phone] = min(cost[phone], c);
  }

  int mx = 0, price = 0;
  string ans = "";
  for(auto it : cnt){
    if(mx < it.s){
      mx = it.s;
      ans = it.f;
      price = cost[it.f];
    }else if(mx == it.s && cost[it.f] < price){
      ans = it.f;
      price = cost[it.f];
    }
  }
  cout << ans << endl;
  
  return 0;
}

