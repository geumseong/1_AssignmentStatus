#include <iostream>
using namespace std;
void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main()
{
	int status[4] = { 0, 0, 0, 0 };	//HP, MP, 공격력, 방어력을 크기 4의 int형 배열로 선언 및 0으로 초기화.
	int input = 0;
	int hpPotionCount;
	int mpPotionCount;
	bool enhanceHP = false;
	bool enhanceMP = false;

	int& hp = status[0];
	int& mp = status[1];
	int& ad = status[2];
	int& def = status[3];

	//HP + MP 값 받기. 두 수 중 하나라도 50 미만이면 초기화
	while (true)
	{
		int input1;
		cin >> input1;
		int input2;
		cin >> input2;

		if (input1 >= 50 && input2 >= 50)
		{
			status[0] = input1;
			status[1] = input2;
			cout << "HP: " << status[0] << " // MP: " << status[1] << endl;
			break;
		}
		else
		{
			cout << "50을 넘지 않는 숫자가 있습니다." << endl;
		}
	}

	//공격력 + 방어력 받기. 두 수 중 하나라도 0 이하면 초기화
	while (true)
	{
		int input1;
		cin >> input1;
		int input2;
		cin >> input2;

		if (input1 > 0 && input2 > 0)
		{
			status[2] = input1;
			status[3] = input2;
			cout << "공격력: " << status[2] << " // 방어력: " << status[3] << endl << endl;
			break;
		}
		else
		{
			cout << "1보다 작은 숫자가 있습니다." << endl;
		}
	}
	

	//call by pointer를 이용해 HP, MP 포션을 각각 5개 지급
	SetPotion(5, &hpPotionCount, &mpPotionCount);

	//스탯 관리 시스템 시작
	while (input != 7)
	{
		cout << "1. HP 회복" << endl << "2. MP 회복" << endl << "3. HP 강화" << endl << "4. MP 강화" << endl << "5. 공격 스킬 사용" << endl << "6. 필살기 사용" << endl << "7. 나가기" << endl;
		cin >> input;

		//1, 2번 선택시 HP/MP가 20 증가, 포션 개수 1개 차감. 0개일 경우 사용 불가.
		//3, 4번 선택시 HP/MP가 2배 증가.
		switch (input)
		{
			case 1:
				if (hpPotionCount > 0)
				{
					hp += 20;
					hpPotionCount--;
					cout << "HP를 회복했습니다." << endl << "현재 체력: " << hp << endl << endl;
				}
				else
				{
					cout << "HP 포션이 없습니다." << endl << endl;
				}
				break;
			case 2:
				if (mpPotionCount > 0)
				{
					mp += 20;
					mpPotionCount--;
					cout << "MP를 회복했습니다." << endl << "현재 마나: " << mp << endl << endl;
				}
				else
				{
					cout << "MP 포션이 없습니다." << endl << endl;
				}
				break;
			case 3:
				hp *= 2;
				cout << "HP가 2배 증가하였습니다." << endl << "현재 체력: " << hp << endl << endl;
				break;
			case 4:
				mp *= 2;
				cout << "MP가 2배 증가하였습니다." << endl << "현재 마나: " << mp << endl << endl;
				break;
			case 5:
				if (mp >= 50)
				{
					mp -= 50;
					cout << "공격했습니다. (마나 50 소모)" << endl << "현재 마나: " << mp << endl << endl;
				}
				else
				{
					cout << "공격하기에 마나가 부족합니다" << endl << endl;
				}
				break;
			case 6:
				if (mp > 0)
				{
					mp /= 2;
					cout << "필살기 사용." << endl << "현재 마나: " << mp << endl << endl;
				}
				break;
			case 7:
				cout << "나가기";
				break;
		}
		cout << "===========================" << endl << endl;
	}
}

void SetPotion(int count, int* p_HPPotion, int* p_MPPotion){
	*p_HPPotion = count;
	*p_MPPotion = count;
}