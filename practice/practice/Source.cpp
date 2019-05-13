#include <iostream>
#include <fstream>
#include <string>
#define Draft 5 // ��������
/*
	������� ���� �������� ������������������ ����������� �����. ���������� ���������� ���������� ��� ��������� (ai,aj) 
	����� ������, � ������� 1 <= i < j <= N, ����� ��������� �������, ������������ ������� �� 13, 
	� ������ ����� � ������������������ ���������� �� �����, ��� �� 5. �������� ��������� ��� ������� ���� ������.
*/
using namespace std;

int main() {
	// �������� �����
	const string path = "input.txt";
	ifstream of(path);
	int curr_num;

	//������������� ���������� ��� ���������� ���������
	int multiplicity26 = 0, // ���-�� ��������� ������� 26
		multiplicity13 = 0, // ���-�� ��������� ������� 13
		multiplicity2 = 0, // ���-�� ������ ���������
		multiplicity1 = 0, // ���-�� �� ������ ���������
		count = 0;

	int Queue[Draft] = { 0 }; // �������
	int i = 0;
	int curr_count = 5;

	for (of >> curr_num; !of.eof(); of >> curr_num) {
		if (curr_num > 0) {
			if (i < Draft) {
				Queue[i] = curr_num;
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
				int curr = curr_num;
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


