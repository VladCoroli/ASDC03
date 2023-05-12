#pragma once

#include "Matrix4L.h"

template <typename T>
class Matrix4LIV : public Matrix4L<T> {
protected:
	T**** vect;
public:
	Matrix4LIV(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4, randomize<T> randomizer)
		: Matrix4L<T>(l1, h1, l2, h2, l3, h3, l4, h4, randomizer) {
		int i1, i2, i3, d, step;
		d = -l4;
		step = h4 - l4 + 1;
		vect = new T***[h1 - l1 + 1] - l1;
		for (i1 = l1; i1 <= h1; i1++) {
			*(vect + i1) = new T**[h2 - l2 + 1] - l2;
			for (i2 = l2; i2 <= h2; i2++) {
				*(*(vect + i1) + i2) = new T*[h3 - l3 + 1] - l3;
				for (i3 = l3; i3 <= h3; i3++, d += step) {
					*(*(*(vect + i1) + i2) + i3) = Matrix4Base<T>::source + d;
				}
			}
		}
	}

	virtual T& elem(int i1, int i2, int i3, int i4) override {
		return *(*(*(*(vect + i1) + i2) + i3) + i4);
	}

	virtual long size() override {
		return Matrix4L<T>::size() + sizeof(T*) * 4 + sizeof(T) * Matrix4L<T>::num;
	}
};