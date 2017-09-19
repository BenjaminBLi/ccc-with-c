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

int N, freq[10010];
map<string, int> id;
string tmp;

int main(){
    cin >> N;
    int idx = 0;
    fori(i, 0, N){
        cin >> tmp;
        if(id.count(tmp) == 0) id[tmp] = idx++;
        freq[id[tmp]]++;
    }
    sort(freq, freq+idx);
    int a = freq[idx-1], rem = N-a;
    cout << min(a, rem+1) + rem << endl;

    return 0;
}