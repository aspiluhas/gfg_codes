class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;
        // Code here
        queue<Node *> q;
        q.push(root);

        bool lefttoright = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                int index = lefttoright ? i : size - i - 1;
                ans[index] = node->data;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            lefttoright = !lefttoright;
            for (auto it : ans)
            {
                result.push_back(it);
            }
        }
        return result;
    }
};