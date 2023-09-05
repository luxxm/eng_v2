#pragma once

#include <vector>
#include "vectors.hpp"

namespace matrices {
	template <typename T>
	class mat4 {
	private:
		 std::vector<std::vector<T>>matrix[4];
	public:
		mat4() {};

		mat4(vectors::vec4<T> *vec_arr) {
			//same issue with operator=()
			for (int i = 0; i < 4; i++)
				this->matrix[i] = vec_arr[i];
		}

		mat4 inverse() {
			//to-do
		}

		void makeIdentity() {
			//clear matrix
			for (int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					this->matrix[i][j] = 0;

			//set diagonal to 1s
			for (int i = 0; i < 3; i++) // i < 3 because no need for 4th row
				this->matrix[i][i] = 1;
		}
		
	//operator overloads
		
		mat4 operator=(vectors::vec4<T> *vec_arr) {
			//this->matrix = vec_arr
			//doesnt work for some reason
			//find fix later
			//should just change the addr of matrix to the one of vec_arr
			//but compiler doesnt like it
			for (int i = 0; i < 4; i++)
				this->matrix[i] = vec_arr[i];
		}

		std::vector<T>& operator[](int n) {
			return matrix[n];
		}

		mat4 operator+(mat4<T> m) {
			mat4 result;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					result[i][j] = this->matrix[i][j] + m[i][j];
			return result;
		}
		mat4 operator+=(mat4<T> m) {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					this->matrix[i][j] += m[i][j];
			return *this;
		}

		mat4 operator-(mat4<T> m) {
			mat4 result;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					result[i][j] = this->matrix[i][j] - m[i][j];
			return result;
		}
		mat4 operator-=(mat4<T> m) {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					this->matrix[i][j] -= m[i][j];
			return *this;
		}

		mat4 operator*(mat4<T> m) {
			mat4 result;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						result[i][j] += this->matrix[i][k]*m[k][j];

			return result;
		}
		vectors::vec4<T> operator*(vectors::vec4<T> v) {
			vectors::vec4<T> result;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					result[i] += this->matrix[i][j]*v[j];
			return result;
		}
	};
};
