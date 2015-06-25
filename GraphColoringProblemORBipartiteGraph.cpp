#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
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
double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
vector <int> graph[2002];
//bool vis[2002];
int color[2002];
void bfs(int v) {
    for(int i=1;i<=v;i++) color[i]=-1;
    int x,flag=0;
    for (int start=1; start<=v;start++) {
        if (color[start] == -1) {
            queue <int> q;
            q.push(start);
            color[start] = 1;
            flag=0;
            while (!q.empty()) {
                x=q.front();
                for (int i=0; i < graph[x].size(); i++) {
                    if (color[graph[x][i]] == -1) {
                        color[graph[x][i]] = !color[x];
                        q.push(graph[x][i]);
                    }
                    else if (color[graph[x][i]] == color[x]) {
                        flag=1;
                    }
                }
                q.pop();
                if (flag) break;
            }
        }
        if (flag) break;
    }
    if (!flag) printf("No suspicious bugs found!\n");
    else printf("Suspicious bugs found!\n");
}
int main() {
    int v,n,x,y,t,temp;
    t=readi();
    temp=0;
    for (temp=1;temp<=t;temp++) {
        v=readi();n=readi();
        for (int i=1;i<=v;i++) graph[i].clear();
        for (int i=0;i<n;i++) {
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        printf("Scenario #%d:\n",temp);
        bfs(v);
    }
return 0;
}
