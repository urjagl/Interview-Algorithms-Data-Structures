// KMP algorithm 

void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i &lt; M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i &lt; N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf(&quot;Found pattern at index %d n&quot;, i-j);
            j = lps[j-1];
        }
 
        // mismatch after j matches
        else if (i &lt; N &amp;&amp; pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

// First Unique character in a string 

  int firstUniqChar(string s) {
        int index = -1;
        std::vector<int> count(256);
        for(int i = 0; i < s.length(); i++){
            count[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(count[s[i]] == 1){
                index = i;
                return index;
            }
        }
        return index;
    }

void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

// Reverse a string 
String reverseString(string& str){
	int len = str.length();
	for(int i = 0; i < len/2 ; i++){
		swap(&str[i], &str[len-i-1]);
	}
	return str;
}

//check duplicates in a string without an data structure. 
bool areChractersUnique(string str)
{
    // An integer to store presence/absence
    // of 26 characters using its 32 bits.
    int checker = 0;
 
    for (int i = 0; i < str.length(); ++i)
    {
        int val = (str[i]-'a');
 
        // If bit corresponding to current
        // character is already set
        if ((checker & (1 << val)) > 0)
            return false;
 
        // set bit in checker
        checker |=  (1 << val);
    }
 
    return true;
}
 

//rite some code to create powersets

// Write a function that sums up integers from a text file, one int per line.

//Example 7:  Format an RGB value (three 1-byte numbers) as a 6-digit hexadecimal string.


// Plus one 


// Write some code to find all permutations of the letters in a particular string.


// Longest Substring at most K distinct characters 



// Add Bold tag in String 


// Valid palindrome 

 bool isPalindrome(string s) {
        int end = s.length() -1;
        int start = 0; 
        while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
        return true;
    }

// Valid parentheses 

bool isValid(string s) {
        stack<char> temp;
        for(char& c: s){
            switch(c){
                case '(' : temp.push(c); break;
                case '{' : temp.push(c); break;
                case '[' : temp.push(c); break;
                case ')' : if(temp.empty() || temp.top() != '(') return false; else temp.pop(); break;
                case ']' : if(temp.empty() || temp.top() != '[') return false; else temp.pop(); break;
                case '}' : if(temp.empty() || temp.top() != '{') return false; else temp.pop(); break;
                default: ;
            }
        }
        return true;
    }


// Valid Number 

 bool isNumber(string s) {
        int i = 0;
        if(s == " " || s[i] == 'e' ){return false;}
        for(; s[i] == ' '; i++){} //Skip the trailing white spaces
        if(s[i] == '+' || s[i] == '-') i++;  // Skip the + and - 
        int countNum = 0;
        int countDecimals = 0;
        for(;(s[i] >= '0' && s[i] <= '9') || s[i] == '.'; i++){ 
            if(s[i] == '.') countDecimals++; else{countNum++;}
        }
         if(countDecimals > 1 || countNum < 1) return false;
        if(s[i] == 'e'){ //Handle the exponent case
            i++;
            if(s[i] == '+' || s[i] == '-') i++;
            int countNum = 0;
            for(; (s[i] >= '0' && s[i] <= '9'); i++) countNum++{}
            if(countNum < 1) return false;
        }
         for(; s[i] == ' '; i++){} 
        return s[i] == 0;
    }

// Remove Duplicates from Sorted Array 

 int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int i = 0;
        for(int j = 1; j < len; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }

// Shortest Palindrome :
    // Given a string s, you are allowed to convert it to a palindrome by 
    // adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.





// Repeated String Match 


//anagram 


// Suppose you have an NxN matrix of positive and negative integers. Write some code that finds the sub-matrix with the maximum sum of its elements.
