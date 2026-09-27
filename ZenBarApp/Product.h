#pragma once
using namespace System;

namespace ZenBarApp {

    // Base class demonstrating: Class, Object, Encapsulation, Abstraction
    public ref class Product abstract
    {
    private:
        String^ name;      // Encapsulation: private fields
        double price;

    public:
        Product(String^ productName, double productPrice)
        {
            name = productName;
            price = productPrice;
        }

        // Encapsulation: public getters/setters
        property String^ Name
        {
            String^ get() { return name; }
            void set(String^ value) { name = value; }
        }

        property double Price
        {
            double get() { return price; }
            void set(double value) { price = value; }
        }

        // Abstraction: subclasses must implement how they prepare themselves
        virtual void Prepare() abstract;

        // A normal virtual method that CAN be overridden (used for polymorphism later)
        virtual double CalculateTax()
        {
            return price * 0.05; // default 5% tax
        }
    };
}