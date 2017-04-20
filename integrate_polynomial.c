#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int degree=0;
    printf(">>> Enter polynomial degree:\n");
    scanf("%d",&degree);

    printf(">>> NOTE: Polynomial is read from lowest power to highest:\n");
    printf("For example: A*x^0 + B*x^1 + C*x^2...\n");

    double *coefficients;
    coefficients = (double *)malloc(degree * sizeof(double));

    for(int i=0; i<=degree; i++){
        printf(">>> Enter coefficient #%d:\n",i);
        scanf("%lf",&coefficients[i]);
    }

    printf(">>> Enter limits of integration\n");

    double a=0;
    double b=0;
    printf(">>> a:");
    scanf("%lf",&a);
    printf(">>> b:");
    scanf("%lf",&b);

    // step size h
    double h=(b-a)/10;

    /*
        We need to iterate over all trapezoids, calculating
        F(x) at each edge.
     */

    double x=0.0,y=0.0,integral=0.0;
    for(int i=1;i<=9;i++){

       x = a + i*h;
       printf("ENDPOINT:%lf\t",x);
       // value of polynomial is sum of all
       // producs of coefficients and x^j 
       for(int j=0;j<=degree;j++){
           y += coefficients[j] * pow(x,j);
       } 
       printf("F(x):%lf\n",y);
       integral += y;
       y=0;
    }

    /*
     Now we need to compute F(x) at the edges
     and add the remaining value to the integral
     */
    double y_a=0,y_b=0;
    
    for(int j=0;j<=degree;j++){
        y_a += coefficients[j] * pow(a,j);
        y_b += coefficients[j] * pow(b,j);
    } 
    printf("ENDPOINT:%lf\tF(x):%lf\n",a,y_a);
    printf("ENDPOINT:%lf\tF(x):%lf\n",b,y_b);
    integral += (y_a + y_b)/2.0;

    printf(">>> Integral using trapezoidal rule of this polynomial is:\n");
    printf("%lf\n",integral*h);

	getchar();

    return 0;
}
