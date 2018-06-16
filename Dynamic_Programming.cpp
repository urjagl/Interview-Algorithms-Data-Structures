// Fibonacci number:

int fib(int n){
	int a = 0;
	int b = 1;
	if(n == 0 || n == 1){
		return n;
	}
	else{
		for(int i = 2; i <=n ; i++){
			int c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}




// DP to solve max number 6, elements are {1,3,5}, 
// total number of ways I can form a number n. 

// Tabulation Method: Bottom Up: 
// initialize to -1
int dp[MAXN];
 
// this function returns the number of 
// arrangements to form 'n' 
int solve(int n)
{ 
  // base case
  if (n < 0)  
      return 0;
  if (n == 0)  
      return 1;
 
  // checking if already calculated
  if (dp[n]!=-1) 
      return dp[n];
 
  // storing the result and returning
  return dp[n] = solve(n-1) + solve(n-3) + solve(n-5);
}


// Longest Common Subsequence Problem solved using dynamic programming: memoization: 

int lcs(char* X, char* Y, int m, int n){
	int L[m+1][n+1]; // the reason i want to declare it m+1, is because the indexng starts from 0 and i want L[m]
	for(int i = 0; i <= m ; i++){
		for(int j = 0; j<= n; j++){
			if(i == 0 || j == 0){
				L[i][j] = 0;
			}
			else if(X[i-1] == Y[j-1]){ //i-1 , because the indexing in the string begins at , only comes to when i = 1; 
				L[i][j] = 1 + L[i-1][j-1] //until there, the common subsequenc is 1 + the previous match so far. 
			}
			else{
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	return L[m][n];
}

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int longestcommonSubsequence(char* X, char* Y){
	int m = strlen(X) ;
	int n = strlen(Y) ;

	int answer = lcs(X,Y,m,n);
	return answer;	
}

// https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/

// Word Break 



// Largest Sum Contiguous Subarray //Maximum subarray problem 
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

// Longest Repeated Subsequence
// basically the common subsequence problem with the repeated substring, the characters cannot be the same at the same index. 
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
  
    // Create and initialize DP table
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
  
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are 
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];          
                       
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}


// Longest Increasing Subsequence

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis( int arr[], int n){
    int *lis, i, j, max = 0;
   int lis[n];
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] ){
            	lis[i] = max(lis[i], lis[j]+1);
            }
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    return max;
}


// Edit Distance 

// Utility function to find the minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of first string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
}



// Minimum Partition 




// Ways to cover a Distance 




// Longest Path in a Matrix 




// Subset Sum Problem 
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;

    for (int i = 1; i <= n; i++) //If the int is 1, 
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1]) // if hte sum is less that the element, don't include the element. 
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1]) // check if it is better to include hte element or not. 
           subset[i][j] = subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]];
       }
     }
     return subset[n][sum];
}



// Longest Common Substring 




// 0-1 Knapsack Problem 

int knapsack(int W[], int V[], int weight, int n){
	KP[n+1][weight+1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < weight; j++){
			if(i == 0 || j == 0 ){KP[i][j] = 0;}
			else if(W[i-1] < weight){
				KP[i][j] = max(V[i-1]+K[i-1][weight-(W[j-1])], KP[i-1][j])
			}
			else{
				KP[i][j] = KP[i-1][j];
			}
		}
	}
	return KP[n][weight];
}


// Shortest Common Supersequence 




// Matrix Chain Multiplication 




// Length of the longest substring without repeating characters 




//Longest Common + Increasing subsequence 







//Given a set of coin denominators, find the minimum number of coins to give a certain amount of change.













