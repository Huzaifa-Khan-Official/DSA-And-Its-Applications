// #include <bits/stdc++.h>
// using namespace std;

// int precedence(char ch) {
//     switch (ch) {
//         case '-':
//         case '+':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         default:
//             return -1;
//     }
// }

// bool isOperand(char ch) {
//     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
// }

// string infixToPostfix(string infix) {
//     int n = infix.size();
//     stack<char> st;
//     string postfix;
    
//     for (int i = 0; i < n; i++) {
//         cout << "Step " << i + 1 << endl;
        
//         if (postfix.length() > 0) {
//             cout << "Postfix ==> " << postfix << endl;
//         } else {
//             cout << "Stack is empty." << endl;
//         }
        
//         // Printing current stack
//         if (!st.empty()) {
//             cout << "Stack ==> ";
//             stack<char> temp = st;
//             while (!temp.empty()) {
//                 cout << temp.top() << ", ";
//                 temp.pop();
//             }
//             cout << endl;
//         } else {
//             cout << "Stack is empty." << endl;
//         }
//         cout << endl;
        
//         if (isOperand(infix[i])) {
//             // Step 2: Operand
//             postfix.push_back(infix[i]);
//         } else if (infix[i] == '(') {
//             // Step 3: Left parenthesis
//             st.push('(');
//         } else if (infix[i] == ')') {
//             // Step 4: Right parenthesis
//             while (st.top() != '(') {
//                 postfix.push_back(st.top());
//                 st.pop();
//             }
//             st.pop();  // Pop the '('
//         } else {
//             // Step 5: Operator
//             while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(infix[i])) {
//                 postfix.push_back(st.top());
//                 st.pop();
//             }
//             st.push(infix[i]);
//         }
//     }
    
//     // Pop all remaining operators in stack
//     while (!st.empty()) {
//         postfix.push_back(st.top());
//         st.pop();
//     }

//     return postfix;
// }

// int main() {
//     string infix = "a*(b*c/(x+y)-(a*d-5)+b)-5*x";
//     string postfix = infixToPostfix(infix);
//     cout << "Infix expression: " << infix << endl;
//     cout << "Postfix expression: " << postfix << endl;
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

// TreeNode structure for the expression tree
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to return precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

// Function to check if the character is an operand (a-z or A-Z)
bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;   // Stack to hold operators
    string postfix;   // Resultant postfix expression
    
    for (int i = 0; i < infix.size(); i++) {
        
        // If the current character is an operand, add it to the postfix expression
        if (isOperand(infix[i])) {
            postfix.push_back(infix[i]);
        }
        // If the current character is '(', push it to the stack
        else if (infix[i] == '(') {
            st.push('(');
        }
        // If the current character is ')', pop from stack until '(' is found
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();  // Pop the '(' from the stack
        }
        // If the current character is an operator
        else {
            // Pop operators from the stack while they have higher or equal precedence
            while (!st.empty() && precedence(st.top()) >= precedence(infix[i]) && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            // Push the current operator to the stack
            st.push(infix[i]);
        }
    }
    
    // Pop any remaining operators in the stack and add them to postfix
    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}

// Function to build the expression tree from a postfix expression
TreeNode* buildExpressionTree(string postfix) {
    stack<TreeNode*> st;
    
    for (char ch : postfix) {
        if (isOperand(ch)) {
            // Create a new node for the operand and push it to the stack
            st.push(new TreeNode(string(1, ch)));
        }
        else {
            // Create a new node for the operator
            TreeNode* node = new TreeNode(string(1, ch));
            
            // Pop two nodes from the stack (right and left operands)
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            
            // Push the operator node back to the stack
            st.push(node);
        }
    }
    
    // The stack will have one element, which is the root of the expression tree
    return st.top();
}

// Function to print the expression tree in inorder fashion
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

// Function to print the expression tree in postfix fashion
void postfixTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postfixTraversal(root->left);
    postfixTraversal(root->right);
    cout << root->value << " ";
}

int main() {
    string infix = "a*(b+c)";
    
    // Step 1: Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    
    // Step 2: Build the expression tree from postfix
    TreeNode* root = buildExpressionTree(postfix);
    
    // Step 3: Print the expression tree in different ways
    cout << "Inorder traversal of expression tree: ";
    inorderTraversal(root);  // Inorder gives us the infix expression
    cout << endl;
    
    cout << "Postorder traversal of expression tree: ";
    postfixTraversal(root);  // Postorder gives us the postfix expression
    cout << endl;
    
    return 0;
}

