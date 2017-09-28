#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

//max time is N-1 if I have to go back
//tree's diameter is the longest path
//clean subtrees that do not have restaurants
//every leaf node needs to be a restaurant.
//do a dfs to construct new adjacency list without the irrelevant nodes.
//find the new tree's diameter
//the answer is 2*E-diameter
vector<vi> tree, pruned;
bool is[100000];
int N, M, ok, a, b, bDst, bNode, pMask, mask, height[100000];

void bfs(int start){
    queue<int> q;
    if(!is[start]) q.push(start);
    int c = start;
    while(!q.empty()){
        c = q.front(); q.pop();
        printf("%d, ", c);
        mask |= 1<<c;
        for(int node : tree[c]){
            if(!(mask&(1<<node)) && !is[node] && height[node] < height[c])
                q.push(node);
        }
    }
    cout << endl;
}
void prune(){
    queue<int> q; mask = 0;
    for(int i = 0; i < N; i++)
        if(tree[i].size() == 1){
            printf("PRUNE: %d\n", i);
        	bfs(i);
        }
    pMask = mask;
}

void makeTree(){
	queue<int> q;
	q.push(0);
	int c = 0, mask = 1;
	height[0] = -1;
	while(!q.empty()){
		height[q.front()] = height[c]+1;
		c = q.front(); q.pop();
		for(int node : tree[c]){
			if(!(mask&(1<<node))){
				mask |= 1<<node;
				q.push(node);
				break;
			}
		}
	}
}


ii dfs(int curr, int mask){
    stack<int> s;
    s.push(curr);
    int maxH = 0, ansV = curr, c = curr; mask = 0;
    bool flag;
    while(!s.empty()){
        c = s.top();
        flag = false;
        for(int node : tree[c]){
            if(!(mask&(1<<node)) && !(pMask&(1<<node))){
                flag = true;
                s.push(node);
                mask |= (1<<node);
                break;
            }
        }
        if(s.size() > maxH){
            maxH = s.size();
            ansV = s.top();
        }
        if(!flag) s.pop();
    }
    return ii(ansV, maxH);
}

int main(){
    scanf("%d %d", &N, &M);
    tree.assign(N, vi()); memset(is, false, sizeof(is));
    memset(height, 0, sizeof(height));
    for(int i = 0; i < M; i++){
        scanf("%d", &ok);
        is[ok] = true;
    }
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        tree[a].push_back(b); tree[b].push_back(a);
    }
    makeTree();
    for(int i =0; i < N; i++){
        printf("n: %d, h: %d\n", i, height[i]);
    }
    prune();
    ii diam;
    //for(int i = 0; i < N; i++) if(pMask&(1<<i)) printf("%d ", i);
    diam = dfs(diam.first, 1<<(diam.first));
    int edges = 2*(N-__builtin_popcount(pMask)-1);
    cout << edges - (diam.second-1) << endl;
    return 0;
}
