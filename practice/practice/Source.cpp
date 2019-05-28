#include <iostream>
#include <fstream>
#include <string>
#define Draft 5 // Смещение
using namespace std;

int main() {
	const string path = "input.txt";
	int a;
	ofstream ofile(path);
	do {
		cin >> a;
		ofile << a << " ";
	} while (a);
	ofile.close();
	// Открытие файла
	ifstream ifile(path);
	int curr_num;

	//Инициализация переменных для выполнения алгоритма
	int multiplicity26 = 0, // Кол-во элементов кратных 26
		multiplicity13 = 0, // Кол-во элементов кратных 13
		multiplicity2 = 0, // Кол-во чётных элементов
		multiplicity1 = 0, // Кол-во не чётных элементов
		count = 0;

	int Queue[Draft] = { 0 }; // Очередь
	int i = 0;
	int Queue_count = 5;

	for (ifile >> curr_num; !ifile.eof(); ifile >> curr_num) {
		if (curr_num > 0) {
			if (i < Draft) {
				Queue[i] = curr_num;
				i++;
			}
			else {
				if (Queue[Queue_count % Draft] % 13 == 0) {
					if (Queue[Queue_count % Draft] % 2 == 0) {
						multiplicity26++;
						multiplicity2++;
					}
					else {
						multiplicity1++;
						multiplicity13++;
					}
				}
				else {
					if (Queue[Queue_count % Draft] % 2 == 0)
						multiplicity2++;
					else
						multiplicity1++;
				}
				if (curr_num % 13 == 0) {
					if (curr_num % 2 == 0)
						count += multiplicity1;
					else
						count += multiplicity2;
				}
				else {
					if (curr_num % 2 == 0)
						count += multiplicity13;
					else
						count += multiplicity26;
				}
				Queue[Queue_count % Draft] = curr_num;
				Queue_count++;
			}
		}
		else {
			cout << "Incorrect input" << endl;
			system("pause");
			return -1;
		}
	}
	if (Queue_count < Draft)
		cout << "Incorrect input"<< endl;
	else
		cout << count << endl;
	system("pause");
	return 0;
}


