// Sinan Göçmez
// 1306180141
// 17.01.2021
// Development Environment: Visual Studio2019

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string remove_space_from_line(string line);
void ayrac(string line[], string arr1[], string arr2[], int n);
int kontrol(string names[], int sayilar[], string str_num[]);
int islem(string names[], int sayilar[], string val[], int n);
void temp(string arr1[], string& arr2);
void degistir(string names[], int sayilar[], string temp_arr[]);
int hesapla(string temp_arr[]);
void if_statement(string names[], int sayilar[], string arr1[]);
int found(string names[], int sayilar[], string ara);
int sorgula(int x, int y, int w, int z, string opr);
void loop_statement(string names[], int sayilar[], string val[]);
void cikis(string names[], int sayilar[], int s);

int main()
{
	ifstream getValue;
	string dname;
	int s = 1;
	do
	{
		dname = "Challange" + to_string(s) + ".inp";
		getValue.open(dname);
		string satir;
		const int vin = 100;
		string satirlar[vin];
		string degisken[vin];
		string valuable[vin];
		int sayilar[vin] = { 0 };
		int i = 0; // satýr sayýsý
		//cout << dname;
		if (getValue.is_open())
		{
			while (getline(getValue, satir))  // dosyanýn sonuna kadar satýr satýr okuyor
			{
				satir = remove_space_from_line(satir);
				satirlar[i] = satir;
				i++;
			}
		}

		getValue.close();
		ayrac(satirlar, degisken, valuable, i);
		kontrol(degisken, sayilar, valuable);

		for (size_t i = 0; i < 100; i++)
		{
			if (degisken[i].find("OUT") != string::npos)
			{
				cikis(degisken, sayilar, s);
			}
		}
		s++;
	} while (s < 15);
	return 0;
}

string remove_space_from_line(string line)
{
	int counter = 0;
	string new_line = "";
	while (counter < line.length())
	{
		if (line[counter] != ' ')
		{
			new_line += line[counter];
		}
		counter++;
	}
	return new_line;
}

void ayrac(string line[], string arr1[], string arr2[], int n)
{
	string delimiter = "=";
	for (size_t i = 0; i < n; i++)
	{
		arr1[i] = line[i].substr(0, line[i].find_first_of(delimiter));
		arr2[i] = line[i].erase(0, 1 + arr1[i].length());
	}
}

int kontrol(string names[], int sayilar[], string str_num[])
{
	//char sembol[] = { '*', '/' , '+', '-', '<' , '>' , '!' , '=', '(' };
	//string const kWords[] = { "OUT" , "IN" , "IF" , "THEN" , "ELSE" , "LOOP" , "TIMES" };
	string const sembol1 = { "+*-/(<>!" };
	int temp = 0;

	for (size_t i = 0; i < 100; i++)
	{
		//new_line = valu[i];
		//cout << new_line << endl;		
		if (str_num[i].find_first_of(sembol1) == string::npos && str_num[i] != "\0")
		{
			//cout << "sayila: " << num[i] << endl;
			temp = stoi(str_num[i]);
			sayilar[i] = temp;
			str_num[i] = "\0";
		}
		if (str_num[i].find_first_of(sembol1) != string::npos && str_num[i] != "\0")
		{
			//int karakter_sayisi = str_num[i].length();
			//cout << karakter_sayisi << endl;			
			islem(names, sayilar, str_num, i);
		}
	}
	return 0;
}

int islem(string names[], int sayilar[], string val[], int n)
{
	string temp_arr[100] = { "\0" };
	string temp1, temp2;
	string const sembol1 = { "*/+-" };
	string const parantez = { "()" };
	int x = 0;
	int sonuc = 0;

	if (val[n].find("IF") == string::npos && val[n].find("TIMES") == string::npos)
	{
		if (val[n].find_first_of(parantez) == string::npos && val[n] != "\0")
		{
			if (val[n].find_first_of(sembol1) != string::npos && val[n] != "\0")
			{
				x = val[n].length();
				if (x != 3)
				{
					temp2 = val[n];
					temp(temp_arr, temp2);
					//val[n] = "\0";
					degistir(names, sayilar, temp_arr);
					sonuc = hesapla(temp_arr);
					sayilar[n] = sonuc;
				}

				if (x == 3)
				{
					temp1 = val[n];
					temp(temp_arr, temp1);
					degistir(names, sayilar, temp_arr);
					//val[n] = "\0";
					sonuc = hesapla(temp_arr);
					sayilar[n] = sonuc;
				}
			}
		}

		string temp3;
		string a, b;
		string temp_arr2[100] = { "\0" };

		if (val[n].find_first_of(parantez) != string::npos)
		{
			x = val[n].length();
			//cout << "burda " << x <<endl;
			temp1 = val[n].substr(0, val[n].find_first_of("("));
			a = val[n].substr(0, val[n].find_first_of("("));
			//cout << temp1.length() << endl;
			temp2 = val[n].substr(0, val[n].find_first_of(")"));
			b = val[n].substr(val[n].find_first_of(")") + 1);
			//cout << temp2.length() << endl;		
			temp3 = val[n].substr(temp1.length() + 1, temp2.length() - 1);
			val[n] = val[n].erase();
			//cout << val[n] << endl;
			//cout << "a: " << a << " b: " << b << " temp3: " << temp3 << endl;
			temp(temp_arr, temp3);
			degistir(names, sayilar, temp_arr);
			sonuc = hesapla(temp_arr);
			temp3 = a + to_string(sonuc) + b;
			//cout << "||" << temp3 << endl;

			if (temp3.find_first_of(sembol1) != string::npos)
			{
				temp(temp_arr2, temp3);
				degistir(names, sayilar, temp_arr2);
				sonuc = hesapla(temp_arr2);
			}
			else
			{
				//cout << "islem yok" << endl;
				sonuc = stoi(temp3);
			}
			//temp(temp_arr, temp3);
			//cout << "||" << sonuc << endl;
			sayilar[n] = sonuc;
		}
	}

	if (val[n].find("IF") != string::npos)
	{
		if_statement(names, sayilar, val);
	}

	if (val[n].find("TIMES") != string::npos)
	{
		loop_statement(names, sayilar, val);
	}

	return 0;
}

void temp(string arr1[], string& arr2)
{
	string temp1, temp2, temp3;
	string const sembol1 = { "*/+-" };
	int x = 0;

	for (size_t i = 0; i < 100; i++)
	{
		if (arr1[i] != "\0")
		{
			x += 1;
		}
	}

	if (arr2.find_first_of(sembol1) != string::npos)
	{
		//cout << "burda" << endl;
		temp1 = arr2.substr(0, arr2.find_first_of(sembol1));
		temp2 = arr2.substr(temp1.length(), 1);
		temp3 = arr2.erase(0, temp1.length() + temp2.length());
		//cout << temp1 << " " << temp2 << " " << temp3 << " string: " << arr2 << endl;

		arr1[x] = temp1;
		arr1[x + 1] = temp2;

		if (temp3 != "\0" && arr2.find_first_of(sembol1) != string::npos)
		{
			temp(arr1, temp3);
		}
	}

	if (temp3 != "\0" && arr2.find_first_of(sembol1) == string::npos)
	{
		arr1[x + 2] = temp3;
		//arr1[x + 3] = "|";
		temp3 = "";
	}
}

void degistir(string names[], int sayilar[], string temp_arr[]) {
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			while (names[i] == temp_arr[j])
			{
				temp_arr[j] = to_string(sayilar[i]);
			}
		}
	}
}

int hesapla(string temp_arr[]) {
	int val1, val2;
	int sonuc = 0;

	string const sembol1 = { "*/+-" };
	string sembol2 = "*/";
	string sembol3 = "+-";

	for (size_t i = 1; i < 100; i++) {
		//cout << " << " << temp_arr[i] <<" "<<sayilar[i]<< endl;
		//if (temp_arr[i].find_first_of("|") != string::npos)		
		if (temp_arr[i].find_first_not_of(sembol2) == string::npos)
		{
			if (temp_arr[i] == "*")
			{
				val1 = stoi(temp_arr[i - 1]);
				val2 = stoi(temp_arr[i + 1]);

				temp_arr[i] = "\0";
				temp_arr[i + 1] = "\0";
				sonuc = val1 * val2;
				//cout << val1 << " " << "* " << val2 << " = " << sonuc << endl;
				temp_arr[i - 1] = to_string(sonuc);
				for (size_t k = 0; k < 50; k++)
				{
					if ((i - 1) < k)
					{
						temp_arr[k] = temp_arr[k + 2];
					}
				}
				//cout << "1.val: " << val1 << " op " << temp_arr[i] << " 2.val: " << val2 << " sonuc: " << sonuc << endl;
			}

			if (temp_arr[i] == "/")
			{
				val1 = stoi(temp_arr[i - 1]);
				val2 = stoi(temp_arr[i + 1]);

				temp_arr[i] = "\0";
				temp_arr[i + 1] = "\0";
				sonuc = val1 / val2;
				//cout << val1 << " " << "/ " << val2 << " = " << sonuc << endl;
				temp_arr[i - 1] = to_string(sonuc);
				for (size_t k = 0; k < 50; k++)
				{
					if ((i - 1) < k)
					{
						temp_arr[k] = temp_arr[k + 2];
					}
				}
				//cout << "1.val: " << val1 << " op " << temp_arr[i] << " 2.val: " << val2 << " sonuc: " << sonuc << endl;
			}

			if (temp_arr[i].find_first_not_of(sembol2) == string::npos) {
				i--;
			}
		}
	}

	for (size_t j = 0; j < 100; j++)
	{
		if (temp_arr[j].find_first_not_of(sembol3) == string::npos) {
			if (temp_arr[j] == "+")
			{
				val1 = stoi(temp_arr[j - 1]);
				val2 = stoi(temp_arr[j + 1]);

				temp_arr[j] = "\0";
				temp_arr[j + 1] = "\0";
				sonuc = val1 + val2;
				//cout << val1 << " " << "+ " << val2 << " = " << sonuc << endl;
				temp_arr[j - 1] = to_string(sonuc);
				for (size_t k = 0; k < 50; k++)
				{
					if ((j - 1) < k)
					{
						temp_arr[k] = temp_arr[k + 2];
					}
					//cout << temp_arr[k] << endl;
				}
				//cout << temp_arr[j] << " " << temp_arr[j + 1] << endl;
				//cout << "1.val: " << val1 << " op " << temp_arr[j] << " 2.val: " << val2 << " sonuc: " << sonuc << endl;
			}
			if (temp_arr[j] == "-")
			{
				val1 = stoi(temp_arr[j - 1]);
				val2 = stoi(temp_arr[j + 1]);

				temp_arr[j] = "\0";
				temp_arr[j + 1] = "\0";
				sonuc = val1 - val2;
				//cout << val1 << " " << "- " << val2 << " = " << sonuc << endl;
				temp_arr[j - 1] = to_string(sonuc);
				for (size_t k = 0; k < 50; k++)
				{
					if ((j - 1) < k)
					{
						temp_arr[k] = temp_arr[k + 2];
					}
				}
			}

			if (temp_arr[j].find_first_not_of(sembol3) == string::npos) {
				j--;
			}
		}
	}
	//cout << " val: " << val1 << " val2: " << val2 << " sonuc: " << sonuc << endl;

	for (size_t i = 0; i < 100; i++)
	{
		//cout << temp_arr[i] << endl;
		if (temp_arr[i].find_first_of(sembol1) == string::npos)
		{
			//cout << "sonuc: " << sonuc << endl;
			return sonuc;
		}
	}
	return 0;
}

void if_statement(string names[], int sayilar[], string arr1[]) {

	string temp1, temp2, temp3;
	string a, b, operators;
	string const sembol1 = { "*/+-" };
	string sembol = "<>";
	int s = 0; // iþlem yapýlan dizi index tutmak için
	int x = 0, y = 0;
	int w = 0, z = 0;

	for (size_t i = 0; i < 100; i++)
	{
		if (arr1[i].find("IF") != string::npos)
		{
			s = i;
			arr1[i] = arr1[i].erase(0, 2);
			temp1 = arr1[i].substr(0, arr1[i].find("THEN"));
			arr1[i] = arr1[i].erase(0, temp1.length() + 4);
			temp2 = arr1[i].substr(0, arr1[i].find("ELSE"));
			arr1[i] = arr1[i].erase(0, temp2.length() + 4);
			temp3 = arr1[i].substr();
			arr1[i] = arr1[i].erase();
			//cout << temp1 << " temp2: " << temp2 << " temp3: " << temp3 << endl;
			//cout << arr1[i];
		}
	}

	string sembol2 = "=";
	if (temp1.find_first_of(sembol) != string::npos)
	{
		a = temp1.substr(0, temp1.find_first_of(sembol));
		if (temp1.find_first_of(sembol2) != string::npos)
		{
			operators = temp1.substr(a.length(), 2);
		}
		else
		{
			operators = temp1.substr(a.length(), 1);
		}
		temp1 = temp1.erase(0, a.length() + operators.length());
		b = temp1;
		temp1 = "\0";
	}

	//cout <<"||"<<temp[s]<<endl;
	if (a.find_first_of(sembol1) != string::npos)
	{
		string temp[50];
		temp[s] = a;
		islem(names, sayilar, temp, s);
	}

	//cout << a << " " << operators << " " << b << " " << sayilar[s] << endl;

	if (sayilar[s] != 0) {
		x = sayilar[s];
		sayilar[s] = 0;
		y = stoi(b);
		w = found(names, sayilar, temp2);
		z = found(names, sayilar, temp3);
		sayilar[s] = sorgula(x, y, w, z, operators);
	}
	else
	{
		x = found(names, sayilar, a);
		y = found(names, sayilar, b);
		w = found(names, sayilar, temp2);
		z = found(names, sayilar, temp3);
		sayilar[s] = sorgula(x, y, w, z, operators);
	}
}

int found(string names[], int sayilar[], string ara) {
	int a;
	for (size_t i = 0; i < 100; i++)
	{
		if (names[i] == ara)
		{
			a = sayilar[i];
			return a;
		}
	}
	return 0;
}

int sorgula(int x, int y, int w, int z, string opr) {
	if (opr == "<=")
	{
		if (x <= y)
		{
			return w;
		}
		else
		{
			return z;
		}
	}

	if (opr == ">=")
	{
		if (x >= y)
		{
			return w;
		}
		else
		{
			return z;
		}
	}

	if (opr == "<")
	{
		if (x < y)
		{
			return w;
		}
		else
		{
			return z;
		}
	}

	if (opr == ">")
	{
		if (x > y)
		{
			return w;
		}
		else
		{
			return z;
		}
	}
	return 0;
}

void loop_statement(string names[], int sayilar[], string val[]) {

	string sembol1 = "+-*/(";
	string temp1, temp2, temp3;
	int k; // index numarasýný tutmak için
	int result = 0;
	string temp_names[100];
	int arr1[100];
	for (size_t i = 0; i < 100; i++)
	{
		temp_names[i] = names[i];
		arr1[i] = sayilar[i];
		if (names[i].find("LOOP") != string::npos)
		{
			k = i;
			names[i] = names[i].erase(0, 4);
			temp1 = names[i];
			//cout << temp1;	
			arr1[i] = found(temp_names, sayilar, temp1);
		}

		if (val[i].find("TIMES") != string::npos)
		{
			temp2 = val[i].substr(0, val[i].find("TIMES"));
			val[i] = val[i].erase(0, temp2.length() + 5);
			temp3 = val[i];
			val[i] = "";
		}
	}

	for (size_t i = 0; i < stoi(temp3); i++)
	{
		if (temp2.find_first_of(sembol1) != string::npos)
		{
			string temp[50];
			temp[k] = temp2;
			islem(names, arr1, temp, k);
			result = arr1[k];
			sayilar[k] = result;
		}
	}
}

void cikis(string names[], int sayilar[], int s) {
	ofstream myFile;
	myFile.open("Challange" + to_string(s) + ".out");
	string temp1;
	int sonuc;
	for (size_t i = 0; i < 100; i++)
	{
		if (names[i].find("OUT") != string::npos) //
		{
			temp1 = names[i].substr(3);
			sonuc = found(names, sayilar, temp1);
		}
	}
	cout << temp1 << " = " << sonuc << endl;
	myFile << sonuc;

	myFile.close();
}

