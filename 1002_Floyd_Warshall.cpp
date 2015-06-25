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
//int graph[500][500];
class cmp {
public:
    bool operator () (pair <int,int> &a, pair<int,int> &b) {
        if (a.first > b.first) return true;
        else return false;
    }
};
int dijkstra (vector <pair <int,int> > graph[], int src, int target, int n) {
    priority_queue <pair<int,int>, vector <pair<int,int> > , cmp> pq;
    bool vis[n];
    int dist[n], nodewt, node;

    fill (vis,vis+n,false);
    fill (dist,dist+n,200001);

    vis[src] = true;
    dist[src] = 0;
    //cout<<src<<" ";
    pq.push(mp(dist[src],src));
    pair <int,int> temp;
    while (!pq.empty()) {
        temp = pq.top();
        //cout<<temp.second<<" ";
        pq.pop();
        vis[temp.second] = true;
        if (temp.second == target) return dist[target];

        repu(i,0,graph[temp.second].size(),1) {
            node = graph[temp.second][i].second;
            nodewt = graph[temp.second][i].first;

            if (!vis[node]) {
                if (dist[node] > max(dist[temp.second], nodewt)) {
                    dist[node] = max (dist[temp.second], nodewt);
                    pq.push (mp(dist[node], node));
                }
            }
        }
    }

    return -1;
}
int main() {
    int t,n,m,x,y,w;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); m = readi();
        vector <pair <int,int> > graph[n];
        while (m--) {
            x = readi(); y =readi(); w = readi();
            graph[x].pb(mp(w,y));
            graph[y].pb(mp(w,x));
        }
        x = readi();
        printf ("Case %d:\n",tc);
        repu(i,0,n,1) {
            w = dijkstra(graph,x,i,n);
            if (w == -1) printf ("Impossible\n");
            else printf ("%d\n", w);
        }
    }
    return 0;
}
/*
//Gives TLE
void floydwarshall (int n) {
    repu(k,0,n,1) {
        repu(i,0,n,1) {
            repu(j,0,n,1) {
                if (i == j && j == k) continue;
                if (graph[i][j] > max(graph[i][k], graph[k][j])) {
                    //cout<<i<<" "<<j<<" "<<k<<":"<<graph[i][j]<<" "<<graph[i][k]<<" "<<graph[k][j]<<"\n";
                    graph[i][j] = max(graph[i][k], graph[k][j]);
                    //cout<<i<<" "<<j<<" "<<k<<":"<<graph[i][j]<<" "<<graph[i][k]<<" "<<graph[k][j]<<"\n";
                }
            }
        }
    }
}
int main() {
    int t,n,m,x,y,w;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); m = readi();
        repu(i,0,n,1) repu(j,0,n,1) graph[i][j] = 200001;
        while (m--) {
            x = readi(); y =readi(); w = readi();
            if (graph[x][y] != 200001 && graph[x][y] <= w) continue;
            graph[x][y] = graph[y][x] = w;
            //graph[x][x] = graph[y][y] = 0;
        }

        floydwarshall(n);
        //repu(i,0,n,1) graph[i][i] = 0;
        x = readi();
        printf("Case %d:\n",tc);
        repu(i,0,n,1) {
            graph[i][i] = 0;
            if (graph[x][i] != 200001)
                printf("%d\n",graph[x][i]);
            else ps ("Impossible\n");
        }
    }
return 0;
}
*/
