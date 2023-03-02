// .Write a program to check if a given bracket sequence is valid or not. The sequence will contain 3 types of brackets -> First Bracket ( ) , Second Bracket { } and Third Bracket [ ]. You can use builtin Stack for this problem.		      10

// Input
// Output
// {[][]()(())}
// Yes
// {[][]()(()))}
// No
// {[](})
// No

// ------------- Solution -----------------------]
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_valid_bracket_sequence(const string& sequence) {
    stack<char> s;
    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            s.push(bracket);
        } else if (bracket == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            } else {
                s.pop();
            }
        } else if (bracket == '}') {
            if (s.empty() || s.top() != '{') {
                return false;
            } else {
                s.pop();
            }
        } else if (bracket == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.empty();
}

int main() {
    string sequence;
    cin >> sequence;
    if (is_valid_bracket_sequence(sequence)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}




