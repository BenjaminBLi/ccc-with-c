#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N, M;
vii points;

bool comp(ii &a, ii &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;}

bool covers(ii &a, ii &b){
     return b.first - a.first >= b.second - a.second;
}

long long calc(int n){
    if(n == 1) return 1LL;
    else return 1LL*n*(n+1)/2;
}

int main(){
    scanf("%d %d", &N, &M);
    int a, b;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        points.push_back(ii(a, b));
    }
    sort(points.begin(), points.end(), comp);
    ii prev = points[0];
    vi idxs;
    idxs.push_back(0);
    for(int i = 1; i < (int) points.size(); i++){
        if(!covers(prev, points[i])){
            prev = points[i];
            idxs.push_back(i);
        }
    }
    int sz = idxs.size();
    int level = 0;
    ii curr, next;
    long long area = 0;
    for(int i =0; i < sz-1; i++){
        curr = points[idxs[i]];
        next = points[idxs[i+1]];
        level = N-curr.first+1;
        area += calc(level);
        //cout << area << endl;
        if(next.second-curr.second < level){
            area -= calc(level-next.second+curr.second);
        }
        //cout << area << endl << endl;;
    }
    area += calc(N-points[idxs[sz-1]].first+1);
    cout << area << endl;
    return 0;
}
