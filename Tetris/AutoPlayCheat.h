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
	作弊的自动玩的算法
	*/
	class AutoPlayCheat : public AutoPlayBase
	{
	public:
		/*
		构造函数
		*/
		AutoPlayCheat(TetrisGame *game) 
			: AutoPlayBase(game)
		{

		}

		/*
		获取操作
		*/
		vector<KeyPressType> get_operation();


	protected:


	private:
		/*
		得到高度和
		*/
		int get_height_sum();

	};

}