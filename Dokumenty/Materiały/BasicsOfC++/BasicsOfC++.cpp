// BasicsOfC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Inheritance.h"

template <typename T> 
void addressPrinter(const T& object)
{
    std::cout << "adress : " << &object << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";

    Basic b;
    std::cout << "adress : " << &b << std::endl;

    addressPrinter<Basic>(b);

    int p = 6;
    // &p - L-Value
    // &&6 - R-Value

    addressPrinter<int>(p);


    Basic bb;
    // Stack = memory will be free automaticly

    bb = std::move(b); // static_cast<>
    bb = b;
    
    //case 2
    Basic* basic = new Basic();
    // basic allocated on STACK
    // new! - allocation on HEAP
    // new = malloc allocate + constuctor call !!
    // basic will be deleted, but its resources not
    delete basic;

    Basic* basic2 = (Basic*) malloc(sizeof(Basic));
    // allocation via malloc, constructor will not be called !!

    //case 3
    int* stackInt = new int();
    std::cout << " --- " << stackInt << std::endl;
    std::cout << " --- " << *stackInt << std::endl;

    Basic* derived = new Derived();
    delete derived;

    Basic* derived1 = new Derived(100);
    // Placement New - for fun :)
    // derived1->myFunc(1, 2);
    // poniewa¿ myFunc jest zdefiniowana w klasie Basic oraz wskaŸnik jest typu Basic!!
    // wybór funkcji w oparciu o static dispatchera
    // polimorfizm nie dzia³a?

    derived1->myFunc(1, 2); // is not virtual

    derived1->myFunc2(3, 4); // is virtual
    // polimorfizm, bo funkcja virtualna
    // tworzy siê v-ptr i v-table
    // wybór funkcji z u¿yciem dynamic dispatchera
    //derived2->myFunc(1, true);
    
    delete derived1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
