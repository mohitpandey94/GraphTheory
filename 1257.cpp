//longest path in a weighted undirected tree

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

int bfs (vector <pair<int,int> > graph[], int n, int src, int dist[]) {
    fill(dist,dist+n,-1);
    queue <int> q;
    dist[src] = 0;
    q.push(src);
    int temp,node,maxnode=src,maxdis = 0;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        //cout<<temp<<" ";
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i].first;
            if (dist[node] == -1) {
                dist[node] = dist[temp] + graph[temp][i].second;
                q.push(node);
                if (dist[node] > maxdis) {
                    maxdis = dist[node];
                    maxnode = node;
                }
            }
        }
    }

    return maxnode;
}
int main() {
    int t,n,l,x,y,dista[30005],distb[30005];
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi();
        //n = readi();
        vector <pair<int,int> > graph[n+1];
        repu(i,0,n-1,1) {
            x = readi(); y = readi(); l = readi();
            //x--; y--;
            graph[x].pb(mp(y,l));
            graph[y].pb(mp(x,l));
        }
        printf("Case %d:\n",tc);
        int maxdis[n];
        y = bfs (graph,n,0,dista);
        //cout<<y<<" ";
        x = bfs (graph,n,y,distb);
        y = bfs (graph,n,x,dista);
        //repu(x,0,n,1) cout<<dista[x]<<" "<<distb[x]<<"\n";

        repu(x,0,n,1) {
            printf("%d\n",max(dista[x],distb[x]));
            //cout<<max (dista[x],distb[x])<<"\n";
        }

        //nl();
    }
return 0;
}
