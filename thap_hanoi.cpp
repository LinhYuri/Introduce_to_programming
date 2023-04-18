#include<iostream>
using namespace std;

void tower(int n, int s, int a, int d){
    if (n == 1){
        cout << s << " " << d << endl;
        return;
    } else {
        tower (n-1, s, d, a);
        tower (1, s, a, d);
        tower (n-1, a, s, d);
    }
}
int B(int n){
    if (n == 1){
        return 1;
    } else {
        return 2*B(n-1) + 1;
    }
}
int main(){
    int n; cin >> n;
    cout << B(n) << endl;
    tower(n, 1, 2, 3);
    return 0;
}