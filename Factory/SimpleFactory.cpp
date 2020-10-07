#include <iostream>

template<typename T>
class Operation {
protected:
	T getNumberA() {
		return _numberA;
	}

	T getNumberB() {
		return _numberB;
	}
public:
	void setNumberA(T t) {
		_numberA = t;
	}

	void setNumberB(T t) {
		_numberB = t;
	}

	virtual T getResult() = 0;
private:
	T _numberA;
	T _numberB;
};

template<typename T>
class AddOperation : public Operation<T> {
public:
	T getResult() override {
		return getNumberA() + getNumberB();
	}
};

template<typename T>
class SubOperation : public Operation<T> {
public:
	T getResult() override {
		return getNumberA() - getNumberB();
	}
};

template<typename T>
class MulOperation : public Operation<T> {
public:
	T getResult() override {
		return getNumberA() * getNumberB();
	}
};

template<typename T>
class DivOperation : public Operation<T> {
public:
	T getResult() override {
		return getNumberA() / getNumberB(); // 除零问题由重载运算符方解决
	}
};

template<typename T>
Operation<T>* createOperation(char op) {
	if (op == '+') return new AddOperation<T>();
	else if (op == '-') return new SubOperation<T>();
	else if (op == '*') return new MulOperation<T>();
	else if (op == '/') return new DivOperation<T>();
	else return nullptr; // 一般最好返回一个对象，只是表示空计算（或者直接抛出异常）
}

int main() {
	char signs[] = { '+', '-', '*', '/' };
	for (auto sign : signs) {
		auto op = createOperation<double>(sign);
		op->setNumberA(11);
		op->setNumberB(10);
		std::cout << op->getResult() << std::endl;
	}
	return 0;
}