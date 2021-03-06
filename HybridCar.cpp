#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine)
    : PetrolCar(petrolEngine), ElectricCar(electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    ElectricCar::restore();
    PetrolCar::restore();
}

void HybridCar::carInfo() {
    std::cout << "Car info:\n "
              << "Speed: " << getSpeed() << '\n'
              << "Petrol Engine Power: " << petrolEngine_->getPower() << '\n'
              << "Capacity: " << petrolEngine_->getCapacity() << '\n'
              << "Current Gear: " << petrolEngine_->getCurrentGear() << '\n'
              << "Gears: " << unsigned(petrolEngine_->getGears()) << '\n'
              << "Electircty Engine Power: " << electricEngine_->getPower() << '\n'
              << "Battery Capacity: " << electricEngine_->getBatteryCapacity() << '\n'
              << "Summary power: " << getEnginePower() << '\n';
}

uint16_t HybridCar::getEnginePower() {
    return petrolEngine_->getPower() + electricEngine_->getPower();
}

void HybridCar::changeEngine(Engine* engine) {
    if (getSpeed() != MINIMUM_VELOCITY) {
        std::cout << "You can't change engine while driving!\n";
        return;
    }

    if (typeid(*engine) == typeid(ElectricEngine)) {
        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(engine);
        std::cout << __FUNCTION__ << std::endl;
        return;
    }

    if (typeid(*engine) == typeid(PetrolEngine)) {
        delete petrolEngine_;
        petrolEngine_ = static_cast<PetrolEngine*>(engine);
        std::cout << __FUNCTION__ << std::endl;
        return;
    }

    std::cout << "Wrong engine!\n";
}