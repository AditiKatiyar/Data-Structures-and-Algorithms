/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int isMirror(TreeNode* A, TreeNode* B) {
    if (A == NULL && B == NULL) {
        return 1;
    }
    
    if ((A == NULL && B != NULL) || (A != NULL && B == NULL)) {
        return 0;
    }
    
    if (A->val == B->val) {
        return isMirror(A->left, B->right) & isMirror(A->right, B->left);
    }
    
    return 0;
}
 
/**
 * check if both trees are symmetrical about center or root element.
 */
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A->left, A->right);
}

/**
 * check if both trees are identical.
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if (A == NULL && B == NULL) {
        return 1;
    }
    
    if ((A == NULL && B != NULL) || (A != NULL && B == NULL)) {
        return 0;
    }
    
    if (A != NULL && B != NULL && A->val == B->val) {
        return isSameTree(A->left, B->left) & isSameTree(A->right, B->right);
    }
    
    return 0;
}