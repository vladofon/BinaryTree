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
			this->root = new Node(key, value, hashCode);
		}
		else if(parent->hash == hashCode)
		{
			parent = new Node(key, value, hashCode);
		}
		else if (parent->hash > hashCode)
		{
			parent->pLeft = new Node(key, value, hashCode);
		}
		else if (parent->hash < hashCode)
		{
			parent->pRight = new Node(key, value, hashCode);
		}

		size++;
	}

private:

	class Node
	{
	public:

		Node* pLeft;
		Node* pRight;
		K key;
		V value;
		long hash;

		Node(K key, V value, long hash, Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			this->key = key;
			this->value = value;
			this->hash = hash;
			this->pLeft = pLeft;
			this->pRight = pRight;
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
};