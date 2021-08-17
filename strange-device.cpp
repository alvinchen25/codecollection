
#include<bits/stdc++.h>
using namespace std;


int main ()
{
    int n, k;
    cin >> n >> k;

    int one=-1, two=-1;
    int a[2];
    a[0]=0, a[1]=0;
    for (int i=1; i<k+2; i++) {
        cout << '?' << " ";
        if (i==1) {
            for (int j=2; j<k+2; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
        else {
            for (int j=1; j<i; j++) {
                cout << j << " ";
            }
            if (i<k+1) {
                for (int j=i+1; j<k+2; j++) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        cout.flush();
        int z, az;
        cin >> z >> az;
        if (one==-1) {
            one=az;
            a[0]++;
        }
        else if (one==az) {
            a[0]++;
        }
        else if (two==-1) {
            two=az;
            a[1]++;
        }
        else {
            a[1]++;
        }
    }
    if (two>one) {
        cout << '!' << " " << a[1] << endl;
    }
    else {
        cout << '!' << " " << a[0] << endl;
    }
}
