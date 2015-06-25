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
stack <int> topo;
int reachables;
void dfs (vector <int> graph[], bool vis[], int src) {
    vis[src] = true;
    //reachables++;
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            dfs (graph,vis,graph[src][i]);
        }
    }
    topo.push(src);
}
void dfs2 (vector <int> graph[], bool vis[], int src) {
    vis[src] = true;
    //reachables++;
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            dfs (graph,vis,graph[src][i]);
        }
    }
    //topo.push(src);
}
int main() {
    int t,n,m,u,v;
    t = readi();

    repu(tc,1,t+1,1) {
        n = readi(); m = readi();

        vector <int> graph[n+1];
        bool vis[n+1];

        repu(i,0,m,1) {
            u = readi(); v = readi();
            graph[u].pb(v);
        }

        fill(vis,vis+n+1,false);
        repu(i,1,n+1,1) {
            if (!vis[i]) {
                dfs(graph,vis,i);
            }
        }
        fill(vis,vis+n+1,false);
        int node,ans=0;
        reachables = 0;

        while (!topo.empty()) {
            node = topo.top();
            //cout<<node<<" ";
            topo.pop();
            reachables = 0;
            if (!vis[node]) {
                ans++;
                cout<<"here"<<node<<"end";
                //fill (vis,vis+n+1,false);
                dfs2(graph,vis,node);

                //if (reachables > ans) ans = reachables;
            }

        }

        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
return 0;
}
