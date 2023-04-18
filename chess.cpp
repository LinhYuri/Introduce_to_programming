// Bài toán n quân hậu: nhập vào kích thước bàn cờ, in ra các khả năng của kết quả

#include<bits/stdc++.h>
using namespace std;

int n;
int a[101];

void check(int n){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (i-j == a[i] - a[j] || i+a[i] == j+a[j]){ // kiểm tra các quân hậu có ăn nhau chéo hay ko
                return;
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j == a[i]){
                cout << "*";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void queen(int n, int pos){
    if (pos == n){
        check(n);
        return;
    } else {
        set <int> sset;
        for (int i=0; i<pos; i++){
            sset.insert(a[i]);
        }
        for (int i=0; i<n; i++){
            if (!sset.count(i)){
                a[pos] = i;
                queen(n, pos+1);
            }
        }
    }
}

int main(){
    cin >> n;
    queen(n, 0);
    return 0;
}