/*Вариант 11 лр 10.
Реализовать любое задание лабораторной работы № 5
с использованием файлового ввода-вывода.
По заданию: Дан массив размера N (N — четное число).
Поменять местами его первый элемент со вторым,
третий — с четвертым и т. д.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

const char* IN_PATH = "lab10.txt";
const char* OUT_PATH = "the_lab10.txt";

int main() {
	setlocale(LC_ALL, "ru");
	ifstream fin;
	fin.open(IN_PATH);

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 0;
	}
	else {
		cout << "Файл открыт!" << endl;
	}
	char s;
	fin.get(s);
	int n = s-'0';
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	fin.close();

	cout << "Ваш массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;


	for (int i = 0; i < n - 1; i += 2) {
		int f = a[i];
		a[i] = a[i + 1];
		a[i + 1] = f;
	}


	cout << "Массив с изменениями: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;


	ofstream recording;
	recording.open(OUT_PATH);

	if (!recording.is_open()) {
		cout << "Ошибка открытия файла!!!" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		recording << a[i] << ' ';
	}
	cout << "Файл записан." << endl << endl;
	recording.close();

	delete[] a;
}