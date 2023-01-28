#include <iostream>
#include <vector>
using namespace std;

int t[1048576];
int m;
int cp(int a, int b) {
    if(a==b) return t[a+m];
    a+=m;
    b+=m;
    b/=2;
    a/=2;
    int em=0;
    while(a<b) {
        em=max(em,t[a*2+1]);
        em=max(em,t[b*2]);
        b/=2;
        a/=2;
    }

    return max(em, t[a]);
}
void updat(int a,int b,int z) {
    a+=m;
    b+=m;
    for(int d=a;d<=b;d++) {
        t[d]+=z;
        int es=d/2;
        while(true) {
            if(t[es]>=t[d]) break;
            else {
                t[es]=t[d];
                es/=2;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int lm,ls,lz;
    cin>>lm>>ls>>lz;
    m=1<<19;
    for(int d=0;d<lz;d++) {
        int a,b,z;
        cin>>a>>b>>z;
        //cout << "cp ab: " <<a <<"-a b-"<<b<<" "<< cp(a,b) << endl;
        if(ls-cp(a,b-1)>=z) {
            cout << "T" << endl;
            updat(a,b-1,z);
        }
        else cout << "N" << endl;
        /*for(int d=1+m;d<=lm+m;d++) {
            cout << t[d] << " ";
        }
        cout << endl;
         */
    }

}


