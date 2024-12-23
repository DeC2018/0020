#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (const char c : s) {
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.empty() || pop(stack) != c)
                return false;
        }

        return stack.empty();
    }

private:
    char pop(std::stack<char>& stack) {
        const char c = stack.top();
        stack.pop();
        return c;
    }
};

int main() {
    Solution solution;
    std::string input1 = "()";
    std::string input2 = "()[]{}";
    std::string input3 = "(]";
    std::string input4 = "([])";

    std::cout << "Example 1: " << (solution.isValid(input1) ? "true" : "false") << std::endl;
    std::cout << "Example 2: " << (solution.isValid(input2) ? "true" : "false") << std::endl;
    std::cout << "Example 3: " << (solution.isValid(input3) ? "true" : "false") << std::endl;
    std::cout << "Example 4: " << (solution.isValid(input4) ? "true" : "false") << std::endl;

    return 0;
}