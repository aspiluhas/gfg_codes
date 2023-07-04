class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==0)
        return ans;
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto i= q.front();
            q.pop();
            
            auto node= i.first;
            int line=i.second;
            
            // if(mp.find(line)==mp.end())
            mp[line]=node->data;
            
            if(node->left)
            q.push({node->left, line-1});
            
            if(node->right)
            q.push({node->right, line+1});
        }
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }

};