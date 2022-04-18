// Binomial Expansion.cpp
#include <iostream> 
#include <cmath> 

using namespace std;

class Father
{
protected:
	int Pascal[10][10];
public:
	void Get_Pascal(void);
};

class Expand : public Father
{
private:
	float A, B;
	int C;

public:
	void Set_Vars(float num1, float num2, float num3)
	{
		A = num1; B = num2; C = num3;
	}
	void Print_Expansion(void);
};

class Compress :public Father
{
private:
	int A, B, C;
	string eqn, coeff;
	int counter = 0, Coeff[10];

public:
	void Get_eqn(string Eqn)
	{
		eqn = Eqn;
	}
	void Get_FirstNum(void);
	void Get_Coeff(int);
	void Set_Vars(void);
	void Print_Compression(void);
};

void EXPAND(void);
void COMPRESS(void);


int main()
{
	string choose;
choose:
	cout << "\tchoose(expand/compress)\n\t";
	cin >> choose;

	if (choose[0] == 'e')
		EXPAND();
	else if (choose[0] == 'c')
		COMPRESS();
	else
	{
		cout << "\n\tbe carefull to letter case\n";
		goto choose;
	}

	return 0;
}


void EXPAND(void)
{
	Expand series;
	float A, B, C;
	cout << "\n\tfor expression (A+BX)^C please enter A,B,C respectively\n\t";
	cin >> A >> B >> C;
	series.Set_Vars(A, B, C);
	series.Print_Expansion();
}

void COMPRESS(void)
{
	Compress Series;
	string eqn;
	cout << "\n\tenter the equation in aform like 1+3X^1+3X^2+X^3\n\t";
	cin >> eqn;
	Series.Get_eqn(eqn);
	Series.Get_FirstNum();
	Series.Set_Vars();
	Series.Print_Compression();
}

void  Ahmed::Get_Pascal(void)
{
	float Pascal[10][10] = { 0.0 };
	int i, k;

	for (i = 0; i < 9; i++)
	{
		Pascal[i][0] = 1;
		Pascal[i][i] = 1;

		for (k = 0; k <= i; k++)
			Pascal[i + 1][k + 1] = Pascal[i][k] + Pascal[i][k + 1];
	}
}

void Expand::Print_Expansion(void)
{
	cout << "\n\texpansion of the equation is\n\t";
	for (int i = 0; i <= C; i++)
	{

		cout << Pascal[C][i] * (pow(A, (C - i)) * pow(B, i)) << "X^" << i;
		if (i != C)
			cout << "+ ";
	}
}

void Compress::Get_FirstNum(void)
{
	for (int i = 0; i < eqn.length(); i++)
	{
		if (i == 0)
			Get_Coeff(i);
		else if (eqn[i] == '+')
			Get_Coeff(i + 1);
	}
}

void Compress::Get_Coeff(int address)
{
	coeff = "0";
	counter++;

	for (int i = address; i <= eqn.length(); i++)
	{
		if (!isalpha(eqn[i]))
			coeff += eqn[i];
		else
			break;
	}
	Coeff[counter - 1] = atof(coeff.c_str());
	cout << Coeff[counter - 1] << endl;
}

void Compress::Set_Vars(void)
{
	C = counter - 1;
	A = pow(Coeff[0], pow(C, -1));
	B = (Coeff[1] / Coeff[0] * A) / Pascal[C][1];
}

void Compress::Print_Compression(void)
{
	cout << "\n\tfor the equation you entered the Compression is\n\n\t";
	cout << "(" << A << " + " << B << "X)^" << C;
}
/*#include <iostream>
#include<cmath>
using namespace std;
class Expand {
private:

	float Pascal[10][10]={0.0};
	float A, B ;
	int C;
public:
	void Set_Vars(float num1, float num2, float num3)
	{
		A = num1; B = num2; C = num3;
	}
	void  Get_Pascal(void);
	void Print_Expansion(void);
};
class compile {
	int a, b, c;
public:
	compile() {}
};
void  Expand :: Get_Pascal(void)
{
	int i, k;
	for (i = 0; i < 9; i++)
	{
		Pascal[i][0] = 1;

		for (k = 0; k <= i; k++)
			Pascal[i + 1][k + 1] = Pascal[i][k] + Pascal[i][k + 1];
	}

	Pascal[i][0] = 1;
}
void Expand::Print_Expansion(void)
{
	cout << "\texpansion of the equation is : ";
	for (int i = 0; i <= C; i++)
	{
		cout << Pascal[C][i] * (pow(A, (C - i)) * pow(B, i)) << "X^" << i;
		if (i != C)
			cout << "+ ";
	}
}

int main()
{
	Expand Series;
	float A, B, C;
	cout << "\tfor equation (A+BX)^C enter A,B,C respectively\n\t";
	cin >> A >> B >> C;
	Series.Set_Vars(A, B, C);
	Series.Get_Pascal();
	Series.Print_Expansion();
	cout << endl<<pow(4, 0.5);
	return 0;
}
*/