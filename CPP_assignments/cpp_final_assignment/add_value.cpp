#include <iostream>
#include <cstring>

using namespace std;

class charInput
{
	public:
	char v;

	void add(char c) 
	{ 
		v = v + c;
		cout << "v: " << v << endl;	
	}

	string getValue() 
	{ 
		return NULL; 
	}
};

class numInput : public charInput 
{ 
	public:

		int v=0;

		void add(int i) 
		{
		        cout << "before: " << i << endl;
			i = i - '0';

			if(i >= 0 && i <= 9)	
				v = v*10 + i;	
//			cout << "drv v: " << v << endl;
		}

		int getValue()
		{
//			cout << "In getValue: " << v << endl;
			return v;
		}
};

int main()
{
	charInput* inputC = new charInput();
	numInput* inputN = new numInput();
	
	inputN->add('1');
	inputN->add('a');
	inputN->add('0');
	inputN->add('b');
	inputN->add('4');

	cout << inputN->getValue() << endl;
	// the output should be 10
	
	return 0;
}
