class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (r1 == 0 && r2 == 0)
            return true;
        if (r1 == 0 && r2 != 0)
            return false;
        if (r1 != 0 && r2 == 0)
            return false;

        bool leftans = isIdentical(r1->left, r2->left);
        bool rightans = isIdentical(r1->right, r2->right);

        bool ans = r1->data == r2->data;

        if (leftans && rightans && ans)
            return true;
        else
            return false;
    }
};