#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
string tmp;

int main(){
    cin >> N;
    int cnt = 0;
    fori(i, 0, N){
        cin >> tmp;
        if(tmp.size() > 10) continue;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
