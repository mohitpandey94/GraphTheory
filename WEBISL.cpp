#include <iostream>
#include <stack>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>

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
vector <int> graph[100015];
vector <int> graphT[100015];
bool vis[100015];
vector <int> sccs[100015];
stack <int> s;
int ans[100015];
int main() {
    int vn,en,x,y,temp,scccount=0;
    cin>>vn;
    cin>>en;


    for (int i = 0; i < en; i++) {
        cin>>x>>y;
        graph[x].pb(y);
        graphT[y].pb(x);
    }

    fill (vis,vis+vn+1,false);


    for (int i = 0; i < vn; i++) {
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

    int mini = INT_MAX;

    for (int i = 0; i < vn; i++) {
        //cout<<sccs[i].size()<<": ";
        for (int j = 0; j < sccs[i].size(); j++) {
            //cout<<sccs[i][j]<<" ";
            mini = min(mini,sccs[i][j]);
        }
        for (int j = 0; j < sccs[i].size(); j++) {
            ans[sccs[i][j]] = mini;
        }
        mini = INT_MAX;
        //cout<<"\n";
    }

    for (int i = 0; i < vn; i++) cout<<ans[i]<<"\n";
    //cout<<scccount<<"\n";
}
