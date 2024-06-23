 #include<stdio.h>
void input_matrix(int r , int c, int arr[r][c]);
void matrix_multiply(int ar, int ac, int a[ar][ac], int br, int bc, int b[br][bc], int c[ar][bc] );
void Output_matrix(int r , int c , int a[r][c]);

int main()
{
    int arows,acols,brows,bcols;

    printf("Enter Rows and columns of 1st matrix : ");
    scanf("%d %d", &arows ,&acols);

    int matrix1[arows][acols];

    input_matrix(arows,acols,matrix1);

    printf("Enter Rows and columns of 2nd matrix : ");
    scanf("%d %d",&brows,&bcols);

    if(acols!=brows)
        {
            printf("Sorry , Multiplication Not Possible ");
        return 0;
        }

    else
    {
        int matrix2[brows][bcols];

        input_matrix(brows,bcols,matrix2);

        int mul_matrix[arows][bcols];

        matrix_multiply(arows,acols,matrix1,brows,bcols,matrix2,mul_matrix);

          printf("The Product Matrix is as follow :\n\n");
        Output_matrix(arows,bcols,mul_matrix);

        return 0;

    }


}
void input_matrix(int r , int c, int a[r][c])
{
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void matrix_multiply(int ar, int ac, int a[ar][ac], int br, int bc, int b[br][bc], int c[ar][bc] )
{

    for(int i=0 ; i<ar ; i++)
    {
        for(int j=0 ; j<bc ; j++)
        {
            int sum=0;
            for(int k=0 ; k<ac ; k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}

void Output_matrix(int r , int c , int a[r][c])
{

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}


