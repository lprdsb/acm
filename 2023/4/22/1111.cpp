#pragma once
#include<iostream>
#include<string>
using std::string;
using std::to_string;

class MyComplex {
private:
	double real;
	double imaginary;
public:
	MyComplex(double real, double imaginary) :real(real), imaginary(imaginary) {}
	string toString()const {
		string str;
		if (real == 0.0) {
			if (imaginary==0.0) {
				str = "0";
			}
			else {
				str = std::to_string(imaginary) + "i";
			}
		}
		else if (imaginary == 0.0) {
			str = to_string(real);
		}
		else if (imaginary < 0.0) {
			str = to_string(real) + to_string(imaginary)+"i";
		}
		else {
			str = to_string(real) + "+" + to_string(imaginary) + "i";
		}
		return str;
	}
	MyComplex operator+(const MyComplex& adds)const {
		return MyComplex(real + adds.real, imaginary + adds.imaginary);
	}
	MyComplex operator+=(const MyComplex& adds) {
		real += adds.real;
		imaginary += adds.imaginary;
		return *this;
	}
	double& operator[](int x) {
		if (x == 0) {
			return real;
		}
		else if (x == 1) {
			return imaginary;
		}
		else{
			std::cout << "the index is out of bound" << std::endl;
			exit(0);
		}
	}
	MyComplex operator++() {//prefix ++
		real += 1;
		imaginary += 1;
		return *this;
	}
	MyComplex operator++(int dummy) {//postfix ++
		MyComplex temp(this->real, this->imaginary);
		real += 1;
		imaginary += 1;
		return temp;
	}
	friend std::ostream &operator<<(std::ostream &os, const MyComplex& c) {
		os << c.toString();
		return os;
	}
	const MyComplex operator=(const MyComplex& c) {
		real = c.real;
		imaginary = c.imaginary;
		return *this;
	}
};