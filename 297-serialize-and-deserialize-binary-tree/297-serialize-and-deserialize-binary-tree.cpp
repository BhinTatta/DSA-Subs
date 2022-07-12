/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string str = "";
        if(!root) return str;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==nullptr) str.append("#,");
            
            if(curr){
                str.append(to_string(curr->val) + ',');
                q.push(curr->left);
                q.push(curr->right);
            }
                
            }
        
        //str.pop_back();
        //cout<<str<<endl;
        return str;
    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s , str , ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            getline(s , str , ',');
            if(str=="#"){
                curr->left = nullptr;
            }
            else{
                TreeNode* lcurr = new TreeNode(stoi(str));
                curr->left = lcurr;
                q.push(lcurr);
            }
            getline(s , str , ',');
            //cout<<str<<endl;
            if(str=="#"){
                curr->right = nullptr;
            }
            else{
                TreeNode* rcurr = new TreeNode(stoi(str));
                curr->right = rcurr;
                q.push(rcurr);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));