#pragma once

#include <string>
#include <iostream>

class Basic
{
public:
	Basic();
	Basic(const Basic&) noexcept;
	Basic(Basic&&) noexcept;
	Basic& operator=(const Basic& other) noexcept;
	Basic& operator=(Basic&& other) noexcept;
	virtual ~Basic() noexcept;
	// virtual ~Basic() noexcept; // case 2

	void printer(std::string msg1, std::string msg2, std::string msg3);

	void myFunc(int val1, int val2); // case 2
	virtual void myFunc2(int val1, int val2); // case 2
	// virtual void myFunc(std::string msg1, std::string msg2); // case 3
	// virtual void myFunc(const std::string msg1, std::string msg2); // case 4
	// virtual bool myFunc(const std::string msg1, std::string msg2); // case 5
	// virtual bool myFunc(const std::string msg1, std::string msg2) const ; // case 6
private:
	int statusCode = 0;

	// v-ptr* due to the fact that virtual function is used
};

class Derived : public Basic
{
public:
	Derived();
	Derived(int p) : val(p) {
		std::cout << " This was called with value: " << val << std::endl;
	};
	~Derived() noexcept;
	void myFunc(int val1, int val2);
	void myFunc(int val1, bool val2);
	void myFunc2(int val1, int val2) override; // case 2
	// void myFunc(std::string msg1, std::string msg2); // case 3
	// void myFunc(const std::string msg1, std::string msg2); // case 4
	// bool myFunc(const std::string msg1, std::string msg2); // case 5
	// bool myFunc(const std::string msg1, std::string msg2) const ; // case 6
	int val = 0;
};