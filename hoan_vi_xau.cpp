//Liệt kê tất cả các hoán vị của một xâu nhập từ bàn phím

#include<iostream>
#include<vector>
using namespace std;

int n, x[100], used[100];
vector <char> v;
void inkq(){
    for (int i=1; i<=n; i++){
        cout << v[x[i]];
    }
    cout << endl;
}

void dequy(int i){
    for (int j=1; j<=n; j++){
        if (used[j] == 0){
            x[i] = j;
            used[j] = 1;
            if (i == n) inkq();
            else dequy(i+1);
            used[j] = 0;
        }
    }
}

int main(){
    string s; cin >> s;
    n = s.size();
    v.push_back('0');
    for (int i=0; i<n; i++){
        v.push_back(s[i]);
    }
    memset(used, 0, sizeof(used));
    dequy(1);
    return 0;
}