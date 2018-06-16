// http://www.cplusplus.com/forum/beginner/131457/

// Without recursion: Inorder tree traversal
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

// Inorder Successor in BST 

// array to BST, BST to array 

//Tree search algorithms. Write BFS and DFS code,
//  explain run time and space requirements. Modify the code to handle trees with weighted edges and loops with BFS and DFS, make the code print out path to goal state.

// Findign the fifth maximum element in a BST

// Check if a BT is a BST 
class TreeNode{
public: 
	int key;
	TreeNode *left;
	TreeNode *right;

	TreeNode(key): key(key), left(NULL), right(NULL){};
}

bool isBST(TreeNode *t, int min, int max){
	if(t == NULL){
		return true;
	}
	if(t->key <= min || t->key > max){
		return false;
	}

	return isBST(t->left, min, t->key) && isBST(t->right, t->key , max);
}

bool isBST1(TreeNode *t){
	int min = INT_MIN;
	int max = INT_MAX;
	isBST(t, min, max);
}

// height of the tree:
int height(TreeNode *t){
	if(t == NULL){
		return 0;
	}
	return 1 + max(height(t->left), height(t->right));
}

// Height iteratively. 
int heightIterative(TreeNode *t){
	if(t == null){
		return 0;
	}
	queue<TreeNode *> q;
	q.push(t);
	int height = 0;

	while(1){
		int Nodecount = q.size();
		if(Nodecount == 0){
			return height;
		}
		height++;
		while(Nodecount > 0){
			TreeNode *t = q.front();
			q.pop();
			if(t->left != NULL) q.push(t->left);
			if(t->right != NULL) q.push(t->right);
			Nodecount--;
		}
	}
}

//sorted array to BST:
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}


// Find the k-th element in a bst 
void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;
 
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);
 
    // Increment count of visited nodes
    c++;
 
    // If c becomes k now, then this is the k'th largest 
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }
 
    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

// Finding the k-th smallest element in a BST
using namespace std;
 
// A BST node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A function to find
int KSmallestUsingMorris(Node *root, int k)
{
    // Count to iterate over elements till we
    // get the kth smallest number
    int count = 0;
 
    int ksmall = INT_MIN; // store the Kth smallest
    Node *curr = root; // to store the current node
 
    while (curr != NULL)
    {
        // Like Morris traversal if current does
        // not have left child rather than printing
        // as we did in inorder, we will just
        // increment the count as the number will
        // be in an increasing order
        if (curr->left == NULL)
        {
            count++;
 
            // if count is equal to K then we found the
            // kth smallest, so store it in ksmall
            if (count==k)
                ksmall = curr->key;
 
            // go to current's right child
            curr = curr->right;
        }
        else
        {
            // we create links to Inorder Successor and
            // count using these links
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
 
            // building links
            if (pre->right==NULL)
            {
                //link made to Inorder Successor
                pre->right = curr;
                curr = curr->left;
            }
 
            // While breaking the links in so made temporary
            // threaded tree we will check for the K smallest
            // condition
            else
            {
                // Revert the changes made in if part (break link
                // from the Inorder Successor)
                pre->right = NULL;
 
                count++;
 
                // If count is equal to K then we found
                // the kth smallest and so store it in ksmall
                if (count==k)
                    ksmall = curr->key;
 
                curr = curr->right;
            }
        }
    }
    return ksmall; //return t

//k-th smallest element (in order tranversal)
class Solution {
public:
int kthSmallest(TreeNode* root, int k) 
{
    vector<int> res;
    inOrderSearch(root,res,k);
    return res.back();
}
private:
void inOrderSearch(TreeNode* root,vector<int>& tmp,int k)
{
    if(root!=NULL)
    {
        inOrderSearch(root->left,tmp,k);
        if(tmp.size()<k) tmp.push_back(root->val);
        if(tmp.size()==k) return;
        inOrderSearch(root->right,tmp,k);
    }
}

};
- red-black tree 
- rotate a tree 

