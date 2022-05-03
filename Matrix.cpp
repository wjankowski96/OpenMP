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
      vector<double> matrix;
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
  double matrix1[2][3];
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

cout<<"-------------gauss-------------"<<endl<<endl;
double b,x[4];
int n=3;
for(int j=0; j<n; j++) {
      for(int i=0; i<n; i++) {
         if(i!=j) {
            b=matrix1[i][j]/matrix1[j][j];
            for(int k=0; k<n+1; k++) { 
               matrix1[i][k]=matrix1[i][k]-b*matrix1[j][k];
               cout<<"wynik: "<<matrix1[i][k]<<endl;
            }
         }
      }
   }
   cout<<"\nThe solution is:\n";
   for(int i=0; i<n; i++) {
      x[i]=matrix1[i][n+1]/matrix1[i][i];
      cout<<"x"<<i << "="<<x[i]<<" "<<endl;
   }

  
    return 0;
}
