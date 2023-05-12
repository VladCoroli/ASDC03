#pragma once

#include "Matrix4C.h"

template <typename T>
class Matrix4CIV : public Matrix4C<T> {
protected:
	T**** vect;
public:
	Matrix4CIV(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4, randomize<T> randomizer)
		: Matrix4C<T>(l1, h1, l2, h2, l3, h3, l4, h4, randomizer) {
		int i2, i3, i4, d, step;
		d = -l1;
		step = h1 - l1 + 1;
		vect = new T***[h4 - l4 + 1] - l4;
		for (i4 = l4; i4 <= h4; i4++) {
			*(vect + i4) = new T**[h3 - l3 + 1] - l3;
			for (i3 = l3; i3 <= h3; i3++) {
				*(*(vect + i4) + i3) = new T*[h2 - l2 + 1] - l2;
				for (i2 = l2; i2 <= h2; i2++, d += step) {
					*(*(*(vect + i4) + i3) + i2) = Matrix4Base<T>::source + d;
				}
			}
		}
	}

	virtual T& elem(int i1, int i2, int i3, int i4) override {
		return *(*(*(*(vect + i4) + i3) + i2) + i1);
	}
	virtual long size() override {
		return Matrix4C<T>::size() + sizeof(T*) * 4 + sizeof(T) * Matrix4C<T>::num;
	}
};