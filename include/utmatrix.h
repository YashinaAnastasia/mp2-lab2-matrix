// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора
#pragma warning(disable : 4996)
#ifndef __TMATRIX_H__
#define __TMATRIX_H__
#include<cstring>
#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template <class T>
class Vector
{
protected:
	int size;
	T* mas;
	int startindex;
public:
	Vector(int i, int _startindex = 0);
	Vector(const Vector <T>& x);
	Vector();
	~Vector();
	Vector(int i, T* x);
	int GetStartIndex()
	{
		return startindex;
	}
	int GetSize()
	{
		return size;
	}
	Vector operator+(const Vector <T> x);
	Vector& operator+=(const Vector<T> x) {
		if (size == x.size) {
			for (int i = 0; i < size; i++)
			{
				mas[i] += x.mas[i];
			}
			return *this;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector operator-(const Vector<T> x) {

		if (size == x.size) {
			Vector res;
			res.size = x.size;
			res.mas = new T[size];
			for (int i = 0; i < size; i++)
			{
				res.mas[i] = mas[i] - x.mas[i];
			}
			return res;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector& operator-=(const Vector<T> x)
	{
		if (size == x.size) {
			for (int i = 0; i < size; i++)
			{
				mas[i] -= x.mas[i];
			}
			return *this;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	T operator*(const Vector<T>& x)//скалярное умножение
	{
		if (size == x.size)
		{
			T sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += mas[i] * x.mas[i];
			}
			return sum;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector operator*(T y)//умножение на скаляр
	{
		Vector s(size);
		for (int i = 0; i < size; i++)
		{
			s.mas[i] = mas[i] * y;
		}
		return s;
	};
	Vector operator/(T y)//деление на скаляр
	{
		if (y != 0)
		{
			Vector s(size);
			for (int i = 0; i < size; i++)
			{
				s.mas[i] - mas[i] / y;
			}
			return s;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation(деление на ноль)");
			throw ex;
		}
	};
	Vector& operator=(const Vector<T>& x)
	{
		if (this != &x)
		{
			if (size != x.size)
			{
				delete[] mas;
				size = x.size;
				startindex = x.startindex;
				mas = new T[size];
			}
			for (int i = 0; i < size; i++)
			{
				mas[i] = x.mas[i];
			}
		}
		return *this;
	};
	bool operator==(const Vector<T>& x)
	{
		bool a;
		if (size == x.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (mas[i] != x.mas[i])
					return a = false;
				else
					a = true;
			}
			if (!a)
				return false;
			else
				return true;
		}
		else
			return false;

	};
	bool operator !=(const Vector<T>& x)
	{
		bool a;
		if (size == x.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (mas[i] != x.mas[i])
					return a = true;
				else
					a = false;
			}
			if (a)
				return true;
			else
				return false;
		}
		else
			return true;
	};
	T& operator[](int i)
	{
		if (i >= 0 && i < size)
		{
			return mas[i];
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Wrong index");
			throw ex;
		}
	};
	Vector operator++()// префиксный ++
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] += 1;
		}
		return *this;
	};
	Vector operator++(int)// постфиксный ++
	{
		Vector tmp(*this);
		for (int i = 0; i < size; i++)
		{
			mas[i]++;
		}
		return tmp;
	};
	friend ostream& operator<<(ostream& os, Vector <T>& x)
	{
		for (int i = 0; i < x.size; i++)
		{
			os << x.mas[i] << " ";
		}
		return os;
	};

	friend istream& operator>>(istream& is, Vector <T>& x)
	{
		setlocale(LC_CTYPE, "Russian");
		cout << "введите компоненты  вектора" << endl;
		for (int i = 0; i < x.size; i++)
		{
			cout << "введите " << i << " элемент" << endl;
			is >> x.mas[i];
		}
		return is;
	}
};
template <class T>
Vector<T>::Vector()
{
	setlocale(LC_CTYPE, "Russian");
	size = 1;
	startindex = 0;
	try {
		mas = new T[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = 1;
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::Vector(int i, int _startindex)
{
	if (i <= 0 || i >= MAX_VECTOR_SIZE)throw 1;
	if (_startindex < 0)throw 1;
	size = i;
	startindex = _startindex;
	try {
		mas = new T[i];
		for (int i = 0; i < size; i++)
		{
			mas[i] = 1;
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::Vector(const Vector <T>& x)
{
	size = x.size;
	startindex = x.startindex;
	try {
		mas = new T[size];

		for (int i = 0; i < size; i++)
		{
			mas[i] = x.mas[i];
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::~Vector()
{
	delete[]mas;
}
template <class T>
Vector<T>::Vector(int i, T* x)
{
	size = i;
	try {
		mas = new T[size];

		for (int j = 0; j < size; j++)
		{
			mas[j] = x[j];
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> x)
{
	if (size == x.size)
	{
		Vector res;
		res.size = x.size;
		try {
			res.mas = new T[size];

			for (int i = 0; i < size; i++)
			{
				res.mas[i] = mas[i] + x.mas[i];
			}

			return res;
		}
		catch (bad_alloc)
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
			throw ex;
		}
	}
	else
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation!");
		throw ex;
	}
}
//f,d
// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public Vector<Vector<ValType> >
{
public:
	TMatrix(int s = 10) : Vector<Vector<ValType>>(s)
	{
		if (s >= MAX_MATRIX_SIZE) throw 1;
		//startindex = 0;
		for (int i = 0; i < s; i++)
		{
			Vector<ValType> temp(size - i, i);
			mas[i] = temp;
		}
	};
	TMatrix(const TMatrix& mt) : Vector<Vector<ValType>>(mt) {};                    // копирование
	TMatrix(const Vector<Vector<ValType> >& mt) : Vector<Vector<ValType>>(mt) {}; // преобразование типа
	bool operator==(const TMatrix& mt) const;      // сравнение
	bool operator!=(const TMatrix& mt) const;      // сравнение
	TMatrix& operator= (const TMatrix& mt);        // присваивание
	TMatrix  operator+ (const TMatrix& mt);        // сложение
	TMatrix  operator- (const TMatrix& mt);        // вычитание
	int GetSize();                                 //получить размер
	operator Vector<Vector<ValType>>()
	{
		return Vector<Vector<ValType>>;
	}

	// ввод / вывод
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
			in >> mt.mas[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
			out << mt.mas[i] << endl;
		return out;
	}
};

template<class ValType>
int TMatrix<ValType>::GetSize()
{
	return size;
}
template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	if (size != mt.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != mt.mas[i]) return false;
	}
	return true;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	if (size != mt.size) return true;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != mt.mas[i]) return true;
	}
	return false;
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	startindex = mt.startindex;
	if (size != mt.size)
	{
		size = mt.size;
		delete[] mas;
		mas = new Vector<ValType>[size];
	}
	for (int i = 0; i < size; i++)
	{
		mas[i] = mt.mas[i];
	}
	return *this;

}

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return Vector<Vector<ValType>>::operator+(mt);
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return Vector<Vector<ValType>>::operator-(mt);
}


// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
class Exception
{
	int Line;// строка, где возникло исключение
	char* File;//файл,где произошло исключение
	char* funck;//функция,где произошло исключение
	char* Descr;//тип исключения
public:
	Exception(int i, const char* f, const char* fu, const char* d)
	{
		Line = i;
		int n = strlen(f) + 1;
		File = new char[n];
		strcpy(File, f);
		n = strlen(fu) + 1;
		funck = new char[n];
		strcpy(funck, fu);
		n = strlen(d) + 1;
		Descr = new char[n];
		strcpy(Descr, d);
	};
	Exception(const Exception& a)
	{
		Line = a.Line;
		int n = strlen(a.File);
		File = new char[n];
		strcpy(File, a.File);
		n = strlen(a.funck);
		funck = new char[n];
		strcpy(funck, a.funck);
		n = strlen(a.Descr);
		Descr = new char[n];
		strcpy(Descr, a.Descr);
	};
	Exception()
	{
		delete[] File;
		delete[] funck;
		delete[] Descr;
	};
	void print()
	{
		std::cout << Descr << std::endl;
		std::cout << "Humber file: " << File << std::endl;
		std::cout << "Name function: " << funck << std::endl;
		std::cout << "Numder line: " << Line << std::endl;
	};
};
#endif