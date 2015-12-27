#pragma once

/***********************************************************************

shape.h
author: Tan Chuanqi 2010-6-10

7����״�Լ����ǵĻ���

***********************************************************************/

#include <algorithm>
#include <vector>

using std::vector;




namespace Tetris 
{


	/*
	base of box1 - box7     ��״�ĳ������
	*/
	class box_base
	{
	public:
		/*
		Ĭ�Ϲ��캯��	
		*/
		box_base() 
			: color( 0 ), 
			current_shape_num( 0 ),
			total_shape_nums(0)
		{
			init_box_data(data);
		}

		/*
		���캯��
		_color �� ����ǰ��ɫ���
		_total_box_nums �� �����ܹ��м��ֱ���
		*/
		box_base( int _color, int _total_box_nums ) 
			: color( _color ), 
			current_shape_num( 0 ), 
			total_shape_nums( _total_box_nums )
		{
			init_box_data(data);
		}

		/*
		�õ�����
		*/
		const vector< vector<int> >& get_box_data() const
		{
			return data;
		}

		/*
		�õ��ܹ��м��ֱ���
		*/
		int get_total_shape_nums() const
		{
			return total_shape_nums;

		}

		/*
		������ת
		*/
		void rotate();

		/*
		������ת
		*/
		void reverse_rotate();

		/*
		����������
		*/
		virtual ~box_base()
		{}

	private:
		/*
		���麯��:�������������״��ŷ�����״
		*/
		virtual vector< vector<int> > get_box_data_by_num( int _num ) const = 0;

	protected:
		vector< vector<int> > data;                                   //��״����
		int color;                                                    //��״����ɫ���
		int current_shape_num;                                          //��ǰ��״���
		int total_shape_nums;                                           //�ܹ����õ���״��Ŀ
		void init_box_data( vector< vector<int> > &_data ) const;     //��data�����е����ʼ��Ϊ0

	};


	/*
	box: ��������
	*/
	class box1 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ1,�ܹ���2�ֱ���
		*/
		box1() : box_base( 1, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: ����
	����
	*/
	class box2 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ2,�ܹ���1�ֱ���
		*/
		box2() : box_base( 2, 1 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box:   ��
	������
	*/
	class box3 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ3,�ܹ���4�ֱ���
		*/
		box3() : box_base( 3, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box:   ����
	����
	*/
	class box4 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ4,�ܹ���2�ֱ���
		*/
		box4() : box_base( 4, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: ����
	����
	*/
	class box5 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ5,�ܹ���2�ֱ���
		*/
		box5() : box_base( 5, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: ������
	��
	*/
	class box6 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ6,�ܹ���4�ֱ���
		*/
		box6() : box_base( 6, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: ������
	��
	*/
	class box7 : public box_base
	{
	public:
		/*
		��ɫ���Ϊ7,�ܹ���4�ֱ���
		*/
		box7() : box_base( 7, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};

}