// Implement addition, subtraction, division, multiplciation without operators 

// Bitwise : AND, OR, NOT, XOR


// palindrome Bit Manipulation () 

// Power of 2:

bool isPowerofTwo(int n){
	return n > 0 && (!(n & (n-1)));
}


int Add(int x, int y)
{
    // Iterate till there is no carry  
    while (y != 0)
    {
        // carry now contains common 
        //set bits of x and y
        int carry = x & y;  
 
        // Sum of bits of x and y where at 
        //least one of the bits is not set
        x = x ^ y; 
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
    }

    int subtract(int x, int y)
{
    // Iterate till there
    // is no carry
    while (y != 0)
    {
        // borrow contains common 
        // set bits of y and unset
        // bits of x
        int borrow = (~x) & y;
 
        // Subtraction of bits of x 
        // and y where at least one
        // of the bits is not set
        x = x ^ y;
 
        // Borrow is shifted by one 
        // so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    return x;
}

int count_one(int n) {
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}

bool isPowerOfFour(int n) {
    return !(n&(n-1)) && (n-1)%3 = 0;
    //check the 1-bit location;
}

nt hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}

// Reverse words in a string. 
void reverseWords(string s)
{
  
  char *word_begin = s;
  char *temp = s; /* temp is for word boundry */
 
  /*STEP 1 of the above algorithm */
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } /* End of while */
 
   /*STEP 2 of the above algorithm */
  reverse(s, temp-1);
}
 
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
  begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
