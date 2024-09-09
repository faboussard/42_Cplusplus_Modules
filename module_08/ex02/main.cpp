#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "\n\t\t MUTANT STACK SUBJECT TEST\n" << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl; //should output 17
		mstack.pop();// 17 goes out
		std::cout << mstack.size() << std::endl; //should output 1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();

		std::cout << "Const iterators: " << std::endl;
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}
		std::stack<int> s(mstack); // copy mstack
	}

	std::cout << "\n\t\tTEST WITH LIST\n" << std::endl;

	{
			std::list<int> lst;

			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);

			std::cout << "std::list contains: ";
			for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << std::endl;
	}
	return 0;
}
