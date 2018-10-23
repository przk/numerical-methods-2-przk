#include "..\include\neville.h"

double neville(double n, double *x, double *f, int sz)
{
	double **T=new double*[sz];
	for(int i=0; i<sz; i++)
	{
		T[i]=new double[sz];
		for(int j=0; j<sz; j++)
			T[i][j]=0;
	}
	
	for(int i=0; i<sz; i++)
	{
		T[i][0]=f[i];
		for(int k=1; k<=i; k++)
		{
			T[i][k]=T[i][k-1]+( T[i][k-1]-T[i-1][k-1] )/( (n-x[i-k])/(n-x[i])-1 );
		}
	}
	return T[sz-1][sz-1];
}
