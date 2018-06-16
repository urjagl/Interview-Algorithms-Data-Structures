vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[n-1]=1;
        
        for(int i=1;i<n;i++)
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
        
        for(int i=n-2;i>=0;i--)
            fromLast[i]=fromLast[i+1]*nums[i+1];
        
        vector<int> res(n);
        for(int i=0;i<n;i++)
            res[i]=fromBegin[i]*fromLast[i];
        
        return res;
    }
//Construct a temp array left such that left[i] contains the product of all elements on left of arr[i] excluding arr[i]
//Construct another temporary array right such that right[i] contains the product of all elements on right of arr[i] excluding arr[i]
// To get the product, multiply left and right


    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> result(n,1);
        for(int i= 0; i< n; i++){
            result[i] = result[i]*fromBegin;
            fromBegin = fromBegin* nums[i];
            result[n-1-i] = result[n-1-i] * fromLast;
            fromLast = fromLast * nums[n-1-i];
        }
        return result;
    }

// Two Sum 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::unordered_map<int,int> indices;
        for(int i = 0; i < nums.size(); ++i){
            indices[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i){
            int lookfor = target - nums[i];
            if(indices.find(lookfor) != indices.end() && indices[lookfor] != i){
                result.emplace_back(i);
                result.emplace_back(indices[lookfor]);
                break;
            }
        }
        return result;
    }

// Reverse Linked List
 ListNode* reverseList(ListNode* head) {
        ListNode *prev;
        ListNode *curr;
        ListNode *temp;
        prev = NULL;
        curr = head;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }

// Delete the node from a linked list, given only an access to the node
 void deleteNode(ListNode* node) {
        node->val = node->next->val;
   node->next = node->next->next;
        
    }

//Level Order Traversal:

vector<vector<int>> ret;
void buildVector(TreeNode *root, int depth){
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());
    
    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}

//Hamming weight:

 int hammingWeight(uint32_t n) {
        int count = 0;
        while (n)
    {
        if((n & 1) == 1)
            count++;
        n = n >> 1;
    }
    return count;
}

// Ransome Note 

bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> mag;
        for(auto c: magazine){
            mag[c]++;
        }
        for (auto c: ransomNote){
            if(mag[c] == 0){
                return false;
            }
            else{
                mag[c]--;
            }
        }
        return true;
    }


//Peeking Iterator:
class PeekingIterator : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
    }

    int peek() {
        return m_next;
    }

    int next() {
        int t = m_next;
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
        return t;
    }

    bool hasNext() const {
        return m_hasnext;
    }
};

//Fib stairs
int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }

//  Lowest common ancestor of given nodes. 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
       if (!root || !p || !q) {
           return NULL;
       }
       
       if (root == p || root == q) {
           return root;
       }
       
       TreeNode* l = lowestCommonAncestor(root->left, p, q);
       TreeNode* r = lowestCommonAncestor(root->right, p, q);
       
       if (l && r) {
           return root;
       }
       
       return l? l : r;
       }

// Merge two sorted linked Lists:
       ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        if(l1==NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        
        while (l1 && l2){
            if (l1->val < l2->val){
                curr = new ListNode(l1->val);
                curr->next = NULL;
                l1 = l1->next;
            }else{
                curr = new ListNode(l2->val);
                curr->next = NULL;
                l2 = l2->next;
            }
            if(head == NULL){
                head = curr;
            }
            else{
                prev->next = curr;
            }
            prev = curr;
            if(l1==NULL)
                curr = l2;
            prev->next = curr;
            if(l2==NULL)
                curr = l1;
            prev->next = curr;
            
        }
        return head;
    }

// A simple atoi() function
int myAtoi(char *str)
{
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
      
    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;  
        i++;  // Also update index of first digit
    }
      
    // Iterate through all digits and update the result
    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
    
    // Return result with sign
    return sign*res;
}
  
// Driver program to test above function
int main()
{
    char str[] = "-123";
    int val = myAtoi(str);
    printf ("%d ", val);
    return 0;
}

// median of two sorted arrays:

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size(), n = nums2.size();
        if (m + n == 0) {
            return 0.0;
        }
        int k = (m + n) / 2;
        size_t p = 0, q = 0;
        int res = 0, last = res, c = -1;
        while (p < m && q < n && c < k) {
            last = res;
            if (nums1[p] < nums2[q]) {
                res = nums1[p++];
            } else {
                res = nums2[q++];
            }
            ++c;
        }
        while (p < m && c < k) {
            last = res;
            res = nums1[p++];
            ++c;
        }
        while (q < n && c < k) {
            last = res;
            res = nums2[q++];
            ++c;
        }
        if (((m + n) & 0x1) == 1) {
            return res;
        } else {
            return (last + res) / 2.0;
        }
    }

//reverse words in a string 
void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }




// Rotated matrix
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }

// trapping rainwater

int findWater(int arr[], int n)
{
    // initialize output
    int result = 0;
     
    // maximum element on left and right
    int left_max = 0, right_max = 0;
     
    // indices to traverse the array
    int lo = 0, hi = n-1;
     
    while(lo <= hi) 
    {
        if(arr[lo] < arr[hi])
        {
            if(arr[lo] > left_max)
            // update max in left
            left_max = arr[lo];
            else
            // water on curr element = max - curr
            result += left_max - arr[lo];
            lo++;
        }
        else
        {
            if(arr[hi] > right_max)
            // update right maximum
            right_max = arr[hi];
            else
            result += right_max - arr[hi];
            hi--;
        }
    }
     
    return result;
}
 
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
        << findWater(arr, n); 
}

// Priority queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue <int> q;
        
        for (int n : nums) {
            q.push (n);
        }
        
         for (int i =0;i<k-1; i++) {
             q.pop();
         }
        return q.top();
    }
};


// Using multi set 
int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        int n = nums.size();
        for (int i = 0; i < n; i++) { 
            mset.insert(nums[i]);
            if (mset.size() > k)
                mset.erase(mset.begin());
        }
        return *mset.begin();
    }
