#include<iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    int l, sz = 0;
    for (int i=0; i < n; i++){
        int sum = 0;
        for (int j=i; j < n; j++){
            sum += a[j];
            if (k*(j-i+1) <= sum && sz < j-i+1){
                sz = j-i+1;
                l = i;
            }
        }
    }
    for (int i=0; i<sz; i++){
        cout << a[i+l] << " ";
    }
    return 0;
}