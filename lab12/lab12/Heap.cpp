#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
	std::cout << x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1); // левого 
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); // вычисление индекса правого доччернего элемента
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1; // Вычисление индекса родителя для массива 
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractMin(int a) // Неправильно
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[a];
			storage[a] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	int Heap::find_min() {
		if (size == 0) {
			return -1; // Куча пуста, нет элемента для возврата
		}
		int** intPtr = reinterpret_cast<int**>(storage); // преобразуем void** в int**
		int minIndex = 0;
		for (int i = 1; i < size; i++) {
			if (*intPtr[i] < *intPtr[minIndex]) { 
				minIndex = i;
			}
		}
		return minIndex; // Возвращаем индекс минимального элемента
	}

	void* Heap::extractI(int i) // Допилить НЕРАБОТАЕТ ТАК КАК НАДО
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[i];
			storage[i] = storage[size - 1];
			size--;
			heapify(i);
		} return rc;
	}
	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	void** Heap::extract_heap() {
		return storage;
	}
	void Heap::unionHeap()
	{

	}
}
