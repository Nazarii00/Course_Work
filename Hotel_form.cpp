#include "Hotel_form.h"
#include "Chart_form.h"
#include <msclr/marshal_cppstd.h>
#include "CHotel.h"

CHotel hotel;

// ���� �볺��� �� ������� DataGridView
bool CourseWork::Hotel_form::addGuestToTable(const CGuest& client) {
	try {
		// ���� ����� ����� � ������ �볺��� �� �������
		dataGridView1->Rows->Add(
			hotel.getTotalRooms().ToString(),          // �������� ������� �����
			client.getRoomNumber().ToString(),        // ����� ������
			gcnew String(client.getName().c_str()),   // ��'� �볺���
			gcnew String(client.getSurname().c_str()),// ������� �볺���
			gcnew String(client.getArrivalDate().c_str()),  // ���� ������
			gcnew String(client.getDepartureDate().c_str()) // ���� ��'����
		);
		return true; // ������ ���������
	}
	catch (System::Exception^ ex) {
		// ������� ��� �������� �볺���
		MessageBox::Show("������� ��������� �����: " + ex->Message, "�������");
		return false;
	}
}

// ������� �������� ������� � DataGridView
void CourseWork::Hotel_form::updateDataGridViev() {
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		// ������� ������ �������� � ���������
		if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr) {
			int currentNumber = Int32::Parse(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
			if (currentNumber != i + 1) {
				dataGridView1->Rows[i]->Cells[0]->Value = i + 1; // ��������� �������
			}
		}
	}
}

// �������� ������� �볺����� � ������
void CourseWork::Hotel_form::fillTable(CHotel& hotel) {
	for (const auto& client : hotel.getClients()) {
		addGuestToTable(client); // ���� ������� �볺��� �� �������
	}
	updateDataGridViev();
}

// ����� �� ��� � DataGridView
void CourseWork::Hotel_form::ClearDataGridView() {
	dataGridView1->Rows->Clear(); // ����� �� ����� �������
}


// ���� �볺���
System::Void CourseWork::Hotel_form::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// �������� �� ������ ���� ��� ��'� �� �������
		if (String::IsNullOrWhiteSpace(textBox1->Text)) {
			throw gcnew System::Exception("��'� �� ���� ���� �������.");
		}

		if (String::IsNullOrWhiteSpace(textBox2->Text)) {
			throw gcnew System::Exception("������� �� ���� ���� �������.");
		}

		// �������� ����������� ������ ������
		int roomNumber;
		if (!Int32::TryParse(textBox3->Text, roomNumber) || roomNumber <= 0) {
			throw gcnew System::Exception("����� ������ ������� ���� ����������� ������.");
		}

		// �������� ����������� ������� �� �������� ���
		DateTime arrivalDateValue;
		if (!DateTime::TryParseExact(textBox4->Text, "dd/MM/yyyy", nullptr, System::Globalization::DateTimeStyles::None, arrivalDateValue)) {
			throw gcnew System::Exception("���� �������� ������� ��������� ������� ��/��/����.");
		}

		DateTime departureDateValue;
		if (!DateTime::TryParseExact(textBox5->Text, "dd/MM/yyyy", nullptr, System::Globalization::DateTimeStyles::None, departureDateValue)) {
			throw gcnew System::Exception("���� ��'���� ������� ��������� ������� ��/��/����.");
		}

		// ��������, ��� ���� ��'���� ���� ����� �� ���� ������
		if (departureDateValue <= arrivalDateValue) {
			throw gcnew System::Exception("���� ��'���� ������� ���� ���� ���� ��������.");
		}

		std::string Name = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string Surname = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string arrivalDate = msclr::interop::marshal_as<std::string>(textBox4->Text);
		std::string departureDate = msclr::interop::marshal_as<std::string>(textBox5->Text);

		// ��������� ������ �볺���
		CGuest client;
		client.setFullInfo(roomNumber, Name, Surname, arrivalDate, departureDate);

		// ��������� �볺���, ���� ���� �� ���� � ������
		if (!hotel.clientExists(client)) {
			hotel.addClient(client);
			hotel.saveClientToFile(client);
			addGuestToTable(client);  
			updateDataGridViev();     
		}
		else
		{
			MessageBox::Show("�볺�� ��� ����!", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("�������: " + ex->Message, "������� �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// ������� ����� � �������
System::Void CourseWork::Hotel_form::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// �������� ����������� ������ ������
		int roomNumber;
		if (!Int32::TryParse(textBox3->Text, roomNumber) || roomNumber <= 0) {
			throw gcnew System::Exception("����� ������ ������� ���� ����������� ������.");
		}

		hotel.removeClient(roomNumber);

		// ��������� ���������� ����� � �������
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr && Int32::Parse(dataGridView1->Rows[i]->Cells[1]->Value->ToString()) == roomNumber) {
				dataGridView1->Rows->RemoveAt(i);  
				break;
			}
		}
		updateDataGridViev();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("�������: " + ex->Message, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


// ������ ��� � ����
System::Void CourseWork::Hotel_form::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		std::ofstream outFile("Hotel_data.txt");

		if (!outFile.is_open()) {
			throw gcnew System::Exception("��������� ������� ���� ��� ������.");
		}
		outFile << hotel;
		outFile.close();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("�������: " + ex->Message, "������� �������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// �������� ���������� ��� ������
System::Void CourseWork::Hotel_form::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	hotel.clearHotel();
	ClearDataGridView();  
}

// ����� ��� � �����
System::Void CourseWork::Hotel_form::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

	openFileDialog1->InitialDirectory = "C:\\Users\\������\\Desktop\\������\\�������\\Course_Work";
	openFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ filePath = openFileDialog1->FileName;
		try {
			// ������� ���, ���� ������ �� �������
			if (!hotel.isEmpty()) {
				hotel.clearHotel();
				ClearDataGridView();
			}

			// ³�������� ���� ��� �������
			std::ifstream inFile(msclr::interop::marshal_as<std::string>(filePath));
			if (!inFile.is_open()) {
				throw gcnew System::Exception("�� ������� ������� ���� ��� �������.");
			}

			// ����������� ��� � ������
			inFile >> hotel;
			inFile.close();

			fillTable(hotel);
		}
		catch (System::Exception^ ex) {
			MessageBox::Show("�������: " + ex->Message, "������� �������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

// ����� �� ����������
System::Void CourseWork::Hotel_form::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream logFile("logs.txt");

	if (!logFile.is_open()) {
		MessageBox::Show("�� ������� ������� ���� �������.", "������� �������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// �������� �� ������� �� ���������� �� ����������/���������.
	int ascending = comboBox3->SelectedIndex;

	switch (comboBox1->SelectedIndex)
	{
	case 0:  
		if (!hotel.isEmpty()) {
			hotel.clearHotel();
		}
		logFile >> hotel;
		hotel.sortByResidenceTime(ascending);
		break;

	case 1:  // ���������� �� ����� ������
		hotel.sortByArrivalDate(ascending);
		break;

	case 2:  // ���������� �� ����� ��'����
		hotel.sortByDepartureDate(ascending);
		break;

	case 3:  // ���������� �� ������� ������
		hotel.sortByRoom(ascending);
		break;

	default:
		break;
	}

	ClearDataGridView();

	// ��������� ������������ �볺��� � DataGridView
	fillTable(hotel);
}


// Գ����� �� ����������
System::Void CourseWork::Hotel_form::button7_Click(System::Object^ sender, System::EventArgs^ e) {

	int selectedIndex = comboBox2->SelectedIndex;
	int filterValue;
	
	std::string Name = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string Surname = msclr::interop::marshal_as<std::string>(textBox2->Text);

	dataGridView1->Rows->Clear();

	// �������� ��������� ������� � ��������� ���������� ������
	switch (selectedIndex)
	{
	case 0:
		try {
			filterValue = Convert::ToInt32(textBox3->Text);
		}
		catch (FormatException^ e) {
			MessageBox::Show("������ ��������� �������� ��� �������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; 
		}
		// ���� ������ ������� ������, ��������� �볺���, �� ���������� �������
		fillTable(hotel.getClientsByRoomNumber(filterValue));
		break;
		// Գ�������� �� ������ �볺���
	case 1:
		fillTable(hotel.getClientsByName(Name));
		break;
		// Գ�������� �� �������� �볺���
	case 2:
		fillTable(hotel.getClientsBySurname(Surname));
		break;
	default:
		break;
	}
}


// �������� �볺���, �� �������� ������
System::Void CourseWork::Hotel_form::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearDataGridView();

	try {
		// ������� ����� longestLiving, ��� �������� ������ �볺���, �� ������� ��������
		CHotel clients = hotel.longestLiving(3);

		// ��������, �� � �볺��� ��� �����������
		if (clients.isEmpty()) {
			MessageBox::Show("���� �볺��� ��� �����������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return; 
		}

		// ���� ������� �볺��� �� �������
		fillTable(clients);
	}
	// ���� ��� ������� ����������� �������
	catch (const std::exception& ex) {
		MessageBox::Show("������� �������: " + gcnew String(ex.what()), "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// ���� ��� ������� �������� �������
	catch (...) {
		MessageBox::Show("������� ������� �������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


// �������� ��䳿 ��� ������, �� ������� ���� ����� ��� �������� �������
System::Void CourseWork::Hotel_form::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	// ������� ���� ����� ��� �������
	Chart_form^ chartForm = gcnew Chart_form();
	// ³������ ����� �� �������� ����
	chartForm->ShowDialog();
}

// �������� ��䳿 ��� ���� "������� ����������", �� ������� �������� ���������� ������ button5
System::Void CourseWork::Hotel_form::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// ������� ������� button5_Click, ��� ����� ��� � �����
	button5_Click(sender, e);
}

// �������� ��䳿 ��� ���� "�������� ����������", �� ������� �������� ���������� ������ button4
System::Void CourseWork::Hotel_form::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// ������� ������� button4_Click, ��� ����� �������
	button4_Click(sender, e);
}

// �������� ��䳿 ��� ���� "�������� ������", �� ������� �������� ���������� ������ button8
System::Void CourseWork::Hotel_form::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// ������� ������� button8_Click, ��� �������� ����� �� �������� ���������� � �����
	button8_Click(sender, e);
}

// �������� ��䳿 ��� ���� "���������� �������", �� ������� �������� ���������� ������ button9
System::Void CourseWork::Hotel_form::����������ĳ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// ������� ������� button9_Click, ��� �������� ������� ����������� ��������� ������
	button9_Click(sender, e);
}

System::Void CourseWork::Hotel_form::�������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int selectedIndex = -1;
		if (dataGridView1->CurrentCell != nullptr)
		{
			selectedIndex = dataGridView1->CurrentCell->RowIndex;
		}

		if (selectedIndex >= 0) {
			// �������� ������� �� nullptr ����� �������������
			String^ name = dataGridView1->Rows[selectedIndex]->Cells[2]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[2]->Value->ToString() : "";
			String^ surname = dataGridView1->Rows[selectedIndex]->Cells[3]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[3]->Value->ToString() : "";
			String^ arrivalDate = dataGridView1->Rows[selectedIndex]->Cells[4]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[4]->Value->ToString() : "";
			String^ departureDate = dataGridView1->Rows[selectedIndex]->Cells[5]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[5]->Value->ToString() : "";
			int roomNumber = dataGridView1->Rows[selectedIndex]->Cells[1]->Value != nullptr ? Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells[1]->Value) : -1;

			// ���� ���������, ��������� �������� roomNumber �� -1 (��� ���� ��������, �� ����� �� �������)
			if (roomNumber == -1) {
				MessageBox::Show("�������: ���� �� ��������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// ������������ String^ � std::string
			std::string stdName = msclr::interop::marshal_as<std::string>(name);
			std::string stdSurname = msclr::interop::marshal_as<std::string>(surname);
			std::string stdArrivalDate = msclr::interop::marshal_as<std::string>(arrivalDate);
			std::string stdDepartureDate = msclr::interop::marshal_as<std::string>(departureDate);

			// ��������� ��'��� CGuest �� ����� ��������� �����
			CGuest clientToRemove(roomNumber, stdName, stdSurname, stdArrivalDate, stdDepartureDate);

			// ��������� �볺��� � ������
			hotel.removeClient(clientToRemove);

			// ��������� �������
			ClearDataGridView(); // ������� �������
			fillTable(hotel);
		}
		else {
			MessageBox::Show("���� �����, ������� �볺��� ��� ���������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("������� �������: " + ex->Message, "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// �������� ��䳿 ��� ������ ToolStrip, ���� ������� ������� ��������� ����� ����� ������ �����������
System::Void CourseWork::Hotel_form::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	�������������ToolStripMenuItem_Click(sender, e);
}

// �������� ��䳿 ��� ������ ToolStrip, ��� ����� ���������� ��� ������ ����� ������ �����������
System::Void CourseWork::Hotel_form::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	button5_Click(sender, e);
}

// �������� ��䳿 ��� ������ ToolStrip, ��� ����� ������� ����� ������ �����������
System::Void CourseWork::Hotel_form::toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	button4_Click(sender, e);
}

// �������� ��䳿 ��� ������ ToolStrip, ��� �������� ������, �� �������� ���������� ����� ������ �����������
System::Void CourseWork::Hotel_form::toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	button8_Click(sender, e);
}

// �������� ��䳿 ��� ������ ToolStrip, ��� �������� ������� ����������� ��������� ������
System::Void CourseWork::Hotel_form::toolStripButton5_Click(System::Object^ sender, System::EventArgs^ e) {
	button9_Click(sender, e);
}