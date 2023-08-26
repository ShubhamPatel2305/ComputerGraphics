#include<graphics.h>

void drawDottedCircle(int x0, int y0, int radius, int dotSpacing)
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

        // Check if it's time for a gap (dotSpacing pixels)
        if (drawPixel)
        {
            if (x >= dotSpacing) // Skip the gap if the current radius is smaller than the dotSpacing
            {
                x -= dotSpacing;
                drawPixel = false; // Toggle drawPixel for the gap
            }
        }
    }
}

int main()
{
    int gdriver = DETECT, gmode, error, x, y, r;
    initgraph(&gdriver, &gmode, "");

    r = 50;
    x = 150;
    y = 150;
    int dotSpacing = 2; // Adjust the dot spacing as needed

    drawDottedCircle(x, y, r, dotSpacing);

    delay(100000);

    return 0;
}
