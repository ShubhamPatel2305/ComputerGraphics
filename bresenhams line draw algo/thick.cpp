#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawThickLine(int x0, int y0, int x1, int y1, int thickness)
{
    int dx, dy, p, x, y;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    x = x0;
    y = y0;

    p = 2 * dy - dx;

    for (int i = 0; i < thickness; ++i)
    {
        if (x1 < x0)
        {
            swap(x0, x1);
            swap(y0, y1);
        }

        while (x <= x1)
        {
            putpixel(x, y, 7);
            if (p >= 0)
            {
                if (y1 > y0)
                    y = y + 1;
                else
                    y = y - 1;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                p = p + 2 * dy;
            }
            x = x + 1;
        }

        x = x0;
        y = y0 + i;
        p = 2 * dy - dx;
        delay(10);
    }
}

int main()
{
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, "");

    x0 = 100;
    y0 = 100;
    x1 = 400;
    y1 = 200;
    int thickness = 5; // Adjust the thickness as needed

    drawThickLine(x0, y0, x1, y1, thickness);

    getch();

    return 0;
}
