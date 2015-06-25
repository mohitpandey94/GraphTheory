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
    vis[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        if (!vis[graph[src][i]]) {
            dfs(graph,vis,graph[src][i],contains,inscc);
        }
    }
}

int main() {
    int t,vn,en,x,y,temp,scccount=0;
    si(t);
    while (t--) {
        si(vn);
        vector <int> graph[vn+1];
        vector <int> graphT[vn+1];
        bool vis[vn+1];
        vector <int> sccs[vn+1];
        stack <int> s;



        for (int i = 1; i <= vn; i++) {
            si(en);
            x=i;
            while (en--) {
                si(y);
                graph[x].pb(y);
                graphT[y].pb(x);
            }
        }

        fill (vis,vis+vn+1,false);


        for (int i = 1; i <= vn; i++) {
            if (!vis[i]) {
                dfs (graph,vis,i,s);
            }
        }

        fill (vis,vis+vn+1,false);
        int contains[vn+1];
        scccount=0;
        while (!s.empty()) {
            temp = s.top();
            //cout<<temp<<" ";
            s.pop();
            if (!vis[temp]) {
                dfs(graphT,vis,temp,contains,scccount);
                scccount++;
            }
        }
        //cout<<"\n";
        int indeg[vn+1];
        fill(indeg,indeg+vn+1,0);
        //for (int i = 1; i <= vn; i++) cout<<ans[i]<<"\n";
        for (int i = 1; i <= vn; i++) {
            for (int j = 0; j < graphT[i].size(); j++) {
                if (contains[graphT[i][j]] != contains[i]) {
                    indeg[contains[graphT[i][j]]]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < scccount; i++) {
            if (!indeg[i]) ans++;
            //cout<<indeg[i]<<"\n";
        }
        //cout<<"ans";
        if (ans > 1) pi(0);
        else {
            ans = 0;
            for (int i = 1; i <= vn; i++) {
                if (!indeg[contains[i]]) ans++;
            }
            pi(ans);
        }
        nl();
    }
}
