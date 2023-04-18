#include<iostream>
using namespace std;

bool ex(string s1, string s2){ // kiểm tra s1 có phải xâu con của s2 không
    if (s1.size() > s2.size()){
        return false;
    } else {
        for (int j=0; j<s2.size(); j++){
            bool ok = true;
            for (int k=0; k<s1.size(); k++){
                if (s1[k] != s2[j+k]){
                    ok = false;
                }
            }
            if (ok){
                return true;
            }
        }
    }
}

int main(){
    string s, t; cin >> s >> t;
    if (ex(s, t)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}