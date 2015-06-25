#include <iostream>
#include <stack>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdio>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d ",x)
#define nl() printf("\n")
#define pb push_back
using namespace std;

vector <int> graph[20010];
vector <int> graphT[20010];
bool vis[20010];
int indeg[20010];
int oudeg[20010];
int contains[20010];
vector <int> sccs[20010];
stack <int> s;

void dfs (vector <int> graph[], bool vis[], int src, stack <int> &s) {
    vis[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        if (!vis[graph[src][i]]) {
            dfs (graph,vis,graph[src][i],s);
        }
    }
    s.push(src);
}

void dfs (vector <int> graph[], bool vis[], int src,int contains[], int inscc) {
    contains[src] = inscc;
    vis[src] = false;

    for (int i = 0; i < graph[src].size(); i++) {
        if (vis[graph[src][i]]) {
            dfs(graph,vis,graph[src][i],contains,inscc);
        }
    }
}
void reset () {
    for (int i =0;i<=20009;i++) {
        graph[i].clear();graphT[i].clear();
        vis[i]=false;
        indeg[i]=0;
        oudeg[i]=0;
        contains[i]=-1;
    }
    while (!s.empty()) s.pop();
}
void input (vector <int> graph[], vector <int> graphT[], int en) {
    int x,y;
    for (int i =0 ;i<en;i++) {
        si(x);si(y);
        graph[x].pb(y);
        graphT[y].pb(x);
    }
}
int main() {
    int t=1,vn,en,x,y,temp,scccount=0;
    si(t);
    for (int tc=1;tc<=t;tc++) {
        reset();
        si(vn);
        si(en);
        input(graph,graphT,en);

        for (int i = 1; i <= vn; i++) {
            if (!vis[i]) {
                dfs (graph,vis,i,s);
            }
        }
        scccount=0;
        //fill(vis,vis+vn+1,false);
        while (!s.empty()) {
            temp = s.top();
            s.pop();
            if (vis[temp]) {
                dfs(graphT,vis,temp,contains,scccount);
                scccount++;
            }
        }

        for (int i = 1; i <= vn; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (contains[graph[i][j]] != contains[i]) {
                    indeg[contains[graph[i][j]]]++;
                    oudeg[contains[i]]++;
                }
            }
        }

        int ans1 = 0,ans2=0;
        for (int i = 0; i < scccount; i++) {
            if (!indeg[i]) ans1++;
            if (!oudeg[i]) ans2++;
        }
        if (scccount == 1) ans1=ans2=0;
        printf("Case %d: %d\n",tc,max(ans1,ans2));
        //nl();
        /*
        if (ans > 1) pi(0);
        else {
            ans = 0;
            for (int i=1;i<=vn;i++) {
                if (!indeg[contains[i]]) {
                    ans++;
                }
            }
            pi(ans);
            nl();
            for (int i=1;i<=vn;i++) {
                if (!indeg[contains[i]]) {
                    pi(i);
                }
            }
        }
        nl();
        */
    }
}
