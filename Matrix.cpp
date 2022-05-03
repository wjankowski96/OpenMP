#include <stdio.h>
#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include "stdio.h"
#include <sys/time.h>
int main()
{
      vector<float> matrix;
  //readfile
  fstream file;
  file.open("matrixC.csv");
  string line;
  while (getline( file, line,'\n'))  
	{
	  istringstream templine(line); 
	  string data;
	  while (getline( templine, data,';')) 
	  {
	    matrix.push_back(stod(data.c_str()));  
	  }
	}
  file.close();
  int row =  3;//(line.size()/2);
  float matrix1[row][row+1];
  int a=0;
  int wiersz=matrix[a];
  cout<<"liczba wierszy "<<wiersz<<endl;
  a=1;
for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
        
       matrix1[i][j]  = matrix[a];
      
       a++;
    }
}

for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
    cout << " " << matrix1[i][j];
        if(j == 3)
            cout << endl;
    }}
/*
cout<<"-------------gauss-------------"<<endl<<endl;
int i,j,k,n=row;
float b;
float x[4];

for(j=1; j<=n; j++) {
      for(i=1; i<=n; i++) {
         if(i!=j) {
            b=matrix1[i][j]/matrix1[j][j];
            for(k=1; k<=n+1; k++) { 
               matrix1[i][k]=matrix1[i][k]-b*matrix1[j][k];

            }
         }
      }
   }

   for(int i=0; i<n; i++)
	{
		for(int j=0; j<n+1; j++)
		cout<<setw(8)<<setprecision(4)<<matrix1[i][j];
		cout<<endl;
	}
	
   cout<<"\nThe solution is:\n";
   for(i=1; i<=n; i++) {
      x[i]=matrix1[i][n+1]/matrix1[i][i];
      cout<<"x"<<i << "="<<setw(5)<<setprecision(5)<<x[i]<<" ";
   }

*/


/*
int N=row,i,j,k;
float temp=0,s, x[N];
for(int j=0; j<N-1; j++)
	{
		for(int i=j+1; i<N; i++)
		{
			temp=matrix1[i][j]/matrix1[j][j];

			for(int k=0; k<N+1; k++)
				matrix1[i][k]-=matrix1[j][k]*temp;
		}
	}
	
		//print the Upper Triangular matrix

	cout<<"\n ---------------------------------\n";
	cout<<"\n Upper Triangular Matrix is:\n";
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N+1; j++)
		cout<<setw(8)<<setprecision(4)<<matrix1[i][j];
		cout<<endl;
	}

	for(i=N-1; i>=0; i--)
	{
		s=0;
		for(j=i+1; j<N; j++)
		s += matrix1[i][j]*x[j];
		x[i]=(matrix1[i][N]-s)/matrix1[i][i];
	}

	//print values of x,y,z

	cout<<"\n The Solution is:\n";
	for(i=0; i<N; i++)
	 cout<<"x["<<setw(3)<<i+1<<"]="<<setw(7)<<setprecision(4)<<x[i]<<endl;

*/	

/* kolejny sposob
int i,j,k;
int n=row;
float res[n];
 for(i=0;i<n;i++) 
    {                   
        for(j=i+1;j<n;j++)
        {
            if(abs(matrix1[i][i]) < abs(matrix1[j][i]))
            {
                for(k=0;k<n+1;k++)
                {
                    
        matrix1[i][k]=matrix1[i][k]+matrix1[j][k];
                    matrix1[j][k]=matrix1[i][k]-matrix1[j][k];
                    matrix1[i][k]=matrix1[i][k]-matrix1[j][k];
                }
            }
      }
    }
   
     
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            float f=matrix1[j][i]/matrix1[i][i];
            for(k=0;k<n+1;k++)
            {
              matrix1[j][k]=matrix1[j][k]-f*matrix1[i][k];
      }
        }
    }
    
    for(i=n-1;i>=0;i--)          
    {                     
        res[i]=matrix1[i][n];
                    
        for(j=i+1;j<n;j++)
        {
          if(i!=j)
          {
              res[i]=res[i]-matrix1[i][j]*res[j];
    }          
  }
  res[i]=res[i]/matrix1[i][i];  
    }
cout<<"\n The Solution is:\n";
	for(i=0; i<n; i++)
	 cout<<"x["<<setw(3)<<i+1<<"]="<<setw(7)<<setprecision(4)<<res[i]<<endl;
*/
int n=row,i,j,k;
float x[n];
cout<<"\nThe matrix after Pivotisation is:\n";
    for (i=0;i<n;i++)            //print the new matrix
    {
        for (j=0;j<=n;j++)
            cout<<matrix1[i][j]<<setw(16);
        cout<<"\n";
    }    
    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                float t=matrix1[k][i]/matrix1[i][i];
                for (j=0;j<=n;j++)
                    matrix1[k][j]=matrix1[k][j]-t*matrix1[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }
     
    cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i=0;i<n;i++)            //print the new matrix
    {
        for (j=0;j<=n;j++)
            cout<<matrix1[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=n-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        x[i]=matrix1[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=i+1;j<n;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                x[i]=x[i]-matrix1[i][j]*x[j];
        x[i]=x[i]/matrix1[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout<<"\nThe values of the variables are as follows:\n";
    for (i=0;i<n;i++)
        cout<<x[i]<<endl;            // Print the va
  
    return 0;
}
