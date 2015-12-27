
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
	�����Զ����㷨
	*/
	class AutoPlaySimple : public AutoPlayBase
	{
	public:
		AutoPlaySimple(TetrisGame *game) 
			: AutoPlayBase(game)
		{

		}

		vector<KeyPressType> get_operation();
	protected:


	private:
		/*
		�õ��߶Ⱥ�
		*/
		int get_height_sum();
		/*
		����ǰ����ָ�ԭ״
		*/
		void reset();

		/*
		�ָ�ԭ״ʱ��ǰ���������
		*/
		point reset_point;

		/*
		�õ��Ĳ����б�
		*/
		vector<KeyPressType> to_do_list;



	};

}