#include<iostream>
using namespace std;

// 오늘의 주제 : 불리언(bool)과 실수

// 불리언(boolean) 참 / 거짓
bool isHighLevel = true;
bool isPlayer = true;// 1
bool isMale = false; // 0

// Note
// 사실 bool은 그냥 1바이트 정수에 불과
// 왜 정수 시간에 안 다뤘을까?
// -> 일리 있음. 어셈블리에서 bool이라는 것은 없음
// bool만 봐도 참/거짓 둘 중 하나라느 힌트를 줍니다.(가독성)

int isFemale = 1;

// bool : 1 바이트 정수
// 레지스터에서 al(최하위 1바이트)에 해당됨.

// 실수( 부동소수점)
// float double
// 3.14
// 쩜. 앞/뒤를 기준으로 16/16씩 끊으면?
// 0~65535 . 0~65535 --> 표현할 수 있는 수의 개수가 적다

// 부동: 움직이지 않는다라는것이 아니라!
// 뜰 부 : 점이 떠다닌다는 뜻이다.
// 부동소수점 : 점을 유동적으로 움직여서 표현하는 방법이라는 뜻
// 3.1415926535
// 1) 정규화 = 3.1415926535 * 10^0
// 2) 31415926535 (유효숫자) 0 (지수)

// float 부호(1비트) 지수(8) 유효숫자(23) = 32비트 = 4바이트
// double 부호(1비트) 지수(11) 유효숫자(52) = 64비트 = 8바이트
float attackSpeed = -3.375f;// float를 사용하고 싶으면 뒤에 f를 붙여야함. // 4 바이트
double attackSpeed2 = 123.4123;//기본으로 double로 잡힘. // 8 바이트

//ex) - 3.375 라는 값을 저장
// 1) 2진수 변환 = (3) + (0.375) = 0b11 + 
// 0.375 = 0.5*0 + 0.25*1 + 0.125*1 = 0b0.011
// 0b11.011
// 2) 정규화 => 0b1.1011 * 2^1 = 0b11.011
// 1(부호, 마이너스일때는 1) 1(지수) 1011(유효숫자)
// 단 지수는 unsigned byte라고 가정하고 숫자+127 만들어줌
// 예산 결과 = 0b 1 10000000 1011000 0000 0000 0000 0000

// 리틀 엔디언 : 00 00 58 c0
// -> c058 0000

// 부동소수점은 '근사값'이다!!1 정확한 값이 아니다.
// 특히 수가 커질 수록 오차 범위도 매우 커진다
// 실수 2개를 == 으로 비교하는 것은 지양하자!!!

int main() {

	cout << isHighLevel << endl;
	

	return 0;
}