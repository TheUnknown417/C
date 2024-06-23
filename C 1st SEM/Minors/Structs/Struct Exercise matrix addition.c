typedef struct
{
    int rows;
    int col;
    int data[10][10];
}matrix;

void InputMatrix(matrix *ptr)
{
    printf("Rows :");
    scanf("%d", &ptr->rows);
    printf("Collumns :");
    scanf("%d", &ptr->col);

    printf("Enter Elements of Matrix \n");
    for(int i=0 ; i<ptr->rows ; i++)
    {
        for(int j=0 ; j<ptr->col ; j++)
        {
            scanf("%d",&ptr->data[i][j]);
        }
    }
}

matrix AddMatrix(matrix m1,matrix m2 ,matrix m3)
{

        for(int i=0 ; i<m1.rows ; i++)
        {
            for(int j=0 ; j<m1.col ; j++)
            {
                m3.data[i][j]=m1.data[i][j]+m2.data[i][j];
            }
        }

        return m3;
}
int main()
{
    matrix m1,m2,m3;

    printf("DATA FOR MATRIX 1\n");
    InputMatrix(&m1);

    printf("\n\n");

    printf("DATA FOR MATRIX 2\n");
    InputMatrix(&m2);

    if(m1.col==m2.col && m1.rows==m2.rows)
    {
        m3=AddMatrix(m1,m2,m3);

    printf("\nSum of Given matrices : \n");

    for(int i=0 ; i<m1.rows ; i++)
    {
        for(int j=0 ; j<m1.col ; j++)
        {
            printf("%d ",m3.data[i][j]);
        }
        printf("\n");
    }

    }
    else
    printf("\n\nError : Matrices Not Suitable for addition");


    return 0;
}
