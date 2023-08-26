#include<graphics.h>

void drawThickCircle(int x0, int y0, int radius, int thickness)
{
    int x = radius;
    int y = 0;
    int err = 0;

    for (int t = 0; t < thickness; ++t)
    {
        while (x >= y)
        {
            putpixel(x0 + x, y0 + y, 7);
            putpixel(x0 + y, y0 + x, 7);
            putpixel(x0 - y, y0 + x, 7);
            putpixel(x0 - x, y0 + y, 7);
            putpixel(x0 - x, y0 - y, 7);
            putpixel(x0 - y, y0 - x, 7);
            putpixel(x0 + y, y0 - x, 7);
            putpixel(x0 + x, y0 - y, 7);

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

        x = radius + t + 1;
        y = 0;
        err = 0;
    }
}

int main()
{
    int gdriver = DETECT, gmode, error, x, y, r;
    initgraph(&gdriver, &gmode, "");

    r = 50;
    x = 150;
    y = 150;
    int thickness = 10; // Adjust the thickness as needed

    drawThickCircle(x, y, r, thickness);

    delay(100000);

    return 0;
}
