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

map <ll, int> frequency;
map <ll, int> focc;
bool cmp (const int &a, const int &b) {
    if (frequency[a] > frequency[b]) return true;
    else if (frequency[a] == frequency[b]) {
        if (focc[a] < focc[b]) return true;
    }
    return false;
}
int main() {
    int n,x;
    ll c;
    n = readi();
    c = readl();
    ll a[n+1];
    repu(i,1,n+1,1) {
        x = readl();
        a[i] = x;
        frequency[x]++;
        if (!focc[x]) focc[x] = i;
    }
    sort (a+1,a+n+1,cmp);

    repu(i,1,n+1,1) cout<<a[i]<<" ";
    nl();
    frequency.clear();
    focc.clear();
    /*map <ll, pair<int,int> > :: iterator it;

    for (it = frequency.begin(); it != frequency.end(); it++) {
        while (it->second.first) {
            cout<<it->first<<" ";
            it->second.first--;
        }
    }*/
return 0;
}
