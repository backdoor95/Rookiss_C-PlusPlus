#include<iostream>
using namespace std;

// 오늘의 주제 : 포인터 연산

// 1. 주소 연산자(&)
// 2. 산술 연산자(+ -)
// 3. 간접 연산자(*)
// 4. 간접 멤버 연산자(->)

struct Player
{
	int hp;// 0 offset
	int damage;// 4
};

int main()
{

	int number = 1;
	// 1) 주소 연산자(&)
	// - 해당 변수의 주소를 알려주세요~
	// - 더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 TYPE* 변환
	int* pointer = &number;

	// 2) 산술 연산자 (+ -)[곱하기, 나누기는 제외]
	// 이렇게도 포인터도 가능하다.
	//pointer++;
	number += 1;// 1 증가.

	// int*
	// - * : 포인터 타입이네! (8바이트) 주소를 담는 바구니!
	// - int : 주소를 따라가면 int(4바이트 정수형 바구니)가 있다고 가정해라!

	// [!] 포인터에서 + , - 등 산술 연산으로 1을 더하거나 빼면,
	// 정말 ' 그 숫자'를 더하고 빼라는 의미가 아니다.
	// 한번에 TYPE의 크기만큼을 이동하라!
	// 다음/이전 바구니로 이동하고 싶다. << [바구니 단위]의 이동으로
	// 즉, 1을 더하면 = 바구니 1개 이동시켜라
	// 3을 더하면 바구니 3개 이동시켜라

	pointer += 1;// 4 증가. why? - 산술적으로 1를 증가하라는 뜻이 아니라. 다음 바구니로 이동해줘 라는 뜻

	// 3) 간접연산자(*)
	// - 포탈을 타고 해당 주소로 슝~ 이동
	*pointer = 3;
	number = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;
	
	/*
	
		Player* playerPtr = &player;
			lea         eax,[player]
			mov         dword ptr [playerPtr],eax

		(*playerPtr).hp = 200;
			mov         eax,dword ptr [playerPtr]
			mov         dword ptr [eax],0C8h
		(*playerPtr).damage = 200;
			mov         eax,dword ptr [playerPtr]
			mov         dword ptr [eax+4],0C8h // 오프셋(OFFSET)을 기준으로 덧셈연산을 함.
	
	*/


	// 4) 간접 멤버 연산자(->)
	//  * :  간접 연산자 (포탈 타고 해당 주소로 간다.)
	//  . :  구조체의 특정 멤버를 다룰 때 사용(어셈블리 언어로 까보면 . 사실상 그냥 덧셈)
	// -> :  [(*) + (.)] 한 방에!
	playerPtr->hp = 200;
	playerPtr->damage = 200;



	return 0;
}