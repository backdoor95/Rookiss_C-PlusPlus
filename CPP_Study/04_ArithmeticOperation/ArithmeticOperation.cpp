#include<iostream>
using namespace std;
// ������ ���� : ������ ����
// �����͸� �����ϴ� ����� ���ؼ� �˾ƺ���

// a[1]
// a��� �̸��� �ٱ��ϸ� �Ҵ��ϰ� �ȿ� 1�� �ִ´�.
int a = 1;

// b[2]
// b��� �̸��� �ٱ��ϸ� �Ҵ��ϰ� �ȿ� 2�� �ִ´�.
int b = 2;

/***********************************************/

//������ ���� break point�� �صΰ�, 
// ctrl + alt + d => ������� �ڵ带 � �� �ִ�.

/***********************************************/
int main() {

#pragma region �������

	// ��� ������

	// a�� b�� �����ϰ� b�� ��ȯ�϶�
	// -> b��� �ٱ��� �ȿ� �ִ� ����, a��� �ٱ��� �ȿ��� �����Ѵ�.

	// ���Կ���
	a = b;

	// ��Ģ����
	// �����ʿ��Ѱ�?
	// ex) ������ ���, ü�� ���, ���������� ī���� 1�� ����.. ���..

	a = b + 3;
	a = b - 3;
	a = b * 3;
	a = b / 3;
	a = b % 3;

	a += 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;

	//����������
	a = a + 1;//add eax, 1 => inc eax
	a++;
	++a;
	a--;
	--a;

	b = a++;
	// 1. b=a
	// 2. a�� 1����
	
	b = ++a;
	// 1. a�� 1����
	// 2. b=a

	b = a + 1 * 3;


#pragma endregion
}