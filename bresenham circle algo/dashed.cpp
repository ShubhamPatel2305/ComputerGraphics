#include<conio.h>
#include<graphics.h>

void drawDashedCircle(int x, int y, int xc, int yc, int dashLength);
void drawCircle(int x, int y, int xc, int yc);

int main()
{
    int gd = DETECT, gm;
    int r, xc, yc, pk, x, y;
    initgraph(&gd, &gm, "");

    xc = 250;
    yc = 250;
    r = 150;
    int dashLength = 2; // Adjust the dash length as needed
    pk = 3 - 2 * r;
    x = 0;
    y = r;
    drawDashedCircle(x, y, xc, yc, dashLength);

    while (x < y)
    {
        if (pk <= 0)
        {
            pk = pk + (4 * x) + 6;
            drawDashedCircle(++x, y, xc, yc, dashLength);
        }
        else
        {
            pk = pk + (4 * (x - y)) + 10;
            drawDashedCircle(++x, --y, xc, yc, dashLength);
        }
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}

void drawDashedCircle(int x, int y, int xc, int yc, int dashLength)
{
    static int count = 0; // Keep track of the number of pixels drawn
    if (count < dashLength)
    {
        drawCircle(x, y, xc, yc);
        count++;
    }
    else
    {
        count = 0; // Reset the count for the next dash
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
