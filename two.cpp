class solver
{
private:

public:
    void printkdistanceNodeDown(Node *root, int k,vector<int> &v) 
{ 
    if (root == NULL || k < 0)
    return;
    if (k==0) 
    { 
        v.push_back(root->data); 
        return; 
    }
    printkdistanceNodeDown(root->left, k-1,v); 
    printkdistanceNodeDown(root->right, k-1,v); 
} 
int printkdistanceNode(Node* root, int target , int k,vector<int> &v) 
{ 
    if (root == NULL) 
    return -1; 
    if (root->data == target) 
    { 
        printkdistanceNodeDown(root, k,v); 
        return 0; 
    }
    int dl = printkdistanceNode(root->left, target, k,v); 
    if (dl != -1) 
    { 
         if (dl + 1 == k) 
            v.push_back(root->data);  
         else
            printkdistanceNodeDown(root->right, k-dl-2,v); 
  
         return 1 + dl; 
    }
 int dr = printkdistanceNode(root->right, target, k,v); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            v.push_back(root->data);  
         else
            printkdistanceNodeDown(root->left, k-dr-2,v); 
         return 1 + dr; 
    } 
  
    return -1; 
} 
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
      vector<int>v;
       int a= printkdistanceNode(root,target,k,v);
       sort(v.begin(),v.end());
    return v;  
    }
};  