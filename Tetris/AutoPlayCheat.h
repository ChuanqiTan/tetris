#pragma once



#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <ctime>
#include <cstdlib>



#include "TetrisGame.h"
#include "AutoPlayBase.h"

using namespace std;




namespace Tetris 
{


	/*
	���׵��Զ�����㷨
	*/
	class AutoPlayCheat : public AutoPlayBase
	{
	public:
		/*
		���캯��
		*/
		AutoPlayCheat(TetrisGame *game) 
			: AutoPlayBase(game)
		{

		}

		/*
		��ȡ����
		*/
		vector<KeyPressType> get_operation();


	protected:


	private:
		/*
		�õ��߶Ⱥ�
		*/
		int get_height_sum();

	};

}