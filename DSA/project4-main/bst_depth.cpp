// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 5: DEPTH AND PATH **/

// EFFECTS: Returns the depth of the target node. Modifies the path vector
//          so that it contains the node values in the path from the root to
//          the target node.
// 
// PSEUDOCODE:
// algorithm GetDepthAndPath
//
//   FUNCTION GetDepthAndPath(bst, target, path):
//     depth = 0
//     size = bst.size()
//     CurrentNode = 0
//     WHILE CurrentNode < size AND bst[CurrentNode] != target DO
//         path.push_back(bst[CurrentNode]) // add current node to path
//         IF target < bst[CurrentNode] THEN
//             CurrentNode = 2 * CurrentNode + 1 //go to the left child
//         ELSE
//             CurrentNode = 2 * CurrentNode + 2 //go to the right child
//         ENDIF
//         depth++ // increment depth
//     ENDWHILE
//     IF CurrentNode >= size THEN // target node not found
//         depth = -1
//         path.clear()
//     ELSE // target node found
//         path.push_back(bst[CurrentNode]) // add current node to path
//     ENDIF
//     RETURN depth // return depth
// ENDFUNCTION
//
//
// COMMENTS:
// GetDepthAndPath: Returns the depth of the target node
int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) {
  // Implement this function.
  int depth = 0;
  int size = bst.size();
  int CurrentNode = 0;
  while(CurrentNode < size && bst[CurrentNode] != target){
    path.push_back(bst[CurrentNode]); // add current node to path
    if(target < bst[CurrentNode]){
      CurrentNode = 2 * CurrentNode + 1; //go to the left child
    }
    else{
      CurrentNode = 2 * CurrentNode + 2; //go to the right child
    }
    depth++; // increment depth
  }
  if(CurrentNode >= size){  //target node not found
    depth = -1;
    path.clear();
  }
  else{ //taget node found
    path.push_back(bst[CurrentNode]); //add current node to path
    
  }
  return depth; //return depth
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> bst;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    bst.push_back(number);
  }
  int target;
  std::cin >> target;
  
  std::vector<int> path;
  int depth = GetDepthAndPath(bst, target, path);

  std::cout << "depth = " << depth << std::endl;
  std::cout << "path = ";
  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i] ;
    if (i < path.size() - 1) {
      std::cout << " ";
    }
  }
  return 0;
}
