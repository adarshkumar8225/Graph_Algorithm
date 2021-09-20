    int result=1;
    int height(struct Node *root)
    {
        if(root==NULL) return 0;
        //Height of left subtree
        int v_left=height(root->left);
        //Height of right subtree
        int v_right=height(root->right);
        
        //If difference of height in left and right subtree>1 
        //In that case make result as 0 since it is not balanced
        if(abs(v_left-v_right)>1) result=0;
        return max(v_left,v_right)+1;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        height(root);
        int val=result;
        result=1;
        return val;
    }
