#pragma once

#include "typedefs.h"

template<typename T>
class Matrix4Base {
protected:
	T* source;

	int l1, h1;
	int l2, h2;
	int l3, h3;
	int l4, h4;

	int D4, D3, D2, D1;

	int num;

public: 
	Matrix4Base(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4, randomize<T> randomizer) {
		this->l1 = l1;
		this->h1 = h1;
		this->l2 = l2;
		this->h2 = h2;
		this->l3 = l3;
		this->h3 = h3;
		this->l4 = l4;
		this->h4 = h4;

		num = (this->h1 - this->l1 + 1) * (this->h2 - this->l2 + 1) * (this->h3 - this->l3 + 1) * (this->h4 - this->l4 + 1);
		source = new T[num];
		for (int i = 0; i < num; i++)
			source[i] = randomizer(i);
	}

	virtual T& elem(int i1, int i2, int i3, int i4) {
		return this->source[(i1 - this->l1) * this->D1 + (i2 - this->l2) * this->D2 + (i3 - this->l3) * this->D3 + (i4 - this->l4) * this->D4];
	}
	virtual void show(bool output) = 0;
	virtual long size() {
		return sizeof(int) * (4 * 2 + 4 + 1) + sizeof(T) * num;
	}
};