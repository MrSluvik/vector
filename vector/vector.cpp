//У контейнері типу vector зберігається набір цілих чисел.
//Створіть функтори для вирішення наступних завдань :
//■ Пошук мінімального значення;+
//■ Пошук максимального значення;+
//■ Сортування даних за спаданням;+
//■ Сортування даних за зростанням;+
//■ Збільшення значень в контейнері на задану константу;
//■ Зменшення значень в контейнері на задану константу;
//■ Видалення елементів з контейнера які рівні шуканому значенню.
//Не забувайте використовувати алгоритми там, де це необхідно.

//2. Змініть функтори з першого завдання на шаблонні
//класи - функторів.Перевірте роботу отриманої програми
//на різних контейнерах з різним вмістом.
#include <iostream>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include <ctime>
#include<time.h>
using namespace std;


void print(vector<int>v) {//ф-н друку вектора
	for (int i = 0; i <v.size(); i++)
	{
		cout << v[i]<<"\t";
	}
}


class MinEl
{
public:
	int operator ()(vector<int>v)
	{
		auto result = min_element(v.begin(), v.end());
		return *result;
	}	
};


class MaxEl
{
public:	
	int operator ()(vector<int>v)
	{
		auto result = max_element(v.begin(), v.end());
		return *result;
	}
};


class Sort
{
public:
	void operator()(vector<int>v) {
		cout << "Сортування за зрозтанням : " << endl;
		sort(v.begin(), v.end(), [](int a, int b) {return a < b;});
		print(v); 
		cout << endl;
		cout << "\nСортування за спаданням : " << endl;
		sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
		print(v); 
		cout << endl;
	}

};


class Plus
{
public:	
		void operator()(vector<int>v, int a) {
			cout << "\n+Вмістимість вектора після збільшення його розміру : " << endl;
			v.resize(a);
			cout << v.size() <<endl;
			print(v);
			cout << endl;
		}
};


class Minus
{
public:
	void operator()(vector<int>v,int a) {
		cout << "\n-Вмістимість вектора після зменшення  його розміру : " << endl;
		v.resize(a);//дозволяє збільшити або зменшити кількість обєктів у векторі  reserve дозволяє лише збільшити кількість вмісту
		cout << v.size() << endl;	//показує ємність вектора 	
		print(v);
		cout << endl;
	}
};


class Delete {
public:
	void operator()(vector<int>v) {
		int a;
		cout<<"\nВведіть значення які хочете видалити"<<endl;
		cin >>a;
			cout << "\nВектор після видалення шуканого елементу:" << endl;
			auto ans = remove(v.begin(), v.end(), a);
			v.erase(ans, v.end());//видаляє задане число
			print(v);
			cout << endl;
		
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	vector<int>v(7);	
	int a = 0, b = 0;

	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 90-20;
	}
	print(v);
	cout << endl;
	MinEl minn;
	cout<<"\nМінімальний елемент у векторі : " << minn(v) << endl<<endl;
	MaxEl maxx;
	cout <<"Максимальний елемент у векторі : " << maxx(v) << endl << endl;

	Sort sortt;
	sortt(v);
	
	Plus Vec;
	cout << "Введіть новий, більший розмір вектора : " << endl;
	cin >> a;
	Vec(v, a);

	Minus Ve;
	cout << "Введіть новий, менший розмір вектора : " << endl;
	cin >> b;
	Ve(v, b);

	Delete d;
	d(v);
}


