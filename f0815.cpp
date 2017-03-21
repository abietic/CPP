#include <iostream>
#include <fstream>
using namespace std;
//-------------------------------------------------------------
class Matrix;
class Vector
{
	private:
		int* v;
		int sz;
	public:
		Vector(Vector& t)
		{
			if(t.size()<=0)
			{
				cerr<<"invalid template\n";
				exit(1);
			}
			sz = t.size();
			v = new int[sz];
			for(int i = 0;i<sz;i++)
			{
				v[i] = t[i];
			}
		}
		Vector()
		{
			sz = 0;
			v = NULL;
		}
		Vector(int s)
		{
			sz = s;
			v = new int[sz];
		}
		~Vector(){ delete[] v; }
		int size(){ return sz; }
		void set(int);
		void display();
		int& operator[](int);
		friend Vector multiply(Matrix& m,Vector& v);
};
//------------------------------------------------------------
//-------------------------------------------------------------
void Vector::set(int s)
{
	sz = s;
	if(s <= 0)
	{
		cerr<<"bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
}
//-----------------------------------------------------------
int& Vector::operator[](int i)
{
	if(i < 0||i>=sz)
	{
		cerr<<"Vector index is out of range\n";
		exit(1);
	}
	return v[i];
}
//----------------------------------------------------------
void Vector::display()
{
	for(int i = 0;i<sz;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}


//----------------------------------------------------------------------
class Matrix
{
	private:
		int* m;
		int szl,szr;
	public:
		Matrix(int x,int y)
		{
			if(x <=0|| y <= 0)
			{
				cerr<<"bad matrix size\n";
				exit(1);
			}
			szl = x;
			szr = y;
			m = new int[x*y];
		}
		Matrix()
		{
			m = NULL;
			szl = 0;
			szr = 0;
		}
		Matrix(Matrix& t)
		{
			if(t.sizeL() <= 0||t.sizeR() <=0)
			{
				cerr<<"invalid template\n";
				exit(1);
			}
			szl = t.sizeL();
			szr = t.sizeR();
			m = new int[szl*szr];
			for(int i = 0;i<szl;i++)
			{
				for(int j = 0;j<szr;j++)
				{
					m[i*szl+j] = t.elem(i,j);
				}
			}
		}
		void set(int, int);
		~Matrix(){ delete[] m; }
		int sizeL(){ return szl; }
		int sizeR(){ return szr; }
		int& elem(int ,int);
		friend Vector multiply(Matrix& m,Vector& v);
};
//--------------------------------------------------------------
//--------------------------------------------------------------
void Matrix::set(int i,int j)
{
	szl = i;
	szr = j;
	if(i <= 0||j <= 0)
	{
		cerr<<"bad Matrix size\n";
		exit(1);
	}
	m = new int[i*j];
}
//-----------------------------------------------------------
int& Matrix::elem(int i, int j)
{
	if(i<0||szl <= i||j<0||szr <= j)
	{
		cerr<<"Matrix index out of range.\n";
		exit(1);
	}
	return m[i*szr+j];
}
//--------------------------------------------------------------
Vector multiply(Matrix& m, Vector& v)
{
	if( m.szr != v.sz )
	{
		cerr<<"Bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(m.szl);
	for(int i = 0;i<m.szl;i++)
	{
		r[i] = 0;
		for( int j = 0;j<m.szr;j++)
		{
			r[i] += m.m[i*(m.szr)+j] * v[j];
		}
	}
	return r;
}

//------------------------------------------------------------
int main()
{
	ifstream in("in");
	int x,y;
	in>>x>>y;
	Matrix ma(x,y);
	for(int i = 0;i<x;i++)
	{
		for(int j = 0;j<y;j++)
		{
			in>>ma.elem(i,j);
		}
	}
	in>>x;
	Vector ve(x);
	for(int i = 0;i<x;++i)
	{
		in>>ve[i];
	}
	multiply(ma,ve).display();
	return 0;
}
