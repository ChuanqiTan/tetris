#pragma once

#include <vector>
#include <memory>

#include "PublicCode.h"
#include "shape.h"
#include "GameStateData.h"
//#include "Form1.h"

using std::vector;
using std::auto_ptr;




namespace Tetris 
{

	/*
	tetris 游戏
	*/
	class TetrisGame
	{
		/*
		声明友元
		*/
		friend class AutoPlaySimple;
		friend class AutoPlayCheat;

	private:
		/*
		单件--私有的构造函数
		*/
		TetrisGame() : next_box( 0 ), current_box( 0 )
		{
			clear();
		}

	public:
		/*
		单件--公开的静态方法
		*/
		static TetrisGame * instance();


		/*
		左移按钮按下
		*/
		void try_left();

		/*
		右移按钮按下
		*/
		void try_right();

		/*
		变形按钮按下
		*/
		void try_deform();

		/*
		向下一格的按钮按下
		*/
		void try_down();

		/*
		快速下降按钮按下
		*/
		void try_quick_down();

		/*
		前进到下一个状态
		*/
		void goto_next_state();

		/*
		恢复初始状态
		*/
		void clear();       

		/*
			得到当前游戏状态数据
		*/
		GameStateData get_current_game_states();

		int get_interval();

		bool check_is_game_over();

	private:
		/*
		单件--私有的静态成员
		*/
		static auto_ptr<TetrisGame> _instance;

		vector< vector<int> > table;                                //游戏显示的主面板
		int current_level;                                          //当前游戏等级
		int lines;                                                  //已经消除的行数
		int score;                                                  //得分
		box_base *next_box;                                         //下一个方块
		box_base *current_box;                                      //当前正在下落的方块
		point current_box_point;                                    //当前的方块的坐标
		bool is_game_over;                                          //游戏是否已经结束

		box_base* produce_random_box();                             //产生下一个随机的方块
		void change_to_next_box();                                  //取下一个方块
		bool check_table_effective();                               //根据当前方块与台面table的状态确定是否合法
	};

}