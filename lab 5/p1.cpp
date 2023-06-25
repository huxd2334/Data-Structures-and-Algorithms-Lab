#include <bits/stdc++.h>
using namespace std;

struct NODE {
    char data;
    NODE* left;
    NODE* right;
};

NODE *createNODE (char);
NODE *create_tree(string postfix);
void pre_order_traversal(NODE *);
void in_order_traversal(NODE *);
void post_order_traversal(NODE *);
float evaluate_postfix(string);

int main() {
    string postfix = "85-42+3/*";

    NODE* tree = create_tree(postfix);

    cout << "\na.Prefix form:\t";
    pre_order_traversal(tree);

    cout << "\nb.Infix form:\t";
    in_order_traversal(tree);

    cout << "\nc.Postfix form:\t";
    post_order_traversal(tree);

    float result = evaluate_postfix(postfix);
    cout << "\nd.Value of the postfix expression: " << result << endl;

    return 0;
}

NODE *createNODE(char data) {
    NODE *ptr = new NODE();
    if (!ptr) {
        cout << "Memory error!\n";
        return NULL;
    }
    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

NODE *create_tree(string postfix) {
    stack<NODE*> st;
    NODE *t, *t1, *t2;

    for (int i = 0; i < postfix.length(); ++i) {
        if (isdigit(postfix[i])) {
            t = createNODE(postfix[i]);
            st.push(t);
        } else {
            t = createNODE(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}

void pre_order_traversal(NODE* root) {
    if (root) {
        cout << root->data << " ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void in_order_traversal(NODE* root) {
    if (root) {
        in_order_traversal(root->left);
        cout << root->data << " ";
        in_order_traversal(root->right);
    }
}

void post_order_traversal(NODE* root) {
    if (root) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->data << " ";
    }
}

float evaluate_postfix(string postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.size(); ++i) {
         
        if (isdigit(postfix[i]))
            st.push(postfix[i] - '0');
 
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (postfix[i]) {
            case '+':
                st.push(op2 + op1);
                break;
            case '-':
                st.push(op2 - op1);
                break;
            case '*':
                st.push(op2 * op1);
                break;
            case '/':
                st.push(op2 / op1);
                break;
            }
        }
    }
    return st.top();
}


