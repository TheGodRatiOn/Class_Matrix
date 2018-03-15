#include <iostream>
#include <new>
#include <fstream>

using namespace std;

class Matrix
{
	int nLines, mColumns;
	int **pMatrix;
	public :
		Matrix();
		Matrix (int NumberOfLines, int NumberOfColumns);
		~Matrix ();
		int get_nLines();
		int get_mColumns();
                Matrix(const Matrix &Obj1);
                int get_Element(int a, int b);
		void Change_Value(int a, int b, int c);
		int& operator()(int a, int b);
		Matrix operator=(Matrix Obj1);
		Matrix operator+=(Matrix Obj1);
		Matrix operator-=(Matrix Obj1);
		Matrix operator*=(Matrix Obj1);
		Matrix operator+=(int k);
		Matrix operator-=(int k);
		Matrix operator*=(int k);
		void Transpose (void);
		Matrix Dot(Matrix Obj1);
                friend ostream& operator << (ostream &output, const Matrix Obj1);
                friend istream& operator >> (istream &input, const Matrix &Obj1);
};

Matrix :: Matrix( int NumberOfLines, int NumberOfColumns)
{
    if ((NumberOfLines > 0) && (NumberOfColumns > 0))
    {
        nLines = NumberOfLines;
        mColumns = NumberOfColumns;
        pMatrix = NULL;

        pMatrix = new int*[nLines];
        for (int i = 0; i < nLines; i++)
        {
            pMatrix[i] = new int[nLines];
            for (int j = 0; j < mColumns; j++)
            {
                pMatrix[i][j] = 0;
            }
        }
    }
    else
    {
	 nLines = 0;
         mColumns = 0;
         pMatrix = NULL;
    }
}

Matrix :: Matrix()
{
   nLines = 0;
   mColumns = 0;
   pMatrix = NULL;
}

Matrix :: ~Matrix()
{
    for (int i = 0; i < this -> nLines; i++)
    {
         delete this -> pMatrix[i];
    }
    delete this -> pMatrix;
    this -> pMatrix = NULL;
}

Matrix :: Matrix(const Matrix &Obj1)
{
   this -> nLines = Obj1.nLines;
   this -> mColumns = Obj1.mColumns;
   pMatrix = NULL;

    pMatrix = new int*[nLines];
    for (int i = 0; i < nLines; i++)
    {
        pMatrix[i] = new int[nLines];
        for (int j = 0; j < mColumns; j++)
	{
            pMatrix[i][j] = 0;
	}
    }
}

int Matrix :: get_nLines()
{
   return nLines;
}

int Matrix :: get_mColumns()
{
   return mColumns;
}

ostream& operator << (ostream &output, const Matrix Obj1)
{
    for (int i = 0; i < Obj1.nLines; i++)
    {
        output << endl;
        for (int j = 0; j < Obj1.mColumns;j++)
        {
		
            output << Obj1.pMatrix[i][j] << " ";
        }
    }
}

istream& operator >> (istream &input, const Matrix &Obj1)
{
    for (int i = 0; i < Obj1.nLines;i++)
	{
	    for (int j = 0; j < Obj1.mColumns; j++)
	    {
	    	input >> Obj1.pMatrix[i][j];
	    }
	}
}

void Matrix :: Change_Value(int a, int b, int c)
{
	pMatrix[a][b] = c;
}

int Matrix :: get_Element(int a, int b)
{
	return pMatrix[a][b];
}

Matrix operator+(Matrix Obj1, Matrix Obj2)
{
	if ((Obj1.get_nLines() == Obj2.get_nLines()) && (Obj1.get_mColumns() == Obj2.get_mColumns()))
	{
	    Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());

     	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

	    for (int i = 0; i < a; i++)
	    {
		 for (int j = 0; j < b; j++)
		 {
		       temp.Change_Value(i, j, Obj1.get_Element(i, j) + Obj2.get_Element(i, j));
		 }
	     }
	     return temp;
	}
	else
	{
	    throw "Wrong input for sum of Matrixes" ;
	}
}

Matrix operator-(Matrix Obj1, Matrix Obj2)
{
	if ((Obj1.get_nLines() == Obj2.get_nLines()) && (Obj1.get_mColumns() == Obj2.get_mColumns()))
	{
	    Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());

     	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

	    for (int i = 0; i < a; i++)
	    {
		   for (int j = 0; j < b; j++)
		   {
			temp.Change_Value(i, j, Obj1.get_Element(i, j) - Obj2.get_Element(i, j));
		   }
	    }
	    return temp;
	}
	else
	{
		 throw "Wrong input for substraction of Matrixes" ;
	}
}

Matrix operator+(Matrix Obj1, int k)
{
	if ((Obj1.get_nLines() > 0 ) && (Obj1.get_mColumns() > 0))
	{

		Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());

		int a = Obj1.get_nLines();
	        int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				temp.Change_Value(i, j, Obj1.get_Element(i, j)  + k);
			}
		}
		return temp;
	}
	else
	{
		 throw "Wrong input for summ of int and Matrix";
	}
}

Matrix operator-(Matrix Obj1, int k)
{
	if ((Obj1.get_nLines() > 0 ) && (Obj1.get_mColumns() > 0))
	{

		Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());
		int a = Obj1.get_nLines();
	        int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				temp.Change_Value(i, j, Obj1.get_Element(i, j)  - k);
			}
		}
		return temp;
	}
	else
	{
		cout << "Wrong input for substraction of int and Matrix" << endl;
	}
}

Matrix operator*(Matrix Obj1, int k)
{
	if ((Obj1.get_nLines() > 0 ) && (Obj1.get_mColumns() > 0))
	{

		Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());
		int a = Obj1.get_nLines();
	        int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				temp.Change_Value(i, j, Obj1.get_Element(i, j)  * k);
			}
		}
		return temp;
	}
	else
	{
		 throw "Wrong input for multiplicaton of int and Matrix";
	}

}

Matrix operator*(Matrix Obj1, Matrix Obj2)
{
	if (((Obj1.get_nLines()) == Obj2.get_nLines()) && (Obj1.get_mColumns() == Obj2.get_mColumns()))
	{
	    Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());

     	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				temp.Change_Value(i, j, Obj1.get_Element(i, j) * Obj2.get_Element(i, j));
			}
		}
		return temp;
	}
	else
	{
		 throw "Wrong input for multiplicaton of Matrixes";
	}
}

Matrix Matrix :: operator+=(Matrix Obj1)
{

	if ((Obj1.get_nLines() == this -> nLines) && (Obj1.get_mColumns() == this -> mColumns))
	{
	    Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());
 
     	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				this -> pMatrix[i][j] = Obj1.get_Element(i, j) + this -> pMatrix[i][j];
			}
		}
		return *this;
	}
	else
	{
		 throw "Wrong input for short summing of Matrixes";
	}
}

Matrix Matrix :: operator-=(Matrix Obj1)
{
    if ((Obj1.get_nLines() == this -> nLines) && (Obj1.get_mColumns() == this -> mColumns))
	{
	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				this -> pMatrix[i][j] = Obj1.get_Element(i, j) - this -> pMatrix[i][j];
			}
		}
		return *this;
	}
	else
	{
		 throw "Wrong input for short substraction of Matrixes";
	}
}

Matrix Matrix :: operator*=(Matrix Obj1)
{
	if ((Obj1.get_nLines() == this -> nLines) && (Obj1.get_mColumns() == this -> mColumns))
	{
	    int a = Obj1.get_nLines();
	    int b = Obj1.get_mColumns();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				this -> pMatrix[i][j] = Obj1.get_Element(i, j) * this -> pMatrix[i][j];
			}
		}
		return *this;
	}
	else
	{
		 throw "Wrong input for short multiplication of Matrixes";
	}
}

Matrix Matrix :: operator+=(int k)
{
	if (this -> pMatrix != NULL)
	{
		for (int i = 0; i < this -> nLines ; i++)
		{
			for (int j = 0; j < this -> mColumns; j++)
			{
				this -> pMatrix[i][j] = this -> pMatrix[i][j] + k;
			}
		}
		return *this;
	}
	else
	{
		 throw "Wrong input for short summ of int and Matrix";
	}
}

Matrix Matrix :: operator-=(int k)
{
	if (this -> pMatrix != NULL )
	{
		for (int i = 0; i < this -> nLines; i++)
		{
			for (int j = 0; j < this -> mColumns; j++)
			{
			        this -> pMatrix[i][j] = this -> pMatrix[i][j] - k;
			}
		}
		return *this;
	}
	else
	{
	 throw "Wrong input for short substraction of int and Matrix";
	}
}

Matrix Matrix :: operator*=(int k)
{
	if (this -> pMatrix != NULL )
	{
	       for (int i = 0; i < this -> nLines; i++)
	       {
		       for (int j = 0; j < this -> mColumns; j++)
		       {
		                 this -> pMatrix[i][j] = this -> pMatrix[i][j] * k;
		       }
	       }
	       return *this;
	}
	else
	{
		 throw "Wrong input for short multiplication of int and Matrix";
	}
}

Matrix Matrix :: operator=(Matrix Obj1)
{
    Matrix temp(Obj1.get_nLines(), Obj1.get_mColumns());

    int a = Obj1.get_nLines();
    int b = Obj1.get_mColumns();

    for(int i = 0; i < a; i++)
    {
    	for(int j = 0; i < b; j++)
    	{
    		temp.Change_Value(i, j, Obj1.get_Element(i, j));
		}
	}

    for(int i = 0; i < this-> nLines; i++)
    {
	delete(this -> pMatrix[i]);
    }
    delete(this -> pMatrix);

    this->nLines = Obj1.get_nLines();
    this->mColumns = Obj1.get_mColumns();
    this->pMatrix = temp.pMatrix;

    return *this;
}

Matrix Matrix :: Dot(Matrix Obj1)
{
	if (this -> mColumns ==  Obj1.get_nLines())
	{
		Matrix temp(this ->nLines, Obj1.get_mColumns());

		int number = 0;

		for (int i = 0; i < this ->nLines; i++)
		{
			for (int j = 0; j < Obj1.get_mColumns(); j++)
			{
				number = 0;
				for ( int k = 0; k <this -> mColumns; k++)
				{
					number +=  this -> pMatrix[i][k] * Obj1.get_Element(k, j);
				}
				temp.Change_Value(i, j, number);
			}
		}
		return temp;
	}
	else
	{
	        throw "Wrong input for dot of Matrix";
	}
}

void Matrix :: Transpose(void)
{
	int temp;

	if ((this -> nLines > 0 ) && (this -> mColumns > 0))
	{
		for (int i = 0; i < this ->nLines; i++)
		{
			for (int j = 0; j < this -> mColumns; j++)
			{
			       if (i == j)
			       {
				      break;
			       }

				temp = this ->pMatrix[i][j];
				this ->pMatrix[i][j] = pMatrix[j][i];
				this ->pMatrix[j][i] = temp;
			}
		}
	}
	else
	{
		throw "Wrong input for Transportation of Matrix";
	}
}

int& Matrix :: operator()(int a, int b)
 {
     return pMatrix[a][b];
 }


int main()
{
    Matrix M1(4, 3), M2(5, 4), M3(5, 3), M4(5, 4), M5(5, 4), M6(4, 4);

    ifstream fin("MatrixIn.txt");
    ofstream fout("MatrixOut.txt");

    fin >> M1;
    fin >> M2;
    fin >> M4;
    fin >> M6;
    fout << M2;
    cout << M1;
    cout << endl;
    cout <<  (M5 = M1 + M4);
    cout << endl;
    cout << (M3 = M2.Dot(M1));
    cout << endl;
    cout << (M4 += M1);
    cout << endl;
    fout << M2;
    M6.Transpose();
    cout << M6;
    cout << endl;
    cout << M3(4,1);
    cout << endl;
    cout << (M4 = M5 + 14);
    cout << endl;
    cout << (M1 += 43);
    cout << endl;
    return 0;
}
