#include<iostream>
#include<fstream>
using namespace std;

void s(int a[], int n) {
    int* b = new int[n];  // 存储偶数
    int* c = new int[n];  // 存储奇数
    int even = 0, odd = 0;
    
    // 分离偶数和奇数
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[even] = a[i];  // 将偶数放入数组b
            even++;
        } else {
            c[odd] = a[i];   // 将奇数放入数组c
            odd++;
        }
    }
    
    // 将偶数数组b放回到a的前面
    for (int i = 0; i < even; i++) {
        a[i] = b[i];
    }
    
    // 将奇数数组c放回到a中，跟在偶数之后
    for (int i = 0; i < odd; i++) {
        a[even + i] = c[i];
    }
    
    // 释放动态分配的内存
    delete[] b;
    delete[] c;
}

int main() {
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");
    
    if (!ifs.is_open()) {
        cout << "Failed to open input file!" << endl;
        return 1; // 错误码
    }
    
    if (!ofs.is_open()) {
        cout << "Failed to open output file!" << endl;
        return 1; // 错误码
    }
    
    int a[200];
    int n = 0;
    
    // 读取文件中的数据
    while (ifs >> a[n]) {
        cout << a[n] << " ";  // 输出每个读取的数值
        n++;
    }
    cout << endl;
    
    cout << "Number of elements read: " << n << endl;
    
    // 调用函数对数组进行处理
    s(a, n);
    
    // 将结果输出到文件
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";   // 输出到控制台进行调试
        ofs << a[i] << " ";    // 写入结果到文件
    }
    cout << endl;

    // 关闭文件
    ifs.close();
    ofs.close();
    
    return 0;
}
