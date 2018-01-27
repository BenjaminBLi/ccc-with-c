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

map<string, int> freq;

int main(){

  string line, s;
  int cnt = 0;
  while(getline(cin, line)){
    rfori(i, line.size()-1, 0)
      if(!isalpha(line[i])) line[i] = ' ';
    stringstream ss;
    ss << line;
    while(ss >> s){
      if(s == "tram") cnt++;
      else if (s == "trolleybus") cnt--;
    }
    
  } 

  if(cnt > 0) cout << "Tram driver" << endl;
  else if(cnt < 0) cout << "Trolleybus driver" << endl;
  else cout << "Bus driver" << endl;
  return 0;
}

