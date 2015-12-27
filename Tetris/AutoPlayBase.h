#pragma once



#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <ctime>
#include <cstdlib>


#include "TetrisGame.h"

using namespace std;



namespace Tetris 
{


	/*
	������Ϸ�İ�������
	*/
	enum KeyPressType
	{
		up,
		down,
		left,
		right,
		quick_down
	};


	/*
	�Զ�����Ϸ�㷨�ĳ������
	*/
	class AutoPlayBase
	{
	public:
		AutoPlayBase(TetrisGame *game) 
			: _game(game)
		{

		}


		virtual ~AutoPlayBase()
		{

		}

		virtual vector<KeyPressType> get_operation() = 0;

	protected:
		TetrisGame *_game;

	private:


	};


	/*
	����Զ�����㷨
	*/
	class AutoPlayRandom : public AutoPlayBase
	{
	public:
		AutoPlayRandom(TetrisGame *game) 
			: AutoPlayBase(game)
		{

		}

		vector<KeyPressType> get_operation()
		{
			vector<KeyPressType> to_do_list;

			/*
			��ʼ������
			*/
			srand((unsigned)time(0));

			/*
			���һ�η���4������
			*/
			int ran_num;		
			ran_num=rand() % 4;

			for (int i = 0; i < ran_num; ++i)
			{
				/*
				�����5�ְ�������
				*/
				int ran_op;
				ran_op = rand() % 5;

				to_do_list.push_back((KeyPressType)ran_op);

			}

			return to_do_list;
		}


	};


}