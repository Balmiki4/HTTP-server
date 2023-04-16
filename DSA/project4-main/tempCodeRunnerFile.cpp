/*
 * autocomplete.cpp
 * 
 * The file where you will implement your autocomplete code for Project 4.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the testcases will fail. 
 */

#include "autocomplete.h"

/** QUESTION 1: FINDNODE **/
// EFFECTS: Traverses the Tree based on the charactes in the prefix and 
//          returns the TreeNode that we end at. If we cannot find a valid node,
//          we return an empty TreeNode. The index variable keeps track of what 
//          character we're at in prefix.
// 
// PSEUDOCODE:
// algorithm FindNode
//   Input:
//   Output: 
//   Your pseudocode goes here.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
  // Implement this function.
  if(index >=prefix.length()){
    return node;
  }
  for(TreeNode<char> child: node.GetChildren()){
    if(child.GetValue()==prefix[index]){
      return FindNode(child, prefix, index+1);
    }
  }
  return TreeNode<char>();
}

/** QUESTION 2: COLLECTWORDS **/

// EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
//          prepends the word with the prefix and adds it to the results vector.
// 
// PSEUDOCODE:
// algorithm CollectWords
//   Input:
//   Output: 
//   Your pseudocode goes here.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.  
void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results) {
  // Implement this function.
  if(node.GetValue()=='$'){
    results.push_back(prefix);
  }
  for(TreeNode<char> child: node.GetChildren()){
    CollectWords(child, prefix + child.GetValue(),results);
    }
  
}

/** QUESTION 3: GETCANDIDATES **/

// EFFECTS: Returns the list of all possible words that can be made starting with
//          the letters in prefix, based on traversing the tree with the given root.
// 
// PSEUDOCODE:
// algorithm GetCandidates
//   Input:
//   Output: 
//   Your pseudocode goes here.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.  
std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
  // Implement this function.
 std::vector<std::string>candidates;
 TreeNode<char> prefixNode= FindNode(root, prefix, 0);
 CollectWords(prefixNode, prefix, candidates);
 return candidates;
}
