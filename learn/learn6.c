#include <stdio.h>
#include <math.h>

int main()
{
    float x = 3;

    x = sqrt(x);
    x = pow(x, 4);
    x = round(3.14);
    x = ceil(x);
    x = floor(x);
    x = abs(x);
    x = log(x);
    x = sin(x);
    x = cos(x);
    x = tan(x);

    printf("%f", x);

    return 0;
}