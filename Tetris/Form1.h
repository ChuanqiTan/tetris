#pragma once

#include "TetrisGame.h"
#include "AutoPlayBase.h"
#include "AutoPlayCheat.h"
#include "AutoPlaySimple.h"
#include "GameStateData.h"
#include "TetrisViewBase.h"



namespace Tetris 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/*
		游戏本身
	*/
	TetrisGame *game = TetrisGame::instance();

	/*
		自动游戏算法
	*/
	AutoPlayBase *auto_play = NULL;

	enum GameStates
	{
		init,
		play,
		pause,
		gameover
	};



	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//

			//首先显示一个默认的画面
			display_game_table( game ); 

			comboBox1->Items->Add("Intelligent");
			comboBox1->Items->Add("Simple");
			comboBox1->Items->Add("Random");

			comboBox1->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbShow;
	private: System::Windows::Forms::PictureBox^  pbNext;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblLines;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lblLevel;
	private: System::Windows::Forms::Label^  lblScore;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;
	private: System::Windows::Forms::Button^  btnNew;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnAutoPlay;

	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pbShow = (gcnew System::Windows::Forms::PictureBox());
			this->pbNext = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblLines = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblLevel = (gcnew System::Windows::Forms::Label());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->btnAutoPlay = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbShow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbNext))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pbShow
			// 
			this->pbShow->Location = System::Drawing::Point(13, 13);
			this->pbShow->Name = L"pbShow";
			this->pbShow->Size = System::Drawing::Size(200, 400);
			this->pbShow->TabIndex = 0;
			this->pbShow->TabStop = false;
			// 
			// pbNext
			// 
			this->pbNext->Location = System::Drawing::Point(231, 13);
			this->pbNext->Name = L"pbNext";
			this->pbNext->Size = System::Drawing::Size(160, 160);
			this->pbNext->TabIndex = 1;
			this->pbNext->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Level";
			// 
			// lblLines
			// 
			this->lblLines->Location = System::Drawing::Point(84, 72);
			this->lblLines->Name = L"lblLines";
			this->lblLines->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lblLines->Size = System::Drawing::Size(60, 12);
			this->lblLines->TabIndex = 3;
			this->lblLines->Text = L"0";
			this->lblLines->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Lines";
			// 
			// lblLevel
			// 
			this->lblLevel->Location = System::Drawing::Point(84, 30);
			this->lblLevel->Name = L"lblLevel";
			this->lblLevel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lblLevel->Size = System::Drawing::Size(60, 12);
			this->lblLevel->TabIndex = 5;
			this->lblLevel->Text = L"0";
			this->lblLevel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblScore
			// 
			this->lblScore->Location = System::Drawing::Point(84, 117);
			this->lblScore->Name = L"lblScore";
			this->lblScore->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lblScore->Size = System::Drawing::Size(60, 12);
			this->lblScore->TabIndex = 6;
			this->lblScore->Text = L"0";
			this->lblScore->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 117);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 12);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Score";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblLines);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->lblScore);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->lblLevel);
			this->groupBox1->Location = System::Drawing::Point(236, 179);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(150, 150);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Statistics";
			// 
			// btnPause
			// 
			this->btnPause->Enabled = false;
			this->btnPause->Location = System::Drawing::Point(320, 335);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(66, 29);
			this->btnPause->TabIndex = 0;
			this->btnPause->TabStop = false;
			this->btnPause->Text = L"Pause";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &Form1::btnPause_Click);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
			this->linkLabel2->LinkColor = System::Drawing::Color::DimGray;
			this->linkLabel2->Location = System::Drawing::Point(318, 405);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(29, 12);
			this->linkLabel2->TabIndex = 11;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Home";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel2_LinkClicked);
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(236, 335);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(66, 29);
			this->btnNew->TabIndex = 0;
			this->btnNew->TabStop = false;
			this->btnNew->Text = L"New";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &Form1::btnNew_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
			this->linkLabel1->LinkColor = System::Drawing::Color::DimGray;
			this->linkLabel1->Location = System::Drawing::Point(273, 405);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(29, 12);
			this->linkLabel1->TabIndex = 12;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Help";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel1_LinkClicked);
			// 
			// btnAutoPlay
			// 
			this->btnAutoPlay->Location = System::Drawing::Point(320, 370);
			this->btnAutoPlay->Name = L"btnAutoPlay";
			this->btnAutoPlay->Size = System::Drawing::Size(66, 26);
			this->btnAutoPlay->TabIndex = 13;
			this->btnAutoPlay->Text = L"AutoPlay";
			this->btnAutoPlay->UseVisualStyleBackColor = true;
			this->btnAutoPlay->Click += gcnew System::EventHandler(this, &Form1::btnAutoPlay_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(231, 374);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(78, 20);
			this->comboBox1->TabIndex = 15;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 426);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->btnAutoPlay);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->btnNew);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pbNext);
			this->Controls->Add(this->pbShow);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tetris by TanChuanQi";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbShow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbNext))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if ( game->check_is_game_over() )
				 {
					 set_game_state(gameover);

					 return;
				 }

				 /*
					处理自动玩
				 */
				 if (btnAutoPlay->Text == "Stop")
				 {
					 //有自动玩游戏的算法
					 if(auto_play)
					 {
						 /*
						 得到算法返回的一系列操作
						 */
						 vector<KeyPressType> to_do_list = auto_play->get_operation();

						 /*
							执行每一个操作
						 */
						 for (vector<KeyPressType>::const_iterator to_do = to_do_list.begin();
							 to_do != to_do_list.end();
							 ++to_do)
						 {
							 switch (*to_do)
							 {
							 case up:
								 game->try_deform();
								 break;

							 case down:
								 game->try_down();
								 break;

							 case left:
								 game->try_left();
								 break;

							 case right:
								 game->try_right();
								 break;

							 case quick_down:
								 game->try_quick_down();
								 break;
							 }

						 }

					 }
				 }

				 game->goto_next_state();
				 timer1->Interval = game->get_interval();

				 display_game_table( game );

			 }

	private: System::Void btnNew_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 set_game_state(init);
			 }

	private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {
				 if ( timer1->Enabled )
				 {
					 set_game_state(pause);
				 }
				 else
				 {
					 set_game_state(play);
				 }
			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if ( timer1->Enabled )
				 {  
					 /*
					 只有在不是自动玩的时候才接受手动按键
					 */
					 if (btnAutoPlay->Text == "AutoPlay")
					 {

						 switch ( e->KeyCode )
						 {                     
						 case Keys::A:
							 game->try_left();
							 break;

						 case Keys::D:
							 game->try_right();
							 break;

						 case Keys::W:
							 game->try_deform();
							 break;

						 case Keys::S:
							 game->try_down();
							 break;

						 case Keys::K:
							 game->try_quick_down();
							 break;
						 } 

						 display_game_table( game );

					 }
				 }
			 }

	private:
		void set_game_state(GameStates to_set)
		{
			switch(to_set)
			{
			case init:
				game->clear();
				timer1->Interval = game->get_interval();
				btnPause->Enabled = true;
				set_game_state(play);  
				break;

			case play:
				timer1->Enabled = true;
				btnPause->Text = "Pause";
				break;

			case pause:
				timer1->Enabled = false;
				btnPause->Text = "Continue";
				break;

			case gameover:
				timer1->Enabled = false;
				MessageBox::Show( "Game Over!" );
				btnPause->Enabled = false;
				break;
			}
		}

		/*
			根据游戏的当前状态来生成显示的画面
		*/
		void display_game_table( TetrisGame *_game )
		{
			Bitmap^ img = gcnew Bitmap( 200, 400 );
			Graphics^ g = Graphics::FromImage( img );

			//获取状态数据
			GameStateData current_state_data = _game->get_current_game_states();


			//画主显示面板
			for ( int i = 0; i < 20; ++i )
			{
				for ( int j = 0; j < 10; ++j )
				{
					//先画一个空心的边框
					Pen^ gray_pen = gcnew Pen( Color::Gray, 2 );
					g->DrawRectangle( gray_pen, 20 * j, 20 * i, 20, 20 );

					//根据 color 画上实心矩形的表示一个方块
					Brush^ _brush = get_brush_color_by_num( current_state_data.table()[i][j] );
					g->FillRectangle( _brush, 20 * j + 2, 20 * i + 2, 16, 16);
				}
			}
			pbShow->Image = img;


			//画下一个要下落的方块
			display_game_next_window( current_state_data.next_box_table() );

			
			//最后显示得分等级等信息
			lblLevel->Text = current_state_data.current_level().ToString();
			lblLines->Text = current_state_data.lines().ToString();
			lblScore->Text = current_state_data.score().ToString();
		}


		/*
			显示下一个方块的提示框
		*/
		void display_game_next_window(const vector< vector<int> > &next_table)
		{
			Bitmap^ img = gcnew Bitmap( 160, 160 );
			Graphics^ g = Graphics::FromImage( img );

			for ( int i = 0; i < 4; ++i )
			{
				for ( int j = 0; j < 4; ++j )
				{
					//先画一个空心的边框
					if ( next_table[i][j] != 0 )
					{
						Pen^ gray_pen = gcnew Pen( Color::Gray, 2 );
						g->DrawRectangle( gray_pen, 40 * j, 40 * i, 40, 40 );
					}

					//根据 color 画上实心矩形的表示一个方块
					Brush^ _brush = get_brush_color_by_num( next_table[i][j] );
					g->FillRectangle( _brush, 40 * j + 2, 40 * i + 2, 36, 36);
				}
			}

			pbNext->Image = img;
		}


		/*
			根据各个方块的编号得到它们的颜色信息        
		*/
		System::Drawing::Brush^ get_brush_color_by_num( int _n )
		{
			Brush^ b;
			switch ( _n )
			{
			case 0:
				b = Brushes::White;
				break;

			case 1:
				b = Brushes::BlueViolet;
				break;

			case 2:
				b = Brushes::Black;
				break;

			case 3:
				b = Brushes::DarkOrange;
				break;

			case 4:
				b = Brushes::Red;
				break;

			case 5:
				b = Brushes::Green;
				break;

			case 6:
				b = Brushes::YellowGreen;
				break;

			case 7:
				b = Brushes::LightCoral;
				break;
			}
			return b;
		}

	private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
			 {
				 System::Diagnostics::Process::Start( "http://sites.google.com/site/chuanqitan" );
			 }


	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
			 {
				 MessageBox::Show( "keyboard help:\nw,s,a,d for Up, Down, Left, Right controls \nk for quick down" );
			 }


	private: System::Void btnAutoPlay_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /*
				 标识这次点击是否为开始自动玩
				 */
				 bool avtive_auto_play = (btnAutoPlay->Text == "AutoPlay");

				 btnAutoPlay->Text = (avtive_auto_play ? "Stop" : "AutoPlay");
				 comboBox1->Enabled = !avtive_auto_play;

				 if (auto_play)
				 {
					 delete auto_play;
				 }

				 if (comboBox1->SelectedIndex == 0)
				 {
					 auto_play = new AutoPlayCheat(game);
				 }
				 else if (comboBox1->SelectedIndex == 1)
				 {
					 auto_play = new AutoPlaySimple(game);
				 }
				 else
				 {
					 auto_play = new AutoPlayRandom(game);
				 }

			 }

	}; // end of class Form1

}// end of namespace

