class Solution
{
public:
    void left(Node *root, vector<int> &ans)
    {
        if (root == 0 || (root->left == 0 && root->right == 0))
            return;
        ans.push_back(root->data);

        if (root->left)
            left(root->left, ans);
        else
            left(root->right, ans);
    }
    void leaf(Node *root, vector<int> &ans)
    {
        if (root == 0)
            return;
        if (root->left == 0 && root->right == 0)
            ans.push_back(root->data);

        leaf(root->left, ans);

        leaf(root->right, ans);
    }
    void right(Node *root, vector<int> &ans)
    {
        if (root == 0 || (root->left == 0 && root->right == 0))
            return;

        if (root->right)
            right(root->right, ans);
        else
            right(root->left, ans);
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == 0)
            return ans;

        ans.push_back(root->data);

        left(root->left, ans);

        leaf(root->left, ans);

        leaf(root->right, ans);
        right(root->right, ans);

        return ans;
    }
};