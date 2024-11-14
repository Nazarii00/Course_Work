#pragma once
#include "CHotel.h"

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Hotel_form
	/// </summary>
	public ref class Hotel_form : public System::Windows::Forms::Form
	{
	public:
		Hotel_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Hotel_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;






	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ зчитатиІнформаціюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститиІнформаціюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ видалитиГостяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ найдовшеЖивутьToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::ToolStripMenuItem^ побудуватиДіаграмуToolStripMenuItem;


	private: System::ComponentModel::IContainer^ components;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Hotel_form::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->зчитатиІнформаціюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститиІнформаціюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видалитиГостяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->найдовшеЖивутьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->побудуватиДіаграмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column6, this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(6, 117);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(650, 233);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Кімната";
			this->Column6->Name = L"Column6";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ім\'я";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Прізвище";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Дата заїзду";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Дата виїзду";
			this->Column5->Name = L"Column5";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->зчитатиІнформаціюToolStripMenuItem,
					this->очиститиІнформаціюToolStripMenuItem, this->видалитиГостяToolStripMenuItem, this->найдовшеЖивутьToolStripMenuItem, this->побудуватиДіаграмуToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(199, 114);
			// 
			// зчитатиІнформаціюToolStripMenuItem
			// 
			this->зчитатиІнформаціюToolStripMenuItem->Name = L"зчитатиІнформаціюToolStripMenuItem";
			this->зчитатиІнформаціюToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->зчитатиІнформаціюToolStripMenuItem->Text = L"Зчитати інформацію";
			this->зчитатиІнформаціюToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hotel_form::зчитатиІнформаціюToolStripMenuItem_Click);
			// 
			// очиститиІнформаціюToolStripMenuItem
			// 
			this->очиститиІнформаціюToolStripMenuItem->Name = L"очиститиІнформаціюToolStripMenuItem";
			this->очиститиІнформаціюToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->очиститиІнформаціюToolStripMenuItem->Text = L"Очистити інформацію";
			this->очиститиІнформаціюToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hotel_form::очиститиІнформаціюToolStripMenuItem_Click);
			// 
			// видалитиГостяToolStripMenuItem
			// 
			this->видалитиГостяToolStripMenuItem->Name = L"видалитиГостяToolStripMenuItem";
			this->видалитиГостяToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->видалитиГостяToolStripMenuItem->Text = L"Видалити гостя";
			this->видалитиГостяToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hotel_form::видалитиГостяToolStripMenuItem_Click);
			// 
			// найдовшеЖивутьToolStripMenuItem
			// 
			this->найдовшеЖивутьToolStripMenuItem->Name = L"найдовшеЖивутьToolStripMenuItem";
			this->найдовшеЖивутьToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->найдовшеЖивутьToolStripMenuItem->Text = L"Найдовше живуть";
			this->найдовшеЖивутьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hotel_form::найдовшеЖивутьToolStripMenuItem_Click);
			// 
			// побудуватиДіаграмуToolStripMenuItem
			// 
			this->побудуватиДіаграмуToolStripMenuItem->Name = L"побудуватиДіаграмуToolStripMenuItem";
			this->побудуватиДіаграмуToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->побудуватиДіаграмуToolStripMenuItem->Text = L"Побудувати діаграму";
			this->побудуватиДіаграмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hotel_form::побудуватиДіаграмуToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1304, 61);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати гостя";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Hotel_form::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(1304, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 40);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Видалити гостя";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Hotel_form::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(662, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(171, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Tag = L"";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(839, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(182, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1027, 62);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(75, 20);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(1108, 62);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(171, 20);
			this->textBox4->TabIndex = 6;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(1108, 102);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(171, 20);
			this->textBox5->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(659, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Ім\'я";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(836, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Прізвище";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(1024, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"№ Кімнати";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(1105, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Дата в\'їзду";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(1105, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Дата виїзду";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1304, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 40);
			this->button3->TabIndex = 13;
			this->button3->Text = L" Записати в файл";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Hotel_form::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(1304, 245);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(143, 40);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Очистити таблицю";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Hotel_form::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1304, 199);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(143, 40);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Зчитати з файлу";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Hotel_form::button5_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"За часом проживання", L"За датою заїзду", L"За датою виїзду",
					L"За кімнатою"
			});
			this->comboBox1->Location = System::Drawing::Point(9, 59);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(171, 21);
			this->comboBox1->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(6, 43);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Тип сортування";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(269, 59);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120, 40);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Сортувати";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Hotel_form::button6_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"За номером кімнати ", L"За ім\'ям", L"За прізвищем" });
			this->comboBox2->Location = System::Drawing::Point(409, 61);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(143, 21);
			this->comboBox2->TabIndex = 19;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(406, 45);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(40, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Пошук";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(558, 60);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(98, 40);
			this->button7->TabIndex = 21;
			this->button7->Text = L"Шукати";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Hotel_form::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(6, 360);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(143, 38);
			this->button8->TabIndex = 22;
			this->button8->Text = L"Найдовше живуть";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Hotel_form::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(155, 360);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(143, 38);
			this->button9->TabIndex = 23;
			this->button9->Text = L"Побудувати діаграму";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Hotel_form::button9_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"За зростанням", L"За спаданням" });
			this->comboBox3->Location = System::Drawing::Point(186, 59);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(77, 21);
			this->comboBox3->TabIndex = 24;
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1472, 42);
			this->toolStrip1->TabIndex = 25;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->AutoSize = false;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(40, 40);
			this->toolStripButton1->Text = L"Видалити гостя";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Hotel_form::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->AutoSize = false;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(40, 40);
			this->toolStripButton2->Text = L"Зчитати дані з файлу";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Hotel_form::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->AutoSize = false;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(40, 40);
			this->toolStripButton3->Text = L"Очистити дані";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Hotel_form::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->AutoSize = false;
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(40, 40);
			this->toolStripButton4->Text = L"Найдовше живуть";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Hotel_form::toolStripButton4_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->AutoSize = false;
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(40, 40);
			this->toolStripButton5->Text = L"Побудувати діаграму";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Hotel_form::toolStripButton5_Click);
			// 
			// Hotel_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->ClientSize = System::Drawing::Size(1472, 412);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Hotel_form";
			this->Text = L"Система обліку послуг готелю";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool addGuestToTable(const CGuest& client);

		void fillTable(CHotel& hotel);

		void updateDataGridViev();

		void ClearDataGridView();

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void зчитатиІнформаціюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void очиститиІнформаціюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void найдовшеЖивутьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void видалитиГостяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void побудуватиДіаграмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton5_Click(System::Object^ sender, System::EventArgs^ e);
	
};
}
