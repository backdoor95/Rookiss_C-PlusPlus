#include<iostream>
using namespace std;

// 오늘의 주제 : 디버깅

void Test2()
{
	int b = 0;
}

void Test1()
{
	int a = 0;
	Test2();
}

int main()
{
	int number = 10;

	Test1();
	// 디버깅
	// F5 -> break Point
	// 조사식에서 "값"도 변경이 가능하다.!!
	// F10 : 함수를 내부고 들어가는 작업은 건너뛰고 결과만
	// F11 : 함수 내부로 들어감.


	// 호출 스택을 보면서 어떻게 타고 들어가는지 보여줌.
	// 중단점 : 중단점만 모아서 보여줌. -> f5 누르고 호출스택 옆에 

	// break point 해서 우클릭 -> 조건 : 조건을 걸어줄수 있다.  

	// break point를 하고 싶지는 않지만, 로그를 출력하고 싶을때 -> 브레이크 포인트 우클릭 -> 작업 클릭

	// 화살표를 드레그해서 앞 줄로 올려 보낼수도 있다!!!!

	// 눈으로 보는것 보다. 브레이크 포인트를 걸어서, 디버깅 하는게 훨씬더 능률이 좋다.!

	// 솔루션 (책장) , 프로젝트(책)

	// 여러개의 프로젝트를 실행시키고 싶을때, -> 솔루션 우클릭 -> 속성클릭

	// 솔루션 탐색기에서 삭제를 한다고 해서 내용물이 삭제 되는건 아님.
	// 솔루션 우클릭 -> 파일 탐색기 폴더 열기 -> 해당 폴더 삭제 해야함.

	// 해당 프로젝트 선택후 우클릭 -> 시작 프로젝트로 설정


	return 0;
}