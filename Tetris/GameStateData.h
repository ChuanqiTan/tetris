#pragma once

#include <vector>
using std::vector;

#include "PublicCode.h"

namespace Tetris 
{
	
	/*
		代表当前的游戏状态
	*/
	class GameStateData
	{
	public:
		GameStateData(const vector< vector<int> > &table, box_base *current_box, point current_box_point, box_base *next_box, int current_level, int lines, int score)
			: _current_level(current_level),
			_lines(lines),
			_score(score)
		{
			for (int i = 0; i < 20; ++i)
			{
				vector<int> temp;

				for (int j = 0; j < 10; ++j)
				{
					temp.push_back(table[i][j]);
				}

				_current_table.push_back(temp);
			}

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (current_box->get_box_data()[i][j] != 0)
					{
						if (current_box_point.x + i >= 0 && current_box_point.y + j >= 0)
						{
							_current_table[current_box_point.x + i][current_box_point.y + j] = current_box->get_box_data()[i][j];
						}						
					}
				}
			}


			for (int i = 0; i < 4; ++i)
			{
				vector<int> temp;

				for (int j = 0; j < 4; ++j)
				{
					temp.push_back(next_box->get_box_data()[i][j]);
				}

				_next_box_table.push_back(temp);
			}

		}

		const vector< vector<int> > & table()
		{
			return _current_table;
		}

		const vector< vector<int> > & next_box_table()
		{
			return _next_box_table;
		}

		int current_level()
		{
			return _current_level;
		}

		int lines()
		{
			return _lines;
		}

		int score()
		{
			return _score;
		}

	private:
		vector< vector<int> > 	_current_table;
		vector< vector<int> >	_next_box_table;
		int 					_current_level;              //当前游戏等级
		int 					_lines;                      //已经消除的行数
		int 					_score;                      //得分
	};

}