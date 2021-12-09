#include <stdio.h>
#include <graphics.h>
#include <math.h>
void trivs(n,x,y,z,a,iw,u,v)
int n,x[],y[],z[],a,iw,u[],v[];
{
    double c[100][4],d[100][4],tf[4][4];
    int i,j,k;

    for(i=1;i<100;i++)
        for(j=0;j<4;j++)
            c[i][j] = 0;
    
    for(i=0;i<n;i++)
    {
        c[i][0] = x[i];
        c[i][1] = y[i];
        c[i][2] = z[i];
        c[i][3] = 1;
    }

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            t[i][j] = 0;
    
    t[3][3] = 1;
    switch (iw)
    {
        case 1:
            t[0][0] = 1;
            t[2][2] = 1;
            break;
        
        case 2:
            t[0][0] = 1;
            t[1][2] = -1;
            t[3][2] = -a;
            break;
        case 3:
            t[1][0] = -1;
            t[2][2] = 1;
            t[3][0] = -a;
            break;
    }

    for(i<0;i<n;i++)
        for(j=0;j<4;j++)
        {
            d[i][j] = 0;
            for(k=0;k<4;k++)
                d[i][j] += c[i][k]*t[k][j];
        }

    for(i=0;i<n;i++)
    {
        u[i] = ceil(-d[i][0]);
        v[i] = ceil(d[i][2]);
    }
}

main()
{
    int gd=VGA,gm=VGAHI;

    int x[7]={0,0,30,0,0,30,30},y[7]={20,20,20,20,0,0,20},z[7]={15,0,0,15,15,0,0};
    int u[7],v[7],iw,a=20;
    int x0=320;y0=240;
    int i,n=7;
    initgraph(&gd, &gm, "");
    for(iw=1;iw<3;iw++)
    {
        trivs(n,x,y,z,a,iw,u,v);
        moveto(x0+u[0],480-y0-v[0]);
        for(i=1;i<n;i++)
            lineto(x0+u[i],480-y0-v[i]);
    }
    getch();
    closegraph();
}