#include <iostream>
using namespace std;
void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main()
{
	int status[4] = { 0, 0, 0, 0 };	//HP, MP, ���ݷ�, ������ ũ�� 4�� int�� �迭�� ���� �� 0���� �ʱ�ȭ.
	int input = 0;
	int hpPotionCount;
	int mpPotionCount;
	bool enhanceHP = false;
	bool enhanceMP = false;

	int& hp = status[0];
	int& mp = status[1];
	int& ad = status[2];
	int& def = status[3];

	//HP + MP �� �ޱ�. �� �� �� �ϳ��� 50 �̸��̸� �ʱ�ȭ
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
			cout << "50�� ���� �ʴ� ���ڰ� �ֽ��ϴ�." << endl;
		}
	}

	//���ݷ� + ���� �ޱ�. �� �� �� �ϳ��� 0 ���ϸ� �ʱ�ȭ
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
			cout << "���ݷ�: " << status[2] << " // ����: " << status[3] << endl << endl;
			break;
		}
		else
		{
			cout << "1���� ���� ���ڰ� �ֽ��ϴ�." << endl;
		}
	}
	

	//call by pointer�� �̿��� HP, MP ������ ���� 5�� ����
	SetPotion(5, &hpPotionCount, &mpPotionCount);

	//���� ���� �ý��� ����
	while (input != 7)
	{
		cout << "1. HP ȸ��" << endl << "2. MP ȸ��" << endl << "3. HP ��ȭ" << endl << "4. MP ��ȭ" << endl << "5. ���� ��ų ���" << endl << "6. �ʻ�� ���" << endl << "7. ������" << endl;
		cin >> input;

		//1, 2�� ���ý� HP/MP�� 20 ����, ���� ���� 1�� ����. 0���� ��� ��� �Ұ�.
		//3, 4�� ���ý� HP/MP�� 2�� ����.
		switch (input)
		{
			case 1:
				if (hpPotionCount > 0)
				{
					hp += 20;
					hpPotionCount--;
					cout << "HP�� ȸ���߽��ϴ�." << endl << "���� ü��: " << hp << endl << endl;
				}
				else
				{
					cout << "HP ������ �����ϴ�." << endl << endl;
				}
				break;
			case 2:
				if (mpPotionCount > 0)
				{
					mp += 20;
					mpPotionCount--;
					cout << "MP�� ȸ���߽��ϴ�." << endl << "���� ����: " << mp << endl << endl;
				}
				else
				{
					cout << "MP ������ �����ϴ�." << endl << endl;
				}
				break;
			case 3:
				hp *= 2;
				cout << "HP�� 2�� �����Ͽ����ϴ�." << endl << "���� ü��: " << hp << endl << endl;
				break;
			case 4:
				mp *= 2;
				cout << "MP�� 2�� �����Ͽ����ϴ�." << endl << "���� ����: " << mp << endl << endl;
				break;
			case 5:
				if (mp >= 50)
				{
					mp -= 50;
					cout << "�����߽��ϴ�. (���� 50 �Ҹ�)" << endl << "���� ����: " << mp << endl << endl;
				}
				else
				{
					cout << "�����ϱ⿡ ������ �����մϴ�" << endl << endl;
				}
				break;
			case 6:
				if (mp > 0)
				{
					mp /= 2;
					cout << "�ʻ�� ���." << endl << "���� ����: " << mp << endl << endl;
				}
				break;
			case 7:
				cout << "������";
				break;
		}
		cout << "===========================" << endl << endl;
	}
}

void SetPotion(int count, int* p_HPPotion, int* p_MPPotion){
	*p_HPPotion = count;
	*p_MPPotion = count;
}