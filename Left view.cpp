 void revpre(Node* root, int level, vector<int>&ans)
    {
        if(root==0)
        return;

        if(ans.size()==level)
        ans.push_back(root->data);

        revpre(root->left,level+1,ans );
        revpre(root->right,level+1,ans );

    }
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int>ans;
        if(root==0)
        return ans;

        revpre(root,0,ans);
        return ans;
}