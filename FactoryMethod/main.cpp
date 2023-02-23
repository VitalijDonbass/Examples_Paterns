#include <iostream>

class IA
{
public:

};

class ConcrectA : public IA
{
public:
	ConcrectA()
	{
		std::cout << "Create ConcrectA" << std::endl;
	}
};

class IFactory
{
public:
	IA* createA()
	{
		return new IA();
	}
};

class ConcrecFactory : public IFactory
{
public:
	ConcrectA* createA()
	{
		return new ConcrectA();
	}
};

int main()
{
	ConcrecFactory fc;

	delete fc.createA();

	return 0;
}