#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

map<char, char> brackets = {
        {')', '('},
        {'}', '{'},
        {']', '['}
};

inline bool open_brackets(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

inline bool close_brackets(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool isCorrect(string& s)
{
    stack<char> st;
    for (auto ch : s) {
        if (open_brackets(ch)) st.push(ch);
        else if (close_brackets(ch)) {
            if (!st.empty() && st.top() == brackets[ch])
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cout << "Type the line:" << endl;
    cin >> s;

    isCorrect((s)) ? cout << "Correct" : cout << "Wrong";
    return 0;
}