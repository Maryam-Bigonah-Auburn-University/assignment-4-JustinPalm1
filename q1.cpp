#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
	private:
		double amountDispensed,
		       amountCharged,
		       costPerGallon;

	public:
		double getAmountDispensed() { return amountDispensed; }
		double getAmountCharged() { return amountCharged; }
		double getCostPerGallon() { return costPerGallon; }
		void setCostPerGallon(double cpg) { costPerGallon = cpg; }
        
		void dispense(int seconds) {

			amountDispensed = seconds * 0.10; // Dispenses 0.10 gallons per second
			
			amountCharged = amountDispensed * costPerGallon;
		}
		void reset() {
            
			amountDispensed = 0.0;
			amountCharged = 0.0;
		}
		// Method to display amounts
		void display() {
            		cout << fixed << setprecision(2); // Set decimal precision for currency
            		cout << "Amount dispensed: " << amountDispensed << " gallons" << endl;
            		cout << "Cost per gallon: $" << costPerGallon << endl;
            		cout << "Total cost: $" << amountCharged << endl;
		}
		};
	
int main() {
	
     // Variables
    double costPerGallon;
    int seconds;

    // Object of GasPump
    GasPump gasPump;

    // Prompt user for input
    cout << "Enter the cost per gallon of gas: $";
    cin >> costPerGallon;
    gasPump.setCostPerGallon(costPerGallon);

    cout << "Enter the number of seconds to pump gas: ";
    cin >> seconds;

    // Dispense gas
    gasPump.dispense(seconds);

    // Display results
    gasPump.display();
	

	return 0;
}
