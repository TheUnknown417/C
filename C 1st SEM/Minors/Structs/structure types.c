struct contract  // this struct has global scope , we can use this struct inside any function
{
    int salary;
} ;

int captain()
{
    typedef struct contract x;
    x babar; // instead of writing the complete struct again , we can use struct type(using struct tag)
    // contract is struct tag , and babar is struct variable
    babar.salary=100000;

    return babar.salary;
}

int main()
{
    typedef struct contract x;

    x Shaheen; // again accessing the global struct and creating further struct variables
    x Rizwan;

    Shaheen.salary=50000;
    Rizwan.salary=50000;


    printf("Salary of Rizwan  : %d",Rizwan.salary);
    printf("\nSalary of Shaheen : %d",Shaheen.salary);
    printf("\nSalary of Babar : %d",captain());
}
