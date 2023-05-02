#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
private:
    TreeNode *root;

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else if (val > node->val) node->right = insert(node->right, val);
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* remove(TreeNode* node, int val) {
        if (!node) return NULL;
        if (val < node->val) node->left = remove(node->left, val);
        else if (val > node->val) node->right = remove(node->right, val);
        else {
            if (!node->left) {
                TreeNode* right = node->right;
                delete node;
                return right;
            }
            else if (!node->right) {
                TreeNode* left = node->left;
                delete node;
                return left;
            }
            else {
                TreeNode* minRight = findMin(node->right);
                node->val = minRight->val;
                node->right = remove(node->right, minRight->val);
            }
        }
        return node;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int op, operand;
    cin >> op >> operand;
    while (op != -1) {
        if (op == 0) bst.insert(operand);
        else if (op == 1) bst.remove(operand);
        cin >> op >> operand;
    }
    bst.inorder();
    return 0;
}
