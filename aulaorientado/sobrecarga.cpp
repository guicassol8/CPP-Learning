#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Circulo {
	private:
		double px, py, raio;
		double calculaArea () {
			return M_PI*raio*raio;
		}	
		double calculaCircunferencia () {
		return 2.0*M_PI*raio;
		}
};
