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

int bfs (vector <int> graph[], int sz) {

    int color[sz+1],ans = 0;
    bool vis[sz+1];
    fill(color,color+sz+1,-1);
    fill(vis,vis+sz+1,false);
    for (int src = 1; src <= sz; src++) {
        if (color[src] != -1 || !graph[src].size()) continue;
        int c0 = 0,c1 =0,maxtil = INT_MIN;
        queue <int> q;
        color[src] = 1;
        c1 = 1;
        q.push(src);
        int temp;

        while (!q.empty()) {
            temp = q.front();
            q.pop();
            //vis[temp] = true;
            //cout<<temp<<" "<<graph[temp].size()<<":";
            repu(i,0,graph[temp].size(),1) {
                if (color[graph[temp][i]] == -1) {
                    color[graph[temp][i]] = !color[temp];
                    if (color[temp] == 1) c0++;
                    else c1++;
                    q.push(graph[temp][i]);
                    //cout<<c0<<" "<<c1<<"\n";
                }
            }
        }
        maxtil = max (c0,c1);
        //cout<<maxtil<<"fbfs:";
        c1 = c0 = 0;
        color[src] = 0;
        c0 = 1;
        q.push(src);

        while (!q.empty()) {
            temp = q.front();
            q.pop();
            //vis[temp] = true;

            repu(i,0,graph[temp].size(),1) {
                if (color[graph[temp][i]] == -1) {
                    color[graph[temp][i]] = !color[temp];
                    if (color[temp] == 1) c0++;
                    else c1++;
                    q.push(graph[temp][i]);
                }
            }
        }
        maxtil = max (maxtil,max(c0,c1));
        ans += maxtil;
    }
    //nl();
    return ans;
}
int main() {
    int t = readi(),n,u,v,maxnum = INT_MIN;
    repu(i,1,t+1,1) {
        n = readi();
        vector <int> graph[20005];
        repu(j,0,n,1) {
            u = readi();
            v = readi();
            graph[u].pb(v);
            graph[v].pb(u);
            maxnum = max(maxnum,max(u,v));
            //cout<<graph[u][0]<<" "<<graph[v][0]<<" ";
        }
        cout<<"Case "<<i<<": ";
        pi(bfs(graph,maxnum));
        nl();
        maxnum = INT_MIN;
        //graph.clear();
    }
return 0;
}
