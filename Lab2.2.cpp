#include <iostream>
#include <string>
using namespace std;

void Shifruvanna(string S[4], unsigned short Rez[4][32])
{
    unsigned char c;
    unsigned short r, t, b;
    short i, j, row, col;
    for (row = 0; row < 4; row++)
    {
        for (col = 0; col < 32; col++)
        {
            r = 0;
            c = S[row][col];
            r |= col;
            r |= row << 5;
            r |= c << 7;
            t = 1;
            b = 0;
            for (j = 0; j < 15; j++)
            {
                if (r & t)
                {
                    if (b == 0) b = 1;
                    else b = 0;
                }
                t <<= 1;
            }
            r |= b << 15;
            Rez[row][col] = r;
        }
    }
}
int main()
{
    string S[4];
    unsigned short Rez[4][32];
    short i, j;
    cout << "Введіть 4 рядки:" << endl;
    for (i = 0; i < 4; i++)
    {
        getline(cin, S[i]);
        while (S[i].length() < 32) S[i] += ' ';
    }
    Shifruvanna(S, Rez);
    cout << "\nРезультат:\n";
    for (i = 0; i < 4; i++)
    {
        cout << "Рядок " << i << ": ";
        for (j = 0; j < 32; j++)
        {
            cout << hex << Rez[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}