// Viết chương trình sinh ra tất cả mật khẩu từ một tập các kí tự. Các kí tự trong tập hợp có thể không được dùng lần nào hoặc dùng nhiều lần. Mật khẩu có độ dài tối đa bằng số lượng phần tử trong tập hợp.
// Input: Một xâu kí tự chứa các kí tự của tập hợp.
// Output: Tất cả các xâu có thể từ các kí tự trong tập đã cho. Mỗi xâu trên một dòng.

#include<iostream>
#include <vector>
using namespace std;

int n;
vector <string> vt;
vector <string> password(int n, vector <string> vt){
    vector <string> v;
    if (n == 0){
        v.push_back("");
        return v;
    } else {
        vector <string> v1 = password(n-1, vt);
        for (int i=0; i<(int)vt.size(); i++){
            for(int j=0; j<(int)v1.size(); j++){
                v.push_back(vt[i] + v1[j]);
            }
        }
    }
    return v;
}
int main (){
    string s; cin >> s;
    n = s.size();
    for (int i=0; i<n; i++){
        string s1 = s.substr(i, 1);
        vt.push_back(s1);
    }
    for (int i=1; i<=n; i++){
        vector < string > v = password(i, vt);
        for (int j=0; j<(int)v.size(); j++){
            cout << v[j] << endl;
        }        
    }
    return 0;
}