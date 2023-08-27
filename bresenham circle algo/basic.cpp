#include<conio.h>
#include<graphics.h>
void drawCircle(int x, int y, int xc, int yc);
int main()
{
	int gd = DETECT, gm;
	int r, xc, yc, pk, x, y;
	initgraph(&gd, &gm, "");
    xc=250;
    yc=250;
    r=150;
	pk = 3 - 2*r;
	x=0; y = r;
	drawCircle(x,y,xc,yc);
	while(x < y)
	{
		if(pk <= 0)
		{
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		}
		else
		{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
        delay(10);
	}

	getch();
	closegraph();
    return 0;
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,GREEN);
	putpixel(-x+xc,y+yc,GREEN);
	putpixel(x+xc, -y+yc,GREEN);
	putpixel(-x+xc, -y+yc, GREEN);
	putpixel(y+xc, x+yc, GREEN);
	putpixel(y+xc, -x+yc, GREEN);
	putpixel(-y+xc, x+yc, GREEN);
	putpixel(-y+xc, -x+yc, GREEN);
}