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
char place[1005][1005];
const int dx[] = {-1,1};
const int dy[] = {-1,1};
struct pos {
    int x;
    int y;
    int cost;
};
typedef struct pos p;

class cmp {
public:
    bool operator () (struct pos &a, struct pos &b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};
bool valid (int i, int j, int r, int c) {
    if (i >= 1 && i <= r && j >= 1 && j <= c) return true;
    return false;
}
int dijkstra (int srx, int sry, int r, int c, int tgx, int tgy) {
    priority_queue <pos, vector <pos>, cmp> pq;
    int cost[r+1][c+1];
    bool vis[r+1][c+1];
    int posx,posy;
    repu(i,0,r+1,1) {
        repu(j,0,c+1,1) {
            cost[i][j] = 99999;
            vis[i][j] = false;
        }
    }
    cost[srx][sry] = 0;
    vis[srx][sry] = true;
    p temp,node;
    temp.x = srx; temp.y = sry; temp.cost = 0;

    pq.push(temp);
    while (!pq.empty()) {
        temp = pq.top();
        vis[temp.x][temp.y] = true;
        if (temp.x == tgx && temp.y == tgy) break;
        pq.pop();
        repu(ind,0,2,1) {
            posx = temp.x+dx[ind]; posy = temp.y;
            if (valid(posx,posy,r,c) && !vis[posx][posy] && place[posx][posy] != 'X') {
                if (cost[temp.x][temp.y] + 1 < cost[posx][posy]) {
                    cost[posx][posy] = cost[temp.x][temp.y] + 1;
                    node.x = posx; node.y = posy; node.cost = cost[posx][posy];
                    pq.push(node);
                }
            }
            posx = temp.x; posy = temp.y+dy[ind];
            if (valid (posx,posy,r,c) && !vis[posx][posy] && place[posx][posy] != 'X') {
                if (cost[posx][temp.y] + 1 < cost[posx][posy]) {
                    cost[posx][posy] = cost[posx][temp.y] + 1;
                    node.x = posx; node.y = posy; node.cost = cost[posx][posy];
                    pq.push(node);
                //    cout<<"("<<node.x<<","<<node.y<<"),"<<node.cost<<",";
                }
            }
            posx = temp.x+dx[ind];
            repu(ind2,0,2,1) {
                posy = temp.y+dy[ind2];
                if (valid (posx,posy,r,c)) {
                    if (!vis[posx][posy] && place[posx][posy] != 'X') {
                        if (cost[posx][posy] > cost[temp.x][temp.y] + 1) {
                            cost[posx][posy] = cost[temp.x][temp.y] + 1;
                            node.x = posx; node.y = posy; node.cost = cost[posx][posy];
                            pq.push(node);
                        }
                    }
                }
            }
        }
    //    cout<<pq.size()<<"sz \n";
    }

    return cost[tgx][tgy];
}
int main() {
    int t,r,c,tgx,tgy,srx,sry,ttaken;
    t = readi();
    while (t--) {
        r = readi();c = readi();
        repu(i,1,r+1,1) {
            repu(j,1,c+1,1) {
                cin>>place[i][j];
                if (place[i][j] == 'S') {
                    srx = i;
                    sry = j;
                }
                else if (place[i][j] == 'F') {
                    tgx = i;
                    tgy = j;
                }
            }
        }
        //tgx = readi(); tgy = readi(); time = readi();
        nl();
        ttaken = dijkstra (srx,sry,r,c,tgx,tgy);
        if (ttaken != 99999) {
            //ps("YES\n");
            pi(ttaken); nl();
        }
        else {
            pi(-1); nl();
        }

    }
return 0;
}
