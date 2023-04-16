#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

/**
THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
DO NOT MODIFY THIS FUNCTION. 
*/
std::string ConvertFloatToStr(float n, int precision) {
  std::stringstream ss; 
  ss << std::fixed << std::setprecision(precision) << n; 
  return ss.str();
}

/**
PSEUDOCODE: 

algorithm ApproxSqrt
  Input: Integer n for which we want approximate the square root and no. of iterations to run
  Output: Square root of n

  Your pseudocode goes here.
  1. Declare and initialize a variable upperBound = n and lowerBound = 0
  2. Declare a variable "sqrt"
  3. Initialize a "count" variable to 0 and do binary search
    loop while (count <= iterations && midpoint^2 == n) 
    find a midpoint for n i.e midpoint = (upperBound + lowerBound)/2
    - if midpoint^2 == n:
         sqrt = midpoint
      else if midpoint^2 < n:
          lowerBound = midpoint++
      else:
          upperBound  = midpoint
   increment the count by 1 i.e count++
  4. return sqrt

COMMENTS:

ApproxSqrt: returns a approximate square root of an integer n
n: integer to find the square root of
iterations: No. of iteratios to run the binary search 
*/
std::string ApproxSqrt(int n, int iterations) {
  // Implement this function.
  // You may call ConvertFloatToStr as part of your solution.
  double lowerBound = 0;
  double upperBound = n;
  int count = 0;
  double midpoint;
  std::string sqrt;

  //Binary search
 if(iterations == 0){
  return ConvertFloatToStr(n, 5);//return original n if iterations is 0 
 }
  else{
  while(count < iterations){
    midpoint = (lowerBound + upperBound)/2;
    if(midpoint * midpoint == n){
      break;
    }
     else if(midpoint * midpoint < n){
      lowerBound = midpoint;
    }
    else{
      upperBound = midpoint;
    }
    count++;
  }
  return ConvertFloatToStr(midpoint, 5);

 }
}
  
