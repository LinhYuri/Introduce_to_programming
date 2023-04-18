// nhập vào các mệnh giá tiền và số tiền cần đổi

#include<iostream>
using namespace std;

int n;  // số tờ tiền đổi
long long x;   // số tiền cần đổi
int a[101];    // mảng lưu các mệnh giá

int money(long long x, int pos){  // biến pos để duyệt từng mệnh giá trong a
    if (x == 0) return 0;  // không đổi tiền
    else if (pos < 0) return -1;  // không đổi được
    else {
        int ans = -1;  // số tờ (=-1 ban đầu không đổi đc)
        for (int i=0; i*a[pos] <= x; i++){
            int so_to = money(x - i*a[pos], pos-1);
            if (so_to != -1){
                if (ans == -1){
                    ans = so_to + i;
                } else {
                    ans = min(ans, so_to + i);
                }
            }
        }
        return ans;
    }
}

int main(){
    cin >> n >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int c = money(x, n-1);
    cout << c << endl;
    return 0;
}