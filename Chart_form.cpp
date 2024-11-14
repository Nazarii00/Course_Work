#include "Chart_form.h"

void CourseWork::Chart_form::LoadChartData() {
	CHotel chartHotel;
	std::ifstream logFile("logs.txt");
	if (!logFile.is_open()) {
		MessageBox::Show("Не вдалося відкрити файл журналу.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	chartHotel.clearHotel();
	logFile >> chartHotel;

	this->chart1->Series["Series1"]->Points->Clear();
	std::map<int, int> roomClientsCount;

	for (const CGuest& client : chartHotel.getClients())
		roomClientsCount[client.getRoomNumber()]++;

	for (const auto& room : roomClientsCount) {
		int index = this->chart1->Series["Series1"]->Points->AddXY(room.first, room.second);
		DataPoint^ point = this->chart1->Series["Series1"]->Points[index];
		point->Color = System::Drawing::Color::FromArgb(255, room.first * 25 % 256, 100, 149);
	}

	this->chart1->Legends[0]->Enabled = false;

	int roomCount = roomClientsCount.size();
	this->chart1->ChartAreas[0]->AxisX->IsStartedFromZero = false;
	this->chart1->ChartAreas[0]->AxisX->Interval = 1;
	this->chart1->ChartAreas[0]->AxisX->Minimum = 0.5;
	this->chart1->ChartAreas[0]->AxisX->Maximum = roomCount + 0.5;

	this->chart1->ChartAreas[0]->AxisX->CustomLabels->Clear();
	for (int roomNumber = 1; roomNumber <= roomCount; roomNumber++) {
		this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(roomNumber - 0.5, roomNumber + 0.5, roomNumber.ToString());
	}

	this->chart1->ChartAreas[0]->AxisY->Title = "Кількість гостей";
	this->chart1->ChartAreas[0]->AxisY->Interval = 1;
	this->chart1->ChartAreas[0]->AxisX->Title = "Номер кімнати";
}


System::Void  CourseWork::Chart_form::buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}