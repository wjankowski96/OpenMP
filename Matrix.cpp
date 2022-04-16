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
/*
using vec    = vector<double>;
using matrix = vector<vec   >;


int main()
{
    float matrixA[3][3];
    float matrixB[3][3];
    float matrixC[3][3];
    
    ifstream myFile;
    myFile.open("matrix1.csv");
    
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; i < 3; i++)
            {

                string line;
                getline(myFile, line, ';');

                matrixA[i][j] = stoi(line);
                //printf("liczba A= %lf\n", matrixA[i][j]);
            }
        }
    
    myFile.close();

  
    ifstream myFileB;
        myFileB.open("matrix2.csv");
  
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; i < 3; i++)
            {

                string line1;
                getline(myFileB, line1, ';');

                matrixB[i][j] = stoi(line1);
                printf("liczba B= %lf\n", matrixB[i][j]);
            }
        }
    
    myFileB.close();

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                printf("wartosc macierzy = %lf", matrixC[i][j]);
            }



//==========================================================


 matrix M = readCSV( "matrix2.csv" );


//==========================================================

    return 0;
}
matrix readCSV( string filename )
{
   matrix M;

   ifstream in( filename );
   string line;
   while ( getline( in, line ) )                   // read a whole line of the file
   {
      stringstream ss( line );                     // put it in a stringstream (internal stream)
      vec row;
      string data;
      while ( getline( ss, data, ',' ) )           // read (string) items up to a comma
      {
         row.push_back( stod( data ) );            // use stod() to convert to double; put in row vector
      }
      if ( row.size() > 0 ) M.push_back( row );    // add non-empty rows to matrix
   }
   return M;
}
*/
#include <iostream>
using namespace std;
FILE * myFile3 = stdout;
#include <stdio.h>
//#include <process.h>
int main()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (c1!=r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }

    // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }
/*
// Zapisywanie do pliku
std::fstream myFile3;

//fopen( myFile3, "matrix3.csv", "w" );
//myFile3.open("matrix3.csv", ios::out | ios::app);
myFile3.open("matrix3.csv");
//std::ofstream myFile3(matrix3.csv);
    
    // Send the column name to the stream
    myFile3 << "Liczba kolumn" << mult << "\n";
    
    // Send data to the stream
    for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++i)
    {
        fwrite(myFile3, "%d\n", mult[i][j]);
    }
    
    // Close the file
    myFile3.close();







*/
fstream file;
    file.open ("matrix3.csv", ios::out | ios::app);
    if (file) {
        
        for(int i = 0; i < c1; i++){
            for(int j = 0; j < c2; j++)
            {
                
                file << mult[i][j]<<";";
                
                
            }
            file <<  endl;
        }
            
    }else{
        printf("Blad pliku");
    }
    
    file.close();
    return 0;
}
