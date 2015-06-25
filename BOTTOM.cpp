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

void dfs (vector <int> graph[], bool vis[], int src, vector <int> sccs[], int inscc) {
    sccs[inscc].pb(src);
    vis[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        if (!vis[graph[src][i]]) {
            dfs(graph,vis,graph[src][i],sccs,inscc);
        }
    }
}

int main() {
    int vn,en,x,y,temp,scccount=0;
    si(vn);
    while (vn) {
        vector <int> graph[vn+1];
        vector <int> graphT[vn+1];
        bool vis[vn+1];
        vector <int> sccs[vn+1];
        stack <int> s;
        int ans[vn+1];
        si(en);


        for (int i = 0; i < en; i++) {
            si(x); si(y);
            graph[x].pb(y);
            graphT[y].pb(x);
        }

        fill (vis,vis+vn+1,false);


        for (int i = 1; i <= vn; i++) {
            if (!vis[i]) {
                dfs (graph,vis,i,s);
            }
        }

        fill (vis,vis+vn+1,false);

        while (!s.empty()) {
            temp = s.top();
            //cout<<temp<<" ";
            s.pop();
            if (!vis[temp]) {
                dfs(graphT,vis,temp,sccs,temp);
                scccount++;
            }
        }
        //cout<<"\n";
        int mini = INT_MAX;
        int contains[vn+1];
        for (int i = 1; i <= vn; i++) {
            for (int j = 0; j < sccs[i].size(); j++) {
                contains[sccs[i][j]] = i;
            }
        }
        bool flag = true;
        //for (int i = 1; i <= vn; i++) cout<<ans[i]<<"\n";
        for (int i = 1; i <= vn; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (contains[graph[i][j]] != contains[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) sccs[contains[i]].clear();
            flag = true;
        }
        //fill (ans,ans+vn+1,0);
        int k = 0;
        for (int i = 1; i <= vn; i++) {
            //cout<<sccs[i].size()<<": ";
            //sort(sccs[i].begin(),sccs[i].end());
            for (int j = 0; j < sccs[i].size(); j++) {
                ans[k++] = sccs[i][j];
                //pi(sccs[i][j]);
                //mini = min(mini,sccs[i][j]);
            }
            /*
            for (int j = 0; j < sccs[i].size(); j++) {
                ans[sccs[i][j]] = mini;
            }
            mini = INT_MAX;
            //cout<<"\n";
            */
        }
        sort(ans,ans+k);
        for (int i = 0; i < k; i++) pi(ans[i]);
        nl();
        //cout<<scccount<<"\n";
        si(vn);
    }
}
