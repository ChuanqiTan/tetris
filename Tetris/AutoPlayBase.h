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
	方块游戏的按键类型
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
	自动玩游戏算法的抽象基类
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
	随机自动玩的算法
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
			初始化种子
			*/
			srand((unsigned)time(0));

			/*
			最多一次返回4个操作
			*/
			int ran_num;		
			ran_num=rand() % 4;

			for (int i = 0; i < ran_num; ++i)
			{
				/*
				随机出5种按键类型
				*/
				int ran_op;
				ran_op = rand() % 5;

				to_do_list.push_back((KeyPressType)ran_op);

			}

			return to_do_list;
		}


	};


}