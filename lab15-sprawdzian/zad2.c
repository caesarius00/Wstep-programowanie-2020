#include <stdio.h>

void minMax(double *arr, int n, int m, double *min, double *max)
{
    *min=*arr;
    *max=*arr;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(*((arr+j*n)+i)>*max) *max=*((arr+j*n)+i);
            if(*((arr+j*n)+i)<*min) *min=*((arr+j*n)+i);
        }
    }
}
int main()
{
    double arr[5][3], min=0, max=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            arr[i][j]=i+j+0.3*i-0.14*j+j-3;
            printf("%5g ", arr[i][j]);
        }
        printf("\n");
    }
    minMax((double *)arr, 5, 3, &min, &max);
    printf("min: %g\nmax: %g\n", min, max);
    return 0;
}