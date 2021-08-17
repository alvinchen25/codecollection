#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int main()
{
    int n, m;
    cin >> n >> m;
    ll x[n];
    vector<pi> pairs;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        pairs.push_back(make_pair(x[i], i));
    }
    sort(pairs.begin(), pairs.end());
    int bads=0;
    for (int i=1; i<n; i++) {
        if (pairs[i].second<pairs[i-1].second) {
            bads++;
        }
    }
    cout << bads+1 << endl;

    int a[m], b[m];

    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i];

    }


}
