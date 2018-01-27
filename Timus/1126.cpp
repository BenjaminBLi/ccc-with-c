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

int m;
int data[25005] = {-1};
int ilast;

int main(){
	
  cin >> m;
  for(int i=0;cin>>data[i];i++)
    ilast = i;

  for(auto p=data; p + m!=data + ilast + 1; p++)
    std::cout << *std::max_element(p,p+m) << std::endl;

  return 0;
}
