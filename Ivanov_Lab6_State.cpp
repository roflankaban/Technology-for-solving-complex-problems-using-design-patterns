/*Ivanov Igor 10-3-IIT
https://sourcemaking.com/design_patterns/state/cpp/1
State design pattern - an FSM with two states and two events
(distributed transition logic - logic in the derived state classes).
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
class Machine //The class displays the status (on / off)
{
	class State *current;
public:
	Machine();
	void setCurrent(State *s)
	{
		current = s;
	}
	void on();
	void off();
};

class State //The class displays the state(on / off)
{
public:
	virtual void on(Machine *m)
	{
		cout << "   already ON\n";
	}
	virtual void off(Machine *m)
	{
		cout << "   already OFF\n";
	}
};

void Machine::on() //Switching mechanism
{
	current->on(this);
}

void Machine::off() //Shutdown mechanism
{
	current->off(this);
}

class ON : public State //Status when on
{
public:
	ON()
	{
		cout << "   ON-ctor ";
	};
	~ON()
	{
		cout << "   dtor-ON\n";
	};
	void off(Machine *m);
};

class OFF : public State //Status when off
{
public:
	OFF()
	{
		cout << "   OFF-ctor ";
	};
	~OFF()
	{
		cout << "   dtor-OFF\n";
	};
	void on(Machine *m)
	{
		cout << "   going from OFF to ON";
		m->setCurrent(new ON());
		delete this;
	}
};

void ON::off(Machine *m) //Inclusion process
{
	cout << "   going from ON to OFF";
	m->setCurrent(new OFF());
	delete this;
}

Machine::Machine()
{
	current = new OFF();
	cout << '\n';
}

int main()
{
	void(Machine:: *ptrs[])() =
	{
		Machine::off, Machine::on
	};
	Machine fsm;
	int num;
	while (1)
	{
		cout << "Enter 0/1: ";
		cin >> num;
		(fsm. *ptrs[num])();
	}
}
/*OFF-ctor
Enter 0/1: 0
already OFF
Enter 0/1: 1
going from OFF to ON   ON-ctor    dtor-OFF
Enter 0/1: 1
already ON
Enter 0/1: 0
going from ON to OFF   OFF-ctor    dtor-ON
Enter 0/1: 1
going from OFF to ON   ON-ctor    dtor-OFF
Enter 0/1: 0
going from ON to OFF   OFF-ctor    dtor-ON
Enter 0/1: 0
already OFF
Enter 0/1:
*/