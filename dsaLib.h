/*
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 2 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */

#ifndef A02_DSALIB_H
#define A02_DSALIB_H

#include <string>
#include <math.h>
#include <vector>

using namespace std;

class DSAException
{
      int _error;
      string _text;

    public:
      DSAException() : _error(0), _text("Success") {}
      DSAException(int err) : _error(err), _text("Unknown Error") {}
      DSAException(int err, const char *text) : _error(err), _text(text) {}

      int getError() { return _error; }
      string &getErrorText() { return _text; }
};

int max(int a, int b)
{
      return (a > b) ? a : b;
}

template <class T>
struct L1Item
{
      T data;
      L1Item<T> *pNext;
      L1Item() : pNext(NULL) {}
      L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List
{
      L1Item<T> *_pHead; // The head pointer of linked list
      size_t _size;      // number of elements in this list
    public:
      L1List() : _pHead(NULL), _size(0) {}
      ~L1List()
      {
            clean();
            _pHead = NULL;
      }

      void clean();
      bool isEmpty()
      {
            return _pHead == NULL;
      }
      size_t getSize()
      {
            return _size;
      }

      // T& at(const int& i);
      T &operator[](int i);

      bool find(T &a, int &idx);
      bool find(const T &a);
      int insert(int i, T &a);
      int remove(int i);

      int push_back(T &a);
      int insertHead(T &a);

      int removeHead();
      int removeLast();
      void deleteItems(T &);

      void reverse();
      void printList();
      void printL1List();
      T &at(int &);
      const T &at(int &) const;

      void traverse(void (*op)(T &))
      {
            L1Item<T> *p = _pHead;
            while (p)
            {
                  op(p->data);
                  p = p->pNext;
            }
      }
      void traverse(void (*op)(T &, void *), void *pParam)
      {
            L1Item<T> *p = _pHead;
            while (p)
            {
                  op(p->data, pParam);
                  p = p->pNext;
            }
      }
};

/// Insert item to the end of the list
/// Return 0 if success
template <class T>
int L1List<T>::push_back(T &a)
{
      if (_pHead == NULL)
      {
            _pHead = new L1Item<T>(a);
      }
      else
      {
            L1Item<T> *p = _pHead;
            while (p->pNext)
                  p = p->pNext;
            p->pNext = new L1Item<T>(a);
      }

      _size++;
      return 0;
}

/// Insert item to the front of the list
/// Return 0 if success
template <class T>
int L1List<T>::insertHead(T &a)
{
      L1Item<T> *p = new L1Item<T>(a);
      p->pNext = _pHead;
      _pHead = p;
      _size++;
      return 0;
}

/// Remove the first item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeHead()
{
      if (_pHead)
      {
            L1Item<T> *p = _pHead;
            _pHead = p->pNext;
            delete p;
            _size--;
            return 0;
      }
      return -1;
}

/// Remove the last item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeLast()
{
      if (_pHead)
      {
            if (_pHead->pNext)
            {
                  L1Item<T> *prev = _pHead;
                  L1Item<T> *pcur = prev->pNext;
                  while (pcur->pNext)
                  {
                        prev = pcur;
                        pcur = pcur->pNext;
                  }
                  delete pcur;
                  prev->pNext = NULL;
            }
            else
            {
                  delete _pHead;
                  _pHead = NULL;
            }
            _size--;
            return 0;
      }
      return -1;
}

template <class T>
void L1List<T>::clean()
{
      while (!isEmpty())
      {
            removeHead();
      }
}
template <class T>
void L1List<T>::printList()
{
      if (isEmpty())
            cout << "NULL";
      L1Item<T> *temp = _pHead;
      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->pNext;
      }
}

template <class T>
void L1List<T>::printL1List()
{
      if (isEmpty())
            cout << "-1\n";
      L1Item<T> *temp = _pHead;
      while (temp->pNext != NULL)
      {
            cout << temp->data << " ";
            temp = temp->pNext;
      }
      cout << temp->data << endl;
}
template <class T>
void L1List<T>::reverse()
{
      L1Item<T> *temp = 0;
      while (_pHead)
      {
            L1Item<T> *next = _pHead->pNext;
            _pHead->pNext = temp;
            temp = _pHead;
            _pHead = next;
      }
      _pHead = temp;
}

template <class T>
T &L1List<T>::at(int &place)
{
      // if(place < 0||place>_size-1) return;
      L1Item<T> *temp = _pHead;
      for (int i = 0; i < place; i++)
      {
            temp = temp->pNext;
      }

      return temp->data;
}

template <class T>
const T &L1List<T>::at(int &place) const
{
      L1Item<T> *temp = _pHead;
      for (int i = 0; i < place; i++)
      {
            temp = temp->pNext;
      }

      return temp->data;
}

template <class T>
T &L1List<T>::operator[](int i)
{
      return at(i);
}

template <class T>
bool L1List<T>::find(const T &a)
{
      L1Item<T> *temp = _pHead;
      for (unsigned int i = 0; i < getSize(); i++)
      {
            if (temp->data == a)
                  return true;
            temp = temp->pNext;
      }
      return false;
}

template <class T>
bool L1List<T>::find(T &a, int &idx)
{
      L1Item<T> *temp = _pHead;
      for (int i = 0; i < getSize(); i++)
      {
            if (temp->data == a)
            {
                  idx = i;
                  return true;
            }
            temp = temp->pNext;
      }
      idx = -1;
      return false;
}

template <class T>
void L1List<T>::deleteItems(T &item)
{
      auto temp = _pHead;
      if (isEmpty())
            return;

      while (temp->data == item)
      {
            _pHead = temp->pNext;
            delete temp;
            temp = _pHead;
            _size--;

            if (temp == nullptr)
                  return;
      }

      while (temp->pNext)
      {
            auto remove_item = temp->pNext;

            if (remove_item->data != item)
            {
                  temp = temp->pNext;
                  remove_item = nullptr;
                  continue;
            }

            temp->pNext = remove_item->pNext;
            delete remove_item;
            remove_item = nullptr;
            _size--;
      }
}

/************************************************************************
 * This section is for AVL tree
 ************************************************************************/
template <class T>
struct AVLNode
{
      T _data;
      AVLNode<T> *_pLeft, *_pRight;
#ifdef AVL_USE_HEIGHT
      int _height;
      AVLNode(T &a) : _data(a), _pLeft(NULL), _pRight(NULL), _height(1) {}
#else
      int _bFactor;
      AVLNode(T &a) : _data(a), _pLeft(NULL), _pRight(NULL), _bFactor(0) {}
#endif

      int height(AVLNode<T> *n)
      {
            if (n == NULL)
                  return 0;
            return _height;
      }
};

template <class T>
class AVLTree
{
      AVLNode<T> *_pRoot;

    public:
      AVLTree() : _pRoot(NULL) {}
      ~AVLTree() { destroy(_pRoot); }

      bool find(T &key, T *&ret) { return find(_pRoot, key, ret); }
      bool insert(T &key) { return insert(_pRoot, key); }
      bool remove(T &key) { return remove(_pRoot, key); }
      void traverseNLR(void (*op)(T &)) { traverseNLR(_pRoot, op); }
      void traverseLNR(void (*op)(T &)) { traverseLNR(_pRoot, op); }
      void traverseLRN(void (*op)(T &)) { traverseLRN(_pRoot, op); }

    protected:
      void destroy(AVLNode<T> *&pR);
      bool find(AVLNode<T> *pR, T &key, T *&ret);
      bool insert(AVLNode<T> *&pR, T &a);
      bool remove(AVLNode<T> *&pR, T &a);
      void traverseNLR(AVLNode<T> *pR, void (*op)(T &));
      void traverseLNR(AVLNode<T> *pR, void (*op)(T &));
      void traverseLRN(AVLNode<T> *pR, void (*op)(T &));

      void rotLeft(AVLNode<T> *&pR);
      void rotRight(AVLNode<T> *&pR);
      void rotLR(AVLNode<T> *&pR);
      void rotRL(AVLNode<T> *&pR);

      bool balanceLeft(AVLNode<T> *&pR);
      bool balanceRight(AVLNode<T> *&pR);

      void printAVL(AVLNode<T> *&pR);
};

template <class T>
void AVLTree<T>::destroy(AVLNode<T> *&pR)
{
      if (pR == NULL)
            return;

      if (pR->_pLeft == NULL && pR->_pRight == NULL)
      {
            delete pR;
            pR = NULL;
      }
      else
      {
            destroy(pR->_pLeft);
            destroy(pR->_pRight);
            delete pR;
            pR = NULL;
      }
}

template <class T>
bool AVLTree<T>::find(AVLNode<T> *pR, T &key, T *&ret)
{
      if (!pR)
            return false;

      if (pR->_data == key)
      {
            ret = &pR->_data;
            return true;
      }

      if (pR->_data < key)
            return find(pR->_pRight, key, ret);
      else
            return find(pR->_pLeft, key, ret);
}

template <class T>
bool AVLTree<T>::insert(AVLNode<T> *&pR, T &a)
{
      if (pR == NULL)
      {
            pR = new AVLNode<T>(a);
            return true;
      }

      if (a < pR->_data)
            insert(pR->_pLeft, a);
      else
      {
            if (a > pR->_data)
                  insert(pR->_pRight, a);
      }

      pR->_height = 1 + max(height(pR->_pLeft), height(pR->_pRight));

      int bal = height(pR->_pLeft) - height(pR->_pRight);

      if (bal > 1)
            balanceLeft(pR);
      else if (bal < -1)
            balanceRight(pR);
      else
            return false;
}

template <class T>
bool AVLTree<T>::remove(AVLNode<T> *&pR, T &a) {}

template <class T>
void AVLTree<T>::traverseNLR(AVLNode<T> *pR, void (*op)(T &))
{
      if (!pR)
            return;

      op(pR->_data);
      traverseNLR(pR->_pLeft, op);
      traverseNLR(pR->_pRight, op);
}

template <class T>
void AVLTree<T>::traverseLNR(AVLNode<T> *pR, void (*op)(T &))
{
      if (!pR)
            return;

      traverseLNR(pR->_pLeft, op);
      op(pR->_data);
      traverseLNR(pR->_pRight, op);
}

template <class T>
void AVLTree<T>::traverseLRN(AVLNode<T> *pR, void (*op)(T &))
{
      if (!pR)
            return;

      traverseLRN(pR->_pLeft, op);
      traverseLRN(pR->_pRight, op);
      op(pR->_data);
}

template <class T>
void AVLTree<T>::rotLeft(AVLNode<T> *&pR)
{
      AVLNode<T> *temp = pR->_pRight;
      AVLNode<T> *rot = temp->_pLeft;

      temp->_pLeft = pR;
      pR->_pRight = rot;

      pR->_height = max(height(pR->_pLeft), height(pR->_pRight)) + 1;
      temp->_height = max(height(pR->_pLeft), height(pR->_pRight)) + 1;
      temp = NULL;
}

template <class T>
void AVLTree<T>::rotRight(AVLNode<T> *&pR)
{
      AVLNode<T> *temp = pR->_pLeft;
      AVLNode<T> *rot = temp->_pRight;

      temp->_pRight = pR;
      pR->_pLeft = rot;

      pR->_height = max(height(pR->_pLeft), height(pR->_pRight)) + 1;
      temp->_height = max(height(pR->_pLeft), height(pR->_pRight)) + 1;
      temp = NULL;
}

template <class T>
void AVLTree<T>::rotLR(AVLNode<T> *&pR)
{
      rotLeft(pR->_pLeft);
      rotRigt(pR);
}

template <class T>
void AVLTree<T>::rotRL(AVLNode<T> *&pR)
{
      rotRight(pR->_pRight);
      rotLeft(pR);
}

template <class T>
bool AVLTree<T>::balanceLeft(AVLNode<T> *&pR)
{

      //height LR
      int lrh = pR->_pLeft->_pRight ? pR->_pLeft->_pRight->_height : 0;

      //height LL
      int llh = pR->_pLeft->_pLeft ? pR->_pLeft->_pLeft->_height : 0;

      int bal = lrh - llh;

      if (bal >= 1)
      {
            rotLR(pR);
            return true;
      }
      else if (bal <= -1)
      {
            rotRight(pR);
            return true;
      }
      else
            return false;
}

template <class T>
bool AVLTree<T>::balanceRight(AVLNode<T> *&pR)
{
      int rrh = pR->_pRight->_pRight ? pR->_pRight->_pRight->_height : 0;

      //height LL
      int rlh = pR->_pRight->_pLeft ? pR->_pRight->_pLeft->_height : 0;

      int bal = rrh - rlh;

      if (bal >= 1)
      {
            rotLeft(pR);
            return true;
      }
      else if (bal <= -1)
      {
            rotRL(pR);
            return true;
      }
      else
            return false;
}

template <class T>
void AVLTree<T>::printAVL(AVLNode<T> *&pR)
{
      if (!pR)
            return;

      cout << pR << "   ";
      printAVL(pR->_pLeft);
      printAVL(pR->_pRight);
}
#endif //A02_DSALIB_H
