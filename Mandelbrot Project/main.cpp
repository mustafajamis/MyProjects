#include <iostream>

#include "FractalCreator.h"

using namespace std;
using namespace MusFirstProject;

int main() {

	int height = 600;

	FractalCreator fractalCreator(800, 600);
	// want to see the actuall Mandelbrot commant the above

	// Note: if you want zoom the Mandelbrot sequence just remember you should not jump so dramatically! :)
	fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
	fractalCreator.addZoom(Zoom(312, height - 304, 0.1));
	fractalCreator.addZoom(Zoom(267, height - 520, 0.1));
	//fractalCreator.addZoom(Zoom(177, height - 286, 0.1));



	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("tests.bmp");

	cout << "We done here World!." << endl;

}