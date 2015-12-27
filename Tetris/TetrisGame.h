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
	tetris ��Ϸ
	*/
	class TetrisGame
	{
		/*
		������Ԫ
		*/
		friend class AutoPlaySimple;
		friend class AutoPlayCheat;

	private:
		/*
		����--˽�еĹ��캯��
		*/
		TetrisGame() : next_box( 0 ), current_box( 0 )
		{
			clear();
		}

	public:
		/*
		����--�����ľ�̬����
		*/
		static TetrisGame * instance();


		/*
		���ư�ť����
		*/
		void try_left();

		/*
		���ư�ť����
		*/
		void try_right();

		/*
		���ΰ�ť����
		*/
		void try_deform();

		/*
		����һ��İ�ť����
		*/
		void try_down();

		/*
		�����½���ť����
		*/
		void try_quick_down();

		/*
		ǰ������һ��״̬
		*/
		void goto_next_state();

		/*
		�ָ���ʼ״̬
		*/
		void clear();       

		/*
			�õ���ǰ��Ϸ״̬����
		*/
		GameStateData get_current_game_states();

		int get_interval();

		bool check_is_game_over();

	private:
		/*
		����--˽�еľ�̬��Ա
		*/
		static auto_ptr<TetrisGame> _instance;

		vector< vector<int> > table;                                //��Ϸ��ʾ�������
		int current_level;                                          //��ǰ��Ϸ�ȼ�
		int lines;                                                  //�Ѿ�����������
		int score;                                                  //�÷�
		box_base *next_box;                                         //��һ������
		box_base *current_box;                                      //��ǰ��������ķ���
		point current_box_point;                                    //��ǰ�ķ��������
		bool is_game_over;                                          //��Ϸ�Ƿ��Ѿ�����

		box_base* produce_random_box();                             //������һ������ķ���
		void change_to_next_box();                                  //ȡ��һ������
		bool check_table_effective();                               //���ݵ�ǰ������̨��table��״̬ȷ���Ƿ�Ϸ�
	};

}