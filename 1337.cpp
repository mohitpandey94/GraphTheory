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
char place[501][501];
bool vis[501][501];
const int dx[] = {-1,1};
const int dy[] = {-1,1};
pair<int,int> from[501][501];
int ans[501][501];
int bfs (int x, int y, int w, int h) {
    int count = 0;
    if (vis[x][y]) {
        return ans [from[x][y].first][from[x][y].second];
    }
    //memset (vis,false,sizeof vis);
    queue <pair <int,int> > q;
    q.push(mp(x,y));
    int i,j;
    vis[x][y] = true;
    from[x][y] = mp(x,y);
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        //cout<<"("<<i<<","<<j<<")\n";

        repu(ind,0,2,1) {
            if (!vis[i+dy[ind]][j] && place[i+dy[ind]][j] != '#' && (i+dy[ind] >= 0 && i + dy[ind] < h)) {
                q.push(mp(i+dy[ind],j));
                vis[i+dy[ind]][j] = true;
                from[i+dy[ind]][j] = mp(x,y);
                if (place[i+dy[ind]][j] == 'C')
                    count++;
            }
            if (!vis[i][j+dx[ind]] && place[i][j+dx[ind]] != '#' && (j+dx[ind] >= 0 && j + dx[ind] < w)) {
                q.push(mp(i,j+dx[ind]));
                vis[i][j+dx[ind]] = true;
                from[i][j+dx[ind]] = mp(x,y);
                if (place[i][j+dx[ind]] == 'C')
                    count++;
            }
        }
    }

    return count;
}
int main() {
    int t,m,n,q,x,y;
    t = readi();

    repu(tc,1,t+1,1) {
        m = readi(); n =readi(); q = readi();

        repu(i,0,m,1) scanf("%s",&place[i]);

        printf ("Case %d:\n",tc);
        while (q--) {
            x = readi(); y = readi();
            x--; y--;
            ans[x][y] = bfs(x,y,n,m);
            printf("%d\n",ans[x][y]);
        }
        memset(vis,false,sizeof vis);
        memset(from,-1,sizeof from);
        memset (ans,0,sizeof ans);
    }
return 0;
}
