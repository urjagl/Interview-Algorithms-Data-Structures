// Remove repeated characters from a string 

// using the indexOf operation in Java



#include <bits/stdc++.h>
using namespace std;
 
char *removeDuplicate(char str[], int n)
{
    // create a set using string characters
    // excluding '\0'
    set<char>s (str, str+n-1);
 
    // print content of the set
    int i = 0;
    for (auto x : s)
       str[i++] = x;
    str[i] = '\0';
 
    return str;
}

// Brute force easy.
char *removeDuplicate(char str[], int n)
{
   // Used as index in the modified string
   int index = 0;   
    
   // Traverse through all characters
   for (int i=0; i<n; i++) {
        
     // Check if str[i] is present before it  
     int j;  
     for (j=0; j<i; j++){
     	if (str[i] == str[j])
           break;
     } 
     // If not present, then add it to
     // result.
     if (j == i)
        str[index++] = str[i];
   }
    
   return str;
}


class LRUCache {

    list<int> used;
    std::unordered_map<int, pair<int, list<int>::iterator>> cache;
    int csize;
public:
    LRUCache(int capacity) : csize(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        int k = it->first;
        used.erase(it->second.second);
        used.push_front(k);
        it->second.second = used.begin();
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        //Check if the key is found in the cache (map), if it is, then just move the key to the front of the list but before remove it from the list and change the iterator pointing the element to begin in the cache map. 
        if (it != cache.end()){
        int k = it->first;
        used.erase(it->second.second);
        used.push_front(k); //Push in the front. 
        it->second.second = used.begin();   
        } 
        // Key is not found 
        else {
            // Now we got to check if the capacity is reached. if yes then delete the last node in the list and the cache map.
			if (cache.size() == csize) {
				cache.erase(used.back());
				used.pop_back();
			}
            // Put the new key into the list front.
            used.push_front(key);
        }
        //either ways make sure the value is in the map and the correct iterator points to it. 
        cache[key] = { value, used.begin() };
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */



    // Java Palidrome number:
    bool isPalUtil(int num, int* dupNum)
{
    // Base case (needed for recursion termination): This statement
    // mainly compares the first digit with the last digit
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
 
    // This is the key line in this method. Note that all recursive
    // calls have a separate copy of num, but they all share same copy
    // of *dupNum. We divide num while moving up the recursion tree
    if (!isPalUtil(num/10, dupNum))
        return false;
 
    // The following statements are executed when we move up the
    // recursion call tree
    *dupNum /= 10;
 
    // At this point, if num%10 contains i'th digit from beiginning,
    // then (*dupNum)%10 contains i'th digit from end
    return (num % 10 == (*dupNum) % 10);
}
 
// The main function that uses recursive function isPalUtil() to
// find out whether num is palindrome or not
int isPal(int num)
{
    // If num is negative, make it positive
    if (num < 0)
       num = -num;
 
    // Create a separate copy of num, so that modifications made
    // to address dupNum don't change the input number.
    int *dupNum = new int(num); // *dupNum = num
 
    return isPalUtil(num, dupNum);
}










