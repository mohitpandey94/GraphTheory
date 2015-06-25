/*****************************
UNSOLVED
*****************************/


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

#define MAX 111060
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
vector <int> graph[MAX];
vector <int> grapht[MAX];
bool vis[MAX];
int comp[MAX],size[MAX];
void dfs (vector<int> graph[], int src, bool vis[], stack <int> &s) {
    vis[src] = true;
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            dfs(graph,graph[src][i],vis,s);
        }
    }
    s.push(src);
}
void dfs (vector<int> graph[], int src, bool vis[], int id, int comp[], int size[]) {
    comp[src] = id;
    size[id]++;
    vis[src] = false;
    //cout<<"SCC:"<<src<<" ";
    repu(i,0,graph[src].size(),1) {
        if (vis[graph[src][i]]) {
            dfs(graph,graph[src][i],vis,id,comp,size);
        }
    }
}
int main() {
    int t,h,p,s,u,v;
    t = readi();
    while (t--) {
        h = readi(); p =readi(); s = readi();
        repu(i,0,MAX,1) {
            graph[i].clear();
            grapht[i].clear();
            comp[i] = 0;
            vis[i] = false;
            size[i] = 0;
        }
        repu(i,0,s,1) {
            u = readi();
            v = readi();
            graph[u].pb(v);
            grapht[v].pb(u);
        }

        stack <int> st;
        repu(i,1,h+1,1) {
            if (!vis[i]) {
                dfs(graph,i,vis,st);
            }
        }

        //repu(i,0,MAX,1) vis[i] = false;
        //memset(vis,false,sizeof vis);
        int node,id = 0;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            if (vis[node]) {
                id += 1;
                size[id] = 0;
                dfs (grapht,node,vis,id,comp,size);
            }
        }

        repu(i,1,h+1,1) size[comp[i]]--;

        int maxr = -1;id = -1;
        repu(i,1,h+1,1) {
            if (size[comp[i]] > maxr) {
                maxr = size[comp[i]];
                id = i;
            }
        }
        cout<<id<<" "<<maxr<<"\n";
    }
return 0;
}
