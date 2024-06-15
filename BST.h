#include "vector"
#include "functional"
#include "stack"
#include "iostream"
using namespace std;
template<typename T>
struct TreeNode{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
class bst {
private:
    TreeNode<T>* root;
    TreeNode<T>* insert_recursion(TreeNode<T>* root, const T& val) {
        if(!root) {
            TreeNode<T>* root = new TreeNode(val);
            return root;
        }
        if(val < root->val) {
            root->left = insert_recursion(root->left, val);
        } else {
            root->right = insert_recursion(root->right, val);
        }
        return root;
    }
    TreeNode<T>* deleteNode(TreeNode<T>* root, const T& key) {
        if(root) {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            }
            else {
                if (!root->left && !root->right) return nullptr;
                if (!root->left || !root->right) {
                    return root->left ? root->left : root->right;
                }
                TreeNode<T> *temp = root->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
    TreeNode<T>* search_recursion(TreeNode<T>* root, const T& val) {
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;

        if(val < root->val) root = search_recursion(root->left, val);
        else root = search_recursion(root->right, val);

        return root;
    }
    TreeNode<T>* extractSubtree_rec(TreeNode<T>* root, const T& val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) {

            TreeNode<T>* newRoot = new TreeNode<T>(root->val);
            newRoot->left = root->left;
            newRoot->right = root->right;

            delete root;
            return newRoot;
        } else {
            TreeNode<T>* leftSubtree = extractSubtree_rec(root->left, val);
            if (leftSubtree != nullptr) return leftSubtree;
            TreeNode<T>* rightSubtree = extractSubtree_rec(root->right, val);
            return rightSubtree;
        }
    }
    void inorder(TreeNode<T>* node, vector<T>& res) {
        if (!node) {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
    void klp_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        klp_rec(root->left, res);
        klp_rec(root->right, res);
    }
    void kpl_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        kpl_rec(root->right, res);
        kpl_rec(root->left, res);
    }
    void plk_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        plk_rec(root->right, res);
        res.push_back(root->val);
        plk_rec(root->left, res);
    }
    void pkl_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        pkl_rec(root->right, res);
        res.push_back(root->val);
        pkl_rec(root->left, res);
    }
    void lpk_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        lpk_rec(root->left, res);
        lpk_rec(root->right, res);
        res.push_back(root->val);
    }
    void lkp_rec(TreeNode<T>* root, vector<T>& res){
        if(root == nullptr) return;
        lkp_rec(root->left, res);
        res.push_back(root->val);
        lkp_rec(root->right, res);
    }
public:
    bst(const vector<T>& array) : root(nullptr) {
        for (T elem: array) {
            this->insert(elem);
        }
    }
    bst() : root(nullptr) {}
    T getroot(){
        if(root == nullptr){
            throw out_of_range("Out of range");
        }
        return root->val;
    }
    void insert(const T& val) {
        root = insert_recursion(root, val);
    }
    void delete_element(const T& val){
        root = deleteNode(root, val);
    }
    TreeNode<T>* search(const T& val){
        return search_recursion(root, val);
    }
    vector<T> inorderTraversal() {
        vector<T> res;
        inorder(root, res);
        return res;
    }
    bst<T> map(function<T(const T&)> func){
        bst<T> new_root; //*
        vector<T> v = inorderTraversal();
        for(T elem : v){
            new_root.insert(func(elem));
        }
        return new_root;
    }

    bst<T> where(function<bool(const T&)> func){
        bst<T> new_root; //*
        vector<T> v = inorderTraversal();
        for(T elem : v){
            if(func(elem)){
                new_root.insert(elem);
            }
        }
        return new_root;
    }
    T reduce(std::function<T(const T&, const T&)> func, const T& c) {
        T res = c;
        vector<T> v = inorderTraversal();
        for(T elem : v){
            res = func(elem, res);
        }
        return res;
    }

    const vector<T>& klp(){
        vector<T> res;
        klp_rec(root, res);
        return res;
    }
    vector<T> kpl(){
        vector<T> res;
        kpl_rec(root, res);
        return res;
    }
    vector<T> lpk(){
        vector<T> res;
        lpk_rec(root, res);
        return res;
    }
    vector<T> lkp(){
        vector<T> res;
        lkp_rec(root, res);
        return res;
    }
    vector<T> pkl(){
        vector<T> res;
        pkl_rec(root, res);
        return res;
    }
    vector<T> plk(){
        vector<T> res;
        plk_rec(root, res);
        return res;
    }
    bst<T> extractSubtree(const T& val) {
        bst<T> newTree;
        TreeNode<T>* subtreeRoot = extractSubtree_rec(root, val);
        if (subtreeRoot != nullptr) {
            newTree.root = subtreeRoot;
        }
        return newTree;
    }
};