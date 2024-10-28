#include <iostream>

using namespace std;

class Temperature {
	private:
		double degreesKelvin,
		       degreesFahrenheit,
		       degreesCelsius;
	public:
		void setTempKelvin(double degreesKelvin) { 
            		degreesCelsius = degreesKelvin - 273.15; // Convert to Celsius
            		degreesFahrenheit = (degreesCelsius * 9.0 / 5.0) + 32; // Convert to Fahrenheit
		}
		double getTempKelvin() { 
			return degreesKelvin;
		}
		void setTempCelsius() {  }
		double getTempCelsius() { 
			return degreesCelsius;
		} 
		void setTempFahrenheit() {  }
		double getTempFahrenheit() { 
			return degreesFahrenheit;
		}
};

int main() {
    // Define variable
    double degreesKelvin;

    // Create an object of Temperature
    Temperature temp;

    // Prompt user for input
    cout << "Enter a temperature in degrees Kelvin: ";
    cin >> degreesKelvin;

    // Set the temperature in Kelvin
    temp.setTempKelvin(degreesKelvin);

    // Display the temperatures in Celsius and Fahrenheit
    cout << "Temperature in Celsius: " << temp.getTempCelsius() << "°C" << endl;
    cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << "°F" << endl;

    return 0;
}
