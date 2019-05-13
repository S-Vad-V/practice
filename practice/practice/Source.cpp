#include <iostream>
#include <fstream>
#include <string>
#define Draft 5 // Смещение
/*
	Входной файл содержит последовательность натуральных чисел. Необходимо определить количество пар элементов (ai,aj) 
	этого набора, в которых 1 <= i < j <= N, сумма элементов нечётна, произведение делится на 13, 
	а номера чисел в последовательности отличаются не менее, чем на 5. Напишите программу для решения этой задачи.
*/

using namespace std;

int Convert_to_Int(string str) {
	/*Функция перевода из типа string в int
		Если в подаваемой строке содержатся только число, то программа вернёт натуральное число
		Иначе выдаст -1, что означает ошибку в работе функции	
	*/
	int res = 0, j = 1;
	for (int i = str.length()-1; i >= 0; --i) {
		if (str[i] - '0' < 10) {
			res += (str[i] - '0') * j;
			j *= 10;
		}
		else 			
			return -1;				
	}
	return res;
}


int main() {
	// Открытие файла
	const string path = "input.txt";
	ifstream of(path);
	string str;

	//Инициализация переменных для выполнения алгоритма
	int multiplicity26 = 0, // Кол-во элементов кратных 26
		multiplicity13 = 0, // Кол-во элементов кратных 13
		multiplicity2 = 0, // Кол-во чётных элементов
		multiplicity1 = 0, // Кол-во не чётных элементов
		count = 0;

	int Queue[Draft] = { 0 }; // Очередь
	int i = 0;
	int curr_count = 5;

	for (of >> str; !of.eof(); of >> str) {
		if (Convert_to_Int(str) > 0) {
			if (i < Draft) {
				Queue[i] = Convert_to_Int(str);
				i++;
			}
			else {
				if (Queue[curr_count % Draft] % 13 == 0) {
					if (Queue[curr_count % Draft] % 2 == 0) {
						multiplicity26++;
						multiplicity2++;
					}
					else {
						multiplicity1++;
						multiplicity13++;
					}
				}
				else {
					if (Queue[curr_count % Draft] % 2 == 0)
						multiplicity2++;
					else
						multiplicity1++;
				}
				int curr = Convert_to_Int(str);
				if (curr % 13 == 0) {
					if (curr % 2 == 0)
						count += multiplicity1;
					else
						count += multiplicity2;
				}
				else {
					if (curr % 2 == 0)
						count += multiplicity13;
					else
						count += multiplicity26;
				}
				Queue[curr_count % Draft] = curr;
				curr_count++;
			}
		}
		else {
			cout << "Incorrect input" << endl;
			system("pause");
			return -1;
		}
	}
	if (curr_count < Draft)
		cout << "Incorrect input"<< endl;
	else
		cout << count << endl;
	system("pause");
	return 0;
}


