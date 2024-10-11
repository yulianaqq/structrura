#include <iostream>
#include <string>

using namespace std; 


struct Car {
    string brand;
    string model;
    int year;
    double price;
    bool negotiable;
    string engine;
    string color;
    int ownerCount;
};


void inputCarInfo(Car& car);
void printCarTable(const Car* cars, int size);

int main() {
    int carCount = 0;
    int maxCars = 2; 
    Car* cars = new Car[maxCars];

    char addMore = 'y';
    while (addMore == 'y' || addMore == 'Y') {
        if (carCount == maxCars) {
          
            maxCars *= 2;
            Car* temp = new Car[maxCars];
            for (int i = 0; i < carCount; ++i) {
                temp[i] = cars[i];
            }
            delete[] cars;
            cars = temp;
        }

        cout << "\nEnter details for car " << (carCount + 1) << ":\n";
        inputCarInfo(cars[carCount]);
        carCount++;

        cout << "Do you want to add another car? (y/n): ";
        cin >> addMore;
        cin.ignore(); 
    }

   
    printCarTable(cars, carCount);

    // Звільняємо пам'ять
    delete[] cars;

    return 0;
}


void inputCarInfo(Car& car) {
    cout << "Enter brand: ";
    getline(cin, car.brand);

    cout << "Enter model: ";
    getline(cin, car.model);

    cout << "Enter year: ";
    cin >> car.year;

    cout << "Enter price: ";
    cin >> car.price;

    cout << "Is the price negotiable (1 for Yes, 0 for No): ";
    int negotiableInput;
    cin >> negotiableInput;
    car.negotiable = (negotiableInput == 1);

    cin.ignore(); 

    cout << "Enter engine: ";
    getline(cin, car.engine);

    cout << "Enter color: ";
    getline(cin, car.color);

    cout << "Enter number of owners: ";
    cin >> car.ownerCount;
    cin.ignore(); 
}


void printCarTable(const Car* cars, int size) {
    
    cout << "Brand       Model       Year   Price      Negotiable  Engine     Color     Owners\n";
    cout << "--------------------------------------------------------------------------\n";

 
    for (int i = 0; i < size; ++i) {
        cout << cars[i].brand << "       "
             << cars[i].model << "       "
             << cars[i].year << "    "
             << cars[i].price << "      "
             << (cars[i].negotiable ? "Yes" : "No") << "         "
             << cars[i].engine << "      "
             << cars[i].color << "       "
             << cars[i].ownerCount << endl;
    }
}
