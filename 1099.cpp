#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
class cmp {
public:
    bool operator () (pair <pair <int,int> , int> &a, pair <pair<int,int>,int > &b) {
        if (a.second > b.second) return true;
        return false;
    }
};
int dijkstra(vector <pair <int,int> > graph[], int src, int target, int n) {
    priority_queue <pair<pair<int,int> ,int>, vector <pair<pair<int,int>,int> >, cmp> pq;
    bool vis[2][n+1];
    int dist[2][n+1], node,wt;
    repu (i,0,2,1)
        fill(vis[i],vis[i]+n+1,0),fill (dist[i],dist[i]+n+1,INT_MAX);
    dist[0][src] = 0;
    pq.push (mp(mp(0,src), dist[0][src]));
    pair <pair<int,int>,int > temp;

    while (!pq.empty()) {
        temp = pq.top();
        vis[temp.first.first][temp.first.second] = true;
        //cout<<"\n"<<temp.first.second<<" "<<vis[temp.first.first][temp.first.second]<<",";
        if (temp.first.second == target && vis[1][temp.first.second] == true) return dist[1][target];
        pq.pop();
        repu(i,0,graph[temp.first.second].size(),1) {
            node = graph[temp.first.second][i].first;
            wt = graph[temp.first.second][i].second;
            if (!vis[1][node]) {
               // cout<<",Pushed:"<<node<<","<<wt<<","<<dist[node]<<","<<dist[temp.first]<<" ";
                wt = wt + dist[temp.first.first][temp.first.second];
                if (dist[0][node] > wt) {
                    dist[1][node] = dist[0][node];
                    dist[0][node] = wt;
                    pq.push(mp(mp(0,node),dist[0][node]));
                    pq.push(mp(mp(1,node),dist[1][node]));
                    //cout<<node<<",";
                }
                else if (dist[0][node] < wt && dist[1][node] > wt) {
                    dist[1][node] = wt;
                    pq.push(mp(mp(1,node),dist[1][node]));
                }
            }
        }
    }
}
int main() {
    int t,n,r,x,y,w;
    t = readi();

    repu(tc,1,t+1,1) {
        n = readi(); r = readi();
        vector <pair <int,int> > graph[n+1];

        while (r--) {
            x = readi(); y = readi(); w = readi();
            graph[x].pb(mp(y,w));
            graph[y].pb(mp(x,w));
        }

        w = dijkstra(graph,1,n,n);
        printf("Case %d: %d\n",tc,w);
    }
return 0;
}
