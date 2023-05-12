#pragma once
#include "Matrix4Base.h"
#include <iostream>
using namespace std;

template<typename T>
class Matrix4C : public Matrix4Base<T> {

public:
	Matrix4C(int l1, int h1, int l2, int h2, int l3, int h3, int l4, int h4, randomize<T> randomizer)
		: Matrix4Base<T>(l1, h1, l2, h2, l3, h3, l4, h4, randomizer) {
		this->D1 = 1;
		this->D2 = (this->h1 - this->l1 + 1) * this->D1;
		this->D3 = (this->h2 - this->l2 + 1) * this->D2;
		this->D4 = (this->h3 - this->l3 + 1) * this->D3;
	}

	/*virtual T& elem(int i1, int i2, int i3, int i4) override {		
		return this->source[(i1 - this->l1) * D1 + (i2 - this->l2) * D2 + (i3 - this->l3) * D3 + (i4 - this->l4) * D4];
	}*/

	virtual void show(bool output) override {
		int i1, i2, i3, i4, item;
		output && cout << "i1\ti2\ti3" << endl;
		for (i1 = this->l1; i1 <= this->h1; i1++) {
			output && cout << i1 << endl;
			for (i2 = this->l2; i2 <= this->h2; i2++) {
				output && cout << "|\t" << i2 << endl;
				for (i3 = this->l3; i3 <= this->h3; i3++) {
					output && cout << "|\t|\t" << i3 << ": ";
					//cout << "(" << i1 << "," << i2 << "," << i3 << ") : ";
					for (i4 = this->l4; i4 <= this->h4; i4++) {
						item = this->elem(i1, i2, i3, i4);
						output && cout << item << " ";
						//cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << this->elem(i1, i2, i3, i4) << endl;
					}
					output && cout << endl;
				}
			}
		}
	}
};