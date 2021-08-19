// PROBLEM: http://www.usaco.org/index.php?page=viewproblem2&cpid=1087
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

using namespace std;
long long LARGE=1000000007;
long long steps[1000005];

int painting(string c, int p, int q) {
    int ans=0;
    for (int i=0; i<26; i++) {
        char x=i+65;
        bool cont=false; //whether there's a continuing paint
        for (int j=p; j<=q; j++) {
            if (cont==false && c[j]==x) {
                ans++;
                cont=true;
            }
            if (cont==true && c[j]<x) {
                cont=false;
            }
        }
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int a[q], b[q];
    int paints=0;
    for (int i=0; i<q; i++) {
        cin >> a[i] >> b[i];
        a[i]=a[i]-1;
        b[i]=b[i]-1;

    }

    int total=0;
    int f[n];
    for (int i=0; i<n; i++) {
        f[i]=0;
    }
    for (int i=0; i<26; i++) {
        char x=i+65;
        bool cont=false; //whether there's a continuing paint
        for (int j=0; j<n; j++) {
            if (cont==false && s[j]==x) {
                total++;
                f[j]++;
                cont=true;
            }
            if (cont==true && s[j]<x) {
                cont=false;
            }
        }
    }
    for (int i=1; i<n; i++) {
        f[i]+=f[i-1];
    }

    int g[n];
    for (int i=0; i<n; i++) {
        g[i]=0;
    }
    for (int i=0; i<26; i++) {
        char x=i+65;
        bool cont=false; //whether there's a continuing paint
        for (int j=n-1; j>=0; j--) {
            if (cont==false && s[j]==x) {
                g[j]++;
                cont=true;
            }
            if (cont==true && s[j]<x) {
                cont=false;
            }
        }
    }
    for (int i=n-2; i>=0; i--) {
        g[i]+=g[i+1];
    }

    for (int i=0; i<q; i++) {
        int ans=0;
        if (a[i]>0) {
            ans+=f[a[i]-1];
        }
        if (b[i]<n-1) {
            ans+=g[b[i]+1];
        }
        cout << ans << endl;

    }



}
