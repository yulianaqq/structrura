#include <iostream>
#include <string>

using namespace std; 


struct WashingMachine {
    string brand;
    string color;
    double width; 
    double depth; 
    double height; 
    int power; 
    int spinSpeed; 
    int heatingTemperature; 
};


void inputWashingMachineInfo(WashingMachine& machine);
void printWashingMachineTable(const WashingMachine* machines, int size);

int main() {
    int machineCount = 0;
    int maxMachines = 2; 
    WashingMachine* machines = new WashingMachine[maxMachines];

    char addMore = 'y';
    while (addMore == 'y' || addMore == 'Y') {
        if (machineCount == maxMachines) {
       
            maxMachines *= 2;
            WashingMachine* temp = new WashingMachine[maxMachines];
            for (int i = 0; i < machineCount; ++i) {
                temp[i] = machines[i];
            }
            delete[] machines;
            machines = temp;
        }

        cout << "\nEnter details for washing machine " << (machineCount + 1) << ":\n";
        inputWashingMachineInfo(machines[machineCount]);
        machineCount++;

        cout << "Do you want to add another washing machine? (y/n): ";
        cin >> addMore;
        cin.ignore(); 
    }

   
    printWashingMachineTable(machines, machineCount);

 
    delete[] machines;

    return 0;
}


void inputWashingMachineInfo(WashingMachine& machine) {
    cout << "Enter brand: ";
    getline(cin, machine.brand);

    cout << "Enter color: ";
    getline(cin, machine.color);

    cout << "Enter width (cm): ";
    cin >> machine.width;

    cout << "Enter depth (cm): ";
    cin >> machine.depth;

    cout << "Enter height (cm): ";
    cin >> machine.height;

    cout << "Enter power (W): ";
    cin >> machine.power;

    cout << "Enter spin speed (rpm): ";
    cin >> machine.spinSpeed;

    cout << "Enter heating temperature (°C): ";
    cin >> machine.heatingTemperature;
    cin.ignore(); 
}

void printWashingMachineTable(const WashingMachine* machines, int size) {
  
    cout << "Brand       Color      Width (cm)  Depth (cm)  Height (cm)  Power (W)  Spin Speed (rpm)  Heating Temperature (°C)\n";
    cout << "-------------------------------------------------------------------------------------------------------------------\n";


    for (int i = 0; i < size; ++i) {
        cout << machines[i].brand << "       "
             << machines[i].color << "       "
             << machines[i].width << "           "
             << machines[i].depth << "          "
             << machines[i].height << "           "
             << machines[i].power << "         "
             << machines[i].spinSpeed << "             "
             << machines[i].heatingTemperature << endl;
    }
}
