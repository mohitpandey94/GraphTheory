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
char place[20][20];
bool vis[20][20];
const int dx[] = {-1,1};
const int dy[] = {-1,1};
int ans;
void bfs (int x, int y, int w, int h) {
    memset (vis,false,sizeof vis);
    queue <pair <int,int> > q;
    q.push(mp(x,y));
    ans = 1;
    int i,j;
    vis[x][y] = true;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        //cout<<"("<<i<<","<<j<<")\n";

        repu(ind,0,2,1) {
            if (!vis[i+dy[ind]][j] && place[i+dy[ind]][j] == '.' && (i+dy[ind] >= 0 && i + dy[ind] < h)) {
                q.push(mp(i+dy[ind],j));
                vis[i+dy[ind]][j] = true;
                ans++;
            }
            if (!vis[i][j+dx[ind]] && place[i][j+dx[ind]] == '.' && (j+dx[ind] >= 0 && j + dx[ind] < w)) {
                q.push(mp(i,j+dx[ind]));
                vis[i][j+dx[ind]] = true;
                ans++;
            }
        }
    }
}
int main() {
    int t,w,h;
    t = readi();
    repu(i,1,t+1,1) {
        w = readi(); h = readi();
        //char place[h][w];
        repu(j,0,h,1) {
            scanf("%s",&place[j]);
        }
        repu(j,0,h,1) {
            repu(k,0,w,1) {
                if (place[j][k] == '@') {
                    bfs (j,k,w,h);
                    break;
                }
            }
        }
        cout<<"Case "<<i<<": "<<ans<<"\n";
        ans = 0;
    }
return 0;
}
