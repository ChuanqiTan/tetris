#include "stdafx.h"


#include "AutoPlaySimple.h"



namespace Tetris 
{




	vector<KeyPressType> AutoPlaySimple::get_operation()
	{
		to_do_list.clear();

		/*
		�����ʼ��λ��,�Թ��ָ�ʱʹ��
		*/
		reset_point = _game->current_box_point;

		/*
		��ʼ��
		*/
		int optimal_y = 9999;
		int optimal_height = 9999;
		int optimal_rotate_time = 0;

		/*
		������ת���õ���ѵ���ת
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
				����λ��
				*/
				if (_game->check_table_effective())
				{
					_game->try_quick_down();

					/*
					�õ�����
					*/
					int current_height_sum = get_height_sum();

					/*
					������ָ��ã��ͱ���
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
			��ת
			*/
			_game->try_deform();
		}



		/*
		��ʼ���ɲ���
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
		��current_box�ָ���ԭ����λ��
		*/
		reset();

		return to_do_list;
	}




	/*
	�õ��߶Ⱥ�
	*/
	int AutoPlaySimple::get_height_sum()
	{
		/*
		����ǰ�����ֵ���뵽����table��
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
		�õ���߸߶�
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
		�������
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
	����ǰ����ָ�ԭ״
	*/
	void AutoPlaySimple::reset()
	{
		/*
		��Ϊ��friend
		*/
		_game->current_box_point = reset_point;
	}


}