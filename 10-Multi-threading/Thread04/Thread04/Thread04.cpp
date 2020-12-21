// Thread04.cpp�: d�finit le point d'entr�e pour l'application console.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include "PerlinNoise.h"
#include "ppm.h"

using namespace std;


// Given z as input generate a 2D image from Perlin noise
// id and id_width are parameters use to generate a unique file name
void make_perlin_noise(int id, int id_width, double z) {
	// Define the size of the image
	unsigned int width = 1280, height = 720;

	// Create an empty PPM image
	ppm image(width, height);

	// Create a PerlinNoise object with a random permutation vector generated with seed
	unsigned int seed = 237;
	PerlinNoise pn(seed);

	unsigned int kk = 0;
	// Visit every pixel of the image and assign a color generated with Perlin noise
	for (unsigned int i = 0; i < height; ++i) {     // y
		for (unsigned int j = 0; j < width; ++j) {  // x
			double x = (double)j / ((double)width);
			double y = (double)i / ((double)height);

			// Wood like structure
			double n = 20 * pn.noise(x, y, z);
			n = n - floor(n);

			// Map the values to the [0, 255] interval, for simplicity we use 
			// tones of grey
			image.r[kk] = floor(255 * n);
			image.g[kk] = floor(255 * n);
			image.b[kk] = floor(255 * n);
			kk++;
		}
	}

	// generate a unique name from id
	string tmp, name;
	tmp = to_string(id);
	if (int diff = id_width - tmp.length()) {
		for (int i = 0; i < diff; ++i) name += "0";
	}
	name = "img_" + name + tmp + ".ppm";

	// Save the image in a PPM file
	image.write(name);
}

int main() {
	int frames = 20;
	int id_width = 4;
	double delta = 1.0 / (double)frames;

	std::vector<std::future<void>> futures;

	//// d�finit les promises
	//std::promise<int> prodPromise;
	//std::promise<int> divPromise;
	//// r�cup�re les futures
	//std::future<int> prodResult = prodPromise.get_future();
	//std::future<int> divResult = divPromise.get_future();

	cout << "traitement en cours" << endl;
	auto start = chrono::steady_clock::now();
	for (int id = 0; id <= frames; ++id) {
		double z = (double)id * delta;
		futures.push_back(std::async(make_perlin_noise , id, id_width, z));
	}
	auto end = chrono::steady_clock::now();

	auto diff = end - start;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	return 0;
}