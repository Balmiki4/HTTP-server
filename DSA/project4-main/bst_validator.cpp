// Run in Repl.it 
// clang++-7 -pthread -std=c++17 -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 4: BST VALIDATOR **/

// EFFECTS: Returns true if the tree is a valid BST, or false otherwise.
// 
// PSEUDOCODE:
// algorithm IsBST

//   FUNCTION IsBstHelper(tree, index, LastValue):
//     IF index >= tree.size() THEN // if index is greater than size, it is a valid tree
//         RETURN true
//     ENDIF
//     IF NOT IsBstHelper(tree, 2*index+1, LastValue) THEN // traverse the left subtree of the tree
//         RETURN false
//     ENDIF
//     IF tree[index] <= LastValue THEN // check the current node
//         RETURN false
//     ENDIF
//     LastValue = tree[index] // set the current node value as last value
//     RETURN IsBstHelper(tree, 2*index+2, LastValue) // traverse the right subtree of the tree
// ENDFUNCTION

// FUNCTION IsBST(binary_tree):
//     LastValue = INT_MIN
//     RETURN IsBstHelper(binary_tree, 0, LastValue) // call the IsBstHelper function with root node index as 0
// ENDFUNCTION

//
// COMMENTS:
// IsBstHelperL: Returns true if the tree is a valid BST, or false otherwise. 
bool IsBstHelper(const std:: vector<int>&tree, int index, int &LastValue){
    if(index >= tree.size()){  // its a valid tree
      return true;
    }

    //traverse the left subtree of the tree
    if(!IsBstHelper(tree, 2*index + 1, LastValue)){
      return false;
    }

    //check the current node
    if(tree[index] <= LastValue){
      return false;
    }
    LastValue = tree[index];
    //Traverse the right subtree of the tree
    return IsBstHelper(tree, 2*index + 2, LastValue);
}
bool IsBST(std::vector<int> &binary_tree) {
  int LastValue = INT_MIN;
  return IsBstHelper(binary_tree, 0, LastValue);
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> binary_tree;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    binary_tree.push_back(number);
  }
  if (IsBST(binary_tree)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  return 0;
}
