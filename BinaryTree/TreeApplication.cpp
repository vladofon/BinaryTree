﻿#include <iostream>
#include"BinaryTree.h"
#include"TreeMap.h"
#include"Comparable.h"

class Long : public Comparable<Long>
{
public:
	long data;

	Long(long data)
	{
		this->data = data;
	}

	Long()
	{
		this->data = 0;
	}

	inline bool equals(Long* item) const noexcept
	{
		if (item == this)
		{
			return true;
		}
		if (item == nullptr)
		{
			return false;
		}

		return (item->data == this->data);
	}

	inline long hashCode() const noexcept
	{
		long prime = 31;
		int result = 1;

		result = prime * result + data;
		return result;
	}
};

using namespace std;

int main()
{
	BinaryTree<Long, Long>* map = new TreeMap<Long, Long>();

	map->insert(Long(10), Long(20));
	map->insert(Long(11), Long(4563456));
	map->insert(Long(12), Long(54546));
	map->insert(Long(13), Long(5657));
	map->insert(Long(14), Long(2634560));
	map->insert(Long(15), Long(456743));
	map->insert(Long(16), Long(2356425));
	map->insert(Long(17), Long(56787));
	map->insert(Long(18), Long(2656));
	map->insert(Long(19), Long(565678));
	map->insert(Long(20), Long(23453654630));
	map->insert(Long(30), Long(678967));
	map->insert(Long(40), Long(47844444444));
	map->insert(Long(50), Long(5678576));
	map->insert(Long(60), Long(2678560));

	cout << map->find(Long(60)).data << endl;

	return 0;
}
