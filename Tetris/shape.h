#pragma once

/***********************************************************************

shape.h
author: Tan Chuanqi 2010-6-10

7种形状以及它们的基类

***********************************************************************/

#include <algorithm>
#include <vector>

using std::vector;




namespace Tetris 
{


	/*
	base of box1 - box7     形状的抽象基类
	*/
	class box_base
	{
	public:
		/*
		默认构造函数	
		*/
		box_base() 
			: color( 0 ), 
			current_shape_num( 0 ),
			total_shape_nums(0)
		{
			init_box_data(data);
		}

		/*
		构造函数
		_color ： 代表当前颜色编号
		_total_box_nums ： 代表总共有几种变形
		*/
		box_base( int _color, int _total_box_nums ) 
			: color( _color ), 
			current_shape_num( 0 ), 
			total_shape_nums( _total_box_nums )
		{
			init_box_data(data);
		}

		/*
		得到数据
		*/
		const vector< vector<int> >& get_box_data() const
		{
			return data;
		}

		/*
		得到总共有几种变形
		*/
		int get_total_shape_nums() const
		{
			return total_shape_nums;

		}

		/*
		正向旋转
		*/
		void rotate();

		/*
		逆向旋转
		*/
		void reverse_rotate();

		/*
		虚析构函数
		*/
		virtual ~box_base()
		{}

	private:
		/*
		纯虚函数:各个子类根据形状编号返回形状
		*/
		virtual vector< vector<int> > get_box_data_by_num( int _num ) const = 0;

	protected:
		vector< vector<int> > data;                                   //形状数据
		int color;                                                    //形状的颜色编号
		int current_shape_num;                                          //当前形状编号
		int total_shape_nums;                                           //总共可用的形状数目
		void init_box_data( vector< vector<int> > &_data ) const;     //将data中所有的项初始化为0

	};


	/*
	box: □□□□
	*/
	class box1 : public box_base
	{
	public:
		/*
		颜色编号为1,总共有2种变形
		*/
		box1() : box_base( 1, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: □□
	□□
	*/
	class box2 : public box_base
	{
	public:
		/*
		颜色编号为2,总共有1种变形
		*/
		box2() : box_base( 2, 1 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box:   □
	□□□
	*/
	class box3 : public box_base
	{
	public:
		/*
		颜色编号为3,总共有4种变形
		*/
		box3() : box_base( 3, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box:   □□
	□□
	*/
	class box4 : public box_base
	{
	public:
		/*
		颜色编号为4,总共有2种变形
		*/
		box4() : box_base( 4, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: □□
	□□
	*/
	class box5 : public box_base
	{
	public:
		/*
		颜色编号为5,总共有2种变形
		*/
		box5() : box_base( 5, 2 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: □□□
	□
	*/
	class box6 : public box_base
	{
	public:
		/*
		颜色编号为6,总共有4种变形
		*/
		box6() : box_base( 6, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};


	/*
	box: □□□
	□
	*/
	class box7 : public box_base
	{
	public:
		/*
		颜色编号为7,总共有4种变形
		*/
		box7() : box_base( 7, 4 )
		{
			data = get_box_data_by_num( current_shape_num );
		}

	private:
		vector< vector<int> > get_box_data_by_num( int _num ) const;
	};

}