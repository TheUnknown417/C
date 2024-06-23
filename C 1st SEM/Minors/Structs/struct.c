#include<stdio.h>
int main()
{
    struct
    {

        int age;                    // properties or characteristics or members
        char *university;
        float gpa;

    } ali,ahmad; // struct variables


    ali.age=18;    // accessing the members of the structure
    ahmad.age=19;

    ali.university="COMSATS";
    ahmad.university="COMSATS";

    ali.gpa=3.9;
    ahmad.gpa=4.0;


    printf("Data of Ali \nAge : %d \nUni : %s \nGPA : %.1f",ali.age,ali.university,ali.gpa);
    printf("\n\nData of Ahmad \nAge : %d \nUni : %s \nGPA : %.1f",ahmad.age,ahmad.university,ahmad.gpa);
}
