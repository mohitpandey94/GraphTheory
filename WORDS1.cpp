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
void dfs (vector<int>graph[], bool vis[], int src) {
    repu(i,0,graph[src].size(),1) {
        if (!vis[graph[src][i]]) {
            vis[graph[src][i]] =  true;
            dfs(graph,vis,graph[src][i]);
            //i = graph[src].size();
        }
    }
}
int main() {
    int t,n;
    int indeg[32],oudeg[32];
    string neg = "The door cannot be opened.", pos = "Ordering is possible.";
    t = readi();
    char src,tar;
    while (t--) {
        n = readi();
        string s[n+1];
        vector <int> graph[32];
        bool att[32];
        fill (att,att+32,false);
        fill(indeg,indeg+32,0);
        fill(oudeg,oudeg+32,0);
        if (n==1) {
            cin>>s[0];
            cout<<pos<<"\n";
            continue;
        }
        repu(i,0,n,1) {
            cin>>s[i];
            src = s[i][0];
            tar = s[i][s[i].length()-1];
            //cout<<(src-'a')<<" "<<(tar-'a')<<"\n";
            graph[src-'a'].pb(tar-'a');
            graph[tar-'a'].pb(src-'a');
            att[src-'a'] = true;
            att[tar-'a'] = true;
            indeg[tar-'a']++;
            oudeg[src-'a']++;
        }
        bool vis[32],flag = true;
        fill(vis,vis+32,false);
        vis[src-'a'] = true;
        dfs(graph,vis,src-'a');
        repu(i,0,26,1) {
            if (att[i] && !vis[i]) {
                flag = false;
                //cout<<"this false,";
                break;
            }
        }
        if (flag) {
            int temp=0;
            repu(i,0,26,1) {
                if (att[i]) {
                    //cout<<(char)(i+'a')<<" ";
                    if (indeg[i] == oudeg[i]) continue;
                    if (abs(indeg[i]-oudeg[i]) == 1) {
                        //cout<<"here,";
                        temp++;
                        if (temp > 2) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                    //    cout<<"bad,";
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) cout<<pos<<"\n";
        else cout<<neg<<"\n";
    }

return 0;
}
