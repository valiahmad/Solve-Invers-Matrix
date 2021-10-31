// solve_invers_matrix.cpp
/*
*
* Solving Matrix By Using Invers Method
* =============PROJECT============
* Copyright (c) vali ahmad rahmani
* Date Jan,16,2021
* name solve_invers_matrix
*
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include "SIM.h"
using namespace std;

double matrix[3][3], answ[3];
///////////////////////////////////////////////////////////FUNCTIONS
void change_input() {
	int i, j;
	system("cls");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << "\nEnter Matrix[" << i << "]" << "[" << j << "] : ";
			cin >> matrix[i][j];
		}
	}
	system("cls");
	for (i = 0; i < 3; i++) {
		cout << "\nEnter Answer[" << i << "] : ";
		cin >> answ[i];
	}
	string file;
	file = "D:\\input.txt";
	ofstream outfile(file, ios::out);
	if (!outfile) {
		cout << "\n***File Not Found***";
		return;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			outfile << matrix[i][j] << " ";
		}
		outfile << answ[i] << endl;
	}
}
void read() {
	int i, j;
	string file = "D:\\input.txt";
	ifstream infile(file, ios::in);
	if (!infile) {
		cout << "\n***File Not Found***";
		return;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			infile >> matrix[i][j];
		infile >> answ[i];
	}
}
void write() {
	string file = "D:\\output.txt";
	ofstream outfile(file, ios::out);
	if (!outfile) {
		cout << "\n***File Not Found***";
		return;
	}
	for (int i = 0; i < 3; i++) {
		outfile << "X" << i << " = " << answ[i] << endl;
	}
}
///////////////////////////////////////////////////////////MAIN
int main()
{
	vector<double>ans;
	int i, j;
	change_input();
	read();
	ans = solve_invers_matrix(matrix, answ);
	cout << "\nAnwer Is :";
	for (i = 0; i < 3; i++) {
		cout << endl << "X" << i << " = " << ans[i];
		answ[i] = ans[i];
	}
	write();
	return 0;
}