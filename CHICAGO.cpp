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
class cmp {
public:
    bool operator () (pair <int,double> &a, pair <int,double> &b) {
        if (a.second < b.second) return true;
        return false;
    }
};
double dijkstra(vector <pair<int,double> > graph[], int n) {
    priority_queue <pair <int,double>, vector <pair<int,double> > , cmp> pq;
    bool vis[n+1];
    double cost[n+1];
    fill (vis,vis+n+1,false);
    fill (cost,cost+n+1,DBL_MIN);

    cost[1] = 1.0;
    pq.push(mp(1,cost[1]));
    pair <int,double> temp;

    while (!pq.empty()) {
        temp = pq.top();
        //cout<<temp.first<<" "<<temp.second<<"\n";
        pq.pop();
        if (temp.first == n) break;
        vis[temp.first] = true;
        int sz = graph[temp.first].size(),node;
        repu(i,0,sz,1) {
            node = graph[temp.first][i].first;
            //cout<<cost[temp.first]<<" "<<graph[temp.first][i].second<<" "<<cost[node]<<"\n";
            if (!vis[node] && cost[node] < cost[temp.first] * graph[temp.first][i].second) {
                cost[node] = cost[temp.first] * graph[temp.first][i].second;
                pq.push(mp(node,cost[node]));
            }
        }
    }

    return cost[n];
}
int main() {
    int n,m,x,y,p;
    cin>>n;
    while (n) {
        cin>>m;
        vector <pair<int,double> > graph[n+1];

        while (m--) {
            cin>>x>>y>>p;
            graph[x].pb(mp(y,p*0.01));
            graph[y].pb(mp(x,p*0.01));
        }

        //cout<<setprecision(6)<<dijkstra(graph,n)*100.00<<" precent\n";
        printf("%.6lf percent\n",dijkstra(graph,n)*100.0);
        cin>>n;
    }
return 0;
}
