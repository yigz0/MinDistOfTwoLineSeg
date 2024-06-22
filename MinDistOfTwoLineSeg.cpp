#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
double MIN;

struct Point
{
    LL x, y;
} p[5];

void setpoints(LL i)
{
    if(i < 3)
    {
        p[1].x = Ax; p[1].y = Ay;
        p[2].x = Bx; p[2].y = By;

        if(i == 1)
        {
            p[3].x = Cx; p[3].y = Cy;
        }
        else
        {
            p[3].x = Dx; p[3].y = Dy;
        }
    }
    else
    {
        p[1].x = Cx; p[1].y = Cy;
        p[2].x = Dx; p[2].y = Dy;

        if(i == 3)
        {
            p[3].x = Ax; p[3].y = Ay;
        }
        else
        {
            p[3].x = Bx; p[3].y = By;
        }
    }
}

double dist(double P)
{
    double X = P * p[1].x + (1 - P) * p[2].x;
    double Y = P * p[1].y + (1 - P) * p[2].y;

    return sqrt((X - p[3].x) * (X - p[3].x) + (Y - p[3].y) * (Y - p[3].y));
}

int main(void)
{
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
    for(LL i = 1; i <= 4; i++)
    {
        setpoints(i);

        double lo = 0, hi = 1;
        for(LL i = 1; i <= 100; i++)
        {
            double p = 0.51 * lo + 0.49 * hi;
            double q = 0.49 * lo + 0.51 * hi;
            if(dist(p) <= dist(q)) hi = q;
            else lo = p;
        }

        if(i == 1) MIN = dist(lo);
        else MIN = min(MIN, dist(lo));
    }

    printf("%.10lf", MIN);

    return 0;
}