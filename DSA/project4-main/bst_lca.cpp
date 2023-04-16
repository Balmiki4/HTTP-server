// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 6: LOWEST COMMON ANCESTOR **/

// EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
// 
// PSEUDOCODE:
// algorithm GetLCA

//   FUNCTION GetLCA(bst, l, m):
//     IF bst.empty() THEN
//         RETURN 0
//     ENDIF
//     current = bst[0]
//     WHILE true DO
//         IF current > l AND current > m THEN // current value is greater than l & m move to the left subtree
//             FOR i = 0 TO bst.size()-1 DO
//                 IF bst[i] < current THEN
//                     current = bst[i]
//                     BREAK
//                 ENDIF
//             ENDFOR
//         ELSE IF current < l AND current < m THEN // current value is smaller than l & m move to the right subtree
//             FOR i = 0 TO bst.size()-1 DO
//                 IF bst[i] > current THEN
//                     current = bst[i]
//                     BREAK
//                 ENDIF
//             ENDFOR
//         ELSE // current value is between l and m, then current value is LCA
//             RETURN current
//         ENDIF
//     ENDWHILE
// ENDFUNCTION

//
// COMMENTS:
// GetLCA: Returns the value of the lowest common ancestor of nodes l and m.
int GetLCA(std::vector<int> &bst, int l, int m) {
  // Implement this function.
  if(bst.empty()){
      return 0;
  } 
  int current = bst[0];
  while (true){
      if(current > l && current > m){  //cuurent value is greater than l & m move to the left subtree
        for(int i = 0; i < bst.size(); i++){
          if(bst[i] < current) {
            current = bst[i];
            break;
          }
        }
      }
      else if(current < l && current < m){//cuurent value is smaller than l & m move to the right subtree
        for(int i = 0; i < bst.size(); i++){
          if(bst[i] > current) {
            current = bst[i];
            break;
            } 
         }
      }
      else{ // If current value is between l and m, then current value is lca
        return current;
      }
  
  
  }
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
  int l, m;
  std::cin >> l;
  std::cin >> m;
  
  std::vector<int> path;
  int lca = GetLCA(bst, l, m);

  std::cout << "lca = " << lca;
  return 0;
}
