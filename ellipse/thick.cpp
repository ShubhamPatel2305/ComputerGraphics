#include<dos.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void drawThickEllipse(int xs1, int ys1, int rx, int ry, int thickness);
void display(int xs, int ys, int x, int y);

void ellips1(int xs1, int ys1, int rx, int ry, int thickness)
{
    int x, y;
    float d1, d2, dx, dy;
    x = 0;
    y = ry;
    d1 = pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2));
    dx = 2 * pow(ry, 2) * x;
    dy = 2 * pow(rx, 2) * y;

    drawThickEllipse(xs1, ys1, x, y, thickness); // Initial display

    do // region one
    {
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * (pow(ry, 2)));
            d1 = d1 + dx + (pow(ry, 2));
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * (pow(ry, 2)));
            dy = dy - (2 * (pow(rx, 2)));
            d1 = d1 + dx - dy + (pow(ry, 2));
        }
        drawThickEllipse(xs1, ys1, x, y, thickness);
        delay(10);
    } while (dx < dy);
    do
    {
        if (d2 > 0)
        {
            x = x;
            y--;
            dy = dy - (2 * (pow(rx, 2)));
            d2 = d2 - dy + pow(rx, 2);
        }
        else
        {
            x++;
            y--;
            dy = dy - (2 * (pow(rx, 2)));
            dx = dx + (2 * (pow(ry, 2)));
            d2 = d2 + dx - dy + pow(rx, 2);
        }
        drawThickEllipse(xs1, ys1, x, y, thickness);
        delay(10);
    } while (y > 0);
}

void drawThickEllipse(int xs1, int ys1, int x, int y, int thickness)
{
    for (int t = 0; t < thickness; ++t)
    {
        display(xs1, ys1, x, y + t);
        display(xs1, ys1, x, y - t);
    }
}

void display(int xs, int ys, int x, int y)
{
    putpixel(xs + x, ys + y, WHITE);
    putpixel(xs - x, ys - y, WHITE);
    putpixel(xs + x, ys - y, WHITE);
    putpixel(xs - x, ys + y, WHITE);
}

int main()
{
    int xs1, ys1;
    float rx1, ry1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    xs1 = 320;
    ys1 = 240;
    rx1 = 80;
    ry1 = 40;
    int thickness = 5; // Adjust the thickness as needed

    ellips1(xs1, ys1, rx1, ry1, thickness);

    getch();
    closegraph();

    return 0;
}
