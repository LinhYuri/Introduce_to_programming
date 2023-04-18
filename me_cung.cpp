// Bạn đột nhiên rơi vào một thế giới 2D được bố trí trên lưới có kích thước W∗H
// . Nhìn xung quanh, bạn nhận ra mình đang ở đâu đó ở hàng dưới cùng với tọa độ là (∗,1)
// . Có một số tảng đá trong các ô khác.

// Bạn nhận thấy những tảng đá đang rơi xuống với tốc độ không đổi là một đơn vị khoảng cách trên mỗi khoảng thời gian tăng dần. Tảng đá tại mỗi tọa độ (x,y)
//  tại lúc thời gian t
//  sẽ có tọa độ (x,y−1)
//  lúc t+1
// . Một tảng đá sẽ biến mất khỏi thế giới một khi y
//   trở thành 0.

// Tại mỗi thời điểm, bạn phải chọn hoặc giữ nguyên vị trí, hoặc di chuyển sang trái hoặc sang phải để tránh bị đè bẹp bởi những tảng đá rơi xuống. Giống như những tảng đá, bạn chỉ có thể di chuyển một đơn vị khoảng cách trong mỗi khoảng thời gian. Nếu vị trí của bạn tại thời điểm t
//  là (x,1)
// , thì bạn có thể ở tại (x,1)
// , chuyển đến (x+1,1)
//  hoặc chuyển đến (x−1,1)
// . Ô chuyển đến phải tồn tại trong phạm vi W
//  và không được chiếm bởi một tảng đá ở cả hai thời điểm t
//  và t+1
// .
// Lưu ý: Đây là một thế giới nơi thời gian rời rạc.

// Đầu vào
// Dòng đầu tiên chứa hai số nguyên cách nhau bởi dấu cách, W
//  và H
// .

// Mỗi H
//  dòng đầu vào tiếp theo chứa W
//  ký tự mô tả một hàng trong lưới. Ký tự thứ j
//  của dòng thứ i
//  xác định trạng thái của ô tại tọa độ (i,j)
// . Các mô tả ký tự như sau:

// R cho biết vị trí đó có chứa đá.
// Y cho biết bạn đang chiếm vị trí đó.
// E cho biết vị trí đó là một ô trống.
// Ràng buộc: 1≤W,H≤1000
// Đầu ra
// In ra YES nếu bạn có thể tránh va vào bất kỳ tảng đá nào. Nếu không, in NO.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, h; cin >> w >> h;
    vector<string> a(h);
    for (auto & i : a) cin >> i;
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == 'R') continue;
            for (int k = -1; k < 2; ++k) {
                int new_j = j + k;
                if (new_j < 0 || new_j >= w) continue;
                if (a[i-1][new_j]=='Y' && a[i-1][j] != 'R')
                    a[i][j] = 'Y';
            }
        }
    }
    int cnt = 0;
    for (auto i : a[h-1]) cnt += i == 'Y';
    if (cnt) cout << "YES";
    else cout << "NO";
}