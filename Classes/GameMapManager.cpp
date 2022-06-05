#include "GameMapManager.h"

#define MAKEMAP(x, y, string) maparr[x][y] = new GameMap(string)
#define MAPNUMBER 5

void GameMapManager::makeGameMap(GameMap***& maparr)
{
	engine = std::mt19937_64(rand_device());
	rand = std::uniform_int_distribution<int>(0, MAPNUMBER - 1);

	int x = rand(engine);
	std::cout << "Map number : " << x << std::endl;
	switch (x)
	{
	case 0:
		doMakeGameMap0(maparr);
		break;
	case 1:
		doMakeGameMap1(maparr);
		break;
	case 2:
		doMakeGameMap2(maparr);
		break;
	case 3:
		doMakeGameMap3(maparr);
		break;
	case 4:
		doMakeGameMap4(maparr);
		break;
	default:
		break;
	}
}

void GameMapManager::doMakeGameMap0(GameMap***& maparr)
{
	MAKEMAP(0, 0, "tmx/Basic_type1_Right_c.tmx");	//������
	MAKEMAP(1, 0, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(2, 0, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(3, 0, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(2, 1, "tmx/Basic_type2_TR_c.tmx");		//������ ����
	MAKEMAP(3, 1, "tmx/Basic_type2_LB_c.tmx");		//���� �Ʒ���
	MAKEMAP(4, 1, "tmx/Basic_type1_Top_c.tmx");		//����
	MAKEMAP(1, 2, "tmx/Basic_type2_TR_c.tmx");		//������ ����
	MAKEMAP(2, 2, "tmx/Basic_type4_c.tmx");			//���� ������ ���� �Ʒ���
	MAKEMAP(3, 2, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(4, 2, "tmx/Basic_type2_LB_c.tmx");		//���� �Ʒ���
	MAKEMAP(1, 3, "tmx/Basic_type1_Bottom_c.tmx");	//�Ʒ���
	MAKEMAP(2, 3, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(3, 3, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(3, 4, "tmx/Basic_type1_Bottom_c.tmx");	//�Ʒ���
}

void GameMapManager::doMakeGameMap1(GameMap***& maparr)
{
	MAKEMAP(1, 0, "tmx/Basic_type1_Top_c.tmx");		//����
	MAKEMAP(1, 1, "tmx/Basic_type3_EmptyL_c.tmx");	//������ ���� �Ʒ���
	MAKEMAP(2, 1, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(3, 1, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(4, 1, "tmx/Basic_type1_Left_c.tmx");	//����
	MAKEMAP(1, 2, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(2, 2, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(2, 3, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(3, 3, "tmx/Basic_type3_EmptyB_c.tmx");	//���� ������ ����
	MAKEMAP(4, 3, "tmx/Basic_type1_Left_c.tmx");	//����
	MAKEMAP(0, 4, "tmx/Basic_type1_Right_c.tmx");	//������
	MAKEMAP(1, 4, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(2, 4, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(3, 4, "tmx/Basic_type2_LB_c.tmx");		//���� �Ʒ���
}

void GameMapManager::doMakeGameMap2(GameMap***& maparr)
{
	MAKEMAP(1, 0, "tmx/Basic_type1_Top_c.tmx");		//����
	MAKEMAP(1, 1, "tmx/Basic_type2_TB_c.tmx");		//���� �Ʒ���
	MAKEMAP(3, 1, "tmx/Basic_type1_Right_c.tmx");	//������
	MAKEMAP(4, 1, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(0, 2, "tmx/Basic_type1_Top_c.tmx");		//����
	MAKEMAP(1, 2, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(2, 2, "tmx/Basic_type3_EmptyB_c.tmx");	//���� ������ ����
	MAKEMAP(3, 2, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(4, 2, "tmx/Basic_type2_LB_c.tmx");		//���� �Ʒ���
	MAKEMAP(0, 3, "tmx/Basic_type2_TB_c.tmx");		//���� �Ʒ���
	MAKEMAP(2, 3, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(3, 3, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(0, 4, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(1, 4, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(2, 4, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(3, 4, "tmx/Basic_type3_EmptyT_c.tmx");	//���� ������ �Ʒ���
	MAKEMAP(4, 4, "tmx/Basic_type1_Left_c.tmx");	//����
}

void GameMapManager::doMakeGameMap3(GameMap***& maparr)
{
	MAKEMAP(2, 0, "tmx/Basic_type1_Right_c.tmx");		//������
	MAKEMAP(3, 0, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(4, 0, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(4, 1, "tmx/Basic_type2_TB_c.tmx");		//���� �Ʒ���
	MAKEMAP(0, 2, "tmx/Basic_type1_Right_c.tmx");		//������
	MAKEMAP(1, 2, "tmx/Basic_type3_EmptyB_c.tmx");	//���� ������ ���� 		
	MAKEMAP(2, 2, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(3, 2, "tmx/Basic_type3_EmptyB_c.tmx");	//���� ������ ����
	MAKEMAP(4, 2, "tmx/Basic_type2_LB_c.tmx");		//���� �Ʒ���
	MAKEMAP(1, 3, "tmx/Basic_type2_TB_c.tmx");		//���� �Ʒ���
	MAKEMAP(3, 3, "tmx/Basic_type1_Bottom_c.tmx");	//�Ʒ���
	MAKEMAP(1, 4, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ��� 
	MAKEMAP(2, 4, "tmx/Basic_type1_Left_c.tmx");		//����
}

void GameMapManager::doMakeGameMap4(GameMap***& maparr)
{
	MAKEMAP(0, 0, "tmx/Basic_type1_Right_c.tmx");		//������
	MAKEMAP(1, 0, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(2, 0, "tmx/Basic_type2_LT_c.tmx");		//���� ����
	MAKEMAP(2, 1, "tmx/Basic_type2_TB_c.tmx");		//���� �Ʒ���
	MAKEMAP(2, 2, "tmx/Basic_type3_EmptyL_c.tmx");	//������ ���� �Ʒ���
	MAKEMAP(3, 2, "tmx/Basic_type2_LR_c.tmx");		//���� ������
	MAKEMAP(4, 2, "tmx/Basic_type1_Left_c.tmx");		//����
	MAKEMAP(1, 3, "tmx/Basic_type1_Right_c.tmx");		//������
	MAKEMAP(2, 3, "tmx/Basic_type3_EmptyR_c.tmx");	//���� ���� �Ʒ���
	MAKEMAP(2, 4, "tmx/Basic_type2_RB_c.tmx");		//������ �Ʒ���
	MAKEMAP(3, 4, "tmx/Basic_type1_Left_c.tmx");		//����
}
