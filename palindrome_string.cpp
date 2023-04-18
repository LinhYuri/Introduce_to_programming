// ho một chuỗi các chữ cái viết thường trong phạm vi ascii[a-z]
// hãy xác định chỉ mục của một ký tự có thể được loại bỏ để biến chuỗi thành một palindrome. Nếu từ đã là một từ đối xứng hoặc không có giải pháp nào, hãy trả về -1. Nếu không, hãy trả lại chỉ mục của ký tự cần xóa.

// Đầu vào
// Dòng đầu tiên chứa số nguyên q, số truy vấn.

// Mỗi q dòng tiếp theo chứa một chuỗi truy vấn s.

// Đầu ra
// chỉ mục của ký tự để loại bỏ hoặc -1

#include <iostream>
using namespace std;

bool check(string const & s, int i, int j) {
    for (; i < j; ) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int i=0, j=s.length()-1;
        for (; i < j && s[i] == s[j];) {
            ++i; --j;
        }
        if (i >= j) {
            cout << -1 << endl;
        } else if (check(s, i+1, j)) cout << i << endl;
        else cout << j << endl;
    }
}

/*--------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    int len = s.length();
    for (int i=0; i<len/2; i++){
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

int find_index_to_remove(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            if (is_palindrome(str.substr(left, right - left))) {
                return right;
            }
            else if (is_palindrome(str.substr(left + 1, right - left))) {
                return left;
            }
            else {
                return -1;
            }
        }
        left++;
        right--;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    while (n--){
        string str; cin >> str;
        int index_to_remove = find_index_to_remove(str);
        if (index_to_remove != -1) {
            cout << index_to_remove << endl;
        }
        else {
            cout << "-1" << endl;
        }        
    }
    return 0;
}