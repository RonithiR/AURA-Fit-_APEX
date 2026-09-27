#pragma once
#include "Product.h"
using namespace System;

namespace ZenBarApp {

    // Derived class demonstrating: Inheritance, Polymorphism, Object
    public ref class CustomElixir : public Product
    {
    private:
        String^ booster;       // e.g. "Ashwagandha", "Collagen"
        int sweetenerLevel;    // 0 = none, 1 = light, 2 = normal, 3 = extra

    public:
        CustomElixir(String^ elixirName, double elixirPrice, String^ boosterName, int sweetLevel)
            : Product(elixirName, elixirPrice)  // calls the base class constructor
        {
            booster = boosterName;
            sweetenerLevel = sweetLevel;
        }

        property String^ Booster
        {
            String^ get() { return booster; }
            void set(String^ value) { booster = value; }
        }

        property int SweetenerLevel
        {
            int get() { return sweetenerLevel; }
            void set(int value) { sweetenerLevel = value; }
        }

        // Abstraction fulfilled: CustomElixir provides its own version of Prepare()
        virtual void Prepare() override
        {
            Console::WriteLine(Name + " is being prepared with " + booster + " booster.");
        }

        // Polymorphism: overrides the base class's tax calculation with a custom formula
        virtual double CalculateTax() override
        {
            return Price * 0.08; // custom elixirs are taxed at 8% instead of the default 5%
        }
    };
}