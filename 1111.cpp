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
void bfs (vector <int> graph[], int n, int src, bool vis[]) {
    fill (vis,vis+n,false);
    queue <int> q;
    vis[src] = true;
    q.push(src);
    int temp = src, node;
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i];
            if (!vis[node]) {
                vis[node] = true;
                q.push(node);
            }
        }
    }

    return ;
}
int main() {
    int t,n,k,m,u,v,src[101];
    t = readi();

    repu(tc,1,t+1,1) {
        k = readi(); n = readi(); m = readi();
        vector <int> graph[n+1];
        bool vis[k][n];
        repu(i,0,k,1) src[i] = readi();
        repu(i,0,m,1) {
            u = readi(); v = readi();
            u--; v--;
            graph[u].pb(v);
        }
        repu(i,0,k,1) {
            bfs (graph,n,src[i]-1,vis[i]);
        }
        int ans = 0,flag = 0;
        repu(i,0,n,1) {
            flag = 0;
            repu(j,0,k,1) {
                if (!vis[j][i]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) ans++;
        }
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
return 0;
}
