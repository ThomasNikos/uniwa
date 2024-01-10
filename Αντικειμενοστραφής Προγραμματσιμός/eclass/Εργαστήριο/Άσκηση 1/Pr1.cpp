#include <iostream>

using namespace std;

int CreateMat (float * &);
void ReadMat (float *, int);
void PrintMat (float [], int );
void FindMax (float *, int, float &, float &);
float& FindMin (float [], int S);

int main (int argc, char *argv[])
{
    int N;
    float *Mat;
    float Meg1, Meg2;

    N = CreateMat (Mat);
    ReadMat (Mat, N);
    PrintMat (Mat, N);
    FindMax (Mat, N, Meg1, Meg2);
    cout << "Max = " << Meg1 << " 2nd Max " << Meg2 << endl;
    float &Mik = FindMin (Mat, N);
    Mik = Mik * 2;
    PrintMat (Mat, N);

    delete[] Mat;
    return 0;
}

int CreateMat (float * &Pin)
{
    int S;
    cout << "Mat Size : ";
    cin >> S;
    //Pin = new (nothrow) float [S];
    Pin = new float [S];
    return S;

}

void ReadMat (float *Arr, int S)
{
    for (int i = 0; i < S; i++)
    {
        cout << "Mat Value for Posis " << i + 1 << " : ";
        cin >> Arr[i];
    }

}

void PrintMat (float Pin[], int S)
{
    int i;
    for (i = 0; i < S; i++)
    {
        cout << "Posis " << i + 1 << " Value : " << Pin[i] << endl;
    }
}

void FindMax (float *Pin, int S, float &max1, float &max2)
{
    max1 = Pin[0];
    max2 = Pin[1];
    if (max2 > max1)
    {
        int tmp = max2;
        max2 = max1;
        max1 = tmp;
    }
    for (i = 2; i < S; i++)
    {
        if (Pin[i] > max1)
        {
            max2 = max1;
            max1 = Pin[i];
        }
        else
        {
            if (Pin[i] > max2 && Pin[i] != max1)
                max2 = Pin[i];
        }
    }
}

float& FindMin (float Pin[], int S)
{
    int Pos;
    Pos = 0;
    for (int i = 1; i < S; i++)
        if (Pin[i] < Pin[Pos])
            Pos = i;
    return Pin[Pos];
}


