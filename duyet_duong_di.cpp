// Viết chương trình tìm đường ra khỏi mê cung kích thước n×m
// Biết ta chỉ có thế đi ngang hoặc dọc trong mê cung và không đi lại các ô đã đi qua.
// Input:
// Dòng đầu tiên chứa 2 số nguyên dương n và m là số hàng và số cột của mê cung, n dòng tiếp theo mỗi dòng chứa m số 0 hoặc 1
// Nếu giá trị của một ô là 0 ô đó có thể đi qua, nếu là 1 ô đó không thể đi qua
// Output:
// Tìm đường đi từ góc trái trên xuống góc phải dưới, in ra màn hình mê cung với các ô trong đường đi được đánh số 2


#include<iostream>
using namespace std;

int const MAX_N = 100;
int n, m, maze[MAX_N][MAX_N];

void inputMaze(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
}

bool isValidMove(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == 0;
}

void Mark(int x, int y){
    maze[x][y] = 2;
}

void unMark(int x, int y){
    maze[x][y] = 0;
}

void printMaze(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

bool solveMaze(int x, int y){
    if(x == n - 1 && y == m - 1){
        Mark(x, y);
        printMaze();
        return true;
    }
    if(isValidMove(x, y)){
        Mark(x, y);
        if(solveMaze(x, y + 1))   return true;
        if(solveMaze(x - 1, y))   return true;
        if(solveMaze(x, y - 1))   return true;
        if(solveMaze(x + 1, y))   return true;
        unMark(x, y);
    }
    return false;
}
