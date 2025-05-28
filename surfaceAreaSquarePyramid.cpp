// Copyright (c) 2025 Adwok Adiebo All rights reserved.
//.
// Created by: Adwok Adiebo
// Created on: May 25th, 2025
/*This program gets the base and height from the user, and then calculates the surface
are of a square pyramid and displays the calculated area in 2 decimal points*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

float surfaceArea(float base, float height) {
    // Calculate the slant height
    float slantHeight = sqrt(pow(height, 2) + pow(base / 2, 2));

    // Calculate the base Area
    float baseArea = pow(base, 2);

    // Calculate the area of one triangular face
    float areaTriangle = (base * slantHeight) / 2;

    /*Calculate the total lateral area (area of all four triangular faces)*/
    float lateralArea = 4 * areaTriangle;

    float totalSurfaceArea = baseArea + lateralArea;

    return totalSurfaceArea;
}

int main() {
    // This is the initial greeting that will
    // be displayed as we run the program.
    std::cout << "Hello and welcome to Adwok's math equation." << std::endl;

    std::string baseString;
    std::string heightString;

    // Get the base from the user as a string
    std::cout << "What is the base: ";
    std::cin >> baseString;

    // Get the height from the user as a string
    std::cout << "What is the height: ";
    std::cin >> heightString;

    try {
        float base;
        float height;
        float calculatedArea;

        // Convert the base to a float
        base = std::stof(baseString);

        // Convert the height to a float
        height = std::stof(heightString);

        if (base <= 0 || height <= 0) {
            // We have to ensure both base and height are both positive numbers
            if (base <= 0 && height <= 0) {
                std::cout << "The base and height have to be"
                " positive numbers." << std::endl;
            } else if (base <= 0) {
                std::cout << "The base has to be a"
                " positive number." << std::endl;
            } else {
                std::cout << "The height has to be a"
                " positive number." << std::endl;
            }
        } else {
            calculatedArea = surfaceArea(base, height);
            std::cout << "The surface area is: " << std::fixed
            // Set the calculated area to 2 decimal places
            << std::setprecision(2) << calculatedArea << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        // If user enters an invalid input the code below will be executed
        std::cout << "Invalid input: Please enter a valid number." << std::endl;
    }
    // Once all the code is done the code below will be
    // executed because this is our finally
    std::cout << "Thank you for participating." << std::endl;
}

