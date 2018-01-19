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

int n, cnt = 0;
map<string, string> users;
map<string, bool> in;
string cmd, name, pass;

int main(){
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n;
  bool ok;
  while(n--){
    cin >> cmd >> name;
    if(cmd == "register"){
      cin >> pass;
      if(users.count(name) == 0){
        users[name] = pass;
        in[name] = false;
        puts("success: new user added");
      }else puts("fail: user already exists");
    }else if(cmd == "login"){
      cin >> pass;
      if(users.count(name)){
        if(users[name] == pass){
          if(in[name]) puts("fail: already logged in"); 
          else puts("success: user logged in");
          in[name] = true;
        }else puts("fail: incorrect password");
      }else puts("fail: no such user");
    }else if(cmd == "logout"){
      if(users.count(name)){
        if(in[name]){
          in[name] = false;
          puts("success: user logged out");
        }else puts("fail: already logged out");
      }else puts("fail: no such user");
    }
  }
  return 0;
}

