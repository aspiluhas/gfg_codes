class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    pair<bool, int> balance(Node *root)
    {
        if (root == 0)
        {
            return {true, 0};
        }

        pair<bool, int> left = balance(root->left);
        pair<bool, int> right = balance(root->right);

        bool leftans = left.first;
        bool rightans = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (leftans && rightans && diff)
        {
            ans.first = true;
        }
        else
            ans.first = false;

        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return balance(root).first;
    }
};
