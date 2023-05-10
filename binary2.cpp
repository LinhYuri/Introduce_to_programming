//Viết chương trình liệt kê tất cả các chuỗi nhị phân có độ dài n chữ số 0 và m chữ số 1

#include<iostream>
#include<vector>
using namespace std;

int n, m, x[100];
void inkq(){
    int cnt0 = 0, cnt1 = 0;
    for (int i=1; i<=n+m; i++){
        if (x[i] == 0) cnt0++;
        else cnt1++;
    } 
    if (cnt0 != n) return;
    else {
        for (int i=1; i<=n+m; i++){
            cout << x[i];
        }
        cout << endl;
    }
}

void recursion(int i){
    for (int j=0; j<=1; j++){
        x[i] = j;
        if (i == n+m) inkq();
        else recursion(i+1);
    }
}

int main(){
    cin >> n >> m;
    recursion(1);
    return 0;
}