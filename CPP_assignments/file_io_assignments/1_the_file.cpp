#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream fio;
	int count=0;
	string str;

	fio.open("the_count.txt", ios::in|ios::out);

	cout << "Writing to the file" << endl;
	fio << "In the the_count.txt file, the file is about counting number of the in the given file the the" << endl;

	fio.seekg(0);

	while(fio >> str)
	{
		if(str == "the")
			count++;
		else
			continue;

	}

	cout << "count of the in the file are: " << count << endl;

	return 0;
}
