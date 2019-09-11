// LeetCodeTest.cpp : Defines the entry point for the console application.
//

#include "Common.h"

#include "tests/LC/BasicCalculator2.h"

#include <iostream>
#include <memory>
#include <chrono>

int main(int argc, char* argv[])
{
	auto begin = chrono::high_resolution_clock::now();

	// code to benchmark
    BasicCalculator2::Test();
    std::cout << "Total time lapsed: " << chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - begin).count() * 0.001 << "ms" << std::endl;
	return 0;
}
