#pragma once

#include "Matrix4L.h"

template <typename T>
class Matrix4LDV : public Matrix4L<T> {
protected:
	int* d;
	const int dSize = 13;
public:
	Matrix4LDV(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4, randomize<T> randomizer)
		: Matrix4L<T>(l1, h1, l2, h2, l3, h3, l4, h4, randomizer) {

		d = new int[dSize];
		d[0] = 4; //dimension
		d[1] = l1;
		d[2] = h1;
		d[3] = l2;
		d[4] = h2;
		d[5] = l3;
		d[6] = h3;
		d[7] = l4;
		d[8] = h4;
		d[7] = Matrix4Base<T>::num; //num of elements
		d[8] = Matrix4L<T>::D1;
		d[9] = Matrix4L<T>::D2;
		d[10] = Matrix4L<T>::D3;
		d[11] = Matrix4L<T>::D4;
		d[12] = l1 * Matrix4L<T>::D1 + l2 * Matrix4L<T>::D2 + l3 * Matrix4L<T>::D3 + l4 * Matrix4L<T>::D4; //sum(ljxDj)
	}

	virtual T& elem(int i1, int i2, int i3, int i4) override {
		return Matrix4Base<T>::source[i1 * d[8] + i2 * d[9] + i3 * d[10] + i4 * d[11] - d[12]];
	}

	virtual long size() override {
		return Matrix4L<T>::size() + sizeof(int) * dSize;
	}
};