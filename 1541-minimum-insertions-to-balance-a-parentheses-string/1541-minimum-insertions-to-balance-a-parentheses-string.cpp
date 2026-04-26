class Solution {
public:
    int minInsertions(string s) {
        stack<char> stack;
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push('(');
            } else {
                if (stack.empty()) {
                    if (i != s.length() - 1 && s[i + 1] == ')') {
                        count++;
                        i++;
                    } else {
                        count += 2;
                    }
                } else {
                    if (i != s.length() - 1 && s[i + 1] == ')') {
                        stack.pop();
                        i++;
                    } else {
                        count++;
                        stack.pop();
                    }
                }
            }
        }

        return count + stack.size() * 2;
    }
};