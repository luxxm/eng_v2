#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

namespace render {
	class screen {
	private:
		std::vector<std::vector<char>> pixels;

		int sX = 50, sY = 50;
	public:
		screen() {
			for (int i = 0; i < sY; i++) {
				std::vector<char> line;
				for (int j = 0; j < sX; j++)
					line.push_back(' ');
				this->pixels.push_back(line);
			}
		}

		screen(int x, int y) {
			this->sX = x;
			this->sY = y;
			
			for (int i = 0; i < sY; i++) {
				std::vector<char> line;
				for (int j = 0; j < sX; j++)
					line.push_back(' ');
				this->pixels.push_back(line);
			}
		}

		int8_t set(int x, int y, char c) {
			if (x < 0 || x >= this->sX || y < 0 || y >= this->sY)
				return -1;

			this->pixels[y][x] = c;

			return 1;
		}

		char get(int x, int y) {
			return this->pixels[y][x];
		}

		int8_t draw() {
			for (int i = 0; i < this->sY; i++) {
				for (int j = 0; j < this->sX; j++)
					std::cout << this->pixels[i][j];
				std::cout << std::endl;
			}

			return 1;
		}

		int8_t clear() {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					this->pixels[i][j] = ' ';

			return 1;
		}

		int8_t flush() {
			return system("clear");
		}
	};
};
