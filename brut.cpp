#include <bits/stdc++.h>
using namespace std;

int m, n; // 60k max

bool czy_mozna(int p, int k, int l, vector<int> const & mz)
{
    for (int idx = p; idx < k; ++idx) {
        if (mz[idx] + l > m) return false;
    }
    return true;
}

void zajmij_miejsca(int p, int k, int l, vector<int> & mz)
{
    for (int idx = p; idx < k; ++idx)
        mz[idx] += l;
}

int main() {
    int z;
    cin>>n>>m>>z;

    vector<int> miejsca_zajete(n-1, 0);

    for(int d=0;d<z;d++) {
        int p,k,l;
        cin>>p>>k>>l;
        if (czy_mozna(p,k,l,miejsca_zajete)) {
            cout << "T\n";
            zajmij_miejsca(p,k,l,miejsca_zajete);
        }
        else
        {
            cout << "N\n";
        }
    }
}
