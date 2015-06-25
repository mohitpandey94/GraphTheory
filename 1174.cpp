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
void bfs (vector <int> graph[], int n, int src, int dist[]) {
    fill(dist,dist+n,-1);
    queue <int> q;
    dist[src] = 0;
    q.push(src);
    int temp = src,node,prevtemp = -1;
    while (!q.empty()) {
        //prevtemp = temp;
        temp = q.front();
        q.pop();
        //cout<<temp<<" ";
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i];
            if (dist[node]==-1) {
                dist[node] = dist[temp] + 1;
                q.push(node);
            }
        }
    }
    //if (temp == dest) swap(prevtemp,temp);
    //maxdis = dist[temp];
    return;
}
int main() {
    int t,n,r,u,v,s,d;
    t = readi();
    int dist1[105],dist2[105],maxdis;
    repu(i,1,t+1,1) {
        n = readi();
        r = readi();
        vector <int> graph[n];
        repu(j,0,r,1) {
            u = readi();
            v = readi();
            graph[u].pb(v);
            graph[v].pb(u);
        }
        s = readi(); d = readi();
        //swap(s,d);
        bfs(graph,n,s,dist1);
        bfs (graph,n,d,dist2);
        maxdis = INT_MIN;
        repu (i,0,n,1) {
            maxdis = max(dist1[i]+dist2[i],maxdis);
        }
        cout<<"Case "<<i<<": ";
        cout<<maxdis<<"\n";
    }
return 0;
}
