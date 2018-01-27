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

void solve(const string &s, bool flag) { 
  int objL, objR, subL, subR, verL, verR;  
  objL = s.find('{'), objR = s.find('}');  
  subL = s.find('('), subR = s.find(')');  
  verL = s.find('['), verR = s.find(']');  
      
  string obj(s.substr(objL+1, objR-objL-1));  
  string sub(s.substr(subL+1, subR-subL-1));  
  string ver(s.substr(verL+1, verR-verL-1));  
  if (!flag) {  
    obj[0] = toupper(obj[0]);  
  } else {   
    obj[0] = tolower(obj[0]);  
  }  
  sub[0] = tolower(sub[0]);  
  ver[0] = tolower(ver[0]);  
      
  cout << obj << " " << sub << " " << ver;  
}  

inline bool isPar(char c) {return (c == '[' || c == '(' || c == '{');}  
      
int main() {  
  string s;  
  getline(cin, s);  

  auto comma = s.find(',');  
  if (comma == string::npos) {  
    solve(s, 0);  
  } else {  
    auto st = comma;  
    while (!isPar(s[st])) st++; 
    solve(s.substr(0, comma), 0);  
    cout << s.substr(comma , st - comma );   
    solve(s.substr(st, s.size()-st+1), 1);  
    cout << '\n'; 
  }     

  return 0;  
}  

