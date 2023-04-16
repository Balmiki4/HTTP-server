#include <string>
/**
PSEUDOCODE: 

algorithm MinimumWordLength
  Input: An array of strings and its length.
  Output: The minimum length of the word in an array

  Your pseudocode goes here. 
  1. Initialize a variable "minLength" with a wordlength of a word at index '0' of an array of words. 
  2. Loop through each word from index i = 1 to the size of an array .
      - if words[i].length < minLength:
          minLength = words[i].length;
  3. Return "minLength".

COMMENTS:
MinimumWordlength: An integer function that returns the minimum length of the word.
words[]: An array of words
length: length of a an array words[]

*/
int MinimumWordLength(std::string words[], int length) {
  // Implement this function. 
  int minLength = words[0].length();
  for(int i = 1; i < length; i++){
    if(words[i].length() < minLength){
      minLength = words[i].length();
    } 
  };
  return minLength;
}

/**
PSEUDOCODE: 

algorithm MaximumWordLength
  Input: An array of strings and its length.
  Output: The maximum length of the word in an array


  Your pseudocode goes here. 
   1. Initialize a variable "maxLength" with a wordlength of a word at index '0' of an array of words. 
  2. Loop through each word from index i = 1 to the size of an array .
      - if words[i].length > maxLength:
          maxLength = words[i].length;
  3. Return "maxLength".


COMMENTS:


MaximumWordlength: An integer function that returns the maximum length of word 
words[]: An array of words
length: length of a an array words[]

*/
int MaximumWordLength(std::string words[], int length) {
  // Implement this function. 
  int maxLength = words[0].length();
  for(int i = 1; i < length; i++){
    if(words[i].length() > maxLength){
      maxLength = words[i].length();
    }
    
  };
  return maxLength;
  
}

/**
PSEUDOCODE: 

algorithm RangeOfWordLengths
  Input: An array of strings and its length.
  Output: The range of lengths of the words in the array (maximum length - minimum length)

  Your pseudocode goes here. 
  1. Initialize a variable "minLength" to the maximum possible integer value and a variable "maxLength" to 0.
  2. Loop through each word in the array.
  3. If the length of the current word is less than "minLength", set "minLength" to the length of the current word.
  4. If the length of the current word is greater than "max_length", set "max_length" to the length of the current word
  5.Return "max_length" - "min_length".

COMMENTS:


RangeOfWordLengths: An integer function that returns the range of the wordlengths.
words[]: An array of words
length: length of a an array words[]

*/
int RangeOfWordLengths(std::string words[], int length) {
  int minLength = MinimumWordLength(words, length);
  int maxLength = MaximumWordLength(words, length);
  return maxLength - minLength;
}

/**
PSEUDOCODE: 

algorithm WordLengthMean
  Input: An array of strings and its length.
  Output: The mean length of the words in the array
  Your pseudocode goes here. 
  1. Initialize a variable "sum" to 0
  2.Loop through each word in the array
    - Add the length of the current word to "sum"
  4. Return "sum" / "length"


COMMENTS:
WordLengthMean: An integer function that returns the range of the wordlengths.
words[]: An array of words
length: length of a an array words[]


*/
int WordLengthMean(std::string words[], int length) {
  // Implement this function. 
  int sum = 0;
  for(int i = 0; i < length; i++){
   sum += words[i].length();
  }

  return sum/length;
}

/**
PSEUDOCODE: 

algorithm WordLengthMode
  Input: An array of strings and its length.
  Output: The mode of the lengths of the words in the array

  Your pseudocode goes here. 
1. Declare an integer array "frequency" of size 100 and initialize each index to 0
2. Loop through each word of an array words[]
    - Increase the frequency of a word length by 1 at index of a length of the word in an array frequency[].
3. Initialize a variable "maxFrequency" = 0 and declare a variable "mode"
4. Then loop throgh each index of an array frequency[];
    if frequency[i] > mode:
      maxFrequency = frequency[i]
      mode = i;
    else if frequency[i] == maxFrequency
    return -1;
5. return mode;


COMMENTS:
WordLengthMode: An integer function that returns the mode of the wordlengths.
words[]: An array of words
length: length of a an array words[]

*/
int WordLengthMode(std::string words[], int length) {
  // Implement this function. 
  int frequency[100]= {};
  int mode;
  //Find the length of each word and store it in an array of frequency at an
  // index of word's length
  for(int i = 0; i < length; i++){
    frequency[words[i].length()]++;
  }

  int MaxFrequency = frequency[0];
  for(int i = 1; i < 100; i++){
    if(frequency[i] > MaxFrequency){
      MaxFrequency = frequency[i];
      mode = i;//mode of word lengths
    }

    else if(frequency[i] == MaxFrequency){//tie of mode of word lengths 
      mode = -1;
    }

  }
  return mode;

}