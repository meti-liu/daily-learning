#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifs("C:/Users/刘博瑞/OneDrive/桌面/code/2024.10/in.txt");  // 或者尝试提供完整路径
    if (!ifs.is_open()) {
        cout << "Failed to open input file!" << endl;
        return 1;
    } else {
        cout << "File opened successfully!" << endl;
    }

    return 0;
}
