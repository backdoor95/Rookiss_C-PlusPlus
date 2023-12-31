#include<iostream>
using namespace std;

// 오늘의 주제 : 동적 할당

// 이번 주제 매우매우 중요!!

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수 / 매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역
// 

// 지금까지 데이터 영역/ 스택 영역 이용해서 
// 이런 저런 프로그램을 잘 만들어 왔다!
// 굳이 새로운 영역이 필요?

// 실제 상황)
// -MMORPG 동접 1명 ~ 5만명, 몬스터 1~500만
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// -스택영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수 넘긴다거나, 하는 용도로는 ok
// 
// -메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는

// 희망사항)
// - 필요한때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 없나? -> HEAP
// 동적할당과 연관된 함수 / 연산자: malloc / free, new / delete, new[] / delete[]

// malloc
// - 할당할 메모리 크기를 건내준다.
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다. (메모리 부족시 NULL 반환)

// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌)을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - c++에 추가됨.
// - malloc/free:함수 || new/delete는 연산자(operator)

// new[] / delete[]
// - new가 malloc에 비해 좋긴 한데~ 배열과 같이 N개 데이터를 같이 할당할때

// malloc/free VS new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!

// 그런데 둘의 가장 가장 근본적인 중요한 차이는 따로 있음!
// new/delete는 (생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다!!!

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

// 전역으로 만들게 되면 안좋은점 
// -> 무조건 최대 갯수인 500만마리를 항상 생성함.
//Monster monster[500 * 10000];

int main()
{	// [컴퓨터 구조]
	// 유저 영역 [메모장][LOL][곰플레이어]
	//-----------------------------------
	// 커널 영역(Window 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리 할당해서 건내줌
	// 유저 영역) ㄳㄳ 잘쓸게요~

	// [													] ==> 엄청 큰 도화지
	// C++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)-> 메모리를 최대한 재활용


	/*
	// Definitions of common types
#ifdef _WIN64
    typedef unsigned __int64 size_t; // unsigned__int64(64비트)를 size_t로 사용하겠다!! 라는 의미
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;
#else
    typedef unsigned int     size_t;// [unsigned int(32비트)를 size_t로 사용하겠다] 라는 의미
    typedef int              ptrdiff_t;
    typedef int              intptr_t;
#endif
	
	*/

	//unsigned - 양수
	
	// 그런데 잠깐! void* ?? 무엇일까?
	// *가 있으니까 포인터는 포인터(주소를 담는 바구니) => ok
	// 타고 가면 void 아무것도 없다? => no
	// 타고 가면 void 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라 => ok
	//void* pointer = malloc(1000);// 1000 바이트 할당!
	
	void* pointer = malloc(sizeof(Monster));// 1000 바이트 할당! ->> c, c++ 둘다 사용

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - 유효한 힙 범위를 초과해서 사용하는 문제

	free(pointer); // size를 안넣어 줬는데 어떻게 메모리를 해제가 가능?

	// 날린 포인터는 처리를 해줘야함.
	pointer = nullptr;
	m1 = nullptr;

	// 
	/*
	
0x01541324  0000000c  ....// 이렇게 할당된 메모리의 크기가 저장되어있다.
0x01541328  00000053  S...
0x0154132C  fdfdfdfd  ????
0x01541330  00000064  d...
0x01541334  00000001  ....
0x01541338  00000002  ....

// [ [12][ ]													] ==> 엄청 큰 도화지

CRT(C 런타임 라이브러리)의 힙 관리자가 정확히 12 바이트(Monster size)를 할당하지 않고, 헤더에 몇바이트를 사용하는지 정보를 담아두는 공간이 있다.

	*/

	// 만약에 free하지 않으면 메모리 누수

	// Double free
	// - 이건 대부분 그냥 크래시만 나고 끝난다. -> 찾기 쉬움
	//free(pointer);

	// Use-After-Free
	 //	m1->_hp = 100;
		//m1->_x = 1;
	 //   m1->_y = 2;
	// 날라간 메모리를 건드릴수 있다.!!! 
	// 바로 크래시가 나지않고, 어떤 중요한 정보를 담고있는 메모리를 건드릴경우
	// 엄청난 문제!!!!
	// - 프로그래머 입장 : OMG 망했다!

	Monster* m2 = new Monster; // -> 기본
	m2->_hp = 100;
	m2->_x = 2;
	m2->_y = 3;

	delete m2;// new -> delete| new[] -> delete[] | malloc -> free  : 짝궁을 맞춰야함.

	Monster*m3 = new Monster[5]; // 많이 쓰이지는 않음, 생성자가 5번 호출
	m3->_hp = 100;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3 + 1);
	m4->_hp = 300;
	m4->_x = 4;
	m4->_y = 5;

	delete[] m3;// 소멸자를 5번 호출

	// c++에서 문제가 발생하는 자주 발생하는 문제 -> delete를 안하거나, 2번 이상할때

	return 0;
}