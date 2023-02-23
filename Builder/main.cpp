#include <iostream>

class ConcrectProduct
{
public:
	ConcrectProduct()
		:val(0.0)
	{
		std::cout << "Create concrect product" << std::endl;
	}

	virtual float& getVariable()
	{
		return val;
	}
private:
	float val;
};

class Builder
{
public:
	Builder()
	{
		this->product = new ConcrectProduct();
	}
	~Builder()
	{
		delete this->product;
	}

	void steap1()
	{
		this->product->getVariable() *= 2;
	}
	void steap2()
	{
		this->product->getVariable() += 2;
	}
	void steap3()
	{
		this->product->getVariable() -= 3.14;
	}

	ConcrectProduct& getResult()
	{
		return *(this->product);
	}

	void reset()
	{
		delete this->product;
		this->product = new ConcrectProduct();
	}
private:
	ConcrectProduct* product;
};

int main()
{
	Builder b;

	b.steap3();
	b.steap1();

	std::cout << "Product: " << b.getResult().getVariable() << std::endl;

	return 0;
}