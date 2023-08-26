#include <graphics.h>
#include <math.h>
#include <dos.h>
 
int main( )
{
float x,y,x1,y1,x2,y2,dx,dy,step;
//steps store how many times you will need to change pixels to reach from start to end
int i,gd=DETECT,gm;
 
initgraph(&gd,&gm,"");
 
x1=100;
y1=100;
x2=200;
y2=200;
 
dx=abs(x2-x1);
dy=abs(y2-y1);
 
if(dx>=dy) //slope less than or equal to 45 deg
step=dx;
else  // slope greater than 45 deg
step=dy;
 
dx=dx/step;
dy=dy/step;
 
x=x1;
y=y1;
 
i=1;
while(i<=step)
{
putpixel(x,y,5);
x=x+dx;
y=y+dy;
i=i+1;
delay(10);
}

delay(100000);
 
closegraph();

return 0;
}