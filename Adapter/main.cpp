#include <iostream>

class IDistans
{
public:
	virtual float getDistans() = 0;
};

class Kg : public IDistans
{
public:
	Kg(float kg = 0.0) :_kg(kg) {}
	float getDistans() override { return this->_kg; }

protected:
	float _kg;
};

class Libs : public IDistans
{
public:
	Libs(float libs) :_libs(libs) {}
	float getDistans() override { return this->_libs; }

protected:
	float _libs;
};

class AdapterToLibs : private Kg, public IDistans
{
public:
	AdapterToLibs(Kg km) : Kg(km.getDistans()) {}
	float getDistans() override { return this->_kg * 2.2; }
};

class AdapterToKm : private Libs, public IDistans
{
public:
	AdapterToKm(Libs libs) : Libs(libs.getDistans()) {}
	float getDistans() override { return this->_libs / 2.2; }
};

float sum(float a, float b)
{
	return a + b;
}

int main()
{
	Kg kg(32.5);
	Libs libs(54.3);

	std::cout << "Sum in libs: " << sum(libs.getDistans(), AdapterToLibs(kg).getDistans()) << std::endl;
	std::cout << "Sum in kg: " << sum(kg.getDistans(), AdapterToKm(libs).getDistans()) << std::endl;

	return 0;
}