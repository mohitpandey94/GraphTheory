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
#define INT_MAX 1061109567
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
    bool operator () (pair <int,int> &a, pair <int,int> &b) {
        if (a.second  > b.second) return true;
        else return false;
    }
};

vector <int> dijkstra (vector <pair <int,int> > graph[], int src, int n) {
    priority_queue <pair <int,int>, vector <pair <int,int> >, cmp> pq;
    vector <int> dist(n+1,INT_MAX);
    bool vis [n+1];
    fill (vis,vis+n+1,false);
    dist[src] = 0;
    pq.push(mp(src,dist[src]));
    pair <int,int> temp,node;
    while (!pq.empty()) {
        temp = pq.top();
        vis[temp.first] = true;
        pq.pop();
        repu(i,0,graph[temp.first].size(),1) {
            node = graph[temp.first][i];
            if (!vis[node.first] && dist[node.first] > dist[temp.first] + node.second) {
                dist[node.first] = dist[temp.first] + node.second;
                pq.push(mp(node.first,dist[node.first]));
            }
        }
    }

    return dist;
}
int main() {
    //cout<<INT_MAX;
    int tc,n,m,k,s,t,u,v,w;
    tc = readi();
    while (tc--) {
        n = readi(); m = readi(); k = readi(); s = readi(); t = readi();
        vector <pair <int,int> > graph[n+1];
        vector <pair <int,int> > graphT[n+1];
        vector <int> d1,d2;
        while (m--) {
            u = readi(); v =readi(); w = readi();
            graph[u].pb(mp(v,w));
            graphT[v].pb(mp(u,w));
        }
        d1 = dijkstra (graph,s,n);
        d2 = dijkstra (graphT,t,n);
        int ans = d1[t];
        while (k--) {
            u = readi(); v = readi(); w = readi();
            ans = min (ans,min(d1[u] + w + d2[v], d1[v] + w + d2[u]));
        }

        if (ans == INT_MAX) {
            pi(-1);
        }
        else pi(ans);
        nl();
    }
return 0;
}
