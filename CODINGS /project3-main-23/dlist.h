#ifndef __DLIST_H__
#define __DLIST_H__

/**********************************************************
 * INSTRUCTOR NOTE: Do not modify the class declarations! *
 * The class Dlist is a class template.                   *
 *********************************************************/
class emptyList
{
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist
{
  // OVERVIEW: contains a double-ended list of Objects

public:
  // Maintenance methods

  Dlist();                          // constructor
  Dlist(const Dlist &l);            // copy constructor
  Dlist &operator=(const Dlist &l); // assignment
  ~Dlist();                         // destructor

  // Operational methods

  // EFFECTS: returns true if list is empty, false otherwise
  bool IsEmpty() const;

  // MODIFIES: this
  // EFFECTS: inserts o at the front of the list
  void InsertFront(const T &o);

  // MODIFIES: this
  // EFFECTS: inserts o at the back of the list
  void InsertBack(const T &o);

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveFront();

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveBack();

private:
  // A private type

  struct node
  {
    node *next;
    node *prev;
    T o;
  };

  // Private member variables

  node *first; // The pointer to the first node (NULL if none)
  node *last;  // The pointer to the last node (NULL if none)

  // Private utility methods

  // EFFECTS: called by constructors to establish empty list invariant
  void MakeEmpty();

  // EFFECTS: called by copy constructor/operator= to copy nodes
  //          from a source instance l to this instance
  void CopyAll(const Dlist &l);

  // EFFECTS: called by destructor and operator= to remove and destroy
  //          all list nodes
  void RemoveAll();
};

// Constructor
template <typename T>
Dlist<T>::Dlist()
{
  MakeEmpty();
}

// Copy constructor
template <typename T>
Dlist<T>::Dlist(const Dlist &l)
{
  MakeEmpty();
  CopyAll(l);
}

// Assignment operator
template <typename T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &l)
{
  if (this != &l)
  {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

// Destructor
template <typename T>
Dlist<T>::~Dlist()
{
  RemoveAll();
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/**********************************************************
 * INSTRUCTOR NOTE: Implement the member functions below. *
 * These member functions are all function templates.     *
 *********************************************************/

// EFFECTS: returns true if list is empty, false otherwise

template <typename T>
bool Dlist<T>::IsEmpty() const
{
  return first == nullptr;
}

// MODIFIES: this
// EFFECTS: inserts o at the front of the list

template <typename T>
void Dlist<T>::InsertFront(const T &o)
{
  node *newNode = new node;
  newNode->o = o;
  newNode->next = first;
  newNode->prev = nullptr;
  if (IsEmpty())
  { // if the list is empty, set the first and last pointers to the new node
    last = newNode;
    // first = newNode;
  }
  else
  { // set o to the front of the list
    // newNode->next = first;
    first->prev = newNode;
  }
  first = newNode;
}

// MODIFIES: this
// EFFECTS: inserts o at the back of the list

template <typename T>
void Dlist<T>::InsertBack(const T &o)
{
  node *newNode = new node;
  newNode->o = o;
  newNode->next = nullptr;
  newNode->prev = last;
  if (IsEmpty())
  { // if the list is empty, set the first and last pointers to the new node
    // last = newNode;
    first = newNode;
  }
  else
  { // set o at the back of the list
    last->next = newNode;
    // newNode->prev = last;
  }
  last = newNode;
}

// MODIFIES: this
// EFFECTS: removes and returns first object from non-empty list
//          throws an instance of emptyList if empty

template <typename T>
T Dlist<T>::RemoveFront()
{
  if (IsEmpty())
  { // throw an exception if the list is empty
    throw emptyList();
  }
  else
  { // return the first node
    T value = first->o;
    node *oldFirst = first;

    first = oldFirst->next;
    if (first == nullptr)
    { // there was just one elemnent and now the list is    empty after removing the first element
      last = nullptr;
    }
    else
    {
      first->prev = nullptr;
    }

    delete oldFirst;
    return value;
  }
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty

template <typename T>
T Dlist<T>::RemoveBack()
{
  if (IsEmpty())
  { // throw an exception if the list is empty
    throw emptyList();
  }
  else
  { // return the last node
    T value = last->o;
    node *oldLast = last;
    last = oldLast->prev;
    if (last == nullptr)
    { // there was just one elemnent and now the list is    empty after removing the last element
      first = nullptr;
    }
    else
    {
      last->next = nullptr;
    }
    delete oldLast;
    return value;
  }
}

// EFFECTS: called by constructors to establish empty list invariant

template <typename T>
void Dlist<T>::MakeEmpty()
{
  first = nullptr;
  last = nullptr;
}

// EFFECTS: called by copy constructor/operator= to copy nodes
//          from a source instance l to this instance

template <typename T>
void Dlist<T>::CopyAll(const Dlist &l)
{

  node *current = l.first;
  while (current != nullptr)
  {
    InsertBack(current->o);
    current = current->next;
  }
}

// EFFECTS: called by destructor and operator= to remove and destroy
//          all list nodes

template <typename T>
void Dlist<T>::RemoveAll()
{
  while (!IsEmpty())
  {
    RemoveFront();
  }
}

/**** INSTRUCTOR NOTE: DO NOT DELETE #endif FROM END OF FILE. ****/
#endif /* __DLIST_H__ */
