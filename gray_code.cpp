// in ra các graycode có n chữ số

#include<bits/stdc++.h>
using namespace std;

int n;
vector <string> graycode(int n){
    vector <string> v;
    if (n == 0){
        v.push_back("");
        return v;
    } else {
        vector <string> v1 = graycode(n-1);
        for (int i=0; i<v1.size(); i++){
            v.push_back("0" + v1[i]);
        }
        for (int i=v1.size() - 1; i>= 0; i--){
            v.push_back("1" + v1[i]);
        }
    }
    return v;
}
int main (){
    cin >> n;
    vector < string > v = graycode(n);
    for (int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}