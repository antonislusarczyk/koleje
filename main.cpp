#include <bits/stdc++.h>
using namespace std;
int dr[2097159];
int um;
int flc(int x) {
    int a=1;
    while(a<x) a*=2;
    if(a==x)return a*2;
    return a;
}
int lc;
bool cm(int pe,int k, int le) {
    k--;
    pe+=lc; k+=lc;
    int m=max(dr[pe],dr[k]);
    int l=pe,p=k;
    while(l/2<p/2) {
        if((l/2)*2==l) m=max(m, dr[l+1]);
        if((p/2)*2==p+1) m=max(m, dr[p-1]);
        l/=2;
        p/=2;
    }
    if(le<=um-m) return 1;
    return 0;
}
void akt(int p, int k, int l) {
    k--;
    p+=lc; k+=lc;
    for(int d=p;d<=k;d++) {
        dr[d]+=l;
        int w=dr[d];
        int e=d;
        while(dr[e/2]<w) {
            dr[e/2]=w;
            e/=2;
        }
    }
}
int main() {
    int n,m,z;
    cin>>n>>m>>z;
    um=m;
    lc=flc(n);
    for(int d=0;d<z;d++) {
        int p,k,l;
        cin>>p>>k>>l;
        if(cm(p,k,l)) {
            cout << "T" << endl;
            akt(p,k,l);
        }
        else cout << "N" << endl;
        /*
        for(int e=lc;e<=lc+n;e++) {
            cout << dr[e] << " ";
        }
        cout << endl;
         */
    }
}