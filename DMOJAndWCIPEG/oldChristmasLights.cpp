#include <bits/stdc++.h>
#define fori(i, N) for(int i = 0; i < N; i++)
using namespace std;
typedef pair<int, int> ii;
int N, K, Q, L[100000], table[17][100000], R[100000], l, t, a, b, r1, l1;
ii idxs[17][100000], tmp, tmp1;
deque<ii> maxQ, minQ;


void gen(){
    fori(i, N){
        table[0][i] = 1;
        idxs[0][i] = ii(i, i);
    }
    for(int i = 1; i < 17; i++){
        for(int j = 0; j +(1<<(i-1)) < N; j++){
            int r = 1<<(i-1);
            if (R[j] >= (r<<1) || R[j] >= R[j+r]){
                table[i][j] = R[j] > r<<1 ? r<<1 : R[j];
                idxs[i][j] = ii(j, j+table[i][j]-1);
            }else{
                table[i][j] = R[j+r] > r<<1?r<<1:R[j+r];
                idxs[i][j] = ii(j+r, j+table[i][j]-1);
            }
        }
    }
}

void query(int a, int b){
    int level = log2(b-a+1);
    //cout << table[level][a] << " " << table[level][b-(1<<level)+1] << endl;
    tmp = idxs[level][a];
    if(table[level][b-(1<<level)+1] > table[level][a])
        tmp = idxs[level][b-(1<<level)+1];
}

int main(){
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    l = 0;
    fori(r, N){
        scanf("%d", &t);
        while(!maxQ.empty() && maxQ.back().first > t) maxQ.pop_back();
        while(!minQ.empty() && minQ.back().first < t) minQ.pop_back();
        maxQ.push_back(ii(t, r));
        minQ.push_back(ii(t, r));
        while(!maxQ.empty() && !minQ.empty() && abs(maxQ.front().first-minQ.front().first) > K){
            if(l == maxQ.front().second)
                maxQ.pop_front();
            if(l == minQ.front().second)
                minQ.pop_front();
            R[l] = r-l;
            l++;
        }
        L[r] = r-l+1;
    }
    for(; l < N; l++) R[l] = N-l;
    gen();
    scanf("%d", &Q);

    fori(q, Q){
        scanf("%d %d", &a, &b);
        a--; b--;
        //printf("%d: %d, %d: %d\n", a, R[a], b, L[b]);

        if(a+R[a]-1 >= b) printf("%d %d\n", a+1, b+1);
        else{
            query(a, b);
            printf("%d %d\n", tmp.first+1, tmp.second+1);
            //cout << endl;
        }

    }
    return 0;
}
