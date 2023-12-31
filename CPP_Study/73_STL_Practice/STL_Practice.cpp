#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
using namespace std;

// 오늘의 주제 : 연습문제


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		// TODO
		// 내 풀이
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			if (*it == number)
			{
				found = true;
				break;
			}
		}
		cout << "found = " << found << endl;

		// Rookiss 풀이
		vector<int>::iterator it = v.end();
		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == number)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}
		int a = 3;
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		//TODO - 내 풀이

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			if (data % 11 == 0)
			{
				found == true;
				break;
			}

		}

		cout << "found : " << found << endl;



		// Rookiss 풀이
		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if ((data % 11) == 0)
			{
				found = true;
				it = v.begin() + i;// list에서는 못쓴다.
				break;
			}
		}

	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;
		//TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data % 2 != 0)
			{
				count++;
			}
		}
		cout << "Count : " << count << endl;
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{

		for (unsigned int i = 0; i < v.size(); i++)
		{
			// ver 1.0
			int& data = v[i]; // 레퍼런스를 만들어서 3을 곱하거나
			data *= 3;
			//ver 2.0
			v[i] *= 3;// v[i] 자체가 참조를 뱉어준다.
		}

	}

	return 0;
}