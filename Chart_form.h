#pragma once
#include"CHotel.h"
#include <map>
namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for Chart_form
	/// </summary>
	public ref class Chart_form : public System::Windows::Forms::Form
	{
	public:
		Chart_form(void)
		{
			InitializeComponent();
			LoadChartData();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Chart_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ buttonBack;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1080, 526);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// buttonBack
			// 
			this->buttonBack->Location = System::Drawing::Point(1098, 12);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(167, 45);
			this->buttonBack->TabIndex = 1;
			this->buttonBack->Text = L"Назад";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &Chart_form::buttonBack_Click);
			// 
			// Chart_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1277, 550);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->chart1);
			this->Name = L"Chart_form";
			this->Text = L"Chart_form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: void LoadChartData();
	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
