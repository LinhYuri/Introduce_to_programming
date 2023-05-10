//Viết chương trình liệt kê tất cả các chuỗi nhị phân có độ dài n

#include<iostream>
using namespace std;

int n, x[100];
void inkq(){
    for (int i=1; i<=n; i++){
        cout << x[i];
    }
    cout << endl;
}

void recursion(int i){
    for (int j=0; j<=1; j++){
        x[i] = j;
        if (i == n) inkq();
        else recursion(i+1);
    }
}

int main(){
    cin >> n;
    recursion(1);
    return 0;
}