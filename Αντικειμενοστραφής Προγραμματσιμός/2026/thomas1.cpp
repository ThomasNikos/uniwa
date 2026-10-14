#include <iostream>
#include <cmath>

using namespace std;

const int N = 5;

struct PosInt
{
	int x;
	int y;
};

struct PosDouble
{
	double x;
	double y;
};

double distance(PosInt p)
{
	return sqrt((double)p.x * p.x + (double)p.y * p.y);
}

double distance(PosDouble p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

PosInt far(PosInt pos[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (distance(pos[i]) > distance(pos[max]))
			max = i;
	}
	return pos[max];
}

PosDouble far(PosDouble pos[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (distance(pos[i]) > distance(pos[max]))
			max = i;
	}
	return pos[max];
}

int main(int argc, char **argv)
{
	PosInt intPos[N] = { {3, 4}, {-1, 2}, {6, -5}, {0, 7}, {-8, 3} };
	cout << "INT" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "(" << intPos[i].x << ", " << intPos[i].y << ") d=" << distance(intPos[i]) << endl;
	}
	PosInt p1 = far(intPos, N);
	cout << "Far: (" << p1.x << ", " << p1.y << ")" << endl;

	PosDouble dblPos[N] = { {1.5, 2.3}, {-4.0, 3.7}, {6.1, -5.2}, {0.5, 8.9}, {-3.3, -3.3} };
	cout << "PosDouble:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "(" << dblPos[i].x << ", " << dblPos[i].y << ")  d=" << distance(dblPos[i]) << endl;
	}
	PosDouble p2 = far(dblPos, N);
	cout << "Farthest: (" << p2.x << ", " << p2.y << ")" << endl;

	return 0;
}
