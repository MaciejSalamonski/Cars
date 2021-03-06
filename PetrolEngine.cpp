#include "PetrolEngine.hpp"

#include <iostream>

#include "InvalidGear.hpp"

constexpr bool NEUTRAL_GEAR = 0;
constexpr short REAR_GEAR = -1;

PetrolEngine::PetrolEngine(uint16_t power, size_t capacity, uint8_t gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::setCurrentGear(int gear) {
    if (gear == REAR_GEAR && currentGear_ != NEUTRAL_GEAR) {
        throw InvalidGear("You have to change gear to neutral if u want to use rear gear!");
    }

    if (gear < REAR_GEAR || gear > getGears()) {
        throw InvalidGear("Wrong gear!");
    }

    currentGear_ = gear;
    std::cout << "changeGear\n";
}
