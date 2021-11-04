#include <iostream>
#include <string>
#include <Windows.h>
#include "List.h"
#include "Keeper.h"
#include "University.h"
#include "Student.h"
#include "Teacher.h"
#include "AdministrativeStaff.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper kipper;
	int c;

	while (true)
	{
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить ВУЗ"
			<< "\n3.Вывод данных на экран"
			<< "\n4.Удалить ВУЗ"
			<< "\n5.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (kipper.load("save.txt"))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {
			int type;
			std::string FIO;
			cout << "\tВыбирите ВУЗ:\n"
				<< "\n\t1.Студент"
				<< "\n\t2.Преподаватель"
				<< "\n\t3.Административный персонал\n\t->";
			cin >> type;
			switch (type)
			{
			case 1: {
				std::string group, specialty, course, GPA;
				cout << "\tВведите ФИО: ";
				getline(cin, FIO);
				getline(cin, FIO);
				cout << "\tВведите группа: ";
				getline(cin, group);
				cout << "\tВведите специальность: ";
				getline(cin, specialty);
				cout << "\tВведите курс: ";
				getline(cin, course);
				cout << "\tВведите средний балл: ";
				getline(cin, GPA);
				kipper.add(new Student(FIO, group, specialty, course, GPA));
				cout << "\tВУЗ №" << kipper.size() << " успешно добавлен\n";
				break; }
			case 2: {
				std::string buffer;
				size_t am;
				List<std::string> groups, subjects;
				cout << "\tВведите ФИО: ";
				getline(cin, FIO);
				getline(cin, FIO);
				cout << "\tВведите кол-во групп: ";
				cin >> am;
				getline(cin, buffer);
				for (size_t i = 0; i < am; i++)
				{
					cout << "\tВведите группу №" << i << ": ";
					getline(cin, buffer);
					groups.push_back(buffer);
				}
				cout << "\tВведите кол-во предметов: ";
				cin >> am;
				getline(cin, buffer);
				for (size_t i = 0; i < am; i++)
				{
					cout << "\tВведите предмет №" << i << ": ";
					getline(cin, buffer);
					subjects.push_back(buffer);
				}
				kipper.add(new Teacher(FIO, groups, subjects));
				cout << "\tВУЗ №" << kipper.size() << " успешно добавлен\n";
				break; }
			case 3: {
				std::string post, phone, responsibility;
				cout << "\tВведите ФИО: ";
				getline(cin, FIO);
				getline(cin, FIO);
				cout << "\tВведите должность: ";
				getline(cin, post);
				cout << "\tВведите телефон: ";
				getline(cin, phone);
				cout << "\tВведите область ответственности: ";
				getline(cin, responsibility);
				kipper.add(new AdministrativeStaff(FIO, post, phone, responsibility));
				cout << "\tВУЗ №" << kipper.size() << " успешно добавлен\n";
				break; }
			default: cout << "\tВыбрано недопустимое значение!\n";
			}
			break; }
		case 3: {
			if (kipper.size() == 0)
				cout << "\tВУЗ отсутствует.\n";
			else
				kipper.print();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\tВУЗ отсутствует.\n";
			else
			{
				size_t num;
				cout << "\tВыбирите ВУЗ. Доступны: №"
					<< (kipper.size() == 1 ? "" : "1 - №")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.del(num - 1);
					cout << "\tДанные успешно удалены\n";
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.save("save.txt"))
				cout << "\tДанные успешно сохранены\n";
			else
				cout << "\tПри сохранении произошла ошибка\n";
			break; }
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}

/*
Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
	▪ добавление и удаление производных объектов абстрактного класса Base;
	▪ полное сохранение себя в файле;
	▪ полное восстановление себя из файла.

ВУЗ хранит данные по студентам, преподавателям и административному персоналу. 
ВУЗ
	Студент:					ФИО, группа, специальность, курс, средний балл;
	Преподаватель:				ФИО, группы, предметы;
	Административный персонал:	ФИО, должность, телефон, область ответственности;

*/