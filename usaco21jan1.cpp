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

vector<int> adj[100000];
bool visited[100000];
bool visited1[100000];
set<int> q[100000];
vector<pair<int,int>> v;
int loopnum[100000];
vector<set<int>> loopset;
set<int> y[100000];

void dfs(int s, int loopy) {
    visited[s]=true;
    loopnum[s]=loopy;
    // y[loopy].insert(q[s].begin(), q[s].end());

    for (int i=0; i<adj[s].size(); i++) {
        if(visited[adj[s][i]]==false) {
            dfs(adj[s][i], loopy);
            // y[loopy].insert(q[adj[s][i]].begin(), q[adj[s][i]].end());
        }
    }
}
/*
void dfs1(int s, int arr[], int big) {
    visited1[s]=true;
    arr[s]=big;
    for (int i=0; i<adj[s].size(); i++) {
        if(visited1[adj[s][i]]==false) {
            arr[adj[s][i]]=big;
            dfs1(adj[s][i], arr, big);

        }
    }
}
*/
void initialize() {
    for (int i=0; i<100000; i++) {
        visited[i]=false;
        //visited1[i]=false;
    }
}

int main() {
    int n,k, m;
    cin >> n >> k >> m;
    int a[k], b[k];

    int ender[n];
    for (int i=0; i<n; i++) {
        ender[i]=i;
        q[i].insert(i);
    }
    for (int i=0; i<k; i++) {
        cin >> a[i] >> b[i];
        a[i]=a[i]-1;
        b[i]=b[i]-1;
    }
    for (int i=0; i<k; i++) {

        int end1=ender[a[i]];
        int end2=ender[b[i]];
        ender[a[i]]=end2;
        ender[b[i]]=end1;
        q[ender[a[i]]].insert(b[i]);
        q[ender[b[i]]].insert(a[i]);
        q[ender[a[i]]].insert(a[i]);
        q[ender[b[i]]].insert(b[i]);
        /*
        for (int i=0; i<n; i++) {
            cout << ender[i] << " ";
        }
        cout << endl;
        */
    }
    for (int i=0; i<n; i++) {
        adj[i].push_back(ender[i]);
        adj[ender[i]].push_back(i);
    }
    int maxsizes[n];
    for (int i=0; i<n; i++) {
        maxsizes[i]=q[i].size();
    }

    int loopnumber=-1;

    initialize();
    for (int i=0; i<n; i++) {
        int large=maxsizes[i];
        if (visited[i]==false) {
            loopnumber++;
            dfs(i, loopnumber);
        }
    }

    /*for (int i=0; i<loopnumber+1; i++) {
        v.push_back(make_pair(loopnumber,y[loopnumber].size()));
    }
    */
    for (int i=0; i<n; i++) {
        y[loopnum[i]].insert(q[i].begin(), q[i].end());
    }
    /*
    for (int i=0; i<=n; i++) {
        if (visited1[i]==false) {
            dfs1(i, maxsizes, wide[i]);
        }
    }
    */
    // cout << v.size() << " " << loopnumber << endl;
    for (int i=0; i<n; i++) {
        //cout << loopnum[i] << endl;
        maxsizes[i]=y[loopnum[i]].size();
    }

    for (int i=0; i<n; i++) {
        cout << maxsizes[i] << endl;
    }


}
