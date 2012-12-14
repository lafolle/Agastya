#include <iostream>

using namespace std;

#include "BinSTree.cpp"

void showMenu(void)
{
  cout << "1 to insert \n";
  cout << "2 to find   \n";
  cout << "3 to delete \n";
  cout << "4 to traverse inorder \n";
  cout << "5 to traverse preorder \n";
  cout << "6 to traverse postorder \n";
  cout << "\n";
  cout << "x to exit\n\n";
  cout << "Your choice: ";
}

int main(void)
{
  BinSTree T;

  char choice = ' ';
  int el = 0;
  while (choice != 'x')
    {
      showMenu();
      cin >> choice;
      if (choice != 'x')
	{
	  switch(choice)
	    {
	    case '1':
	      cout << "Enter key: ";
	      cin >> el;
	      T.insert(el);
	      if (T.hasError())
		cout << "Inserting did not work\n";
	      else
		cout << "Element inserted\n";
	      break;
	    case '2':
	      cout << "Enter search key: ";
	      cin >> el;
	      T.find(el);
	      if (T.hasError())
		cout << "Element not found\n";
	      else
		cout << "Element found was " << T.retrieve() << "\n";
	      break;
	    case '3':
	      if (!T.isEmpty())
		{
		  cout << "Enter delete key: ";
		  cin >> el;
		  T.remove(el);
		  if (T.hasError())
		    cout << "Could not delete\n";
		  else
		    cout << "Element deleted\n";
		}
	      else
		cout << "Tree is empty\n";
		  break;
	    case '4': 
	      if (T.isEmpty())
		cout << "Tree is empty \n";
	      else
		T.traverse(IN_ORDER);
	      break;
	    case '5': 
	      if (T.isEmpty())
		cout << "Tree is empty \n";
	      else
		T.traverse(PRE_ORDER);
	      break;
	    case '6': 
	      if (T.isEmpty())
		cout << "Tree is empty \n";
	      else
		T.traverse(POST_ORDER);
	      break;

	    default: cout << "Invalid choice...\n";
	    }
	  cout << "Press key + RETURN to continue ... ";
	  char cc;
	  cin >> cc;
	}
    }
  T.destroy();
  return 0;
}
