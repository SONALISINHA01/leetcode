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
    void ser(TreeNode* root,string& ans){
        if(root==nullptr){
            ans+="null ";
            return;
        }
        ans+=to_string(root->val);
        ans += " ";
        ser(root->left,ans);
        ser(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        ser(root,ans);
        return ans;
    }
    TreeNode* tree(vector<string> &nodes,int &i){
        if(i>=nodes.size()){
            return nullptr;
        }
        if(nodes[i]=="null"){
            i++;
            return nullptr;
        }
        TreeNode* ans = new TreeNode(stoi(nodes[i]));
        i++;
        ans->left=tree(nodes,i);
        ans->right = tree(nodes,i);
        return ans;

    }
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        int n =data.size();
        string temp="";
        TreeNode* ans;
        for(int i=0;i<n;i++){
            if(data[i]==' '){
                nodes.push_back(temp);
                temp="";
            }else{
                temp += data[i];
            }
        }
        int i=0;
        return tree(nodes,i);

    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));