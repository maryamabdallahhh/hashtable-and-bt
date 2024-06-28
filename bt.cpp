#include <iostream>
#include <algorithm>
#include <cmath>
 //problem1
// Define the TreeNode structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    int tree_max() const {
        if (root == nullptr) {
            throw std::runtime_error("Tree is empty");
        }
        return tree_max_helper(root);
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    int tree_max_helper(TreeNode* node) const {
        if (node == nullptr) {
            return std::numeric_limits<int>::min();
        }
        int left_max = tree_max_helper(node->left);
        int right_max = tree_max_helper(node->right);
        return std::max({ node->value, left_max, right_max });
    }
};
//problem2 
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    int tree_height() const {
        return tree_height_helper(root);
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    int tree_height_helper(TreeNode* node) const {
        if (node == nullptr) {
            return -1;
        }
        int left_height = tree_height_helper(node->left);
        int right_height = tree_height_helper(node->right);
        return std::max(left_height, right_height) + 1;
    }
};
//problem3
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    int total_nodes() const {
        return total_nodes_helper(root);
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    int total_nodes_helper(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        int left_count = total_nodes_helper(node->left);
        int right_count = total_nodes_helper(node->right);
        return 1 + left_count + right_count;
    }
};
//problem4
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    int total_leaf_nodes() const {
        return total_leaf_nodes_helper(root);
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    int total_leaf_nodes_helper(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        int left_leaf_count = total_leaf_nodes_helper(node->left);
        int right_leaf_count = total_leaf_nodes_helper(node->right);
        return left_leaf_count + right_leaf_count;
    }
};
//problem5
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    bool is_exists(int value) const {
        return is_exists_helper(root, value);
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    bool is_exists_helper(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        return is_exists_helper(node->left, value) || is_exists_helper(node->right, value);
    }
};
//problem6
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void add(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    bool is_perfect_recursive() const {
        int height = tree_height(root);
        return is_perfect_recursive_helper(root, height, 0);
    }

    bool is_perfect_formula_based() const {
        int height = tree_height(root);
        int node_count = total_nodes(root);
        int max_nodes = std::pow(2, height + 1) - 1;
        return node_count == max_nodes;
    }

private:
    TreeNode* root;

    void addHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    int tree_height(TreeNode* node) const {
        if (node == nullptr) {
            return -1;
        }
        int left_height = tree_height(node->left);
        int right_height = tree_height(node->right);
        return std::max(left_height, right_height) + 1;
    }

    int total_nodes(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + total_nodes(node->left) + total_nodes(node->right);
    }

    bool is_perfect_recursive_helper(TreeNode* node, int height, int level) const {
        if (node == nullptr) {
            return true;
        }
        // Check if node is a leaf
        if (node->left == nullptr && node->right == nullptr) {
            return level == height;
        }
        // Check if node has both children
        if (node->left == nullptr || node->right == nullptr) {
            return false;
        }
        return is_perfect_recursive_helper(node->left, height, level + 1) &&
            is_perfect_recursive_helper(node->right, height, level + 1);
    }
};


int main() {
    

    return 0;
}
