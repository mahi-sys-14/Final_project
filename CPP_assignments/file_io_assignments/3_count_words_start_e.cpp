#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream input;
	string str;
	int count=0;

	input.open("word_start_e.txt", ios::in|ios::out);

	input << "count word start with e, elephant has big ears, learning is easy" << endl;
	input << "earn respect with loyalty, be eager to learn" << endl;

	input.seekg(0);

	while(input >> str)
	{
		if(str[0] == 'e')
		{
			count++;
		}
		else
			continue;
	}

	cout << "the number of words that start with 'e' are: " << count << endl;

	return 0;
}

