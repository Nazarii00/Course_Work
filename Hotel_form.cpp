#include "Hotel_form.h"
#include "Chart_form.h"
#include <msclr/marshal_cppstd.h>
#include "CHotel.h"

CHotel hotel;

// Додає клієнта до таблиці DataGridView
bool CourseWork::Hotel_form::addGuestToTable(const CGuest& client) {
	try {
		// Додає новий рядок з даними клієнта до таблиці
		dataGridView1->Rows->Add(
			hotel.getTotalRooms().ToString(),          // Загальна кількість кімнат
			client.getRoomNumber().ToString(),        // Номер кімнати
			gcnew String(client.getName().c_str()),   // Ім'я клієнта
			gcnew String(client.getSurname().c_str()),// Прізвище клієнта
			gcnew String(client.getArrivalDate().c_str()),  // Дата приїзду
			gcnew String(client.getDepartureDate().c_str()) // Дата від'їзду
		);
		return true; // Успішне додавання
	}
	catch (System::Exception^ ex) {
		// Помилка при додаванні клієнта
		MessageBox::Show("Помилка додавання гостя: " + ex->Message, "Помилка");
		return false;
	}
}

// Оновлює значення індексів у DataGridView
void CourseWork::Hotel_form::updateDataGridViev() {
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		// Оновлює перший стовпець з індексами
		if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr) {
			int currentNumber = Int32::Parse(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
			if (currentNumber != i + 1) {
				dataGridView1->Rows[i]->Cells[0]->Value = i + 1; // Оновлення індексу
			}
		}
	}
}

// Заповнює таблицю клієнтами з готелю
void CourseWork::Hotel_form::fillTable(CHotel& hotel) {
	for (const auto& client : hotel.getClients()) {
		addGuestToTable(client); // Додає кожного клієнта до таблиці
	}
	updateDataGridViev();
}

// Очищає всі дані в DataGridView
void CourseWork::Hotel_form::ClearDataGridView() {
	dataGridView1->Rows->Clear(); // Очищає всі рядки таблиці
}


// Додає клієнта
System::Void CourseWork::Hotel_form::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Перевірка на порожні поля для ім'я та прізвища
		if (String::IsNullOrWhiteSpace(textBox1->Text)) {
			throw gcnew System::Exception("Ім'я не може бути порожнім.");
		}

		if (String::IsNullOrWhiteSpace(textBox2->Text)) {
			throw gcnew System::Exception("Прізвище не може бути порожнім.");
		}

		// Перевірка правильності номера кімнати
		int roomNumber;
		if (!Int32::TryParse(textBox3->Text, roomNumber) || roomNumber <= 0) {
			throw gcnew System::Exception("Номер кімнати повинен бути натуральним числом.");
		}

		// Перевірка правильності формату та діапазону дат
		DateTime arrivalDateValue;
		if (!DateTime::TryParseExact(textBox4->Text, "dd/MM/yyyy", nullptr, System::Globalization::DateTimeStyles::None, arrivalDateValue)) {
			throw gcnew System::Exception("Дата прибуття повиння відповідати формату дд/ММ/рррр.");
		}

		DateTime departureDateValue;
		if (!DateTime::TryParseExact(textBox5->Text, "dd/MM/yyyy", nullptr, System::Globalization::DateTimeStyles::None, departureDateValue)) {
			throw gcnew System::Exception("Дата від'їзду повиння відповідати формату дд/ММ/рррр.");
		}

		// Перевірка, щоб дата від'їзду була пізніше за дату приїзду
		if (departureDateValue <= arrivalDateValue) {
			throw gcnew System::Exception("Дата від'їзду повинна бути після дати прибуття.");
		}

		std::string Name = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string Surname = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string arrivalDate = msclr::interop::marshal_as<std::string>(textBox4->Text);
		std::string departureDate = msclr::interop::marshal_as<std::string>(textBox5->Text);

		// Створення нового клієнта
		CGuest client;
		client.setFullInfo(roomNumber, Name, Surname, arrivalDate, departureDate);

		// Додавання клієнта, якщо його ще немає в системі
		if (!hotel.clientExists(client)) {
			hotel.addClient(client);
			hotel.saveClientToFile(client);
			addGuestToTable(client);  
			updateDataGridViev();     
		}
		else
		{
			MessageBox::Show("Клієнт вже існує!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка: " + ex->Message, "Помилка вводу", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// Видаляє гостя з таблиці
System::Void CourseWork::Hotel_form::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Перевірка правильності номера кімнати
		int roomNumber;
		if (!Int32::TryParse(textBox3->Text, roomNumber) || roomNumber <= 0) {
			throw gcnew System::Exception("Номер кімнати повинен бути натуральним числом.");
		}

		hotel.removeClient(roomNumber);

		// Видалення відповідного рядка з таблиці
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr && Int32::Parse(dataGridView1->Rows[i]->Cells[1]->Value->ToString()) == roomNumber) {
				dataGridView1->Rows->RemoveAt(i);  
				break;
			}
		}
		updateDataGridViev();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка: " + ex->Message, "Помилка видалення", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


// Записує дані в файл
System::Void CourseWork::Hotel_form::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		std::ofstream outFile("Hotel_data.txt");

		if (!outFile.is_open()) {
			throw gcnew System::Exception("Неможливо відкрити файл для запису.");
		}
		outFile << hotel;
		outFile.close();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка: " + ex->Message, "Файлова помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// Очищення інформації про готель
System::Void CourseWork::Hotel_form::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	hotel.clearHotel();
	ClearDataGridView();  
}

// Зчитує дані з файлу
System::Void CourseWork::Hotel_form::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

	openFileDialog1->InitialDirectory = "C:\\Users\\Назарій\\Desktop\\Проєкти\\Курсова\\Course_Work";
	openFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ filePath = openFileDialog1->FileName;
		try {
			// Очищуємо дані, якщо список не порожній
			if (!hotel.isEmpty()) {
				hotel.clearHotel();
				ClearDataGridView();
			}

			// Відкриваємо файл для читання
			std::ifstream inFile(msclr::interop::marshal_as<std::string>(filePath));
			if (!inFile.is_open()) {
				throw gcnew System::Exception("Не вдалося відкрити файл для читання.");
			}

			// Завантажуємо дані в готель
			inFile >> hotel;
			inFile.close();

			fillTable(hotel);
		}
		catch (System::Exception^ ex) {
			MessageBox::Show("Помилка: " + ex->Message, "Файлова помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

// Сортує за параметром
System::Void CourseWork::Hotel_form::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream logFile("logs.txt");

	if (!logFile.is_open()) {
		MessageBox::Show("Не вдалося відкрити файл журналу.", "Файлова Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Параметр що відповідає за сортування за зростанням/спаданням.
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

	case 1:  // Сортування за датою приїзду
		hotel.sortByArrivalDate(ascending);
		break;

	case 2:  // Сортування за датою від'їзду
		hotel.sortByDepartureDate(ascending);
		break;

	case 3:  // Сортування за номером кімнати
		hotel.sortByRoom(ascending);
		break;

	default:
		break;
	}

	ClearDataGridView();

	// Додавання відсортованих клієнтів у DataGridView
	fillTable(hotel);
}


// Фільтрує за параметром
System::Void CourseWork::Hotel_form::button7_Click(System::Object^ sender, System::EventArgs^ e) {

	int selectedIndex = comboBox2->SelectedIndex;
	int filterValue;
	
	std::string Name = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string Surname = msclr::interop::marshal_as<std::string>(textBox2->Text);

	dataGridView1->Rows->Clear();

	// Перевірка вибраного фільтра і виконання відповідного пошуку
	switch (selectedIndex)
	{
	case 0:
		try {
			filterValue = Convert::ToInt32(textBox3->Text);
		}
		catch (FormatException^ e) {
			MessageBox::Show("Введіть правильне значення для фільтра.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; 
		}
		// Якщо фільтр пройшов успішно, додаються клієнти, що відповідають фільтру
		fillTable(hotel.getClientsByRoomNumber(filterValue));
		break;
		// Фільтрація за іменем клієнта
	case 1:
		fillTable(hotel.getClientsByName(Name));
		break;
		// Фільтрація за прізвищем клієнта
	case 2:
		fillTable(hotel.getClientsBySurname(Surname));
		break;
	default:
		break;
	}
}


// Виводить клієнтів, що найдовше живуть
System::Void CourseWork::Hotel_form::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearDataGridView();

	try {
		// Викликає метод longestLiving, щоб отримати список клієнтів, які прожили найдовше
		CHotel clients = hotel.longestLiving(3);

		// Перевірка, чи є клієнти для відображення
		if (clients.isEmpty()) {
			MessageBox::Show("Немає клієнтів для відображення.", "Увага", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return; 
		}

		// Додає кожного клієнта до таблиці
		fillTable(clients);
	}
	// Блок для обробки стандартних винятків
	catch (const std::exception& ex) {
		MessageBox::Show("Виникла помилка: " + gcnew String(ex.what()), "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// Блок для обробки невідомих винятків
	catch (...) {
		MessageBox::Show("Виникла невідома помилка.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


// Обробник події для кнопки, що відкриває нову форму для побудови графіка
System::Void CourseWork::Hotel_form::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	// Створює нову форму для графіка
	Chart_form^ chartForm = gcnew Chart_form();
	// Відкриває форму як діалогове вікно
	chartForm->ShowDialog();
}

// Обробник події для меню "Зчитати інформацію", що викликає обробник натискання кнопки button5
System::Void CourseWork::Hotel_form::зчитатиІнформаціюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Викликає функцію button5_Click, яка зчитує дані з файлу
	button5_Click(sender, e);
}

// Обробник події для меню "Очистити інформацію", що викликає обробник натискання кнопки button4
System::Void CourseWork::Hotel_form::очиститиІнформаціюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Викликає функцію button4_Click, яка очищує таблицю
	button4_Click(sender, e);
}

// Обробник події для меню "Найдовше живуть", що викликає обробник натискання кнопки button8
System::Void CourseWork::Hotel_form::найдовшеЖивутьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Викликає функцію button8_Click, яка виводить крієнтів що найдовше проживають в готелі
	button8_Click(sender, e);
}

// Обробник події для меню "Побудувати діаграму", що викликає обробник натискання кнопки button9
System::Void CourseWork::Hotel_form::побудуватиДіаграмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Викликає функцію button9_Click, яка виводить діаграму популярності готельних номерів
	button9_Click(sender, e);
}

System::Void CourseWork::Hotel_form::видалитиГостяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int selectedIndex = -1;
		if (dataGridView1->CurrentCell != nullptr)
		{
			selectedIndex = dataGridView1->CurrentCell->RowIndex;
		}

		if (selectedIndex >= 0) {
			// Перевірка значень на nullptr перед використанням
			String^ name = dataGridView1->Rows[selectedIndex]->Cells[2]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[2]->Value->ToString() : "";
			String^ surname = dataGridView1->Rows[selectedIndex]->Cells[3]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[3]->Value->ToString() : "";
			String^ arrivalDate = dataGridView1->Rows[selectedIndex]->Cells[4]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[4]->Value->ToString() : "";
			String^ departureDate = dataGridView1->Rows[selectedIndex]->Cells[5]->Value != nullptr ? dataGridView1->Rows[selectedIndex]->Cells[5]->Value->ToString() : "";
			int roomNumber = dataGridView1->Rows[selectedIndex]->Cells[1]->Value != nullptr ? Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells[1]->Value) : -1;

			// Якщо необхідно, додатково перевірте roomNumber на -1 (або інше значення, що вказує на помилку)
			if (roomNumber == -1) {
				MessageBox::Show("Помилка: Поля не заповнені.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Перетворюємо String^ у std::string
			std::string stdName = msclr::interop::marshal_as<std::string>(name);
			std::string stdSurname = msclr::interop::marshal_as<std::string>(surname);
			std::string stdArrivalDate = msclr::interop::marshal_as<std::string>(arrivalDate);
			std::string stdDepartureDate = msclr::interop::marshal_as<std::string>(departureDate);

			// Створюємо об'єкт CGuest на основі отриманих даних
			CGuest clientToRemove(roomNumber, stdName, stdSurname, stdArrivalDate, stdDepartureDate);

			// Видалення клієнта з готелю
			hotel.removeClient(clientToRemove);

			// Оновлюємо таблицю
			ClearDataGridView(); // Очищаємо таблицю
			fillTable(hotel);
		}
		else {
			MessageBox::Show("Будь ласка, виберіть клієнта для видалення.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Виникла помилка: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

// Обробник події для кнопки ToolStrip, який викликає функцію видалення гостя через панель інструментів
System::Void CourseWork::Hotel_form::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	видалитиГостяToolStripMenuItem_Click(sender, e);
}

// Обробник події для кнопки ToolStrip, яка зчитує інформацію про гостей через панель інструментів
System::Void CourseWork::Hotel_form::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	button5_Click(sender, e);
}

// Обробник події для кнопки ToolStrip, яка очищує таблицю через панель інструментів
System::Void CourseWork::Hotel_form::toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	button4_Click(sender, e);
}

// Обробник події для кнопки ToolStrip, яка виводить гостей, що найдовше проживають через панель інструментів
System::Void CourseWork::Hotel_form::toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	button8_Click(sender, e);
}

// Обробник події для кнопки ToolStrip, яка виводить діаграму популярності готельних номерів
System::Void CourseWork::Hotel_form::toolStripButton5_Click(System::Object^ sender, System::EventArgs^ e) {
	button9_Click(sender, e);
}