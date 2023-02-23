#include <iostream>

class IA
{
public:
	virtual float getValue() = 0;
	virtual IA* clone() = 0;
};

class ConcretA : public IA
{
public:
	ConcretA(float val = 0.0)
		:value(val)
	{
	}

	float getValue()
	{
		return this->value;
	}
	ConcretA* clone()
	{
		std::cout << "Cloning object" << std::endl;
		return new ConcretA(this);
	}
private:
	float value;
protected:
	ConcretA(const ConcretA* obj)
		:value(obj->value)
	{
	}
};

int main()
{
	ConcretA* original = new ConcretA(3.14);
	ConcretA* clon = original->clone();
	
	std::cout << "Original: " << original->getValue() << std::endl;
	std::cout << "Clon: " << clon->getValue() << std::endl;

	delete original;
	delete clon;

	return 0;
}