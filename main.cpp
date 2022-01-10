#include <iostream>

using namespace std;

template <typename T1, typename T2>
class myMap
{
  struct Node
  {
    pair<T1, T2> info;
    Node* next = nullptr;
  };

  Node* head = nullptr;
  Node* tail = head;
  int size = 0;
public:
  myMap()
  {

  }

  bool insert(pair<T1, T2> pa)
  {
    bool x = false;

    Node* tempPtr = new Node;
    tempPtr -> info = pa;

    if (head == nullptr)
    {
      head = tempPtr;
    }

    else
    {
      Node* tempPtr2 = head;

      while (tempPtr2 -> next != nullptr)
      {
        if (find(pa.first) != nullptr)
        {
          x = false;
          return x;
        }

        tempPtr2 = tempPtr2 -> next;
      }

      tempPtr2 -> next = tempPtr;
      x = true;
      return x;
    }

    return x;
  }
    
  Node* find(T1 t) // Return pointer
  {
    Node* tempPtr = head;

    while (tempPtr != nullptr)
    {
      if (tempPtr -> info.first == t)
      {
        cout << t << " was found!\n";
        return tempPtr;
      }

      tempPtr = tempPtr -> next;
    }

    if (tempPtr == nullptr)
    {
      cout << t << " was NOT found! Oh no!\n";
      return nullptr;
    }

    return nullptr;
  }

  T1* begin()
  {
    T1* tempPtr;

    if (size != 0)
    {
      tempPtr = head -> info -> first;
    }

    return nullptr;
  }

  T1* end()
  {
    return nullptr;
  }
    
  void display() const
  {
    Node* tempPtr = head;  
	    
    while (tempPtr != nullptr)
	  {
      cout << tempPtr -> info.first << " " << tempPtr -> info.second << endl;
      tempPtr = tempPtr -> next;
    }
  }

  ~myMap()
  {

  }
};

int main()
{
  myMap <char, int> mp1;
  
  mp1.insert (pair<char, int>('z', 900));
  mp1.insert (pair<char, int>('a', 100));
  mp1.insert (pair<char, int>('c', 300));

  bool ret = mp1.insert (pair<char, int>('z', 500));  // This insertion should fail since the key exists

  if (ret == false)
  {
    cout << "Element 'z' already existed\n";
  }

  else  // If ret == true
  {
    cout << "It is inserted.\n";
  }

  // Test find() function
  mp1.find('c');  // Return pointer pointing to element 'c'

  mp1.find('x');  // Return nullptr indicating element not found

  // The following display() function will display
  //  a -> 100
  //  c -> 300
  //  z -> 900
  // This function is not a member function of the map in STL.
  // But in order to check the result of our works we need this function.
  mp1.display();
  
  return 0;
}