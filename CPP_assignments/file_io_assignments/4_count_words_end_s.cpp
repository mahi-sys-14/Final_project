#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream input;
	string str;
	int count=0;

	input.open("word_end_s.txt", ios::in|ios::out);

	input << "count words end with s, elephants has big ears, learning is always easy" << endl;
	input << "learning satisfies us, continuous studies always helps us" << endl;

	input.seekg(0);

	while(input >> str)
	{
//		cout << str << " ";
		int l = str.length() - 1;
//		cout << "end position: " << l << endl << endl;

		if(str[l] == 's')
		{
			//cout << str << " " << endl << "str last char: " << str[l] << endl << endl;
			count++;
		}
		else if(str[l] == ',')
		{
			if(str[l-1] == 's')
			{
				//cout << "last char ," << endl;	
				//cout << str << " " << endl << "str last char: " << str[l] << endl << endl;
				count++;
			}
			else
				continue;
		}
		else
			continue;
	}

	cout << "the number of words that ends with 's' are: " << count << endl;

	return 0;
}

