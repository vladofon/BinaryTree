#pragma once
#include"BinaryTree.h"

template<class K, class V>
class TreeMap : public BinaryTree<K, V>
{
public:

   TreeMap()
   {
      this->root = nullptr;
      this->size = 0;
   }

   V find(K key)
   {
      long hashCode = key.hashCode();

      Node* node = findParentFor(hashCode);

      if (node->hash == hashCode)
      {
         return node->value;
      }

      return V();
   }

   void insert(K key, V value)
   {
      long hashCode = key.hashCode();

      Node* parent = findParentFor(hashCode);

      if (parent == nullptr)
      {
         this->root = new Node(key, value, hashCode, nullptr);
      }
      else if (parent->hash == hashCode)
      {
         parent = new Node(key, value, hashCode, parent);
      }
      else if (parent->hash > hashCode)
      {
         parent->pLeft = new Node(key, value, hashCode, parent);
      }
      else if (parent->hash < hashCode)
      {
         parent->pRight = new Node(key, value, hashCode, parent);
      }

      size++;
   }

   void remove(K key)
   {
      Node* toDelete = findParentFor(key.hashCode());

      Node* parent = toDelete->parent;

      bool isLeft = (parent->hash > toDelete->hash) ? true : false;

      if (toDelete != nullptr)
      {
         if (toDelete->pLeft != nullptr && toDelete->pRight != nullptr)
         {
            Node* newNode = toDelete->pRight;
            Node* lowerBranch = toDelete->pLeft;

            Node* lastLeft = findLastLeft(newNode);
            lastLeft->pLeft = lowerBranch;

            parent->add(newNode);
         }
         else if (toDelete->pLeft != nullptr)
         {
            Node* newNode = toDelete->pLeft;

            parent->add(newNode);
         }
         else if (toDelete->pRight != nullptr)
         {
            Node* newNode = toDelete->pRight;

            parent->add(newNode);
         }
         else
         {
            (isLeft) ? parent->pLeft = nullptr : parent->pRight = nullptr;
         }
      }

      delete[] toDelete;
   }

private:

   class Node
   {
   public:

      Node* pLeft;
      Node* pRight;
      Node* parent;
      K key;
      V value;
      long hash;

      Node(K key, V value, long hash, Node* parent, Node* pLeft = nullptr, Node* pRight = nullptr)
      {
         this->key = key;
         this->value = value;
         this->hash = hash;
         this->parent = parent;
         this->pLeft = pLeft;
         this->pRight = pRight;
      }

      void add(Node* item)
      {
         if (item->hash > hash)
         {
            pRight = item;
         }
         else
         {
            pLeft = item;
         }
      }
   };

   Node* root;
   long size;

   Node* findParentFor(long hashCode)
   {
      Node* current = this->root;

      if (size == 0 || size == 1)
      {
         return current;
      }

      while (true)
      {
         if (hashCode < current->hash)
         {
            if (current->pLeft == nullptr)
            {
               return current;
            }
            else {
               current = current->pLeft;
            }
         }
         else if (hashCode > current->hash)
         {
            if (current->pRight == nullptr)
            {
               return current;
            }
            else {
               current = current->pRight;
            }
         }
         else
         {
            return current;
         }
      }
   }

   Node* findLastLeft(Node* node)
   {
      while (node->pLeft != nullptr)
      {
         node = node->pLeft;
      }

      return node;
   }
};