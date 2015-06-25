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

void bfs (vector <int> graph[], int n, int src, int vis[]) {
    //fill (vis,vis+n,false);
    bool vis2[n+1];
    queue <int> q;
    fill (vis2,vis2+n+1,false);
    q.push(src);
    //cout<<"src="<<src<<": ";
    int temp = src, node;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        vis[temp]++;
        vis2[temp] = true;
        //cout<<"\n"<<temp<<":";
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i];
            //cout<<node<<" "<<vis[node]<<",";
            if (!vis2[node]) {
                //vis[node]++;
                q.push(node);
            }
        }
    }

    return ;
}
int main() {
    int t,n,m,x,y;
    t = readi();
    while (t--) {
        n = readi();
        vector <int> graph[n+1];
        repu(i,1,n+1,1) {
            m = readi();
            while (m--) {
                y = readi();
                graph[i].pb(y);
            }
            //cout<<graph[i].size()<< " ";
        }
        //nl();
        int vis[n+1];
        fill (vis,vis+n+1,0);
        repu(i,1,n+1,1) {
            bfs(graph,n,i,vis);
            //cout<<"\n";
            //repu(j,1,n+1,1)
            //cout<<vis[j]<<" ";
            //cout<<"\n";
        }
        int count = 0;
        repu(i,1,n+1,1) {
            if(vis[i] == n) count++;
        }
        cout<<count<<"\n";
    }

return 0;
}
