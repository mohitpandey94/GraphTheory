#include <bits/stdc++.h>
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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)
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
int d[1000];
int f[1000];
int parent[1000];
int color[1000];
int timer;
vector <int> v[1000];
vector <int> vt[1000];
stack <int> s;
void dfs_visit(int vertex) {
        timer++;
        d[vertex] = timer;
        color[vertex] = 1;
        for (int i =0 ; i < v[vertex].size(); i++) {
                //cout<<" here ->"<<i;
                if (color[v[vertex][i]] == 0) {
                parent[v[vertex][i]] = vertex;
                dfs_visit(v[vertex][i]);
                }
        }
        color[vertex] = 2;
        timer++;
        f[vertex] = timer;
        s.push(vertex);
}
void dfs(int n) {
       for (int i=0; i<n; i++) {
                cout<<i<<" ";
                if (color[i] == 0) {
                        dfs_visit(i);
                }

       }
}
void dfs_vis2 (int u) {
        color[u] = 1;
        cout<<u<<" ";
        for (int i=0; i < vt[u].size(); i++) {
                if (color[vt[u][i]] == 0) {
                        //cout<<vt[u][i]<<" ";
                        parent[vt[u][i]] = u;
                        color[vt[u][i]] = 1;
                        dfs_vis2(vt[u][i]);
                }
        }
        color[u] = 2;
}
void dfs2(int n) {
        while (!s.empty()) {
                int u = s.top();
                s.pop();
                cout<<"\nTopo:"<<u<<" ";
                if (color[u] == 0) {
                        cout<<"\nSCC:"<<u<<" ";
                        color[u] = 1;
                        for (int i =0 ; i < vt[u].size(); i++) {
                                if (color[vt[u][i]] == 0) {
                                        dfs_vis2(vt[u][i]);
                                }
                        }
                        color[u]=2;
                        nl();
                }
        }
}
int main() {
        int n;
        int e;
        int p;
        int q;
        n=readi();
        e=readi();
        for (int i=0; i < e; i++) {
              p=readi();
              q=readi();
               v[p].pb(q);
               vt[q].pb(p);
        }
        dfs(n);
        nl();
        for (int i=0; i < n; i++) {
                cout<<d[i]<<" " << f[i]<<endl;
        }
        cout<<s.size()<<endl;
        memset(color,0,sizeof(color));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        memset(parent,-1,sizeof(parent));
        dfs2(n);
return 0;
}
/*
8
14
0 1
1 4
4 0
4 5
1 5
1 2
2 6
6 5
5 6
2 3
3 2
3 7
7 7
6 7
*/
