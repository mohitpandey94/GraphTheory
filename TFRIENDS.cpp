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
void dfs (vector <int> graph[], bool vis[],int src, stack<int> &s) {
    vis[src] = true;
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            dfs (graph,vis,graph[src][i],s);
        }
    }
    s.push(src);
}
void dfs(vector <int> graph[],bool vis[], int src) {
    vis[src] = true;
    //sccno[src] = scc;
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            dfs(graph,vis,graph[src][i]);
        }
    }
}
int main() {
    int t,n;
    char c;
    t = readi();
    while (t--) {
        n = readi();
        vector <int> graph[n+1];
        vector <int> grapht[n+1];
        bool vis[n+1];
        repu(i,0,n,1) {
            repu(j,0,n,1) {
                cin>>c;
                if (c == 'Y') {
                    graph[i].pb(j);
                    grapht[j].pb(i);
                }
            }
        }
        fill(vis,vis+n+1,false);
        stack <int> s;
        repu(i,0,n,1) {
            if (!vis[i]) {
                dfs(graph,vis,i,s);
            }
        }
        fill(vis,vis+n+1,false);
        //int sccno[n+1];
        int scc = 0;
        int node;
        //fill (sccno,sccno+n+1,-1);
        //cout<<"h"<<s.size()<<"\n";
        while (!s.empty()) {
            node = s.top();
            s.pop();
            if (!vis[node]) {
                //cout<<node<<","<<grapht[node].size()<<" ";
                dfs(grapht,vis,node);
                scc++;
                //cout<<"here";
            }
        }
        cout<<scc<<"\n";
    }
return 0;
}
