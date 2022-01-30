#pragma once

template<class K, class V>
class BinaryTree
{
public:

   virtual V find(K key) = 0;

   virtual void insert(K key, V value) = 0;

   virtual void remove(K key) = 0;
};