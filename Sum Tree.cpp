class Solution
{
public:
    pair<bool, int> sumtree(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = sumtree(root->left);
        pair<bool, int> rightAns = sumtree(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        int leftSum = leftAns.second;
        int rightSum = rightAns.second;

        bool condn = root->data == leftSum + rightSum;

        pair<bool, int> ans;

        if (isLeftSumTree && isRightSumTree && condn)
        {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node *root)
    {
        // Your code here

        return sumtree(root).first;
    }
};