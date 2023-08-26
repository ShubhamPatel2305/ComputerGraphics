#include <graphics.h>
#include <math.h>
#include <dos.h>

void drawDashedLine(int x1, int y1, int x2, int y2, int dashLength) {
    float x, y, dx, dy, step;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        step = dx;
    else
        step = dy;

    dx = dx / step;
    dy = dy / step;

    x = x1;
    y = y1;

    int i = 1;
    while (i <= step) {
        if (i % (dashLength * 2) <= dashLength) {
            putpixel(x, y, 5);
        }

        x = x + dx;
        y = y + dy;
        i = i + 1;
        delay(10);
    }

    delay(100000);

    closegraph();
}

int main() {
    int x1 = 100;
    int y1 = 100;
    int x2 = 200;
    int y2 = 200;
    int dashLength = 5; // Adjust the dash length as needed

    drawDashedLine(x1, y1, x2, y2, dashLength);

    return 0;
}
