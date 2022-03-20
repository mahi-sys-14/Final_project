#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	fstream f;
	int count=0, i=0;
	string str;

	f.open("count_words_with_a.txt", ios::in|ios::out);
	
	f << "Mahima Pranali are working together in the classroom for both the classes" << endl;
	f << "In CPP & linux internals" << endl;

	f.seekg(0);

	while(f >> str)
	{
//		cout << str << endl;

		for(i=0; i<str.length(); i++)
		{
			if(str[i] == 'a')
			{
				count++;
				break;
			}
			else
			{
				continue;
			}
		}


	}

	cout << "Number of words that has 'a' in them are: " << count << endl;

	return 0;
}
