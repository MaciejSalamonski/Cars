#include <iostream>

#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    try {
        car->accelerate(-900);
    } catch (const std::logic_error& error) {
        std::cout << error.what() << '\n';
    }
    car->restore();
    opel.changeGear(2);
    opel.changeGear(-1);
    opel.changeGear(0);
    opel.changeGear(-1);
    opel.changeGear(-2);
    car->carInfo();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    try {
        car->changeEngine(new PetrolEngine(150, 700, 4));
    } catch (const std::logic_error& error) {
        std::cout << error.what() << '\n';
    }
    car->turnLeft();
    car->carInfo();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
    car->changeEngine(new ElectricEngine(150, 700));
    car->changeEngine(new PetrolEngine(180, 700, 4));
    car->carInfo();
    car->setSpeed(-100);
    std::cout << car->getSpeed() << '\n';
}
