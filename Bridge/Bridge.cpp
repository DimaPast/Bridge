#include <iostream>
#include <Windows.h>


class Implementor {
public:
    virtual void operationImpl() const = 0;
};


class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA: Виконання операції реалізації A." << std::endl;
    }
};


class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB: Виконання операції реалізації B." << std::endl;
    }
};


class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() const = 0;
};


class ConcreteAbstractionA : public Abstraction {
public:
    ConcreteAbstractionA(Implementor* impl) : Abstraction(impl) {}

    void operation() const override {
        std::cout << "ConcreteAbstractionA: Виконання операції A." << std::endl;
        implementor->operationImpl();
    }
};


class ConcreteAbstractionB : public Abstraction {
public:
    ConcreteAbstractionB(Implementor* impl) : Abstraction(impl) {}

    void operation() const override {
        std::cout << "ConcreteAbstractionB: Виконання операції B." << std::endl;
        implementor->operationImpl();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    ConcreteImplementorA* implA = new ConcreteImplementorA();
    ConcreteImplementorB* implB = new ConcreteImplementorB();

   
    Abstraction* abstractionA = new ConcreteAbstractionA(implA);
    Abstraction* abstractionB = new ConcreteAbstractionB(implB);

   
    abstractionA->operation();
    abstractionB->operation();

   
    delete implA;
    delete implB;
    delete abstractionA;
    delete abstractionB;

    return 0;
}
