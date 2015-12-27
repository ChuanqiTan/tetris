
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
	简易自动玩算法
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
		得到高度和
		*/
		int get_height_sum();
		/*
		将当前方块恢复原状
		*/
		void reset();

		/*
		恢复原状时当前方块的坐标
		*/
		point reset_point;

		/*
		得到的策略列表
		*/
		vector<KeyPressType> to_do_list;



	};

}