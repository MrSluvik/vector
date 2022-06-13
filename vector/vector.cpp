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

template<typename T>
void print(vector<T>v) {//ф-н друку вектора
	for (int i = 0; i <v.size(); i++)
	{
		cout << v[i]<<"\t";
	}
}

template<class T>
class MinEl
{
public:
	T operator ()(vector<T>v)
	{
		auto result = min_element(v.begin(), v.end());
		return *result;
	}	
};

template<class T>
class MaxEl
{
public:	
	int operator ()(vector<T>v)
	{
		auto result = max_element(v.begin(), v.end());
		return *result;
	}
};

template<class T>
class Sort
{
public:
	void operator()(vector<T>v) {
		cout << "Сортування за зрозтанням : " << endl;
		sort(v.begin(), v.end(), [](T a, T b) {return a < b;});
		print(v); 
		cout << endl;
		cout << "\nСортування за спаданням : " << endl;
		sort(v.begin(), v.end(), [](T a, T b) {return a > b; });
		print(v); 
		cout << endl;
	}

};

template<class T>
class Plus
{
public:	
		void operator()(vector<T>v, T a) {
			cout << "\n+Вмістимість вектора після збільшення його розміру : " << endl;
			v.resize(a);
			cout << v.size() <<endl;
			print(v);
			cout << endl;
		}
};

template<class T>
class Minus
{
public:
	void operator()(vector<T>v,T a) {
		cout << "\n-Вмістимість вектора після зменшення  його розміру : " << endl;
		v.resize(a);//дозволяє збільшити або зменшити кількість обєктів у векторі  reserve дозволяє лише збільшити кількість вмісту
		cout << v.size() << endl;	//показує ємність вектора 	
		print(v);
		cout << endl;
	}
};

template<class T>
class Delete {
public:
	void operator()(vector<T>v) {
		T a;
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
	vector<double>v= { 10.4, 10.1, 3.8, 9.3, 7.2, 3.6, 4.6 ,7.9};
	
	int a = 0, b = 0;
	/*for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 90-20;
	}*/
	print(v);
	cout << endl;
	MinEl<double> minn;
	cout<<"\nМінімальний елемент у векторі : " << minn(v) << endl<<endl;
	MaxEl<double> maxx;
	cout <<"Максимальний елемент у векторі : " << maxx(v) << endl << endl;

	Sort<double> sortt;
	sortt(v);
	
	Plus<double> Vec;
	cout << "Введіть новий, більший розмір вектора : " << endl;
	cin >> a;
	Vec(v, a);

	Minus<double> Ve;
	cout << "Введіть новий, менший розмір вектора : " << endl;
	cin >> b;
	Ve(v, b);

	Delete<double> d;
	d(v);
}


