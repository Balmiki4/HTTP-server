// Run in repl.it:
// g++ -pthread -std=c++17 -o calc calc.cpp;
//./calc < calc_test1.in
// Run in zeus:
// g++ -pthread -o calc calc.cpp;
//./calc < calc_test1.in

#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero
{
};
class badInput
{
};
void DoPrintAll(Dlist<double> &stack);
/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/*******************************************************
 * INSTRUCTOR NOTE: Implement the functions below.     *
 * You may throw exception classes emptyList, divZero, *
 * or badInput from these functions as needed.         *
 ******************************************************/

// EFFECTS: performs + operation

// PSEUDOCODE:
//  - Begin the DoAdd() function.
//  - Check if the given stack is empty using the IsEmpty() method of the Dlist class. If it is empty, throw an emptyList exception.
//  - If the stack is not empty, remove the front element of the stack using the RemoveFront() method of the Dlist class and store it in a variable a.
//  - Check again if the stack is not empty using the IsEmpty() method.
//  - If the stack is not empty, remove the front element of the stack using the RemoveFront() method of the Dlist class and store it in a variable b.
//  - Add the values of a and b together and insert the result at the front of the stack using the InsertFront() method of the Dlist class.
//  - If the stack was initially empty, insert a back into the stack using the InsertFront() method of the Dlist class, and then throw an emptyList exception.
//  - End the DoAdd() function.

void DoAdd(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();

    if (!stack.IsEmpty())
    { // check for empty again after removing one item to    make sure there are more than two items
      double b = stack.RemoveFront();
      stack.InsertFront(a + b); // insert the addition of two numbers
    }
    else
    {
      stack.InsertFront(a);
      throw emptyList();
    }
  }
}
// EFFECTS: performs - operation

// PSEUDOCODE:
//  Function DoSub(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          if stack is not empty then
//              b = stack.RemoveFront()
//              result = b - a
//              stack.InsertFront(result)
//          else
//              stack.InsertFront(a)
//              throw emptyList
//          endif
//      endif
//  End Function

void DoSub(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    if (!stack.IsEmpty())
    { // check for empty again after removing one item to    make sure there are more than two items
      double b = stack.RemoveFront();
      stack.InsertFront(b - a); // insert the subtraction of two numbers
    }
    else
    {
      stack.InsertFront(a);
      throw emptyList();
    }
  }
}

// EFFECTS: performs * operation

// PSEUDOCODE:
//  Function DoMult(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          if stack is not empty then
//              b = stack.RemoveFront()
//              result = a * b
//              stack.InsertFront(result)
//          else
//              stack.InsertFront(a)
//              throw emptyList
//          endif
//      endif
//  End Function

void DoMult(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    if (!stack.IsEmpty())
    { // check for empty again after removing one item to    make sure there are more than two items
      double b = stack.RemoveFront();
      stack.InsertFront(a * b); // insert the multiplication of two numbers
    }
    else
    {
      stack.InsertFront(a);
      throw emptyList();
    }
  }
}

// EFFECTS: performs / operation

// PSEUDOCODE:
//  Function DoDiv(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          if stack is not empty then
//              b = stack.RemoveFront()
//              if a == 0 then
//                  throw divZero
//              endif
//              result = b / a
//              stack.InsertFront(result)
//          else
//              stack.InsertFront(a)
//              throw emptyList
//          endif
//      endif
//  End Function

void DoDiv(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    if (!stack.IsEmpty())
    { // check for empty again after removing one item to    make sure there are more than two items
      double b = stack.RemoveFront();
      if (a == 0)
      {
        throw divZero(); // if a == 0 throw error
      }
      stack.InsertFront(b / a); // insert the division of b/a
    }
    else
    {
      stack.InsertFront(a);
      throw emptyList();
    }
  }
}

// EFFECTS: performs n operation

// PSEUDOCODE:
//  Function DoNeg(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          negated = -1 * a
//          stack.InsertFront(negated)
//      endif
//  End Function

void DoNeg(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    stack.InsertFront(-1 * a); // negate the number and insert it in front
  }
}

// EFFECTS: performs d operation

// PSEUDOCODE:
//  Function DoDup(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          stack.InsertFront(a)
//          stack.InsertFront(a)
//      endif
//  End Function

void DoDup(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    stack.InsertFront(a); // duplicate the number a
    stack.InsertFront(a); // because the number was removed initially
  }
}

// EFFECTS: performs r operation

// PSEUDOCODE:
//  Function DoRev(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          if stack is empty then
//              stack.InsertFront(a)
//              throw emptyList
//          else
//              b = stack.RemoveFront()
//              stack.InsertFront(a)
//              stack.InsertFront(b)
//          endif
//      endif
//  End Function

void DoRev(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    if (!stack.IsEmpty())
    { // check for empty again after removing one item to    make sure there are more than two items
      double b = stack.RemoveFront();
      // reverse the order of numbers and insert
      stack.InsertFront(a);
      stack.InsertFront(b);
    }
    else
    {
      stack.InsertFront(a);
      throw emptyList();
    }
  }
}

// EFFECTS: performs p operation

// PSEUDOCODE:
//  Function DoPrint(stack: Dlist<double>)
//      if stack is empty then
//          throw emptyList
//      else
//          a = stack.RemoveFront()
//          print a
//          stack.InsertFront(a)
//      endif
//  End Function

void DoPrint(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    double a = stack.RemoveFront();
    std::cout << a << std::endl; // print the top element of stack
    stack.InsertFront(a);        // insert the number again so that the stack is unchanged
  }
}

// EFFECTS: performs c operation

// PSEUDOCODE:
//  void DoClear(Dlist<double> &stack)
//  {
//    // Remove all elements from the stack
//    while (!stack.IsEmpty())
//    {
//      stack.RemoveFront();
//    }
//  }

void DoClear(Dlist<double> &stack)
{
  while (!stack.IsEmpty())
  {
    stack.RemoveFront();
  }
}

// EFFECTS: performs a operation

// PSEUDOCODE:
//  - Check if the stack is empty, throw an exception if it is.
//  - Create a temporary list to store the elements of the stack in reverse order.
//  - While the stack is not empty, remove the top element, print it, and insert it at the back of the temporary list.
//  - Replace the original stack with the temporary list, so that the order of the elements is preserved.
//  - Print a newline character to end the line.

void DoPrintAll(Dlist<double> &stack)
{
  if (stack.IsEmpty())
  {
    throw emptyList();
  }
  else
  {
    Dlist<double> temp;

    if (!stack.IsEmpty())
    {
      double num = stack.RemoveFront();
      std::cout << num;
      temp.InsertBack(num);
    }

    while (!stack.IsEmpty())
    {
      double num = stack.RemoveFront();
      std::cout << " " << num;
      temp.InsertBack(num);
    }

    stack = temp;
    std::cout << " " << std::endl;
  }
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

bool DoOne(Dlist<double> &stack)
{
  std::string s;
  double d;

  std::cin >> s;
  switch (s[0])
  {
  case '+':
    DoAdd(stack);
    break;
  case '-':
    DoSub(stack);
    break;
  case '*':
    DoMult(stack);
    break;
  case '/':
    DoDiv(stack);
    break;
  case 'n':
    DoNeg(stack);
    break;
  case 'd':
    DoDup(stack);
    break;
  case 'r':
    DoRev(stack);
    break;
  case 'p':
    DoPrint(stack);
    break;
  case 'c':
    DoClear(stack);
    break;
  case 'a':
    DoPrintAll(stack);
    break;
  case 'q':
    return true;
    break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    d = std::atof(s.c_str());
    stack.InsertFront(d);
    break;
  default:
    badInput e;
    throw e;
    break;
  }
  return false;
}

int main()
{
  Dlist<double> stack;

  bool done = false;
  while (!done)
  {
    try
    {
      done = DoOne(stack);
    }
    catch (emptyList e)
    {
      std::cout << "Not enough operands\n";
    }
    catch (divZero e)
    {
      std::cout << "Divide by zero\n";
    }
    catch (badInput e)
    {
      std::cout << "Bad input\n";
    }
  }
}
