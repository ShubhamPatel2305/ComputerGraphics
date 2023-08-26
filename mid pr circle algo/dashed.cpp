#include<graphics.h>

void drawDashedCircle(int x0, int y0, int radius, int dashLength)
{
    int x = radius;
    int y = 0;
    int err = 0;
    bool drawPixel = true;

    while (x >= y)
    {
        if (drawPixel)
        {
            putpixel(x0 + x, y0 + y, 7);
            putpixel(x0 + y, y0 + x, 7);
            putpixel(x0 - y, y0 + x, 7);
            putpixel(x0 - x, y0 + y, 7);
            putpixel(x0 - x, y0 - y, 7);
            putpixel(x0 - y, y0 - x, 7);
            putpixel(x0 + y, y0 - x, 7);
            putpixel(x0 + x, y0 - y, 7);
        }

        drawPixel = !drawPixel; // Toggle drawPixel

        delay(100);

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

int main()
{
    int gdriver = DETECT, gmode, error, x, y, r;
    initgraph(&gdriver, &gmode, "");

    r = 150;
    x = 300;
    y = 300;
    int dashLength = 10; // Adjust the dash length as needed

    drawDashedCircle(x, y, r, dashLength);

    delay(100000);

    return 0;
}
