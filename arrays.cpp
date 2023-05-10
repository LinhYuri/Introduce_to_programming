// Cho 2 mảng số nguyên, ta cần tìm tất cả các số nguyên thỏa mãn hai điều kiện sau:
// Các số cần tìm là bội của tất cả phần tử trong mảng thứ nhất.
// Các số cần tìm là ước của tất cả phần tử trong mảng thứ hai.

#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    int c = gcd(a, b);
    return a * b / c;
}

int main(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    
    int x=0, y=0, uc=a[0], bc=b[0];
    sort(b, b+m);
    while (x < n-1){
        int tmp = lcm(uc, a[x+1]);
        uc = tmp;
        x++;
    }
    
    while (y < m-1){
        int tmp = gcd(b[y], b[y+1]);
        b[y+1] = tmp;
        y++;
    }
    
    int ans = 0;
    for (int i=uc; i<=bc; i+=uc){
        int cnt = 0;
        for (int j=0; j<m; j++){
            if (b[j] % i != 0){
                break;
            }
            cnt++;
        }
        if (cnt == m) ans++;
    }
    cout << ans << endl;
}