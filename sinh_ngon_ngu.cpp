// Cho một bảng chữ cái của ngôn ngữ X với thứ tự từ điển là thứ tự cho trong input. Viết chương trình liệt kê tất cả các từ độ dài 2 hoặc 3 theo thứ tự từ điển của ngôn ngữ X
// Giới hạn: có tối đa 25 chữ cái là các chữ cái a..z hoặc chữ số 0..9

// Input: Một chuỗi tối đa 25 kí tự là các chữ cái từ a đến z hoặc chữ số từ 0 đến 9, thể hiện từ điển của ngôn ngữ X
// Output: Một dòng liệt kê tất cả các từ có độ dài 2 hoặc 3 theo thứ tự từ điển của ngôn ngữ X


#include<iostream>

using namespace std;

string input_string;

void print(string output_string){
    cout << output_string << ' ';
}

void fill(int n, string output_string){
    if(n == 2)  print(output_string);
    if(n == 3){
        print(output_string);
        return;
    }
    for(int i = 0; i <(int) input_string.size(); i++){
        output_string += input_string[i];
        fill(n + 1, output_string);
        output_string.pop_back();
    }
}

int main(){
    cin >> input_string;
    fill(0, "");
}