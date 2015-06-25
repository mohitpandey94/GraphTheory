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
char tolower (char c) {
    return (c + 'a');
}
int main() {
    //cout<<('B' + 32 - 'a');
    int t,n;
    string s;
    t = readi();
    while (t--) {
        n = readi();
        cin>>s;
        int hashKey[27] = {0}, needed = 0;

        repu(i,0,2*n-2,1) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                hashKey[s[i]-'a']++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (hashKey[s[i] + 32 - 'a']) {
                    hashKey[s[i] + 32 - 'a']--;
                }
                else {
                    needed++;
                }
            }
        }
        cout<<needed<<"\n";
    }
return 0;
}
