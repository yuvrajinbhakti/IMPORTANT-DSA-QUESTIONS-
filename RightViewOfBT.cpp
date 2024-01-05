//method 1 
void helper(Node *root, set<int> &s,vector<int> &ans,int currLevel){
    if(root==NULL) return ;

    if(s.find(currLevel) == s.end()){
        ans.push_back(root->data);
}
        s.insert(currLevel);
    if(root->right!=NULL){
    helper(root->right,s,ans,currLevel+1);
    }
    if(root->left!=NULL){
    helper(root->left,s,ans,currLevel+1);
    }
   
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    set<int> s;
    helper(root, s,ans,0);
    return ans;
}







//method 2 

//if we do level order traversal then t.c. - O(N), .s.c- O (N)
// if we do recursive traversal then t.c. - O(N), .s.c- O (Ht Of BT)

/*recursive way

for right view
f(node,level){  //initially node=root,level=0
    if(node==NULL) reutrn;
    if(level==ds.size())ds.add(node);   // it mean we come to this level for first time
    f(node->right,level+1);
    f(node->left,level+1);
}

for left view 
f(node,level){  //initially node=root,level=0
    if(node==NULL) reutrn;
    if(level==ds.size())ds.add(node);   // it mean we come to this level for first time
    f(node->left,level+1);
    f(node->right,level+1);
    }
*/

//right view
class Solution{
    vector<int> rightView(TreeNode* root){
        vector<int> ans;
        helper(root,0,ans);
        return ans;
    }
    public:
    void helper(TreeNode * root,int level,vector<int> &ans){
        if(root==NULL) return;
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);
    }
}
