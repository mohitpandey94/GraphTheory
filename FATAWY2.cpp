#include <cstdlib>
#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <string>
#include<vector>
#include<math.h>
#include <map>
#include <string.h>

using namespace std;
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

string fatawy [600];
int lengths[600], lcs[600][600],L[600][600];
int LCS(string a , string b, int n, int m){
    //int n = (a).length() , m = (b).length();
    //int L [n+1][m+1];
    //cout<<a<<" "<<b<<" "<<n<<" "<<m;
    for(int i=0 ; i<=n ; i++)
        L[i][0]=0;
    for(int i=0 ; i<=m ; i++)
        L[0][i]=0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            if(a[i-1]==b[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else if (L[i-1][j] > L[i][j-1])
                L[i][j]=L[i-1][j];
            else
                L[i][j]=L[i][j-1];
        }
    }// end of external for

    return L[n][m];
}

int main() {
    int t, n;
    int th2;
    double TH;

    scanf("%d",&t);
    int count=1;
    while (t--){
        scanf("%d %d",&n,&th2);
        TH= (double)th2/100.0;
        //  cout<<TH<<endl;
        //   TH/=100.0;
        for(int i=0 ; i<n ; i++){
            cin>>fatawy[i];
            lengths[i] = fatawy[i].length();
        }// end of reading input
        UnionFind UF(n);
        //  cout << "U "<<UF.numDisjointSets()<<endl;
        int res;
        double percent1 , percent2;
        for (int i = 0; i < n; i++) {
            for (int j=i+1;j<n;j++) {
                if (!lcs[i][j]) lcs[i][j] = lcs[j][i] = LCS(fatawy[i],fatawy[j],lengths[i],lengths[j]);
            }
        }
        //cout<<"here";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(UF.isSameSet(i, j)) continue;
                res = lcs[i][j];
                //   cout<<fatawy[i]<<" "<<fatawy[j]<<" "<<res<<endl;
                percent1= (double) (res*1.0) / (double) (lengths[i]*1.0);
                percent2= (double) (res*1.0) / (double) (lengths[j]*1.0);
                //  cout<<percent1<<" "<<percent2<<" "<<TH<<endl;
                if(percent1 >=TH && percent2 >= TH){
                    UF.unionSet(i, j);
                    //  cout<<"** "<<UF.numDisjointSets()<<endl;
             //          cout<<"i" << i<<" "<<j << endl;
                }
            }
        }// end of processing
        printf("Case #%d:\n",count++);
        printf("%d\n",UF.numDisjointSets());
        memset(lcs,0,sizeof lcs);
    }

return 0;
}
