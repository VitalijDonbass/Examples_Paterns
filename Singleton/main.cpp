#include <iostream>

class Singleton
{
public:
	static Singleton& get()
	{
		if (Singleton::obj == nullptr)
			Singleton::obj = new Singleton();
		return *Singleton::obj;
	}

	float getPI() { return this->pi; }
	float getSum(float a, float b) { return a + b; }

	~Singleton() { delete Singleton::obj; }
private:
	static Singleton* obj;

	const float pi;

	Singleton() :pi(3.141596){}
	Singleton(const Singleton& obj) = delete;
	Singleton& operator=(const Singleton& obj) = delete;
};

Singleton* Singleton::obj = nullptr;

int main()
{
	std::cout << "2.43 + 5.43 = " << Singleton::get().getSum(2.43, 5.43) << std::endl;
	std::cout << "PI = " << Singleton::get().getPI() << std::endl;

	return 0;
}