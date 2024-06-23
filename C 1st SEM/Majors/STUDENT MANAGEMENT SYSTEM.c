#include<stdio.h>
#include<string.h>
#define MAX_NAME_LENGHT 50
#define MAX_NUM_STUDENTS 10

int Stu_n=0;

typedef struct
{
    char name[50];
    int roll_num;
    float gpa;
}student;


void Add_student(student *ptr)
{
    fflush(stdin);
    printf("Enter name : ");
    fgets(ptr->name,sizeof(ptr->name),stdin);

    printf("Enter Roll Number : ");
    scanf("%d",&ptr->roll_num);

     printf("Enter GPA : ");
     scanf("%f",&ptr->gpa);

    printf("Data Successfully Entered for student %d",Stu_n+1);
    printf("\n\n");

}

void Display_students(student *ptr)
{
    printf("Name : %s",ptr->name);
    printf("Roll Number : %d\n",ptr->roll_num);
    printf("GPA : %.2f\n",ptr->gpa);

    printf("\n");
}

void Search_student(student std[])
{
    int isPresent=0;
    int srch;
        printf("Enter the Roll Number for Searching : ");
        scanf("%d",&srch);
printf("Searching....\n");
    for(int i=0 ; i<Stu_n ; i++)
    {
        if(srch==std[i].roll_num)
        {
            isPresent=1;
            printf("Name : %s",std[i].name);
            printf("Roll No : %d\n",std[i].roll_num);
            printf("GPA : %.2f\n",std[i].gpa);
        }

    }
    if(isPresent==0)
        printf("No Record Found for the Entered Roll Number \n");

    printf("\n\n");
}

void Avg_gpa(student std[])
{
    float sum;
    for(int i=0 ; i<Stu_n ; i++)
    {
        sum+=std[i].gpa;
    }

    float avg=sum/Stu_n;

    printf("Average of GPA of the students present in the record is : %.2f",avg);
    printf("\n\n");
}
void Del_student(student std[])
{
    int isPresent=0;
    int del_roll;
    printf("Enter the Roll Number for Deleting :");
    scanf("%d",&del_roll);

     for(int i1=0 ; i1<Stu_n ; i1++)
    {
        if(del_roll==std[i1].roll_num)
        {
            isPresent=1;
            // Shift elements to fill the gap
            for(int i=i1 ; i<Stu_n ; i++)
            {
                /*strcpy(std[i].name,std[i+1].name);  shifting each variables of Struct one by one
                std[i].roll_num=std[i+1].roll_num;
                std[i].roll_num=std[i+1].roll_num;*/
                std[i]=std[i+1];                        // shifting the complete struct
            }
            printf("Record Successfully Deleted\n ");
            Stu_n--;
        }

    }
    if(isPresent==0)
             printf("No Record Found for the Entered Roll Number \n");

}

void Write_file(student std[])
{
    FILE *fptr=fopen("Student.txt","w");
    for(int i=0 ; i<Stu_n ; i++)
    {
        fprintf(fptr,"%s\t%d\t%f",std[i].name,std[i].roll_num,std[i].gpa);
    }
    fclose(fptr);
    printf("Data Successfully Written to FIle");

    printf("\n\n");
}

void Red_play(student std[])
{
    FILE *fptr=fopen("Student.txt","r");
    char name[MAX_NAME_LENGHT];
    int roll_num;
    float gpa;

    if(fptr!=NULL)
    {
        while(!feof(fptr))
        if(fscanf(fptr,"%s\t%d\t%f",name,&roll_num,&gpa)==3)
        {
            printf("Name : %s\n Roll Number :%d \n GPA : %.2f",name,roll_num,gpa);
        }

    }
    else
        printf("File Does not Exist");

    fclose(fptr);
    printf("\n\n");
}
int main()
{
    printf("*** Student Management System ***\n");
    printf("1. Add Student\n");
    printf("2. Display Student\n");
    printf("3. Search Student by Roll_Number\n");
    printf("4. Average of GPA of All Students\n");
    printf("5. Delete Student\n");
    printf("6. ADD to File\n");
    printf("7. Display Data From File\n");
    printf("0. EXIT\n\n");

    student student_list[MAX_NUM_STUDENTS];
    int choice;

do{

    printf("Enter your Choice : ");
    scanf("%d",&choice);
    printf("\n\n");


    switch(choice)
    {
    case 1:
        if(Stu_n<MAX_NUM_STUDENTS)
        {
              printf("***ADDING***\n");
            printf("Enter Information of Student %d\n",Stu_n+1);
            Add_student(&student_list[Stu_n]);
            Stu_n++;
            break;
        }
        else
            printf("Maximum number of Students Reached");

    case 2:
        printf("\n\n");
        printf("***Displaying***\n");
        for(int i=0 ; i<Stu_n ; i++)
        {
           printf("Info of Student %d\n",i+1);
           Display_students(&student_list[i]);
        }
        break;

    case 3:
        printf("***SEARCHING***\n");
        Search_student(student_list);
        break;

    case 4:
        printf("***AVERAGE***\n");
        Avg_gpa(student_list);
        break;

    case 5:
        printf("***DELETING***\n");
        Del_student(student_list);
        break;

    case 6:
        printf("***WRITING TO FILE***\n");
        Write_file(student_list);
        break;

    case 7:
        printf("***READING AND DISPALYING FROM FILE***\n");
        Red_play(student_list);
        break;


    default:
        printf("Enter a Valid Choice");
        printf("\n\n");
        break;


    }

    }while(choice!=0);
}
