#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
#include <cmath>
#include <string>
using namespace std;

int maxOD(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	return a + b;
}
int minOD(int a, int b) {
	int ans;
	if (a > b) {
		for (int i = 2; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				ans = i;
				break;
			}
		}
	}
	else {
		for (int i = 2; i <= b; i++) {
			if (a % i == 0 && b % i == 0) {
				ans = i;
				break;
			}
		}
	}
	return ans;
	
}

bool isPrime(int a) {
	bool flag = true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			flag = false;
		}
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));


	cout << "Сколько \"случайных\" чисел вы хотите в файле?" << endl;
	int num;
	int tmp;
	vector<int> vec;
	cin >> num;
	while (num < 0) {
		cout << "Вы не можете ввести отрицательное количество чисел, не так ли? " << endl;
		cin >> num;
	}
	ofstream inp;
	inp.open("inp.txt");
	if (!inp.is_open()) {
		cout << "Sorry, can't open your file...";
	}
	else {
		
			
			for (int i = 0; i < num; i++) {
				tmp = rand() % 100;
				vec.push_back(tmp);
				inp << tmp << endl;
			}

	}
	inp.close();
	
	inp.open("prime.txt");
	

	for (int i = 0; i < vec.size(); i++) {
		if (isPrime(vec[i])) {
			inp << vec[i] << endl;
			
		}
	}


	inp.close();

	cout << "Содержание какого файла вы хотете просмотреть? \n1. Первый файл \n2. Второй файл \n3. Оба файла" << endl;
	int opt;
	cin >> opt;
	cout << endl;
	ifstream outp;

	switch(opt) {
	case 1:
		
		outp.open("inp.txt");
		if (!outp.is_open()) {
			cout << "Sorry, can't open file. ";
		}
		else {
			int tmp;
			while (outp >> tmp) {
				cout << tmp << endl;
			}
			outp.close();
		}
		break;

	case 2:
		outp.open("prime.txt");
			if (!outp.is_open()) {
				cout << "Sorry, can't open file. ";
			}
			else {
				int tmp;
				while (outp >> tmp) {
					cout << tmp << endl;
				}
				outp.close();
			}
		break;
		
	case 3:
		cout << "Первый файл: " << endl;
		outp.open("inp.txt");
		if (!outp.is_open()) {
			cout << "Sorry, can't open file. ";
		}
		else {
			int tmp;
			while (outp >> tmp) {
				cout << tmp << endl;
			}
			outp.close();
		}
		cout << endl << "Второй файл: " << endl;
		outp.open("prime.txt");
		if (!outp.is_open()) {
			cout << "Sorry, can't open file. ";
		}
		else {
			int tmp;
			while (outp >> tmp) {
				cout << tmp << endl;
			}
			outp.close();
		}
		break;
	}

}