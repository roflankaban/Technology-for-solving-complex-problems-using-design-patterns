/*https://ru.wikipedia.org/wiki/%D0%A1%D1%82%D1%80%D0%B0%D1%82%D0%B5%D0%B3%D0%B8%D1%8F_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)
Ivanov Igor 10-3-IIT


The class that uses the algorithm (Context) includes the abstract class (Strategy), 
which has an abstract method that determines how the algorithm is invoked.
Each derived class implements one required variant of the algorithm.
*/
#include "stdafx.h"
#include <iostream>

struct Strategy_1
{
	void use() { std::cout << "Strategy_1" << std::endl; };
};

struct Strategy_2
{
	void use() { std::cout << "Strategy_2" << std::endl; };
};

struct Strategy_3
{
	void use() { std::cout << "Strategy_3" << std::endl; };
};

template <class Operation>
struct Client : public Operation
{
	void useStrategy()
	{
		this->use();
	}
};

int main(int /*argc*/, char* /*argv*/[])
{
	Client<Strategy_1> customClient1;
	customClient1.useStrategy();

	Client<Strategy_2> customClient2;
	customClient2.useStrategy();

	Client<Strategy_3> customClient3;
	customClient3.useStrategy();
	system("pause");
	return 0;
}
/*Strategy_1
Strategy_2
Strategy_3
*/