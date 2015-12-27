#include "stdafx.h"


#include "TetrisGame.h"


namespace Tetris 
{


	auto_ptr<TetrisGame> TetrisGame::_instance = auto_ptr<TetrisGame>();

	/*
	����--�����ľ�̬����
	*/
	TetrisGame * TetrisGame::instance()
	{
		if (!_instance.get())
		{
			_instance = auto_ptr<TetrisGame>(new TetrisGame());
		}

		return _instance.get();
	}

	int TetrisGame::get_interval()
	{
		return 500 - current_level * 40;
	}

	bool TetrisGame::check_is_game_over()
	{
		return is_game_over; 
	}


	void TetrisGame::try_left()
	{
		--current_box_point.y;

		if ( !check_table_effective() )
		{
			++current_box_point.y;
		}
	}

	void TetrisGame::try_right()
	{
		++current_box_point.y;

		if ( !check_table_effective() )
		{
			--current_box_point.y;
		}
	}

	void TetrisGame::try_deform()
	{
		current_box->rotate();

		if ( !check_table_effective() )
		{
			current_box->reverse_rotate();
		}
	}

	void TetrisGame::try_down()
	{
		goto_next_state();
	}

	void TetrisGame::try_quick_down()
	{
		do 
		{
			++current_box_point.x;
		} while ( check_table_effective() );
		--current_box_point.x;
	}
	void TetrisGame::goto_next_state()
	{
		if ( !is_game_over )
		{

			if ( current_box == 0 )           //��Ϸ�տ�ʼ
			{
				change_to_next_box();
			}
			else
			{
				++current_box_point.x;                   //�����������
				if ( !check_table_effective() )           //�����ǰ�����״̬��Ч,��ʾ�����ټ���������,��ָ�ԭ״̬�����д���
				{
					--current_box_point.x;

					//����ǰ�����ֵ���뵽����table��
					for ( int i = 0; i < 4; ++i )
					{
						for ( int j = 0; j < 4; ++j )
						{
							if ( current_box->get_box_data()[i][j] != 0 )
							{
								if ( current_box_point.x + i < 0 )                    //����,��Ϸ����
								{
									is_game_over = true;
									return;
								}
								else
								{
									if ( current_box_point.x + i >= 0 && current_box_point.y + j >= 0 )
									{
										table[current_box_point.x + i][current_box_point.y + j] = current_box->get_box_data()[i][j];
									}                            
								}
							}
						}
					}

#pragma region ���������������,��Ҫ�����ﴦ��÷ֺ�����

					//���Կ�����Strategy����µĵ÷��㷨

					int _boom_lines( 0 );
					for ( int i = current_box_point.x + 3; i >= ( current_box_point.x < 0 ? 0 : current_box_point.x ); --i )
					{
						bool is_full( true );
						for ( int j = 0; j < 10; ++ j)
						{
							if ( table[i][j] == 0 )
							{
								is_full = false;
								break;
							}
						}

						if ( is_full )
						{
							for ( int ki = i; ki > 0; --ki )
							{
								for ( int kj = 0; kj < 10; ++kj )
								{
									table[ki][kj] = table[ki-1][kj];
								}
							}
							++i;
							++_boom_lines;
						}                
					}

					if ( _boom_lines != 0 )
					{            
						lines += _boom_lines;
						if ( _boom_lines == 4 )
						{
							score += 1000;
						}
						else if ( _boom_lines == 3 )
						{
							score += 600;
						}
						else if ( _boom_lines == 2 )
						{
							score += 300;
						}
						else if( _boom_lines == 1 )
						{
							score +=100;
						}
						current_level = score / 3000;
					}

#pragma endregion

					//����ȡ��һ��������¼�
					change_to_next_box();
					return;

				}
			}
		}
	}

	void TetrisGame::clear()       //�ָ���ʼ״̬
	{
		table.clear();
		for ( int i = 0; i < 20; ++i )
		{
			vector<int> vec( 10, 0 );
			table.push_back( vec );
		}
		current_level = 0;
		lines = 0;
		score = 0;
		delete next_box;
		next_box = 0;
		delete current_box;
		current_box = 0;

		next_box = produce_random_box();
		current_box = produce_random_box();
		is_game_over = false;
	}

	GameStateData TetrisGame::get_current_game_states()
	{
		return GameStateData(table, current_box, current_box_point, next_box, current_level, lines, score);
	}

	box_base* TetrisGame::produce_random_box()
	{
		int ran_num;
		srand((unsigned)time(0));
		ran_num=rand() % 7;

		box_base *p_box;
		switch ( ran_num )
		{
		case 0:
			p_box = new box1();
			break;
		case 1:
			p_box = new box2();
			break;
		case 2:
			p_box = new box3();
			break;
		case 3:
			p_box = new box4();
			break;
		case 4:
			p_box = new box5();
			break;
		case 5:
			p_box = new box6();
			break;
		case 6:
			p_box = new box7();
			break;
		}

		current_box_point.x = -4;    
		current_box_point.y = 3;
		return p_box;
	}

	void TetrisGame::change_to_next_box()
	{
		delete current_box;
		current_box = next_box;
		next_box = produce_random_box();
	}

	/*
	���ݵ�ǰ������̨��table��״̬ȷ���Ƿ�Ϸ�
	*/
	bool TetrisGame::check_table_effective()
	{
		for ( int i = 0; i < 4; ++i )
		{
			for ( int j = 0; j < 4; ++j )
			{
				if ( current_box->get_box_data()[i][j] != 0 )               //ֻ�Է�����������ĵ���д���
				{                
					if ( current_box_point.x + i >= 20                        //���½�
						|| current_box_point.y + j >=10                         //���ҽ�
						|| current_box_point.y + j < 0                          //�����
						||( current_box_point.x + i >= 0 && current_box_point.y + j >= 0 && table[current_box_point.x + i][current_box_point.y + j] != 0 ) )  //�����еķ�������
					{
						return false;                    
					}
				}
			}
		}
		return true;
	}


}