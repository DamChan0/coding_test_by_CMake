#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 괄호 문자열이 올바른지 확인하는 함수
bool isValid(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false; // 스택이 비어있는 경우
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // 괄호의 짝이 맞지 않는 경우
            }
        }
    }

    return st.empty(); // 스택이 비어있어야 올바른 괄호 문자열
}

// 주어진 문자열을 회전시켜 올바른 괄호 문자열이 되는 경우의 수를 찾는 함수
int solution(const string& s) {
    int count = 0;
    int len = s.length();

    // 문자열을 회전시켜가며 올바른 괄호 문자열인지 확인
    for (int i = 0; i < len; i++) {
        string rotated = s.substr(i) + s.substr(0, i); // 회전된 문자열 생성
        if (isValid(rotated)) count++;
    }

    return count;
}

int main() {
    string s1 = "[](){}";
    string s2 = "}]()[{";
    string s3 = "[)(]";
    string s4 = "}}}";

    cout << "Result 1: " << solution(s1) << endl; // Expected output: 3
    cout << "Result 2: " << solution(s2) << endl; // Expected output: 2
    cout << "Result 3: " << solution(s3) << endl; // Expected output: 0
    cout << "Result 4: " << solution(s4) << endl; // Expected output: 0

    return 0;
}
