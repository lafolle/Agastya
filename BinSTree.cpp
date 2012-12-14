//                                                    March 6, 1998
//                                                 Bert G. Wachsmuth
//   BinSTree class
//   **************
//   This file contains the source code to implement a Binary Search
//   Tree class, as discussed during the semester. Note that the class
//   should be working (except for isFull which always returns false),
//   but many methods could and should be optimized further. That is
//   especially true for 'findNode' and 'findParent' which should be 
//   combined into one method, and 'remove', which should be optimized
//   to be more "esthetically pleasing".
//
#ifndef BINSTREE
#define BINSTREE
#include <iostream>

using namespace std;

typedef int Element;   // for simplicity, may change later
typedef int KeyType;   // for simplicity, may change later

const int PRE_ORDER = 1;
const int IN_ORDER = 2;
const int POST_ORDER = 3;
const int LEVEL_ORDER = 4;
/* ****************************************************************** */
/* *****************      NODE  CLASS    **************************** */
/* ******************************************************************* */
class Node
{
   public: Node *left;
   public: Node *right;
   public: Element data;

   public: Node(void);
   public: Node(Element);
};
/* ******************************************************************* */
/* *******************    BINSTREE CLASS    ************************* */
/* ****************************************************************** */
class BinSTree
{     // Fields
   private: Node *root;
   private: Node *current;
   private: int error;

      // Constructor and public methods
   public: BinSTree(void);
   public: void insert(Element);
   public: void remove(KeyType);
   public: Element retrieve(void);
   public: void traverse(int order);
   public: void find(KeyType);
   public: void destroy(void);
   public: int isFull(void);
   public: int isEmpty(void);
   public: int hasError(void);

      // Private (utility) methods
   private: void preorder(Node *, int);
   private: void inorder(Node *, int);
   private: void postorder(Node *, int);
   private: Node* findParent(KeyType key);
   private: Node* findNode(KeyType key);
   private: Node* findRighty(Node *);
   private: void destroyNode(Node *);
};
/* ******************************************************************* */
/* *******************   NODE CLASS IMPLEMENTATION  ****************** */
/* ******************************************************************* */
Node::Node(void)
{
   left = right = 0;
}
/* ******************************************************************* */
Node::Node(Element el)
{
   left = right = 0;
   data = el;
}
/* ******************************************************************* */
/* ****************   BINSTREE CLASS IMPLEMENTATION   **************** */
/* ******************************************************************* */
BinSTree::BinSTree(void)
{
   root = current = 0;
   error = false;
}
/* ******************************************************************* */
void BinSTree::find(KeyType key)
{
   Node *p = findNode(key);
   if (p == 0)
      error = true;
   else
     {
       error = false;
       current = p;
     }
}
/* ******************************************************************* */
void BinSTree::insert(Element el)
{
  if (root == 0)
    root = new Node(el);
  else
    {
      Node *p = findNode(el);
      if (p == 0)                         // not found, ready to insert
	{
	  Node *parent = root;            // assume root is parent
	  if (p != root)                  // can find parent, so let's do
	    parent = findParent(el);
	  if (el > parent->data)
	    {
	      parent->right = new Node(el); 
	      current = parent->right;
	    }
	  else
	    {
	      parent->left = new Node(el);
	      current = parent->left;
	    }
	  error = false;                  // everything worked
	}
      else                                // duplicate key, not inserted
	error = true;
    }
}
/* ******************************************************************* */
void BinSTree::traverse(int order)
{
   if (order == PRE_ORDER)
      preorder(root, 0);
   else if (order == IN_ORDER)
      inorder(root, 0);
   else if (order == POST_ORDER)
      postorder(root, 0);
   else
      cout << "no such order " << endl;
}
/* ******************************************************************* */
Element BinSTree::retrieve(void)
{
  return current->data;
}
/* ******************************************************************* */
int BinSTree::isFull(void)
{ 
  return 0;
}
/* ******************************************************************* */
int BinSTree::isEmpty(void)
{
  return (root == 0);
}
/* ******************************************************************* */
int BinSTree::hasError(void)
{ 
  return error;
}
/* ******************************************************************* */
void BinSTree::remove(KeyType key)
{
  /* NOTE: This is not at all the easiest possible delete routine.
           However, it comes closest to the algorithm we discussed
	   in class without attempting to be too fancy at all.

           The algorithm could easily be improved by "factoring out"
	   its common elements, and even more by combining some of
	   the cases into one. */

  Node *p = findNode(key);             
  if (p == 0)                                 // is node is in the tree ?
    error = true;
  else                                        // yes, let's proceed
    {
      if ((p->right == 0) && (p->left == 0))       // deleting leaf - easy ...
	{
	  if (p != root)    // (can find parent now ...)   
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = 0;
	      else
		parent->left = 0;
	    }
	  else
	    root = 0;
          delete(p);
	  error = false;
	  current = root;
	}
      else if ((p->right == 0) && (p->left != 0))  // right subtree empty,
                                                   // left subtree not.
	{
	  if (p != root)    // (can find parent now ...)
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = p->left;
	      else
		parent->left = p->left;
	    }
	  else
	    root = root->left;
	  delete(p);
	  error = false;
	  current = root;
	}
      else if ((p->right != 0) && (p->left == 0))  // left subtree empty,
                                                   // right subtree not.
	{
	  if (p != root)    // (can find parent now ...)
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = p->right;
	      else
		parent->left = p->right;
	    }
	  else
	    root = p->right;
	  delete(p);
	  error = false;
	  current = root;
	}
      else                                         // left and right 
                                                   // subtrees not empty
	{
	  Node *righty = findRighty(p->left);
	  Node *parent = findParent(righty->data);
	  p->data = righty->data;   // swapping data with righty
	  if (parent != p)
	    parent->right = righty->left;
	  else
	    p->left = righty->left;
	  delete(righty);
	  error = false;
	  current = root;
	}
    }
}
/* ******************************************************************* */
void BinSTree::destroy(void)
{
  destroyNode(root);
}

/* ******************************************************************* */

void BinSTree::inorder(Node *p, int level)
{
   if (p != 0)
     {
       inorder(p->left, level+1);
       cout << "Node " << p->data << " at level " << level << endl;
       inorder(p->right, level+1);
     }
}
/* ******************************************************************* */
void BinSTree::preorder(Node *p, int level)
{
  if (p != 0)
    {
      cout << "Node " << p->data << " at level " << level << endl;
      preorder(p->left, level+1);
      preorder(p->right, level+1);
    }
}
/* ******************************************************************* */
void BinSTree::postorder(Node *p, int level)
{ 
  if (p != 0)
    {
      postorder(p->left, level+1);
      postorder(p->right, level+1);
      cout << "Node " << p->data << " at level " << level << endl;
    }
}
/* ******************************************************************* */
void BinSTree::destroyNode(Node *p)
{
  if (p != 0)
    {
      destroyNode(p->left);
      destroyNode(p->right);
      delete(p);
    }
}
/* ******************************************************************* */
Node* BinSTree::findParent(KeyType key)
{
   Node *p = root, *q = 0;
   while ((p != 0) && (p->data != key))
     {
       q = p;
       if (p->data > key)
	 p = p->left;
       else
	 p = p->right;
     }
   return q;
}
/* ******************************************************************* */
Node* BinSTree::findNode(KeyType key)
  /* This function returns a pointer to the node containing the key 
     value 'key' if it is in the tree. Otherwise, it returns null */
{
   Node *p = root;
   while ((p != 0) && (p->data != key))
     if (p->data > key)
       p = p->left;
     else
       p = p->right;
   return p;
}
/* ******************************************************************* */
Node* BinSTree::findRighty(Node *p)
{
  Node *righty = p;
  while (righty->right != 0)
    righty = righty->right;
  cout << "found right-most node to be: " << righty->data << endl;
  return righty;
}
/* ******************************************************************* */
#endif
//                                                    March 6, 1998
//                                                 Bert G. Wachsmuth
//   BinSTree class
//   **************
//   This file contains the source code to implement a Binary Search
//   Tree class, as discussed during the semester. Note that the class
//   should be working (except for isFull which always returns false),
//   but many methods could and should be optimized further. That is
//   especially true for 'findNode' and 'findParent' which should be 
//   combined into one method, and 'remove', which should be optimized
//   to be more "esthetically pleasing".
//
#ifndef BINSTREE
#define BINSTREE
#include <iostream.h>

typedef int Element;   // for simplicity, may change later
typedef int KeyType;   // for simplicity, may change later

const int PRE_ORDER = 1;
const int IN_ORDER = 2;
const int POST_ORDER = 3;
const int LEVEL_ORDER = 4;
/* ****************************************************************** */
/* *****************      NODE  CLASS    **************************** */
/* ******************************************************************* */
class Node
{
   public: Node *left;
   public: Node *right;
   public: Element data;

   public: Node(void);
   public: Node(Element);
};
/* ******************************************************************* */
/* *******************    BINSTREE CLASS    ************************* */
/* ****************************************************************** */
class BinSTree
{     // Fields
   private: Node *root;
   private: Node *current;
   private: int error;

      // Constructor and public methods
   public: BinSTree(void);
   public: void insert(Element);
   public: void remove(KeyType);
   public: Element retrieve(void);
   public: void traverse(int order);
   public: void find(KeyType);
   public: void destroy(void);
   public: int isFull(void);
   public: int isEmpty(void);
   public: int hasError(void);

      // Private (utility) methods
   private: void preorder(Node *, int);
   private: void inorder(Node *, int);
   private: void postorder(Node *, int);
   private: Node* findParent(KeyType key);
   private: Node* findNode(KeyType key);
   private: Node* findRighty(Node *);
   private: void destroyNode(Node *);
};
/* ******************************************************************* */
/* *******************   NODE CLASS IMPLEMENTATION  ****************** */
/* ******************************************************************* */
Node::Node(void)
{
   left = right = 0;
}
/* ******************************************************************* */
Node::Node(Element el)
{
   left = right = 0;
   data = el;
}
/* ******************************************************************* */
/* ****************   BINSTREE CLASS IMPLEMENTATION   **************** */
/* ******************************************************************* */
BinSTree::BinSTree(void)
{
   root = current = 0;
   error = false;
}
/* ******************************************************************* */
void BinSTree::find(KeyType key)
{
   Node *p = findNode(key);
   if (p == 0)
      error = true;
   else
     {
       error = false;
       current = p;
     }
}
/* ******************************************************************* */
void BinSTree::insert(Element el)
{
  if (root == 0)
    root = new Node(el);
  else
    {
      Node *p = findNode(el);
      if (p == 0)                         // not found, ready to insert
	{
	  Node *parent = root;            // assume root is parent
	  if (p != root)                  // can find parent, so let's do
	    parent = findParent(el);
	  if (el > parent->data)
	    {
	      parent->right = new Node(el); 
	      current = parent->right;
	    }
	  else
	    {
	      parent->left = new Node(el);
	      current = parent->left;
	    }
	  error = false;                  // everything worked
	}
      else                                // duplicate key, not inserted
	error = true;
    }
}
/* ******************************************************************* */
void BinSTree::traverse(int order)
{
   if (order == PRE_ORDER)
      preorder(root, 0);
   else if (order == IN_ORDER)
      inorder(root, 0);
   else if (order == POST_ORDER)
      postorder(root, 0);
   else
      cout << "no such order " << endl;
}
/* ******************************************************************* */
Element BinSTree::retrieve(void)
{
  return current->data;
}
/* ******************************************************************* */
int BinSTree::isFull(void)
{ 
  return 0;
}
/* ******************************************************************* */
int BinSTree::isEmpty(void)
{
  return (root == 0);
}
/* ******************************************************************* */
int BinSTree::hasError(void)
{ 
  return error;
}
/* ******************************************************************* */
void BinSTree::remove(KeyType key)
{
  /* NOTE: This is not at all the easiest possible delete routine.
           However, it comes closest to the algorithm we discussed
	   in class without attempting to be too fancy at all.

           The algorithm could easily be improved by "factoring out"
	   its common elements, and even more by combining some of
	   the cases into one. */

  Node *p = findNode(key);             
  if (p == 0)                                 // is node is in the tree ?
    error = true;
  else                                        // yes, let's proceed
    {
      if ((p->right == 0) && (p->left == 0))       // deleting leaf - easy ...
	{
	  if (p != root)    // (can find parent now ...)   
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = 0;
	      else
		parent->left = 0;
	    }
	  else
	    root = 0;
          delete(p);
	  error = false;
	  current = root;
	}
      else if ((p->right == 0) && (p->left != 0))  // right subtree empty,
                                                   // left subtree not.
	{
	  if (p != root)    // (can find parent now ...)
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = p->left;
	      else
		parent->left = p->left;
	    }
	  else
	    root = root->left;
	  delete(p);
	  error = false;
	  current = root;
	}
      else if ((p->right != 0) && (p->left == 0))  // left subtree empty,
                                                   // right subtree not.
	{
	  if (p != root)    // (can find parent now ...)
	    {
	      Node *parent = findParent(key);
	      if (parent->data < key)
		parent->right = p->right;
	      else
		parent->left = p->right;
	    }
	  else
	    root = p->right;
	  delete(p);
	  error = false;
	  current = root;
	}
      else                                         // left and right 
                                                   // subtrees not empty
	{
	  Node *righty = findRighty(p->left);
	  Node *parent = findParent(righty->data);
	  p->data = righty->data;   // swapping data with righty
	  if (parent != p)
	    parent->right = righty->left;
	  else
	    p->left = righty->left;
	  delete(righty);
	  error = false;
	  current = root;
	}
    }
}
/* ******************************************************************* */
void BinSTree::destroy(void)
{
  destroyNode(root);
}

/* ******************************************************************* */

void BinSTree::inorder(Node *p, int level)
{
   if (p != 0)
     {
       inorder(p->left, level+1);
       cout << "Node " << p->data << " at level " << level << endl;
       inorder(p->right, level+1);
     }
}
/* ******************************************************************* */
void BinSTree::preorder(Node *p, int level)
{
  if (p != 0)
    {
      cout << "Node " << p->data << " at level " << level << endl;
      preorder(p->left, level+1);
      preorder(p->right, level+1);
    }
}
/* ******************************************************************* */
void BinSTree::postorder(Node *p, int level)
{ 
  if (p != 0)
    {
      postorder(p->left, level+1);
      postorder(p->right, level+1);
      cout << "Node " << p->data << " at level " << level << endl;
    }
}
/* ******************************************************************* */
void BinSTree::destroyNode(Node *p)
{
  if (p != 0)
    {
      destroyNode(p->left);
      destroyNode(p->right);
      delete(p);
    }
}
/* ******************************************************************* */
Node* BinSTree::findParent(KeyType key)
{
   Node *p = root, *q = 0;
   while ((p != 0) && (p->data != key))
     {
       q = p;
       if (p->data > key)
	 p = p->left;
       else
	 p = p->right;
     }
   return q;
}
/* ******************************************************************* */
Node* BinSTree::findNode(KeyType key)
  /* This function returns a pointer to the node containing the key 
     value 'key' if it is in the tree. Otherwise, it returns null */
{
   Node *p = root;
   while ((p != 0) && (p->data != key))
     if (p->data > key)
       p = p->left;
     else
       p = p->right;
   return p;
}
/* ******************************************************************* */
Node* BinSTree::findRighty(Node *p)
{
  Node *righty = p;
  while (righty->right != 0)
    righty = righty->right;
  cout << "found right-most node to be: " << righty->data << endl;
  return righty;
}
/* ******************************************************************* */
#endif



