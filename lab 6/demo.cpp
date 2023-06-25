#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(char data) {
    TreeNode* newNode = new TreeNode();
    if (!newNode) {
        cout << "Memory error!\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* buildBinaryTree(string postfix) {
    stack<TreeNode*> st;
    TreeNode *t, *t1, *t2;

    for (int i = 0; i < postfix.length(); ++i) {
        if (isalnum(postfix[i])) {
            t = createNode(postfix[i]);
            st.push(t);
        } else {
            t = createNode(postfix[i]);
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

void preOrderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

int evaluatePostfix(string postfix) {
    stack<int> st;
    int result;

    for (int i = 0; i < postfix.length(); ++i) {
        if (isdigit(postfix[i])) {
            st.push(postfix[i] - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (postfix[i]) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }
    result = st.top();
    st.pop();
    return result;
}

int main() {
    string postfix = "85-42+3/*";

    TreeNode* root = buildBinaryTree(postfix);

    cout << "Prefix form: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Infix form: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Postfix form: ";
    postOrderTraversal(root);
    cout << endl;

    int result = evaluatePostfix(postfix);
    cout << "Postfix expression value: " << result << endl;

    return 0;
}
