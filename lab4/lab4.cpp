#include <iostream>
#include <ctime>
#include "Matrix4L.h"
#include "Matrix4C.h"
#include "Matrix4LDV.h"
#include "Matrix4CDV.h"
#include "Matrix4LIV.h"
#include "Matrix4CIV.h"

using namespace std;

clock_t begin_time;

int generator(int index);
char charGen(int index);

void start();
double stop();

int main()
{
	int l1 = 1, h1 = 4,
		l2 = -8, h2 = -6,
		l3 = 0, h3 = 2,
		l4 = -2, h4 = 0;

	start();
	Matrix4L<int> matrix4l(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	double init_4l = stop();
	start();
	matrix4l.show(true);
	double show_4l = stop();

	cout << endl << endl;

	start();
	Matrix4C<int> matrix4c(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	double init_4c = stop();
	start();
	matrix4c.show(true);
	double show_4c = stop();

	cout << endl;
	cout << "4L init time: " << init_4l << endl
		<< "4L pass through time: " << show_4l << endl
		<< "4L size: " << matrix4l.size() << endl << endl
		<< "4C init time: " << init_4c << endl
		<< "4C pass through time: " << show_4c << endl
		<< "4C size: " << matrix4l.size() << endl << endl;

	start();
	Matrix4LDV<int> matrix4ldv(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	cout << "4LDV init time: " << stop() << endl;
	start(); matrix4ldv.show(false);
	cout << "4LDV pass through time: " << stop() << endl
		<< "4LDV size: " << matrix4ldv.size() << endl << endl;

	start();
	Matrix4CDV<int> matrix4cdv(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	cout << "4CDV init time: " << stop() << endl;
	start(); matrix4cdv.show(false);
	cout << "4CDV pass through time: " << stop() << endl
		<< "4CDV size: " << matrix4cdv.size() << endl << endl;

	start();
	Matrix4LIV<int> matrix4liv(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	cout << "4LIV init time: " << stop() << endl;
	start(); matrix4liv.show(false);
	cout << "4LIV pass through time: " << stop() << endl
		<< "4LIV size: " << matrix4liv.size() << endl << endl;

	start();
	Matrix4CIV<int> matrix4civ(l1, h1, l2, h2, l3, h3, l4, h4, generator);
	cout << "4CIV init time: " << stop() << endl;
	start(); matrix4civ.show(false);
	cout << "4CIV pass through time: " << stop() << endl
		<< "4CIV size: " << matrix4civ.size() << endl << endl;
}

int generator(int index) {
	/*if (index == 35)
		return '0';
	else if (index < 26)
		return 'a' + index;
	return '1' + index - 26;*/
	return index;
}
char charGen(int index) {
	if (index == 35)
		return '0';
	else if (index < 26)
		return 'a' + index;
	return '1' + index - 26;
}
void start() {
	begin_time = clock();
}
double stop() {
	return float(clock() - begin_time) / CLOCKS_PER_SEC;
}