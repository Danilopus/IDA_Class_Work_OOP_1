#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Class Work 22.05.2023 -------------------------------------------	

// Сергей Дмитриевич

// ООП - подход ориентированный на взаимодействие оъектов в программе

// Принципы ООП

// 1 Инкапсуляция
// 2 Наследование
// 3 Полиморфизм

// Класс
class myClass
{
// приватные переменные - с земли
private:
	int _data;
public:
	int data;
protected:
	int data2;

public:
	int Summ(int data)
	{
		return _data + data;
	}	
	int Summ_2(int data);
};

int myClass::Summ_2(int data)
{
	return _data + data;
}

class Tovar
{
private:
	std::string _name;// { "Markov" };
	double _price;

public:
	// Конструктор
	Tovar(std::string name, double price)
	{
		_name = name;
		_price = price;
	}
	
	void COUT_Tovar()
	{
		std::cout << "\n_name:  " << _name;
		std::cout << "\n_price: " << _price;
	}
	void SetName(std::string name)
	{
		_name = name;
	}
	void SetPrice(double price)
	{
		_price = price;
	}
	std::string GetName()
	{
		return _name;
	}
	double Get_Price()
	{
		return _price;
	}
};

class Slave
{
private:
	char _id;
	std::string _name;
public:
	Slave(char ch, std::string name)
	{
		_id = ch;
		_name = name;
	}
	char Get_id()
	{
		return _id;
	}
	std::string Get_name()
	{
		return _name;
	}
	void Set_id(char ch)
	{
		_id = ch;
	}
	void Set_name(std::string name)
	{
		_name = name;
	}


};


// Объект

//Task 1
void Task_1()
{
	myClass myObject;
	myObject.data = 10;

	Tovar tovar_obj_1("new good", 15.55);
	tovar_obj_1.COUT_Tovar();

	tovar_obj_1.SetName("rifle");
	tovar_obj_1.SetPrice(77.54);
	tovar_obj_1.COUT_Tovar();

	std::cout << "\nTovar_obj_1.GetName():\t" << tovar_obj_1.GetName();


}
//Task 2
void Task_2()
{
Tovar tovar_obj_1("gun", 220.15);
Tovar tovar_obj_2("bullet", 5.05);
Tovar tovar_obj_3("armor", 500);
tovar_obj_1.COUT_Tovar();
tovar_obj_2.COUT_Tovar();
tovar_obj_3.COUT_Tovar();
}


void SearchbyName(std::string str_search)
{
	//Data_Base.Search(str_search);
}

//Task_3
void Task_3()
{
	Slave slave_1(30, "rAGNAR");
	std::cout << "\nGet_name " << slave_1.Get_name() << "\nGet_id " << int(slave_1.Get_id());
}

//Task_4
void Task_4()
{
	Slave* slave_2 = new Slave(48, "Askold");
}




#include <vector>
// Vector
std::vector<int> vector_1{7,8,9,10,11,12};
std::vector<int> vector_2{ 1,2,3 };

//vector_1.push_back(5);
//int a = 0, b=5;
//b = a + 8;

 
void Task_6()
{
	//Методы vector:
	vector_1.push_back(5);
	vector_1.size();
	vector_1.pop_back(); // убирает последний элемент
	vector_1.begin(); // первый элемент
	vector_1.end();  //
	vector_1.erase(vector_1.begin()+2);

	//int i1 = vector_1.begin();
	//std::cout << vector_1.begin();
	std::cout << *vector_1.begin();

	std::cout << vector_1.at(0);
}

#include <iterator>
//
void Iterator()
{
	std::vector<int> vector_1{ 5,7,9,11,13,15 };
	//Объявляем итератор (аналог указателя для объектов STL)
	std::vector<int>::iterator vector_1_iterator;
	vector_1_iterator = vector_1.begin();
	std::cout << "\nvector_1_iterator: " << *vector_1_iterator;
	std::cout << "\n\n";

	for (vector_1_iterator = vector_1.begin(); vector_1_iterator != vector_1.end(); vector_1_iterator++)
	{
		std::cout << *vector_1_iterator << " | ";
	}
}


class Men
{
private:
	char _age;
	std::string _name;
public:
	Men(char ch, std::string name) : _name(name), _age(ch)
	{	
	}
	/*Men(char ch, std::string name)
	{
		_age = ch;
		_name = name;
	}*/

	char Get_id()
	{
		return _age;
	}
	std::string Get_name()
	{
		return _name;
	}
	void Set_id(char ch)
	{
		_age = ch;
	}
	void Set_name(std::string name)
	{
		_name = name;
	}


};

void Task_7()
{
	std::vector<Men> people;
	std::vector<Men>::iterator people_iterator;

	Men men1(33, "Erik");
	Men men2(73, "Bob");
	Men men3(43, "Thor");
	people.push_back(men1);
	people.push_back(men2);
	people.push_back(men3);

	std::cout << "\n\n";
	for (people_iterator = people.begin(); people_iterator != people.end(); people_iterator++)
	{
		//std::cout << (*people_iterator).Get_name() << " | ";
		std::cout << people_iterator->Get_name() << " | ";
	}
		
	
	std::vector<std::string> names;
	names.push_back(men1.Get_name());
	names.push_back(men2.Get_name());
	names.push_back(men3.Get_name());

	//auto it = names.begin();

	std::cout << "\n\n";

	for (const auto& it : names)
		std::cout << it << " || ";

}

//Task_8
void Task_8()
{
	std::vector<Men*> people;
	std::vector<Men*>::iterator people_iterator;
	
	Men* men1 = new Men(33, "Erik");
	Men* men2 = new Men(73, "Bob");
	Men* men3 = new Men(43, "Thor");
	people.push_back(men1);
	people.push_back(men2);
	people.push_back(men3);

	std::cout << "\n\n";
	for (people_iterator = people.begin(); people_iterator != people.end(); people_iterator++)
	{
		//std::cout << (*people_iterator).Get_name() << " | ";
		//std::cout << people_iterator->Get_name() << " | ";
		std::cout << (*people_iterator)->Get_name() << " | ";
	}


	std::vector<std::string> names;
	names.push_back((*men1).Get_name());
	names.push_back((*men2).Get_name());
	names.push_back((*men3).Get_name());

	//auto it = names.begin();

	std::cout << "\n\n";

	for (const auto& it : names)
		std::cout << it << " || ";


	delete men1, men2, men3;
}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
//srand(time(NULL));
	//Task_1();
	//Task_2();
	//Task_3();
	//Task_4();
	Task_6();

	Iterator();

	Task_7();
	





std::cout << "\n\n";
system("pause");	
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
