#include "stdafx.h"

#include "AutoPlayCheat.h"



namespace Tetris 
{

	vector<KeyPressType> AutoPlayCheat::get_operation()
	{
		/*
		初始化
		*/
		point optimal_point;
		int optimal_rotate_times;
		int optimal_score = 99999;

		/*
		进行旋转，得到最佳的旋转
		*/
		for (int rotate_times = 0; rotate_times < _game->current_box->get_total_shape_nums(); ++rotate_times)
		{
			for (int j = -3; j < 10; ++j)
			{
				for (int i = 17; i >= 0; --i)
				{
					point test_point;
					test_point.x = i;
					test_point.y = j;

					/*
					假设这个点
					*/
					_game->current_box_point = test_point;

					/*
					如果能摆放在这个点
					*/
					if (_game->check_table_effective())
					{
						int score = get_height_sum();

						if (score != 0 && score < optimal_score)
						{
							optimal_score = score;
							optimal_rotate_times = rotate_times;
							optimal_point = test_point;
						}

						break;

					}

				}
			}

			_game->try_deform();
		}

		/*
		直接改变状态
		*/
		for (int i = 0; i < optimal_rotate_times; ++i)
		{
			_game->try_deform();
		}
		_game->current_box_point = optimal_point;
		_game->goto_next_state();
		_game->goto_next_state();


		vector<KeyPressType> to_do_list;
		return to_do_list;
	}


	/*
	得到高度和
	*/
	int AutoPlayCheat::get_height_sum()
	{
		/*
		将当前方块的值放入到背景table中
		*/
		for ( int i = 0; i < 4; ++i )
		{
			for ( int j = 0; j < 4; ++j )
			{
				if ( _game->current_box->get_box_data()[i][j] != 0 )
				{

					if ( _game->current_box_point.x + i >= 0 && _game->current_box_point.y + j >= 0 )
					{
						_game->table[_game->current_box_point.x + i][_game->current_box_point.y + j] = -1;
					}                            

				}
			}
		}


		int sum = 0;


		/*
		得到所有列的总高度
		*/
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				if (_game->table[j][i] != 0)
				{
					sum += (20 - j);
					break;
				}
			}

		}

		/*
		加上最高高度
		*/
		int max_height = 0;

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (_game->table[i][j] != 0)
				{
					max_height = 20 - i;
					break;
				}
			}

			if (max_height != 0)
			{
				break;
			}
		}

		sum += max_height;


		/*
		处理消行事件，如果能消行则加分
		*/
		int _boom_lines( 0 );

		for ( int i = _game->current_box_point.x + 3; i >= ( _game->current_box_point.x < 0 ? 0 : _game->current_box_point.x ); --i )
		{
			bool is_full( true );
			for ( int j = 0; j < 10; ++ j)
			{
				if ( _game->table[i][j] == 0 )
				{
					is_full = false;
					break;
				}
			}

			if ( is_full )
			{
				++_boom_lines;
			}                
		}


		/*
		给不同的消行增加不同的权重
		*/
		if ( _boom_lines != 0 )
		{            
			if ( _boom_lines == 4 )
			{
				sum += 10000;
			}
			else if ( _boom_lines == 3 )
			{
				sum += 6000;
			}
			else if ( _boom_lines == 2 )
			{
				sum += 3000;
			}
			else if( _boom_lines == 1 )
			{
				sum +=1000;
			}


		}


		/*
		清除背景
		*/
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (_game->table[i][j] == -1)
				{
					_game->table[i][j] = 0;
				}
			}
		}

		return sum;

	}

}