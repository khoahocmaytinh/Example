#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class Singleton
{
public:
	static T* getInstance()
	{
		static T* instance = nullptr;
		if (!instance)
			instance = new T();
		return instance;
	}
protected:
	Singleton() {}
	~Singleton() {}
public:
	Singleton(Singleton const &) = delete;
	Singleton& operator=(Singleton const &) = delete;
};

class Logger :public Singleton<Logger>    // derived Singleton<Logger>
{
	friend class Singleton<Logger>;
private:
	Logger() {};
	~Logger() {};
public:
	void print(void) { std::cout << "hello" << std::endl; }
};

int main()
{
	Logger::getInstance()->print();

	return 0;
}