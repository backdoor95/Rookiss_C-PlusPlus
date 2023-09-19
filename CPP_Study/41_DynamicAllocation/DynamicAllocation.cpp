#include<iostream>
using namespace std;

// ������ ���� : ���� �Ҵ�

// �̹� ���� �ſ�ſ� �߿�!!

// �޸� ���� ����
// - ������ �ڵ尡 ����Ǵ� ���� -> �ڵ� ����
// - ����(global)/����(static) ���� -> ������ ����
// - ���� ���� / �Ű� ���� -> ���� ����
// - ���� �Ҵ� -> �� ����
// 

// ���ݱ��� ������ ����/ ���� ���� �̿��ؼ� 
// �̷� ���� ���α׷��� �� ����� �Դ�!
// ���� ���ο� ������ �ʿ�?

// ���� ��Ȳ)
// -MMORPG ���� 1�� ~ 5����, ���� 1~500��
// - ���� ���� �̺�Ʈ -> 5�е��� ���Ͱ� 10�� ���� ����

// -���ÿ���
// �Լ��� ������ ���� �����Ǵ� �Ҿ����� �޸�
// ��� �Լ��� �Ű����� �ѱ�ٰų�, �ϴ� �뵵�δ� ok
// 
// -�޸� ����
// ���α׷��� ����Ǵ� ���߿��� '������' ���Ǵ�

// �������)
// - �ʿ��Ѷ��� ����ϰ�, �ʿ������ �ݳ��� �� �ִ�!
// - �׷��鼭�� (���ð��� �ٸ���) �츮�� ����/�Ҹ� ������ ������ �� �ִ�!
// - �׷� �Ƹ��ٿ� �޸� ����? -> HEAP
// �����Ҵ�� ������ �Լ� / ������: malloc / free, new / delete, new[] / delete[]

// malloc
// - �Ҵ��� �޸� ũ�⸦ �ǳ��ش�.
// - �޸� �Ҵ� �� ���� �ּҸ� ����Ű�� �����͸� ��ȯ���ش�. (�޸� ������ NULL ��ȯ)

// free
// - malloc (Ȥ�� ��Ÿ calloc, realloc ���� ����)�� ���� �Ҵ�� ������ ����
// - �� �����ڰ� �Ҵ�/���Ҵ� ���θ� �����ؼ� ����

// new / delete
// - c++�� �߰���.
// - malloc/free:�Լ� || new/delete�� ������(operator)

// new[] / delete[]
// - new�� malloc�� ���� ���� �ѵ�~ �迭�� ���� N�� �����͸� ���� �Ҵ��Ҷ�

// malloc/free VS new/delete
// - ��� ���Ǽ� -> new/delete ��!
// - Ÿ�Կ� ������� Ư���� ũ���� �޸� ������ �Ҵ��������? -> malloc/free ��!

// �׷��� ���� ���� ���� �ٺ����� �߿��� ���̴� ���� ����!
// new/delete�� (����Ÿ���� Ŭ������ ���) ������/�Ҹ��ڸ� ȣ�����ش�!!!

class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}

public:
	int _hp;
	int _x;
	int _y;
};

// �������� ����� �Ǹ� �������� 
// -> ������ �ִ� ������ 500�������� �׻� ������.
//Monster monster[500 * 10000];

int main()
{	// [��ǻ�� ����]
	// ���� ���� [�޸���][LOL][���÷��̾�]
	//-----------------------------------
	// Ŀ�� ����(Window ���� �ٽ� �ڵ�)

	// ���� ����) �ü������ �����ϴ� API ȣ��
	// Ŀ�� ����) �޸� �Ҵ��ؼ� �ǳ���
	// ���� ����) ���� �߾��Կ�~

	// [													] ==> ��û ū ��ȭ��
	// C++������ �⺻������ CRT(C��Ÿ�� ���̺귯��)�� [�� ������]�� ���� �� ���� ���
	// ��, ���� ���Ѵٸ� �츮�� ���� API�� ���� ���� �����ϰ� ������ ���� ���� (MMORPG ���� �޸� Ǯ��)-> �޸𸮸� �ִ��� ��Ȱ��


	/*
	// Definitions of common types
#ifdef _WIN64
    typedef unsigned __int64 size_t; // unsigned__int64(64��Ʈ)�� size_t�� ����ϰڴ�!! ��� �ǹ�
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;
#else
    typedef unsigned int     size_t;// [unsigned int(32��Ʈ)�� size_t�� ����ϰڴ�] ��� �ǹ�
    typedef int              ptrdiff_t;
    typedef int              intptr_t;
#endif
	
	*/

	//unsigned - ���
	
	// �׷��� ���! void* ?? �����ϱ�?
	// *�� �����ϱ� �����ʹ� ������(�ּҸ� ��� �ٱ���) => ok
	// Ÿ�� ���� void �ƹ��͵� ����? => no
	// Ÿ�� ���� void ���� �ִ��� �𸣰����ϱ� �ʰ� ������ ��ȯ�ؼ� ����ض� => ok
	//void* pointer = malloc(1000);// 1000 ����Ʈ �Ҵ�!
	
	void* pointer = malloc(sizeof(Monster));// 1000 ����Ʈ �Ҵ�! ->> c, c++ �Ѵ� ���

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - ��ȿ�� �� ������ �ʰ��ؼ� ����ϴ� ����

	free(pointer); // size�� �ȳ־� ��µ� ��� �޸𸮸� ������ ����?

	// ���� �����ʹ� ó���� �������.
	pointer = nullptr;
	m1 = nullptr;

	// 
	/*
	
0x01541324  0000000c  ....// �̷��� �Ҵ�� �޸��� ũ�Ⱑ ����Ǿ��ִ�.
0x01541328  00000053  S...
0x0154132C  fdfdfdfd  ????
0x01541330  00000064  d...
0x01541334  00000001  ....
0x01541338  00000002  ....

// [ [12][ ]													] ==> ��û ū ��ȭ��

CRT(C ��Ÿ�� ���̺귯��)�� �� �����ڰ� ��Ȯ�� 12 ����Ʈ(Monster size)�� �Ҵ����� �ʰ�, ����� �����Ʈ�� ����ϴ��� ������ ��Ƶδ� ������ �ִ�.

	*/

	// ���࿡ free���� ������ �޸� ����

	// Double free
	// - �̰� ��κ� �׳� ũ���ø� ���� ������. -> ã�� ����
	//free(pointer);

	// Use-After-Free
	 //	m1->_hp = 100;
		//m1->_x = 1;
	 //   m1->_y = 2;
	// ���� �޸𸮸� �ǵ帱�� �ִ�.!!! 
	// �ٷ� ũ���ð� �����ʰ�, � �߿��� ������ ����ִ� �޸𸮸� �ǵ帱���
	// ��û�� ����!!!!
	// - ���α׷��� ���� : OMG ���ߴ�!

	Monster* m2 = new Monster; // -> �⺻
	m2->_hp = 100;
	m2->_x = 2;
	m2->_y = 3;

	delete m2;// new -> delete| new[] -> delete[] | malloc -> free  : ¦���� �������.

	Monster*m3 = new Monster[5]; // ���� �������� ����, �����ڰ� 5�� ȣ��
	m3->_hp = 100;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3 + 1);
	m4->_hp = 300;
	m4->_x = 4;
	m4->_y = 5;

	delete[] m3;// �Ҹ��ڸ� 5�� ȣ��

	// c++���� ������ �߻��ϴ� ���� �߻��ϴ� ���� -> delete�� ���ϰų�, 2�� �̻��Ҷ�

	return 0;
}