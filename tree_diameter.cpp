

int max1=0;
int height(struct Node *root)
{
    if(root==NULL) return 0;
    //Height of left subtree
    int v_left=height(root->left);
    //Height of right subtree
    int v_right=height(root->right);
    //Modification is done in height function to get the diameter of tree
    //left_subtree+right_subtree+1
    if((v_left+v_right+1)>max1) max1=v_left+v_right+1;
    return max(v_left,v_right)+1;
}

// Function to return the diameter of a Binary Tree.
int diameter(struct Node* root) {
    // code here
    int result;
    height(root);
    result=max1;
    max1=0;
    return result;
}
