#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Pair(string s)
{
    stack<char> st;

}

/*#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 判断括号是否匹配
bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

// 判断括号字符串是否有效
bool isValid(string s) {
    stack<char> st;  // 创建一个栈

    for (char c : s) {
        // 如果是左括号，入栈
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        // 如果是右括号，检查栈顶是否匹配
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !isMatchingPair(st.top(), c)) {
                return false;  // 不匹配或者栈为空，直接返回false
            }
            st.pop();  // 匹配成功，弹出栈顶
        }
    }

    // 如果遍历结束后栈为空，说明所有括号匹配
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string with brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "Brackets are balanced." << endl;
    } else {
        cout << "Brackets are not balanced." << endl;
    }

    return 0;
}*/
