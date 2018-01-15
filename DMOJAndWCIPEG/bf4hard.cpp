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

const int MAXN = 1000010;
string a, b;
int fail[MAXN], n, m, st = -1, en = -1;

void calc(){
  int i = 1, len = 0;
  while(i < m){
    if(b[i] == b[len]){
      len++;
      fail[i] = len;
      i++;
    }else{
      if(len != 0) len = fail[len-1];
      else{
        fail[i] = 0;
        i++;
      }
    }
  }
}

void getMatch(){
  calc();

  int i = 0, j = 0;
  while(i < n){
    if(b[j] == a[i]) 
      i++, j++;
    if(j == m) {
      st = i-j;
      return;
    }else if(i < n && b[j] != a[i]){
      if(j) j = fail[j-1];
      else i++;
    }
  }
}

int main(){
  cin >> a >> b;
  n = a.size();
  m = b.size();

  getMatch();
  cout << st << endl;

  return 0;
}

