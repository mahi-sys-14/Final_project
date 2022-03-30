#include<iostream>
#include<list>
#include<cstring>

using namespace std;
list<int> l;

class myList
{
	public:
//		list<int> l;
		list<int> :: iterator p;

		// constructor to initialize an empty node
		myList() { }
//		{
//			list<int> l;
//			l();
//		}

		// add the new node at the beginning
		void InsertBeg(int x)
		{
			p = l.begin();

			l.insert(p, 1, x);
		}

		// delete the last node
		void DeleteLast()
		{
		//	p = l.begin();
		//	cout << "In dellast begin: " << *p << endl;

			p = l.end();
		//	cout << "In dellast: " << *p << endl;
			p--;

//			cout << "In del last: " << *p << endl;
			l.erase(p);
		}

		// swap the first node with the last node
		void SwaapTwo()
		{
			int temp=0;
			list<int> :: iterator p2;

			p = l.begin();
//			cout << "In swapTwo begin: " << *p << endl;

			p2 = l.end();
			p2--;
//			cout << "In swapTwo last: " << *p2 << endl;

			temp = *p;
			*p = *p2;
			*p2 = temp;
		}

		void Display()
		{
			p = l.begin();

			while(p != l.end())
			{
				cout << *p << " ";
				p++;
			}

			cout << endl;
		}

		// friend : reverse the list
		friend void ReverseList();
};

void ReverseList()
{
	list<int> :: iterator p;// = l1.begin();

//	cout << "In reverse" << endl;
	l.reverse();
/*
	p = l.begin();

	while(p != l.end())
	{
		cout << *p << " ";
		p++;
	}

	cout << endl;
*/
}

class InsertList : public myList
{
	public:
		list<int> :: iterator p3;

		// add the new node at the end of the list
		void InsertEnd(int x)
		{
			p3 = l.end();
			
			l.insert(p3, 1, x);
		}

		// insert the node at the given index
		void InsertAt(int index, int value)
		{
			p3 = l.begin();
//			cout << "InsertAt begin: " << *p3 << endl;

			advance(p3, index);
//			cout << "InsertAt index: " << *p3 << endl;

			l.insert(p3, 1, value);
		}

		// insert the node two nodes after the given index
		void Insert2post(int after_indx, int value)
		{
			int inc=0;

			p3 = l.begin();
//			cout << "Insert2post begin: " << *p3 << endl;

			inc = after_indx + 2;
			advance(p3, inc);
//			cout << "Insert2post index: " << *p3 << endl;

			l.insert(p3, 1, value);
		}
};

class DeleteList : public myList
{
	public:
		list<int> :: iterator p4;
	
		// delete the first node
		void DeleteFirst()
		{
			p4 = l.begin();

//			cout << *p4 << endl;

			l.erase(p4);
		}

		// delete the node at given index
		void DeleteAt(int pos)
		{
			p4 = l.begin();
//			cout << *p4 << endl;

			advance(p4, pos);
//			cout << *p4 << endl;

			l.erase(p4);
		}

		// delete the last but one node
		void DeleteLastButOne()
		{
			p4 = l.end();
			p4--;

//			cout << *p4 << endl;

			l.erase(p4);
		}
};

class Manipulate : public myList
{
	public:
		list<int> :: iterator p5, p6;
//		list<int> :: iterator p6;

		// swap the nodes at given indices
		void Swap(int i, int j)
		{
			int temp=0;

			p5 = l.begin();
			advance(p5, i);
//			cout << "swap: " << *p5 << endl;

			temp = *p5;

			p6 = l.begin();
			advance(p6, j);
//			cout << "swap: " << *p5 << endl;

			*p5 = *p6;
			*p6 = temp;
		}

		// bring a given node at the start of list
		void reOrder(int bnf)
		{
			int temp=0;

			p5 = l.begin();
			advance(p5, bnf);
			temp = *p5;
//			cout << "reorder: " << *p5 << endl;
			l.erase(p5);

			p5 = l.begin();
			l.insert(p5, 1, temp);
		}
};

int main()
{
/*	int choice;

	cout << "Enter your choice" << endl; 
	cout << "1. InsertBeg()" << endl << "2. DeleteLast()" << endl << "3. SwaapTwo()" << endl << "4. ReverseList()" << endl << "5. InsertEnd()" << endl; 
	cout << "6. InsertAt()" << endl << "7. Inser2postt()" << endl << "8. Delete()" << endl << "9. Delete()" << endl << "10.DeleteButOne()" << endl; 
	cout << "11. Swap()" << endl << "12. reOrder()" << endl;

	cin >> choice;
*/


//	myList mL;
	InsertList mL;
	DeleteList dL;
	Manipulate mp;

	mL.InsertBeg(1);
	mL.InsertBeg(2);
	mL.InsertBeg(3);
	mL.InsertBeg(5);
	mL.InsertBeg(9);

	cout << "list after adding at begin" << endl;
	mL.Display();

	mL.DeleteLast();
	cout << "list after deleting last node" << endl;
	mL.Display();

	mL.SwaapTwo();
	cout << "List after swapping first and last node" << endl;
	mL.Display();

	ReverseList();
	cout << "Displaying reversed list" << endl;
	mL.Display();

	mL.InsertEnd(10);
	mL.InsertEnd(12);
	mL.InsertEnd(14);
	mL.InsertEnd(18);

	cout << "list after adding at end" << endl;
	mL.Display();

	mL.InsertAt(2, 22);
	cout << "list after adding value at given index" << endl;
	mL.Display();

	mL.Insert2post(3, 11);
	cout << "list after adding value post given index" << endl;
	mL.Display();

	dL.DeleteFirst();
	cout << "Delete the first node" << endl;
	dL.Display();

	dL.DeleteAt(7);
	cout << "Delete the node at position" << endl;
	dL.Display();

	dL.DeleteLastButOne();
	cout << "Delete the last node at" << endl;
	dL.Display();

	mp.Swap(3,5);
	cout << "Swap the 2 nodes at given position" << endl;
	dL.Display();

	mp.reOrder(4);
	cout << "Reordering given node at first" << endl;
	mp.Display();


	return 0;
}
