#pragma once
#ifndef _SIM_
#define _SIM_

#include <iostream>
#include <vector>
using namespace std;
vector<double> minor(double matrix[3][3]);
double det_3(double matrix[3][3]) {
	double answ;
	answ = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
		- matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
		+ matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
	return answ;
}
vector<double> invers(double matrix[3][3]) {
	int i, j;
	static double answ;
	static bool _switch = true;
	if (_switch) {
		_switch = false;
		answ = det_3(matrix);
		return minor(matrix);
	}
	if (!_switch && answ) {
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				matrix[i][j] /= answ;
		vector<double>matrix_coded;
		matrix_coded.clear();
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				matrix_coded.push_back(matrix[i][j]);
		_switch = true;
		return matrix_coded;
	}
	else if (!answ)cout << "\n***No Answer!***";
}
vector<double> solve_invers_matrix(double matrix[3][3], double answ[3]) {
	vector<double>invers_matrix;
	double x[3];
	int i, j;
	invers_matrix = invers(matrix);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[i][j] = invers_matrix[i * 3 + j];
	invers_matrix.clear();
	for (i = 0; i < 3; i++) {
		x[i] = 0;
		for (j = 0; j < 3; j++)
			x[i] = x[i] + matrix[i][j] * answ[j];
	}
	invers_matrix.push_back(x[0]);
	invers_matrix.push_back(x[1]);
	invers_matrix.push_back(x[2]);
	return invers_matrix;
}
vector<double> appendant(double matrix[3][3]) {
	double new_matrix[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			new_matrix[i][j] = matrix[j][i];
	return invers(new_matrix);
}
vector<double> harmonic(double matrix[3][3]) {
	matrix[0][1] *= -1;
	matrix[1][0] *= -1;
	matrix[2][1] *= -1;
	matrix[1][2] *= -1;
	return appendant(matrix);
}
vector<double> minor(double matrix[3][3]) {
	double new_matrix[3][3];
	new_matrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	new_matrix[0][1] = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	new_matrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	new_matrix[1][0] = matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1];
	new_matrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	new_matrix[1][2] = matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0];
	new_matrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	new_matrix[2][1] = matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0];
	new_matrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return harmonic(new_matrix);
}
#endif