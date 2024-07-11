/*
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

Constraints:
1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                current += c;
            }
        }

        return current;
    }
};


// Not optimal 
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (auto &c: s) {
            if (c != ')') st.push(c);
            else {
                string s;
                while (st.top() != '(') {
                    s += st.top();
                    st.pop();
                }
                st.pop();
                cout << s << endl;
                for (auto &k: s) st.push(k);
            }
        }
        string ans;
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            if (ch == '(' || ch == ')') continue;
            ans = ch + ans;
        }
        return ans;
    }
};