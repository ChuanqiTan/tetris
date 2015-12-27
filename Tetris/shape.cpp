/***********************************************************************

shape.cpp
author: Tan Chuanqi 2010-6-10

7种形状以及它们的基类

***********************************************************************/

#include "stdafx.h"

#include <algorithm>
#include <vector>
#include <memory>

#include "shape.h"

using std::vector;


namespace Tetris 
{


	void box_base::init_box_data( vector< vector<int> > &_data ) const
	{
		for ( int i = 0; i < 4; ++i )
		{
			vector<int> vec( 4, 0 );
			_data.push_back( vec );
		} 
	}

	void box_base::rotate()
	{
		current_shape_num = ( current_shape_num + 1 ) % total_shape_nums;
		data = get_box_data_by_num( current_shape_num );
	}

	void box_base::reverse_rotate()
	{
		current_shape_num = ( current_shape_num - 1 + total_shape_nums ) % total_shape_nums;
		data = get_box_data_by_num( current_shape_num );
	}


	/*
	box: □□□□
	*/
	vector< vector<int> > box1::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			_box_data[ 3 ][ 3 ] = color;
			break;
		case 1:
			_box_data[ 0 ][ 1 ] = color;
			_box_data[ 1 ][ 1 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box: □□
	□□
	*/
	vector< vector<int> > box2::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box:   □
	□□□
	*/
	vector< vector<int> > box3::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			break;
		case 1:
			_box_data[ 1 ][ 0 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			break;
		case 2:
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		case 3:
			_box_data[ 1 ][ 1 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box:   □□
	□□
	*/
	vector< vector<int> > box4::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		case 1:
			_box_data[ 1 ][ 0 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box: □□
	□□
	*/
	vector< vector<int> > box5::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			break;
		case 1:
			_box_data[ 1 ][ 1 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box: □□□
	□
	*/
	vector< vector<int> > box6::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			break;
		case 1:
			_box_data[ 1 ][ 0 ] = color;
			_box_data[ 1 ][ 1 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		case 2:
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			break;
		case 3:
			_box_data[ 1 ][ 0 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		}
		return _box_data;
	}


	/*
	box: □□□
	□
	*/
	vector< vector<int> > box7::get_box_data_by_num( int _num ) const
	{
		vector< vector<int> > _box_data;
		init_box_data(_box_data);

		switch ( _num )
		{
		case 0:
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 2 ][ 2 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			break;
		case 1:
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 1 ][ 1 ] = color;
			_box_data[ 2 ][ 1 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			break;
		case 2:
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 3 ][ 1 ] = color;
			_box_data[ 3 ][ 2 ] = color;
			break;
		case 3:
			_box_data[ 1 ][ 0 ] = color;
			_box_data[ 2 ][ 0 ] = color;
			_box_data[ 3 ][ 0 ] = color;
			_box_data[ 1 ][ 1 ] = color;
			break;
		}
		return _box_data;
	}

}