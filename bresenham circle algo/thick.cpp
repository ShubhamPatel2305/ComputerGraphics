#include<conio.h>
#include<graphics.h>

void drawThickCircle(int x, int y, int xc, int yc, int radius, int thickness);
void drawCircle(int x, int y, int xc, int yc);

int main()
{
    int gd = DETECT, gm;
    int r, xc, yc, pk, x, y;
    initgraph(&gd, &gm, "");

    xc = 250;
    yc = 250;
    r = 150;
    int thickness = 10; // Adjust the thickness as needed
    pk = 3 - 2 * r;
    x = 0;
    y = r;
    drawThickCircle(x, y, xc, yc, r, thickness);

    while (x < y)
    {
        if (pk <= 0)
        {
            pk = pk + (4 * x) + 6;
            drawThickCircle(++x, y, xc, yc, r, thickness);
        }
        else
        {
            pk = pk + (4 * (x - y)) + 10;
            drawThickCircle(++x, --y, xc, yc, r, thickness);
        }
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}

void drawThickCircle(int x, int y, int xc, int yc, int radius, int thickness)
{
    for (int t = 0; t < thickness; ++t)
    {
        drawCircle(x, y + t, xc, yc);
    }
}

void drawCircle(int x, int y, int xc, int yc)
{
    putpixel(x + xc, y + yc, GREEN);
    putpixel(-x + xc, y + yc, GREEN);
    putpixel(x + xc, -y + yc, GREEN);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(y + xc, x + yc, GREEN);
    putpixel(y + xc, -x + yc, GREEN);
    putpixel(-y + xc, x + yc, GREEN);
    putpixel(-y + xc, -x + yc, GREEN);
}
