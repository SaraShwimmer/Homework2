// HW2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

//Задание 1

/*
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы
переназначения имени, изменения возраста и веса. Создать производный класс Student
(студент), имеющий поле года обучения. Определить методы переназначения и увеличения
этого значения. Создать счетчик количества созданных студентов. В функции main() создать
несколько студентов. По запросу вывести определенного человека.
*/

enum class sex { man, woman };

class Person {
private:
	string* m_name;
	int m_age;
	sex m_gender;
	double m_weight;

public:

	Person(string* name, int age = 0, sex gender = sex::man, double weight = 0)
		: m_name(name), m_age(age), m_gender(gender), m_weight(weight) {}

	void setName(string* name) {
		m_name = name;
	};
	void setAge(int age) {
		m_age = age;
	};
	void setWeigth(double weight) {
		m_weight = weight;
	};
	const string* getName() {
		return m_name;
	};
	int getAge() {
		return m_age;
	};
	sex getGender() {
		return m_gender;
	};
	double getWeight() {
		return m_weight;
	};
};

class Student :public Person {
private:
	int yearOfStudy = 0;

public:

	Student(string* name, int age = 0, sex gender = sex::man, double weight = 0, int yearOfStudy = 0)
		: Person(name, age, gender, weight) {}
	int setYearOfStudy(int year) {
		yearOfStudy = year;
	}
	int getYearOfStudy() {
		return yearOfStudy;
	};
	void addStudyYear() {
		yearOfStudy++;
	};

};

class StudentsGroup {

private:
	int static const m_maxStudents = 3;
	int m_studentsAmount = 0;
	Student* m_students[m_maxStudents];
public:
	int getStudentsAmount() {
		return m_studentsAmount;
	};
	bool addStudent(Student* student) {

		if (m_studentsAmount >= m_maxStudents)
			return false;

		m_students[m_studentsAmount++] = student;
		return true;
	};
	Student* getStudent(string* name) {
		for (int i = 0; i < m_studentsAmount; i++) {
			if (*(m_students[i]->getName()) == *name) {
				return m_students[i];
			}
		}
		return NULL;
	};
	~StudentsGroup() {
		while (m_studentsAmount > 0) {
			delete m_students[--m_studentsAmount];
		}
	};

};


int main() {
	StudentsGroup studentsGroup;
	string studentName = "Pain";
	studentsGroup.addStudent(new Student(&studentName));
	cout << "Student amount = " << studentsGroup.getStudentsAmount() << endl;
	string searchName;
	cin >> searchName;
	Student* studentFound = studentsGroup.getStudent(&searchName);
	if (studentFound == NULL) {
		cout << "Student not found!";
	}
	else {
		cout << "Student found!";
	}
	return 0;
}

//Задание 2

/*
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс
GrannySmith, который наследует класс Apple
*/

//class Fruit {
//private:
//	string m_name;
//	string m_color;
//
//public:
//	Fruit(string name, string color) :
//		m_name(name), m_color(color) {}
//
//	//функция возвращает значение "имя"
//	string getName() {
//		return m_name;
//	}
//	//функция возвращает значение "цвет"
//	string getColor() {
//		return m_color;
//	}
//
//};
//class Apple :public Fruit {
//protected:
//	//необходимо для возможности вывода данных в класс GrannySmith
//	Apple(string name, string color) :Fruit(name, color) {
//
//	}
//public:
//
//	Apple(string color = "red") : Fruit("apple", color) {
//	}
//};
//class Banana :public Fruit {
//public:
//	Banana() : Fruit("banana", "yellow") {}
//
//};
//class GrannySmith :public Apple {
//public:
//	GrannySmith() :Apple("Granny Smith apple", "green") {
//
//	}
//};
//
//int main()
//{
//	Apple a;
//	Banana b;
//	GrannySmith c;
//
//	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//
//	return 0;
//
//}


//Задание 3
/*
Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя
объектно-ориентированное программирование. Сколько будет классов в программе? Какие классы
будут базовыми, а какие производными? Продумать реализацию игры с помощью классов и записать результаты.
*/

////класс, содержащий значение карт
//class Card {};
////класс, содержащий значение рубашки и зависящий от класса Card
//class Suit : public Card{};
////класс, содержащий значение карт на "столе"
//class Desk {};
////класс, обозначающий человека - игрока
//class Player{};
////класс, обозначающий компьютер-игрока
//class Computer{};
////класс, содержащий рейтинг игры
//class Rank{};
