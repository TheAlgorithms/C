#include<stdio.h>
#include<math.h>

#define SIZE 4                   //Set this size to whatever you want


void PrintMatrix(double A[SIZE][SIZE])
{
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			printf("%2.6lf\t",A[i-1][j-1]);
		}
		printf("\n");
	}
}
void PrintVector(double x[SIZE])
{
	for(int i=1;i<=SIZE;i++)
		printf("%2.6lf\n",x[i-1]);
	
}

int MatrixEqual(const double A[SIZE][SIZE],const double B[SIZE][SIZE])
{
	int t=0;
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			if(A[i-1][j-1]!=B[i-1][j-1])
				t++;
	return t;
}

int VectorEqual(const double A[SIZE],const double B[SIZE])
{
	int t=0;
	for(int i=1;i<=SIZE;i++)
			if(A[i-1]!=B[i-1])
				t++;
	return t;
}

void VectorSubtraction(const double A[SIZE],const double B[SIZE],double C[SIZE])
{
	for(int i=1;i<=SIZE;i++)
		C[i-1]=A[i-1]-B[i-1];
}

double VectorNorm(const double A[SIZE])
{
	double sum=0.0;
	for(int i=1;i<=SIZE;i++)
		sum+=A[i-1]*A[i-1];
	
	return sqrt(sum);
}

void SubtractVector(const double A[SIZE],const double B[SIZE],double C[SIZE])
{
	for(int i=1;i<=SIZE;i++)
		C[i-1]=A[i-1]-B[i-1];
}

void AbsoluteMatrix(const double A[SIZE][SIZE], double B[SIZE][SIZE])
{
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			B[i-1][j-1]=fabs(A[i-1][j-1]);
}
int IsZeroMatrix(const double A[SIZE][SIZE])
{
	int t=0;
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			if(fabs(A[i-1][j-1])!=0)
				t++;
	//printf("t = %d\n",t);
	return t;
}

void MatrixMult(const double S[SIZE][SIZE], const double T[SIZE][SIZE],double C[SIZE][SIZE])
{	
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			for(int k=1;k<=SIZE;k++)
				C[i-1][j-1]+=S[i-1][k-1]*T[k-1][j-1];
}


void MatrixSubtraction(const double A[SIZE][SIZE],const double B[SIZE][SIZE], double C[SIZE][SIZE])
{
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			C[i-1][j-1]=A[i-1][j-1]-B[i-1][j-1];
}


void MatrixVector(const double S[SIZE][SIZE], const double X[SIZE],double Y[SIZE])
{	
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
				Y[i-1]+=S[i-1][j-1]*X[j-1];

}


double ResidualNorm(const double A[SIZE][SIZE], const double x[SIZE],const double b[SIZE])        
{	
	double Y[SIZE]={0};
	double R[SIZE]={0};
	MatrixVector(A,x,Y);
	VectorSubtraction(b,Y,R); 
	return VectorNorm(R);

}

void Richardson(const double A[SIZE][SIZE],const double b[SIZE],double x[SIZE])
{
	int M=1000;                                         //Maximum number of iterations
	double r[SIZE]={0};
	for(int k=0;k<M;k++)
	{
		for(int i=0;i<SIZE;i++)                          //The Richardson algorithm solves a matrix system Ax=b
		{
			double sum=0;
			for(int j=0;j<SIZE;j++)
			{
				sum+=A[i][j]*x[j];
			}
			r[i]=b[i]-sum;
		}
		for(int i=0;i<SIZE;i++)
		{
			x[i]=x[i]+r[i];			
		}
		printf("%lf\n",ResidualNorm(A,x,b));
		if(ResidualNorm(A,x,b)<1e-6)
			break;
	}
	PrintVector(x);
}

int main()
{	int A={0};                               //Re-enter A and b assuming the form Ax=b
	int b={0};
	double x[SIZE]={0,0,0};
	Richardson(A,b,x);
	return 0;
}


