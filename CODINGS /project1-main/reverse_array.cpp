/**
PSEUDOCODE: 

algorithm ReverseArray
  Input: An array of list of integer and length of an array
  Output: Reverse array
  Side Effect: 

  Your pseudocode goes here. 
  1: Run for loop length/2 times
      Swap the elements at the front and end of the array until 
      it reaches the middle of the array using a temporary variable .

   

COMMENTS:
ReverseArray:Reverses given array arr[]
length: Size of an array
*/
void ReverseArray(int arr[], int length) {
  // Implement this function.
  if(length < 2){
    return;
  }
  for(int i = 0; i < length/2; i++){
    int temp = arr[length-1-i];
    arr[length-1-i] = arr[i];
    arr[i] = temp;
  }
}