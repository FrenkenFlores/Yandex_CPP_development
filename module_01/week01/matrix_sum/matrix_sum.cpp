//
// Created by FrenkenFlores on 13.01.2022.
//
#include <new>
#include <iostream>
#include <stdexcept>

class Matrix {
private:
	int _num_rows;
	int _num_cols;
	int **_matrix;

public:
	Matrix(): _num_rows(0), _num_cols(0) {
		_matrix = nullptr;
	}
	Matrix(const int num_rows, const int num_cols): _num_rows(num_rows), _num_cols(num_cols), _matrix(nullptr) {
		Reset(_num_rows, _num_cols);
	}

	void Print() const{
		for (int j = 0; j < _num_rows; j++) {
			for (int i = 0; i < _num_cols; i++) {
				std::cout << &_matrix[j][i] << "(" << _matrix[j][i] << ")";
				if (i != GetNumColumns() - 1)
					std::cout << " ";
			}
			std::cout << std::endl;
		}
	}

	void Reset(const int new_num_rows, const int new_num_cols) {
		_num_rows = new_num_rows;
		_num_cols = new_num_cols;
		if (_num_rows < 0) {
			throw std::out_of_range("num_rows must be >= 0");
		}
		if (_num_cols < 0) {
			throw std::out_of_range("num_columns must be >= 0");
		}

		// Clean old matrix
		if (_matrix) {
			for (int i = 0; i < _num_cols; i++) {
				delete[] _matrix[i];
			}
			delete [] _matrix;
		}

		// If it is empty matrix
		if (_num_rows == 0 && _num_cols == 0) {
			_matrix = nullptr;
		}
		else {
			try {
				_matrix = new int*[_num_cols];
				for (int i = 0; i < _num_cols; i++) {
					_matrix[i] = new int[_num_rows];
					for (int j = 0; j < _num_rows; j++) {
						_matrix[i][j] = 0;
					}
				}
			} catch (const std::bad_array_new_length &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}

	int At(const int num_row, const int num_col) const {
		if (num_row >= _num_rows || num_col >= _num_cols || num_row < 0 || num_col < 0) throw std::out_of_range("Out of range");
		return _matrix[num_row][num_col];
	}

	int &At(const int num_row, const int num_col) {
		if (num_row >= _num_rows || num_col >= _num_cols || num_row < 0 || num_col < 0) throw std::out_of_range("Out of range");
		return _matrix[num_row][num_col];
	}

	int GetNumRows() const {
		return _num_rows;
	}

	int GetNumColumns() const {
		return _num_cols;
	}

	~Matrix() {
		Reset(0, 0);
	}

};

std::istream &operator>>(std::istream &is, Matrix &matrix) {
	int num_rows, num_cols;
	is >> num_rows >> num_cols;
	matrix.Reset(num_rows, num_cols);
	for (int j = 0; j < matrix.GetNumRows(); j++) {
		for (int i = 0; i < matrix.GetNumColumns(); i++) {
			is >> matrix.At(j, i);
		}
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
	os << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
	for (int j = 0; j < matrix.GetNumRows(); j++) {
		for (int i = 0; i < matrix.GetNumColumns(); i++) {
			os << matrix.At(j, i);
			if (i != matrix.GetNumColumns() - 1)
				os << " ";
		}
		os << std::endl;
	}
	return os;
}

bool operator==(const Matrix &matrix1, const Matrix &matrix2) {
	if (matrix1.GetNumColumns() != matrix2.GetNumColumns() || matrix1.GetNumRows() != matrix2.GetNumRows()) {
		return false;
	}
	for (int j = 0; j < matrix1.GetNumRows(); j++) {
		for (int i = 0; i < matrix1.GetNumColumns(); i++) {
			if (matrix1.At(j, i) != matrix2.At(j, i))
				return false;
		}
	}
	return true;
}

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {
	if (matrix1.GetNumRows() != matrix2.GetNumRows()) {
		throw std::invalid_argument("Mismatched number of rows");
	}

	if (matrix1.GetNumColumns() != matrix2.GetNumColumns()) {
		throw std::invalid_argument("Mismatched number of columns");
	}

	Matrix new_matrix(matrix1.GetNumRows(), matrix1.GetNumColumns());

	for (int j = 0; j < matrix1.GetNumRows(); j++) {
		for (int i = 0; i < matrix1.GetNumColumns(); i++) {
			new_matrix.At(j, i) = matrix1.At(j, i) + matrix2.At(j, i);
		}
	}
	return new_matrix;
}