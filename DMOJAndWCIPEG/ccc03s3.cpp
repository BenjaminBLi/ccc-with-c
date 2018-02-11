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
const int MAXN = 25;
int rem, R, C, col = 1, a[MAXN][MAXN];

bool valid(int r, int c){
    return 0 <= r && r < R && 0 <= c && c < C && a[r][c] == 0;
}

int flood(int r, int c){
    int cnt = 1;
    a[r][c] = col;
    fori(i, -1, 2){
        fori(j, -1, 2){
            if(abs(i + j) == 1 && valid(r + i, c + j)){
                cnt += flood(r+i, c+j);
            }
        }
    }
    return cnt;
}

int main(){
    scanf("%d%d%d", &rem, &R, &C);
    fori(i, 0, R) {
        fori(j, 0, C){
            char ch;
            scanf(" %c", &ch);
            if(ch == 'I'){
                a[i][j] = -1;
            }
        }
    }

    priority_queue<int> pq;
    fori(i, 0, R) fori(j, 0, C){
        if(a[i][j] == 0){
            col++;
            pq.push(flood(i, j));
        }
    }

    int cnt = 0;
    while(pq.size() && pq.top() <= rem){
        rem -= pq.top();
        pq.pop();
        cnt++;
    }

    if(cnt != 1) printf("%d rooms, %d square metre(s) left over\n", cnt, rem);
    else printf("%d room, %d square metre(s) left over\n", cnt, rem);

    return 0;
}

