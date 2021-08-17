// PROBLEM: https://codeforces.com/contest/1270/problem/E
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    long long n;
    cin >> n;
    long long x[n], y[n];
    long long subtract[n];
    for (long long i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        subtract[i]=y[i]-x[i]+4194304;
        x[i]+=4194304;
    }

    long long r=2;
    long long red=0;
    bool found=false;
    while (found==false) {
        red=0;
        for (long long i=0; i<n; i++) {
            if (subtract[i] % r< r/2 && subtract[i] % r>=0) {
                red+=1;
            }
        }
        if (red>0 && red<n) {
            cout << red << endl;
            for (long long i=0; i<n; i++) {
                if (subtract[i] % r< r/2 && subtract[i] % r>=0) {
                    cout << i+1 << " ";
                }
            }
            found=true;
        }
        else {
            red=0;
            for (long long i=0; i<n; i++) {
                if (x[i] % r< r/2 && x[i] % r>=0) {
                    red++;
                }
            }
            if (red>0 && red<n) {
                cout << red << endl;
                for (long long i=0; i<n; i++) {
                    if (x[i] % r< r/2 && x[i] % r>=0) {
                        cout << i+1 << " ";
                    }
                }
                found=true;
            }
        }
        r*=2;
    }
}
