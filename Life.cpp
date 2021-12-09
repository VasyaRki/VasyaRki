#include <iostream>
#include <ctime>
#include <windows.h>
#define height 30
#define width 120
#define generation 300
const char pixel = '*';

using namespace std;

void field_drawing(char screan[])
{
    for (int i = 0; i < generation; i++)
    {
        int _i = rand() % (height * width);
        screan[_i] = pixel;
    }

    for (int i = 0; i < width * height; i++)
    {
        if (screan[i] != pixel) screan[i] = ' ';
    }
}

int evolution(char screan[], int i, int j) {

    int counter = 0;

    if (screan[i + j * width - width] == pixel) counter++;

    if (screan[i + j * width - width - 1] == pixel) counter++;

    if (screan[i + j * width - width + 1] == pixel) counter++;


    if (screan[i + j * width + width] == pixel) counter++;


    if (screan[i + j * width + width + 1] == pixel) counter++;

    if (screan[i + j * width + width - 1] == pixel) counter++;

    if (screan[i + j * width - 1] == pixel) counter++;

    if (screan[i + j * width + 1] == pixel) counter++;

    return counter;
};

int main()
{
    srand(time(NULL));
    char screan[height * width + 1];
    screan[height * width] = '\0';
    int kill = 0, live = 0, _kill[height * width], _live[height * width];

    field_drawing(screan);

    for (int k = 2; k < 1000000; k++)
    {
        kill = 0, live = 0;
        for (int i = 0; i < width; i++)
        {

            for (int j = 0; j < height; j++)
            {

                int counter = evolution(screan, i, j);

                if (counter == 3)
                {
                    _live[live] = i + j * width;
                    live++;
                }
                else if (counter > 3 || counter < 2)
                {
                    _kill[kill] = i + j * width;
                    kill++;
                }
            }
        }
        for (int n = 0; n < live; n++)
        {
            screan[_live[n]] = pixel;
        }
        for (int n = 0; n < kill; n++)
        {
            screan[_kill[n]] = ' ';
        }
        cout << screan;
        Sleep(500); 
    }
}
