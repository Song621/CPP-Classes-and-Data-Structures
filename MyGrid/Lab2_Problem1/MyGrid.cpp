#include "MyGrid.h"

MyGrid::MyGrid()
{
	myX = myY = 0;
	NumRows = NumCols = 0;
}

MyGrid::MyGrid(long x, long y, long row, long col)
{
	myX = x;
	myY = y;
	NumRows = row;
	NumCols = col;
	gridElements.resize(NumRows);
	for (int i = 0; i < gridElements.size(); i++)
	{
		gridElements[i].resize(NumCols);
	}
	
}
bool MyGrid::loadGridFromFile(const string& filename)
{
	ifstream readfile;
	readfile.open(filename);
	//cout << filename << endl;
	if (readfile.good())
	{
		readfile >> myX >> myY;
		readfile>> NumRows >> NumCols;
		gridElements.resize(NumRows);
		for (int i = 0; i < gridElements.size(); i++)
		{
			gridElements[i].resize(NumCols);
		}
		//cout << myX << " " << myY << endl;
		//cout << NumRows << " " << NumCols << endl;
		//cout << gridElements.size() << endl;
		//cout << gridElements[0].size() << endl;

		//cout << "***************" << endl;
		for (int i = 0; i < NumRows; i++)
		{
			for (int j = 0; j < NumCols; j++)
			{
				readfile >> gridElements[i][j];
				//cout << gridElements[i][j] << " ";
			}
			//cout << endl;
		}
		return true;
	}

	return false;
}

void MyGrid::zeroOutGrid()
{
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			gridElements[i][j] = 0;
		}
	}
}

long MyGrid::getNumRows() const
{
	return NumRows;
}

long MyGrid::getNumCols() const
{
	return NumCols;
}


MyGrid MyGrid::operator+(MyGrid const& rhs) const
{
	MyGrid temp,temp1,temp2;
	long newX, newY, smallX, smallY, bigX, bigY;
	long tempRow, tempCol;
	//bool smallX_row, smallX_col, bigX_row, bigX_col;
	//bool smallY_row, smallY_col, bigY_row, bigY_col;

	if (myX < rhs.myX){
		newX = smallX = myX;
		bigX = rhs.myX;
		tempRow = rhs.NumCols;// rhs.NumRows;
	}
	else{
		newX = smallX = rhs.myX;
		bigX = myX;
		tempRow = NumCols;// NumRows;
	}

	if (myY > rhs.myY){
		newY = bigY = myY;
		smallY = rhs.myY;
		tempCol = rhs.NumRows;//rhs.NumCols;
	}
	else{
		newY = bigY = rhs.myY;
		smallY = myY;
		tempCol = NumRows;// NumCols;
	}



	long newCol = bigX + tempRow - smallX;
	long newRow = bigY - smallY + tempCol;

	//cout <<"newX:"<<newX << endl;
	//cout << "newY" << newY << endl;
	//cout <<"newX:" <<bigX<< "+"<<tempRow<< "-"<<smallX<<endl;
	//cout << "newY:" << bigY <<"-"<<smallY<<"+"<<tempCol << endl;;
	//cout << "newrow: " << newRow << endl;
	//cout << "newcol" << newCol << endl;

	temp.myX = temp1.myX = temp2.myX = newX;
	temp.myY = temp1.myY = temp2.myY = newY;
	temp.NumRows  = temp1.NumRows  = temp2.NumRows = newRow;
	temp.NumCols = temp1.NumCols  = temp2.NumCols = newCol;
	temp.gridElements.resize(newRow);
	temp1.gridElements.resize(newRow);
	temp2.gridElements.resize(newRow);
	for (int i = 0; i < newRow; i++)
	{
		temp.gridElements[i].resize(newCol);
		temp1.gridElements[i].resize(newCol);
		temp2.gridElements[i].resize(newCol);
	}
	temp.zeroOutGrid();
	temp1.zeroOutGrid();
	temp2.zeroOutGrid();

	
	if (newX == myX)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1 && judgeY <= myY)
				{
					locationI = i + bigY - smallY;
					locationJ = j - bigY + smallY;
					//cout << "hello ";
					a = newX + i - myX;
					b = myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = gridElements[a][b];
				}
			}
		}
	}
	
	if (newX == rhs.myX)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
				{
					locationI = i + bigY - smallY;
					locationJ = j - bigY + smallY;
					//cout << "hello ";
					a = newX + i - rhs.myX;
					b = rhs.myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << rhs.gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = rhs.gridElements[a][b];
				}
			}
		}
	}
	
	if (newY == myY)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1 && judgeY <= myY)
				{
					locationI = i - bigX + smallX;
					locationJ = j + bigX - smallX;
					//cout << "hello ";
					a = newX + i - myX;
					b = myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = gridElements[a][b];
				}
			}
		}
	}
	
	if (newY == rhs.myY)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
				{
					locationI = i - bigX + smallX;
					locationJ = j + bigX - smallX;
					//cout << "hello ";
					a = newX + i - rhs.myX;
					b = rhs.myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << rhs.gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp2.gridElements[locationI][locationJ] = rhs.gridElements[a][b];
				}
			}
		}
	}
	/*
	for (int i = 0; i < newRow; i++)
	{
		for (int j = 0; j < newCol; j++)
		{
			long judgeX = newX + i;
			long judgeY = newY - j;
			
			long a, b;
			if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1  && judgeY <= myY)
			{
				//cout << "hello ";
				a = newX + i - myX;
				b = myY - newY + j;
				cout << a << " " <<b;
				cout << " " << gridElements[a][b] << endl;
				cout << i << "---" << j << endl;
				temp1.gridElements[i][j] = gridElements[a][b];
			}
			
			if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
			{
				a = newX + i - rhs.myX;
				b = rhs.myY - newY + j;
				cout << a << " " << b;
				cout << " " << rhs.gridElements[a][b] << endl;
				cout<< i<< "-----"<<j<<endl;
				temp2.gridElements[i][j] = rhs.gridElements[a][b];
			}
		}
	}*/
	
	for (int i = 0; i < newRow; i++)
	{
		for (int j = 0; j < newCol; j++)
		{
			temp.gridElements[i][j] = temp1.gridElements[i][j] + temp2.gridElements[i][j];
			//cout << temp.gridElements[i][j]<<" ";
		}
		//cout << endl;
	}
	//cout << "temp:" << temp.gridElements.size() << endl;
	return temp;
}


MyGrid MyGrid::operator-(MyGrid const& rhs) const
{

	MyGrid temp,temp1,temp2;
	long newX, newY, smallX, smallY, bigX, bigY;
	long tempRow, tempCol;
	//bool smallX_row, smallX_col, bigX_row, bigX_col;
	//bool smallY_row, smallY_col, bigY_row, bigY_col;

	if (myX < rhs.myX){
		newX = smallX = myX;
		bigX = rhs.myX;
		tempRow = rhs.NumCols;// rhs.NumRows;
	}
	else{
		newX = smallX = rhs.myX;
		bigX = myX;
		tempRow = NumCols;// NumRows;
	}

	if (myY > rhs.myY){
		newY = bigY = myY;
		smallY = rhs.myY;
		tempCol = rhs.NumRows;//rhs.NumCols;
	}
	else{
		newY = bigY = rhs.myY;
		smallY = myY;
		tempCol = NumRows;// NumCols;
	}



	long newCol = bigX + tempRow - smallX;
	long newRow = bigY - smallY + tempCol;

	//cout <<"newX:"<<newX << endl;
	//cout << "newY" << newY << endl;
	//cout <<"newX:" <<bigX<< "+"<<tempRow<< "-"<<smallX<<endl;
	//cout << "newY:" << bigY <<"-"<<smallY<<"+"<<tempCol << endl;;
	//cout << "newrow: " << newRow << endl;
	//cout << "newcol" << newCol << endl;

	temp.myX = temp1.myX = temp2.myX = newX;
	temp.myY = temp1.myY = temp2.myY = newY;
	temp.NumRows = temp1.NumRows = temp2.NumRows = newRow;
	temp.NumCols = temp1.NumCols = temp2.NumCols = newCol;
	temp.gridElements.resize(newRow);
	temp1.gridElements.resize(newRow);
	temp2.gridElements.resize(newRow);
	for (int i = 0; i < newRow; i++)
	{
		temp.gridElements[i].resize(newCol);
		temp1.gridElements[i].resize(newCol);
		temp2.gridElements[i].resize(newCol);
	}
	temp.zeroOutGrid();
	temp1.zeroOutGrid();
	temp2.zeroOutGrid();


	if (newX == myX)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1 && judgeY <= myY)
				{
					locationI = i + bigY - smallY;
					locationJ = j - bigY + smallY;
					//cout << "hello ";
					a = newX + i - myX;
					b = myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = gridElements[a][b];
				}
			}
		}
	}

	if (newX == rhs.myX)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
				{
					locationI = i + bigY - smallY;
					locationJ = j - bigY + smallY;
					//cout << "hello ";
					a = newX + i - rhs.myX;
					b = rhs.myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << rhs.gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = rhs.gridElements[a][b];
				}
			}
		}
	}

	if (newY == myY)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1 && judgeY <= myY)
				{
					locationI = i - bigX + smallX;
					locationJ = j + bigX - smallX;
					//cout << "hello ";
					a = newX + i - myX;
					b = myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp1.gridElements[locationI][locationJ] = gridElements[a][b];
				}
			}
		}
	}

	if (newY == rhs.myY)
	{
		for (int i = 0; i < newRow; i++)
		{
			long locationI, locationJ;
			for (int j = 0; j < newCol; j++)
			{
				long judgeX = newX + i;
				long judgeY = newY - j;

				long a, b;
				if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
				{
					locationI = i - bigX + smallX;
					locationJ = j + bigX - smallX;
					//cout << "hello ";
					a = newX + i - rhs.myX;
					b = rhs.myY - newY + j;
					//cout << a << " " << b;
					//cout << " " << rhs.gridElements[a][b] << endl;
					//cout << i << "---" << j << endl;
					temp2.gridElements[locationI][locationJ] = rhs.gridElements[a][b];
				}
			}
		}
	}
	/*
	for (int i = 0; i < newRow; i++)
	{
		for (int j = 0; j < newCol; j++)
		{
			long judgeX = newX + i;
			long judgeY = newY - j;

			long a, b;
			if (judgeX >= myX && judgeX <= myX + NumRows - 1 && judgeY >= myY - NumCols + 1  && judgeY <= myY)
			{
				//cout << "hello ";
				a = newX + i - myX;
				b = myY - newY + j;
				cout << a << " " <<b;
				cout << " " << gridElements[a][b] << endl;
				cout << i << "---" << j << endl;
				temp1.gridElements[i][j] = gridElements[a][b];
			}

			if (judgeX >= rhs.myX && judgeX <= rhs.myX + rhs.NumRows - 1 && judgeY >= rhs.myY - rhs.NumCols + 1 && judgeY <= rhs.myY)
			{
				a = newX + i - rhs.myX;
				b = rhs.myY - newY + j;
				cout << a << " " << b;
				cout << " " << rhs.gridElements[a][b] << endl;
				cout<< i<< "-----"<<j<<endl;
				temp2.gridElements[i][j] = rhs.gridElements[a][b];
			}
		}
	}*/

    for (int i = 0; i < newRow; i++)
    {
	    for (int j = 0; j < newCol; j++)
	    {
		    temp.gridElements[i][j] = temp1.gridElements[i][j] - temp2.gridElements[i][j];
		    //cout << temp.gridElements[i][j] << " ";
	    }
	    //cout << endl;
    }
    //cout << "temp:" << temp.gridElements.size() << endl;
    return temp;
}

MyGrid MyGrid::operator+(long const& num) const
{
	MyGrid temp(myX, myY, NumRows, NumCols);
	
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			temp.gridElements[i][j] = gridElements[i][j] + num;
		}
	}

	return temp;
}

MyGrid operator+(long const& lhs, MyGrid const& rhs)
{
	MyGrid temp(rhs.myX, rhs.myY, rhs.NumRows, rhs.NumCols);
	for (int i = 0; i < temp.NumRows; i++)
	{
		for (int j = 0; j < temp.NumCols; j++)
		{
			temp.gridElements[i][j] = rhs.gridElements[i][j] + lhs;
		}
	}
	return temp;
}

MyGrid& MyGrid::operator+=(MyGrid const& rhs)
{
	myX = rhs.myX;
	myY = rhs.myY;
	NumRows = rhs.NumRows;
	NumCols = rhs.NumCols;
	gridElements.resize(rhs.NumRows);
	for (int i = 0; i < rhs.NumRows; i++)
	{
		gridElements[i].resize(rhs.NumCols);
	}

	//cout << gridElements.size() << " " << gridElements[0].size() << endl;
	//cout << rhs.NumRows << " " << rhs.NumCols << endl;
	zeroOutGrid();

	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			gridElements[i][j] += rhs.gridElements[i][j];
			//cout << gridElements[i][j] << " ";
		}
		//cout << endl;
	}
	return *this;
}

MyGrid& MyGrid::operator++()
{
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			gridElements[i][j] += 1;
		}
	}
	return *this;
}

MyGrid MyGrid::operator++(int)
{
	MyGrid temp = *this;
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			temp.gridElements[i][j] ++;
		}
	}

	return temp;
}

MyGrid& MyGrid::operator--()
{
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			gridElements[i][j] --;
		}
	}
	return *this;
}

MyGrid MyGrid::operator--(int)
{
	MyGrid temp = *this;
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			temp.gridElements[i][j] --;
		}
	}

	return temp;
}

MyGrid MyGrid::operator-() const
{
	MyGrid temp = *this;
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			temp.gridElements[i][j] = 0 - temp.gridElements[i][j];
		}
	}

	return temp;
}

bool MyGrid::operator==(MyGrid const& rhs) const
{
	if (myX == rhs.myX && myY == rhs.myY || NumRows == rhs.NumRows || NumCols == rhs.NumCols)
	{
		for (int i = 0; i < NumRows; i++)
		{
			for (int j = 0; j < NumCols; j++)
			{
				if (gridElements[i][j] != rhs.gridElements[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}

fstream& operator<<(fstream& os, const MyGrid& gridIn)
{
	string a;
	os << gridIn.myX << " " << gridIn.myY << endl;
	os<< gridIn.NumRows << " " << gridIn.NumCols << endl;
	for (int i = 0; i < gridIn.NumRows; i++)
	{
		for (int j = 0; j < gridIn.NumCols; j++)
		{
			os<<gridIn.gridElements[i][j]<<" ";
		}
		os << endl;
	}
	return os;
}
