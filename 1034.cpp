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
stack <int> s;
void dfs (vector <int> graph[], bool vis[], int n, int node) {
    vis[node] = true;
    //cout<<node<<"->";
    for (int i = 0; i < graph[node].size(); i++) {
        if (!vis[graph[node][i]]) {
            dfs(graph,vis,n,graph[node][i]);
        }
    }
    s.push(node);

    return ;
}
void dfs2 (vector <int> graph[], bool vis[], int n, int node) {
    vis[node] = true;
    //cout<<node<<" ";
    for (int i = 0; i < graph[node].size(); i++) {
        if (!vis[graph[node][i]]) {
            dfs2(graph,vis,n,graph[node][i]);
        }
    }

    return ;
}
int main() {
    int t,n,m,a,b,count;
    t = readi();

    repu(tc,1,t+1,1) {
        n = readi(); m = readi();
        vector <int> graph[n+1];

        count = 0;
        repu(i,0,m,1) {
            a = readi(); b = readi();
            graph[a].pb(b);
        }
        int node;
        bool vis[n+1];
        fill (vis,vis+n+1,false);
        while (!s.empty()) s.pop();
        repu(i,1,n+1,1) {
            if (!vis[i]) {
                dfs (graph,vis,n,i);
            }
        }

        fill (vis,vis+n+1,false);

        while (!s.empty()) {
            node = s.top();
            //cout<<node<<" ";
            s.pop();
            if (!vis[node]) {
                count++;
                dfs2(graph,vis,n,node);
                //nl();
            }
        }
        printf("Case %d: %d\n",tc,count);
        count = 0;
        while (!s.empty()) s.pop();
    }
return 0;
}
