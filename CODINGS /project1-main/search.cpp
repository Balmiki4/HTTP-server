/**
PSEUDOCODE: 

algorithm LinearSearch
  Input: An array of integer and target value
  Output: Index of a target value

  Your pseudocode goes here. 
1. Run a for loop for each index "i"of a given array
2. if numbers[i] == target value:
    return i;
    else:
    return -1
COMMENTS:

LinearSearch: returns an index of a target value
length: Size of an array
numbers[]: An array of list of an integer
n: target value
*/
int LinearSearch(int numbers[], int length, int n) {
  // Implement this function.
  for(int i = 0; i < length; i++){
    if(numbers[i] == n){
      return i;
      break;
    }
  }
  return -1;
}

/**
PSEUDOCODE: 

algorithm BinarySearch
  Input: An array of integer and target value
  Output: Index of a target value

  Your pseudocode goes here.
  1: Set a upperBound = last index of an array and lowerBouind  = first iondex of an array
  2: Declare and initialize a variables "found = false" and "targetIndex = -1".
  3: run a loop while(found = false  && lowerBound <= upperBound)
      find a midpoint = (lowerBound + upperBound)/2
          if(numbers[midpoint]  == target):
           targetIndex = count;
           break;
          esle if numbers[midpoint] < target:
          lowerBound = midpoint++
          else :
          upperBound = midpoint
  4.  return targetIndex;
   
COMMENTS:

BinarySearch: returns the index of a target value 
length: Size of an array
numbers[]: An array of list of an integer
n: target value
*/
int BinarySearch(int numbers[], int length, int n) {
  // Implement this function.
 int lowerBound = 0;
 int upperBound = length;
 int midpoint;
 bool found = false;
 int targetIndex = -1;

 while(!found && lowerBound <= upperBound){
  midpoint = (lowerBound + upperBound)/2;
  if(numbers[midpoint] == n){
    targetIndex = midpoint;
    found = true;
  }
  else if(numbers[midpoint] < n){
    lowerBound  = midpoint++;
  }
  else{
    upperBound = midpoint;
  }

 }
  return targetIndex;
}