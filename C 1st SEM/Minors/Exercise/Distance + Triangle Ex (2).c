#include<stdio.h>
#include<math.h>
double calculate_distance(double x1,double y1 , double x2 , double y2);
double calculate_area(double x1, double y1 , double x2 , double y2, double  x3, double y3);
double checking_the_point(double  x , double y, double x1, double y1,double x2,double y2,double x3,double y3);
int main()
{
    double x,y,x1,y1,x2,y2,x3,y3,res,verify;
    double z =calculate_distance(7,4,10,8);
    printf("The distance b/w the given points is %.2lf",z);

    printf("\n\n X-coordinate of Vertex A : ");
    scanf("%lf",&x1);
    printf("X-coordinate of Vertex A : ");
    scanf("%lf",&y1);
    printf("X-coordinate of Vertex B : ");
    scanf("%lf",&x2);
    printf("Y-coordinate of Vertex B : ");
    scanf("%lf",&y2);
    printf("X-coordinate of Vertex C : ");
    scanf("%lf",&x3);
    printf("Y-coordinate of Vertex C : ");
    scanf("%lf",&y3);

    res=calculate_area(x1,y1,x2,y2,x3,y3);
    if(res==0)
        printf("Invalid Triangle");
    else
        printf("%.2lf",res);


    printf("\nEnter a point to check whether it lies insides the triangle or not");
    printf("\nX-coordinate : ");
    scanf("%lf",&x);
    printf("\nY-coordinate : ");
    scanf("%lf",&y);



    verify=checking_the_point(x,y,x1,y1,x2,y2,x3,y3);
    if(verify==1)
        printf("Point lies inside the triangle");
    else
        printf("Point does not lie inside the triangle");

}

double calculate_distance(double x1,double y1 , double x2 , double y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double calculate_area(double x1, double y1 , double x2 , double y2, double  x3, double y3)
{
    double a,b,c,S;
    a=calculate_distance( x1, y1 ,  x2 ,  y2);
    b=calculate_distance( x2, y2 ,  x3 ,  y3);
    c=calculate_distance( x3,  y3 , x1 , y1);

    S=(a+b+c)/2;  // necessary for Heron's Formula


     if(a+b>c && b+c>a && a+c>b)        // the sum of any two sides must be greater than the third side
        return sqrt(S*(S-a)*(S-b)*(S-c));    // Heron's Formula
    else
        return 0;


}

double checking_the_point(double  x , double y, double x1, double y1,double x2,double y2,double x3,double y3)
{
    double PAB,PBC,PCA,ABC;
    PAB=calculate_area(x, y, x2, y2, x3, y3);
    printf("\n%lf",PAB);
    PBC=calculate_area(x1, y1, x, y, x3, y3);
    printf("\n%lf",PBC);
    PCA=calculate_area(x1, y1, x2, y2, x, y);

    printf("\n%lf",PCA);

    ABC=calculate_area(x1,y1,x2,y2,x3,y3);
    printf("\n%lf",ABC);

    if(ABC==PAB+PBC+PCA)
        return 1;
    else
    return 0;
}
