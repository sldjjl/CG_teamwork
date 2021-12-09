#include <stdio.h>
#include <graphics.h>
#include <math.h>
void trivs(n,x,y,z,a,iw,u,v)
int n,x[],y[],z[],a,iw;
double u[],v[];
{
    double c[100][4],d[100][4],t[4][4];
    double ct,st,cf,sf;
    double theta=45,fai=35.16,pi=3.1415926;
    ct = cos(theta/180*pi);
    st = sin(theta/180*pi);
    cf = cos(fai/180*pi);
    sf = sin(fai/180*pi);
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
        case 4:
            t[0][0] = ct;
            t[1][0] = -st;
            t[0][2] = -st*sf;
            t[1][2] = -ct*sf;
            t[2][2] = cf;
            t[3][3] = 1;
    }

    for(i=0;i<n;i++)
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

    int x[18]={180,180,0,0,90,90,180,180,180,180,90,90,90,90,90,90,0,0};
    int y[18]={0,120,120,120,120,120,120,0,0,0,0,120,0,0,120,0,0,120};
    int z[18]={0,0,0,150,150,75,75,75,0,75,75,75,75,150,150,150,150,150};
    double u[18],v[18];
    int iw,a=20;
    int x0=320;y0=240;
    int i,n=18;
    initgraph(&gd, &gm, "c:\\tc");
    for(iw=1;iw<=4;iw++)
    {
        trivs(n,x,y,z,a,iw,u,v);
        moveto(x0+(int)u[0],480-y0-(int)v[0]);
        for(i=1;i<n;i++)
            lineto(x0+(int)u[i],480-y0-(int)v[i]);
    }
    getch();
    closegraph();
}