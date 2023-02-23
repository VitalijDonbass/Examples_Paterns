#include <iostream>

class IA
{

};

class IB
{

};

class ConcrectA : public IA
{
public:
	ConcrectA()
	{
		std::cout << "Create A" << std::endl;
	}
};

class ConcrectB : public IB
{
public:
	ConcrectB()
	{
		std::cout << "Create B" << std::endl;
	}
};

class IFactory
{
public:
	IA* createA()
	{
		return new IA();
	}

	IB* createB()
	{
		return new IB();
	}
};

class ConcrectFactory : public IFactory
{
public:
	ConcrectA* createA()
	{
		return new ConcrectA();
	}

	ConcrectB* createB()
	{
		return new ConcrectB();
	}
};

int main()
{
	ConcrectFactory fc;

	delete fc.createA();
	delete fc.createB();

	return 0;
}