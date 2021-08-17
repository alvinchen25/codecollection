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

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    ll vertsum=0;
    ll horsum=0;
    // horsum
    for (int i=0; i<n; i++) {
        int x=0, y=0;
        for (int j=0; j<n; j++) {
            if (j%2==0) {
                x+=a[i][j];
            }
            else {
                y+=a[i][j];
            }
        }
        horsum+=max(x,y);
    }
    //vertsum
    for (int i=0; i<n; i++) {
        int x=0, y=0;
        for (int j=0; j<n; j++) {
            if (j%2==0) {
                x+=a[j][i];
            }
            else {
                y+=a[j][i];
            }
        }
        vertsum+=max(x,y);
    }
    cout << max(horsum, vertsum) << endl;
}
