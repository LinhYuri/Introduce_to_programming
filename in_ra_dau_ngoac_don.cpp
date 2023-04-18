// in ra n cặp dấu ngoặc hợp lệ

#include<iostream>
using namespace std;

int n;  // số cặp dấu ngoặc
char a[10005];
void back(int pos, int cur){  // cur là số ngoặc mở - số ngoặc đóng (đk cur >= 0)
    if (pos == 2*n){
        if (cur == 0){
            for (int i=0; i<2*n; i++){
                cout << a[i];
            }
            cout << endl;
        }
    }
    else {
        a[pos] = '(';
        back(pos + 1, cur + 1);
        if (cur > 0){
            a[pos] = ')';
            back(pos + 1, cur - 1);
        }
    }
}

int main(){
    cin >> n;
    back(0,0);
    return 0;    
}