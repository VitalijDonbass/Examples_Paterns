#include <iostream>
#include <string>

//??'???? ?? ??? ????????? ????????? ????????

class IOutput
{
public:
    virtual ~IOutput() {}

    virtual void output(std::string message) = 0;
};

class ConsoleOutput : public IOutput
{
public:
    void output(std::string message) override
    {
        std::cout << message << std::endl;
    }
};

//////////////////////////////////////////

//??'???? ??? ????????? ????????? ????????

class Abstract
{
public:
    Abstract(IOutput& outp) :output(outp) {}
    virtual ~Abstract() {}

    virtual void genMessage() = 0;

protected:
    IOutput& output;
};

class A : public Abstract
{
public:
    A(IOutput& outp) : Abstract(outp) {}

    void genMessage() override
    {
        this->output.output("Output from A!");
    }
};

class B : public Abstract
{
public:
    B(IOutput& outp) : Abstract(outp) {}

    void genMessage() override
    {
        this->output.output("Output from B!");
    }
};

//////////////////////////////////////////

int main() 
{
    IOutput* oup = new ConsoleOutput();

    A a(*oup);
    B b(*oup);

    a.genMessage();
    b.genMessage();

    delete oup;

    return 0;
}