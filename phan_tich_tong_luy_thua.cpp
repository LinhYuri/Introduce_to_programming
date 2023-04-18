#include<bits/stdc++.h>
using namespace std;

int ways(int x, int n, int pos){
    if (x == 0) return 1;
    if (pos == 0) return 0;
    return ways(x-pow(pos, n), n, pos-1) + ways(x, n, pos-1);
}

int main(){
    int x, n; cin >> x >> n;
    cout << ways(x, n, pow(x, 1.0/n));
    return 0;
}