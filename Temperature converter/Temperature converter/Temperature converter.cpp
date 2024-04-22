#include <iostream>


using namespace std;

// Base class
class Temperature {
protected:
	double value;
public:
	Temperature(double temp) : value(temp) {}
	virtual void convert() = 0; // Pure virtual function
};
// Derived class for Celsius to Fahrenheit conversion
class CelsiusToFahrenheit : public Temperature {
public:
	CelsiusToFahrenheit(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = (value * 9 / 5) + 32;
		cout << value << " degrees Celsius is equal to " << convertedTemp << " degrees Fahrenheit." << std::endl;
	}
};
// Derived class for Fahrenheit to Celsius conversion
class FahrenheitToCelsius : public Temperature {
public:
	FahrenheitToCelsius(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = (value - 32) * 5 / 9;
		cout << value << " degrees Fahrenheit is equal to " << convertedTemp << " degrees Celsius." << std::endl;
	}
};
// Derived class for Celsius to Kelvin conversion
class CelsiusToKelvin : public Temperature {
public:
	CelsiusToKelvin(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = value + 273.15;
		cout << value << " degrees Celsius is equal to " << convertedTemp << " Kelvin." <<endl;
	}
};
// Derived class for Fahrenheit to Kelvin conversion
class FahrenheitToKelvin : public Temperature {
public:
	FahrenheitToKelvin(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = (value + 459.67) * 5 / 9;
		cout << value << " degrees Fahrenheit is equal to " << convertedTemp << " Kelvin."<< endl;
	}
};
// Derived class for Kelvin to Celsius conversion
class KelvinToCelsius : public Temperature {
public:
	KelvinToCelsius(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = value - 273.15;
		cout << value << " Kelvin is equal to " << convertedTemp << " degrees Celsius." << endl;
	}
};
// Derived class for Kelvin to Fahrenheit conversion
class KelvinToFahrenheit : public Temperature {
public:
	KelvinToFahrenheit(double temp) : Temperature(temp) {}
	void convert() override {
		double convertedTemp = (value * 9 / 5) - 459.67;
		cout << value << " Kelvin is equal to " << convertedTemp << " degrees Fahrenheit."<< endl;
	}
};
int main() {
	int numConversions;
	cout << "Enter the number of temperature conversions to perform: ";
	cin >> numConversions;
	for (int i = 0; i < numConversions; i++) {
		int choice;
		double temperature;
		cout << "Conversion " << (i + 1) << endl;
		cout << "1. Celsius to Fahrenheit" << endl;
		cout << "2. Fahrenheit to Celsius" << endl;
		cout << "3. Celsius to Kelvin" << endl;
		cout << "4. Fahrenheit to Kelvin" << endl;
		cout << "5. Kelvin to Celsius" << endl;
		cout << "6. Kelvin to Fahrenheit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "Enter the temperature value: ";
		cin >> temperature;
		Temperature* tempObj;
		switch (choice) {
		case 1:
			tempObj = new CelsiusToFahrenheit(temperature);
			break;
		case 2:
			tempObj = new FahrenheitToCelsius(temperature);
			break;
		case 3:
			tempObj = new CelsiusToKelvin(temperature);
			break;
		case 4:
			tempObj = new FahrenheitToKelvin(temperature);
			break;
		case 5:
			tempObj = new KelvinToCelsius(temperature);
			break;
		case 6:
			tempObj = new KelvinToFahrenheit(temperature);
			break;
		default:
			std::cout << "Invalid choice. Skipping this conversion." << std::endl;
			continue;
		}
		tempObj->convert();
		delete tempObj;
	}
	return 0;
}