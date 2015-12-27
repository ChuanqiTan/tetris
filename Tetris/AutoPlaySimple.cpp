#include "stdafx.h"


#include "AutoPlaySimple.h"



namespace Tetris 
{




	vector<KeyPressType> AutoPlaySimple::get_operation()
	{
		to_do_list.clear();

		/*
		保存最开始的位置,以供恢复时使用
		*/
		reset_point = _game->current_box_point;

		/*
		初始化
		*/
		int optimal_y = 9999;
		int optimal_height = 9999;
		int optimal_rotate_time = 0;

		/*
		进行旋转，得到最佳的旋转
		*/
		for (int rotate_times = 0; rotate_times < _game->current_box->get_total_shape_nums(); ++rotate_times)
		{

			for (int i = -3; i < 10; ++i)
			{
				point new_begin_point;
				new_begin_point.x = reset_point.x;
				new_begin_point.y = i;

				_game->current_box_point = new_begin_point;
				/*
				设置位置
				*/
				if (_game->check_table_effective())
				{
					_game->try_quick_down();

					/*
					得到评分
					*/
					int current_height_sum = get_height_sum();

					/*
					如果评分更好，就保存
					*/
					if (current_height_sum < optimal_height)
					{
						optimal_height = current_height_sum;
						optimal_y = i;
						optimal_rotate_time = rotate_times;
					}
				}
			}

			/*
			旋转
			*/
			_game->try_deform();
		}



		/*
		开始生成操作
		*/
		for (int i = 0; i < optimal_rotate_time; ++i)
		{
			to_do_list.push_back(up);
		}

		if (optimal_y < reset_point.y)
		{
			for (int i = 0; i < abs(optimal_y - reset_point.y); ++i)
			{
				to_do_list.push_back(left);
			}
		}
		else if (optimal_y > reset_point.y)
		{
			for (int i = 0; i < abs(optimal_y - reset_point.y); ++i)
			{
				to_do_list.push_back(right);
			}
		}

		to_do_list.push_back(quick_down);

		/*
		把current_box恢复到原来的位置
		*/
		reset();

		return to_do_list;
	}




	/*
	得到高度和
	*/
	int AutoPlaySimple::get_height_sum()
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

		//for (int i = 0; i < 10; ++i)
		//{
		//	for (int j = 0; j < 20; ++j)
		//	{
		//		if (_game->table[j][i] != 0)
		//		{
		//			sum += (20 - j);
		//			break;
		//		}
		//	}

		//}

		/*
		得到最高高度
		*/
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (_game->table[i][j] != 0)
				{
					sum = 20 - i;
					break;
				}
			}

			if (sum != 0)
			{
				break;
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

	/*
	将当前方块恢复原状
	*/
	void AutoPlaySimple::reset()
	{
		/*
		因为是friend
		*/
		_game->current_box_point = reset_point;
	}


}