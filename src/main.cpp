#include <chrono>
#include <iostream>
#include <thread>
#include "utils/matrices.hpp"
#include "utils/vectors.hpp"
#include "utils/renderer.hpp"

int main() {
	render::screen scr(30, 20);
	
	scr.set(10, 10, 'X');
	scr.draw();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	scr.flush();
};
