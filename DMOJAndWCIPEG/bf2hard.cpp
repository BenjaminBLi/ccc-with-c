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

const int seed = 131, MAXN = 1000010;
string a;
int k;
ll hsh[MAXN], base[MAXN];

ll getHash(int l, int r){
  return hsh[r] - base[r-l+1]*(l == 0 ? 0 : hsh[l-1]);
}

int comp(int sta, int stb){
  int mid, lo = 0, hi = k-1;
  while(lo < hi){
    mid = lo + (hi-lo)/2;
    if(getHash(sta, sta+mid) == getHash(stb, stb+mid)){
      lo = mid+1;
    }else{
      hi = mid;
    }
  }
  return lo;
}

int main(){
  cin >> a >> k;
  int n = a.size();
  //generate hash for idx 1
  base[0] = 1;
  hsh[0] = a[0];
  fori(i, 1, n){
    hsh[i] = hsh[i-1]*seed + a[i];
    base[i] = base[i-1]*seed;
  }

  int bst = 0;

  fori(i, 1, n-k+1){
    //check to see if index i is better than the current one
    int pos = comp(bst, i);
    if(a[bst+pos] > a[i+pos]) bst = i;
    //cout << "i: " << i << ", " << pos << " curr: " << bst << endl;
  }

  cout << a.substr(bst, k) << endl;

  return 0;
}

