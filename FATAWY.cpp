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

//int lcs[502][502];
char s[502][25];
int lengths[502];
int dp[2][502];
bool vis[502];
vector <int> graph[502];

int maxo (int a, int b) {
    return (a > b?a:b);
}
int lcslen (char* a, char* b, int n, int m) {
	//init
	//repu(i,0,n+1,1) dp[i][0] = 0;
	repu(j,0,m+1,1) dp[0][j] = dp[1][j] = 0;
    int turn = 1,id1,id2;
	repu(i,1,n+1,1) {
	    id1 = turn&1;
	    id2 = (turn&1)^1;
		repu(j,1,m+1,1) {
		    if (a[i-1] != b[j-1]) {
                dp[id1][j] = maxo(dp[id2][j],dp[id1][j-1]);
		    }
			else {
				dp[id1][j] = dp[id2][j-1]+1;
			}
		}
		turn++;
	}
	return dp[id1][m];
}
/*
void bfs (vector <int> graph[], int src, bool vis[]) {
    queue <int> q;
    int temp,node;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i];
            if (!vis[node]) {
                q.push(node);
                vis[node] = true;
            }
        }
    }
}
*/
void dfs (vector <int> graph[], int src, bool vis[]) {
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            vis[graph[src][i]] = true;
            dfs(graph,graph[src][i],vis);
        }
    }
}
int main() {
    int t,n,th,val,ans,len=0;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); th = readi();
        repu(i,0,n,1) {
            scanf("%s",s[i]);
            while (s[i][len++] != '\0') ;
            lengths[i] = len-1;
            len=0;
        }
        /*
        repu(i,0,n,1) {
            repu(j,i+1,n,1) {
                lcs[j][i] = lcs[i][j] = lcslen(s[i],s[j],lengths[i],lengths[j]);
            }
        }
        */
        repu(i,0,n,1) {
            repu(j,i+1,n,1) {
                val = lcslen(s[i],s[j],lengths[i],lengths[j]);
                if (((double) (val*100.0) / (double) (lengths[i]*1.0)) >= (double)(th*1.0) && ((double) (val*100.0) / (double) (lengths[j]*1.0)) >= (double)(th*1.0)) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }
        ans=0;
        repu(i,0,n,1) {
            if (!vis[i]) {
                vis[i] = true;
                dfs (graph,i,vis);
                ans++;
            }
        }
		printf("Case #%d:\n%d\n",tc,ans);
		repu(i,0,n+1,1) vis[i]=false,graph[i].clear();
    }
return 0;
}
