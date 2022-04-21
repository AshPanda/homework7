/*
1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, 
а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. 
Затем переместите ресурс, которым владеет указатель today в указатель date. 
Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
• Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам). 
Функция должна вернуть более позднюю дату.
• Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.

Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
*/

#include <iostream>
//Task#1
class Date
{
public:
	Date(int day, int month, int year) : Day(day), Month(month), Year(year) {}
	const int& getDay() const {
		return Day;
	}
	const int& getMonth() const {
		return Month;
	}
	const int& getYear() const {
		return Year;
	}
	friend std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		os << d.Day << '.' << d.Month << '.' << d.Year;

		return os;
	}

protected:
	int Day;
	int Month;
	int Year;
};

template <class T>
class _ptr
{
private:
	T* ptr;
public:
	_ptr(T* ptr = nullptr) : ptr(ptr) {}
	~_ptr() { delete ptr; }

	_ptr(_ptr& p) {
		ptr = p.ptr;
		p.ptr = nullptr;
	}

	_ptr& operator=(_ptr& p)
{
		if (&p == this)
			return *this;

		delete ptr;
		ptr = p.ptr;
		p.ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }

	bool isNull() const { return ptr == nullptr; }
};
void Task1()
{
	_ptr<Date> today(new Date(21, 04, 2022));

	std::cout << "Day: " << today->getDay() << std::endl;
	std::cout << "Month: " << today->getMonth() << std::endl;
	std::cout << "Year: " << today->getYear() << std::endl;
	std::cout << "today: " << *today << std::endl;

	_ptr<Date> date;

	if (today.isNull())
	{
		std::cout << "today is null\n";
	}
	else
	{
		std::cout << "today is not null\n";
	}
	if (date.isNull())
	{
		std::cout << "date is null\n";
	}
	else
	{
		std::cout << "date is not null\n";
	}
	date = today;
	if (today.isNull())
	{
		std::cout << "today is null\n";
	}
	else
	{
		std::cout << "today is not null\n";
	}
	if (date.isNull())
	{
		std::cout << "date is null\n";
	}
	else
	{
		std::cout << "date is not null\n";
	}

	std::cout << "date: " << *date << std::endl;
}
//Task#2
const _ptr<Date>& Compair(const _ptr<Date>&, const _ptr<Date>&);


const _ptr<Date>& Compair(const _ptr<Date>& a, const _ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

void Swap(_ptr<Date>& a, _ptr<Date>& b)
{
	_ptr<Date> temp(a);
	a = b;
	b = temp;
}

void Task2()
{
	_ptr<Date> date1(new Date(6, 11, 2024));
	_ptr<Date> date2(new Date(10, 10, 2023));
	_ptr<Date> date3(new Date(11, 07, 2025));

	std::cout << *Compair(date1, date2) << std::endl;
	Swap(date2, date3);
	std::cout << *Compair(date1, date2) << std::endl;
}

int main()
{
	Task1();
	Task2();
}

