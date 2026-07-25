#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <list>
#include <msclr\marshal_cppstd.h>

namespace std {

	string table[100] = {};
	list<string> list1[100] = {};
	int freeCount = sizeof(table) / sizeof(table[0]);
	int totalCompareCount = 0;
	int searchCount = 0;

	//Получение хеша
	int get_hash(string A) {
		if (A.length() != 1) {
			return ((int)A[0] + (int)A[A.length() - 2]) % (sizeof(table) / sizeof(table[0])); // вычисляем хеш для строки
		}
		else {
			return ((int)A[0] + (int)A[0]) % (sizeof(table) / sizeof(table[0])); // вычисляем хеш для строки
		}
	}

	//Заполнение таблицы идентификаторов
	void fill_table(string A, int& count, int& free) {
		int h = get_hash(A);

		if (table[h] == "") {
			table[h] = A;	// если в table[h] ничего нет, пихаем туда A
			free--;
		}
		else {
			list1[h].push_back(A);	// в связном списке по индексу h добавляем A
			list1[h].sort();	// сортируем для возможности бинарного поиска
			count++;
		}
	}

	//Очистка таблицы
	void clear_table() {
		list1->clear();
		for (int i = 0; i <= (sizeof(table) / sizeof(table[0])); i++) {
			table[i] = "";
		}
	}

	//Поиск строки в тексте
	bool find_text(string A, int& count) {
		int h = get_hash(A);	// ищем хеш строки
		count++;

		if (table[h] == A) {	// если в таблице в позиции h лежит строка A, то строка найдена
			return true;
		}
		else if (!list1[h].empty()) {	// если лежит другая строка, и к данной позиции присоединен упорядоченный список, смотрим его
			list<string> list2 = list<string>(list1[h].begin(), list1[h].end());	// достаем этот список и присваиваем его переменной list2
			for (auto i = list2.begin(); i != list2.end(); advance(i, 1)) {
				count++;
				if (*i == A) {	// если строка в данной позиции списка совпала с искомой строкой, то строка найдена
					return true;
				}
				else if (*i > A) {	// если строка не совпала, и строка из списка больше искомой, то дальше нет смысла смотреть, т.к. следующие строки в списке будут больше искомой
					return false;
				}
			}
		}

		return false;
	}
}

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ fileLoad_button;
	private: System::Windows::Forms::Button^ fileSelect_button;



	private: System::Windows::Forms::TextBox^ fileName;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ search_button;
	private: System::Windows::Forms::TextBox^ targetText;




	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ searchCount;












	private: System::Windows::Forms::Button^ statsReset_button;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Label^ averageCompareCount;
	private: System::Windows::Forms::Label^ searchStatus;




	private: System::Windows::Forms::Label^ totalCompareCount;


	private: System::Windows::Forms::Label^ compareCount;

	private: System::Windows::Forms::RichTextBox^ fileData;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ averageCollCount;

	private: System::Windows::Forms::Label^ collCount;





	protected:

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->fileData = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->fileLoad_button = (gcnew System::Windows::Forms::Button());
			this->fileSelect_button = (gcnew System::Windows::Forms::Button());
			this->fileName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->averageCollCount = (gcnew System::Windows::Forms::Label());
			this->collCount = (gcnew System::Windows::Forms::Label());
			this->averageCompareCount = (gcnew System::Windows::Forms::Label());
			this->searchStatus = (gcnew System::Windows::Forms::Label());
			this->totalCompareCount = (gcnew System::Windows::Forms::Label());
			this->compareCount = (gcnew System::Windows::Forms::Label());
			this->searchCount = (gcnew System::Windows::Forms::Label());
			this->statsReset_button = (gcnew System::Windows::Forms::Button());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->targetText = (gcnew System::Windows::Forms::TextBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->fileData);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(292, 408);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Исходные данные";
			// 
			// fileData
			// 
			this->fileData->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->fileData->Location = System::Drawing::Point(7, 20);
			this->fileData->Name = L"fileData";
			this->fileData->ReadOnly = true;
			this->fileData->Size = System::Drawing::Size(279, 382);
			this->fileData->TabIndex = 0;
			this->fileData->Text = L"";
			this->fileData->WordWrap = false;
			this->fileData->TextChanged += gcnew System::EventHandler(this, &MyForm::fileData_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->fileLoad_button);
			this->groupBox2->Controls->Add(this->fileSelect_button);
			this->groupBox2->Controls->Add(this->fileName);
			this->groupBox2->Location = System::Drawing::Point(310, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(353, 105);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Исходный файл";
			// 
			// fileLoad_button
			// 
			this->fileLoad_button->Location = System::Drawing::Point(198, 67);
			this->fileLoad_button->Name = L"fileLoad_button";
			this->fileLoad_button->Size = System::Drawing::Size(147, 30);
			this->fileLoad_button->TabIndex = 2;
			this->fileLoad_button->Text = L"Загрузить файл";
			this->fileLoad_button->UseVisualStyleBackColor = true;
			this->fileLoad_button->Click += gcnew System::EventHandler(this, &MyForm::fileLoad_button_Click);
			// 
			// fileSelect_button
			// 
			this->fileSelect_button->Location = System::Drawing::Point(6, 67);
			this->fileSelect_button->Name = L"fileSelect_button";
			this->fileSelect_button->Size = System::Drawing::Size(147, 30);
			this->fileSelect_button->TabIndex = 1;
			this->fileSelect_button->Text = L"Выбрать файл";
			this->fileSelect_button->UseVisualStyleBackColor = true;
			this->fileSelect_button->Click += gcnew System::EventHandler(this, &MyForm::fileSelect_button_Click);
			// 
			// fileName
			// 
			this->fileName->Location = System::Drawing::Point(7, 20);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(338, 20);
			this->fileName->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->searchCount);
			this->groupBox3->Controls->Add(this->statsReset_button);
			this->groupBox3->Controls->Add(this->search_button);
			this->groupBox3->Controls->Add(this->targetText);
			this->groupBox3->Location = System::Drawing::Point(310, 125);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(353, 251);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Поиск идентификатора";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->averageCollCount);
			this->groupBox5->Controls->Add(this->collCount);
			this->groupBox5->Controls->Add(this->averageCompareCount);
			this->groupBox5->Controls->Add(this->searchStatus);
			this->groupBox5->Controls->Add(this->totalCompareCount);
			this->groupBox5->Controls->Add(this->compareCount);
			this->groupBox5->Location = System::Drawing::Point(10, 105);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(334, 140);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Упорядоченный список с логарифмическим поиском";
			// 
			// averageCollCount
			// 
			this->averageCollCount->AutoSize = true;
			this->averageCollCount->Location = System::Drawing::Point(188, 114);
			this->averageCollCount->Name = L"averageCollCount";
			this->averageCollCount->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->averageCollCount->Size = System::Drawing::Size(124, 13);
			this->averageCollCount->TabIndex = 10;
			this->averageCollCount->Text = L"В среднем коллизий: 0";
			// 
			// collCount
			// 
			this->collCount->AutoSize = true;
			this->collCount->Location = System::Drawing::Point(242, 81);
			this->collCount->Name = L"collCount";
			this->collCount->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->collCount->Size = System::Drawing::Size(68, 13);
			this->collCount->TabIndex = 8;
			this->collCount->Text = L"Коллизий: 0";
			// 
			// averageCompareCount
			// 
			this->averageCompareCount->AutoSize = true;
			this->averageCompareCount->Location = System::Drawing::Point(6, 114);
			this->averageCompareCount->Name = L"averageCompareCount";
			this->averageCompareCount->Size = System::Drawing::Size(130, 13);
			this->averageCompareCount->TabIndex = 7;
			this->averageCompareCount->Text = L"В среднем сравнений: 0";
			// 
			// searchStatus
			// 
			this->searchStatus->AutoSize = true;
			this->searchStatus->Location = System::Drawing::Point(19, 25);
			this->searchStatus->Name = L"searchStatus";
			this->searchStatus->Size = System::Drawing::Size(117, 13);
			this->searchStatus->TabIndex = 4;
			this->searchStatus->Text = L"Поиск не проводился";
			// 
			// totalCompareCount
			// 
			this->totalCompareCount->AutoSize = true;
			this->totalCompareCount->Location = System::Drawing::Point(30, 81);
			this->totalCompareCount->Name = L"totalCompareCount";
			this->totalCompareCount->Size = System::Drawing::Size(106, 13);
			this->totalCompareCount->TabIndex = 6;
			this->totalCompareCount->Text = L"Всего сравнений: 0";
			// 
			// compareCount
			// 
			this->compareCount->AutoSize = true;
			this->compareCount->Location = System::Drawing::Point(62, 54);
			this->compareCount->Name = L"compareCount";
			this->compareCount->Size = System::Drawing::Size(74, 13);
			this->compareCount->TabIndex = 5;
			this->compareCount->Text = L"Сравнений: 0";
			// 
			// searchCount
			// 
			this->searchCount->AutoSize = true;
			this->searchCount->Location = System::Drawing::Point(7, 54);
			this->searchCount->Name = L"searchCount";
			this->searchCount->Size = System::Drawing::Size(103, 13);
			this->searchCount->TabIndex = 3;
			this->searchCount->Text = L"Всего поиск: 0 раз";
			// 
			// statsReset_button
			// 
			this->statsReset_button->Location = System::Drawing::Point(255, 54);
			this->statsReset_button->Name = L"statsReset_button";
			this->statsReset_button->Size = System::Drawing::Size(89, 28);
			this->statsReset_button->TabIndex = 2;
			this->statsReset_button->Text = L"Сброс";
			this->statsReset_button->UseVisualStyleBackColor = true;
			this->statsReset_button->Click += gcnew System::EventHandler(this, &MyForm::statsReset_button_Click);
			// 
			// search_button
			// 
			this->search_button->Enabled = false;
			this->search_button->Location = System::Drawing::Point(255, 20);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(89, 28);
			this->search_button->TabIndex = 1;
			this->search_button->Text = L"Поиск";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &MyForm::search_button_Click);
			// 
			// targetText
			// 
			this->targetText->Location = System::Drawing::Point(7, 20);
			this->targetText->Name = L"targetText";
			this->targetText->Size = System::Drawing::Size(242, 20);
			this->targetText->TabIndex = 0;
			this->targetText->TextChanged += gcnew System::EventHandler(this, &MyForm::targetText_TextChanged);
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(420, 392);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(147, 28);
			this->exit_button->TabIndex = 3;
			this->exit_button->Text = L"Выход из программы";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &MyForm::exit_button_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"*.txt";
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"TXT Files (*.txt)|*.txt|All files (*.*)|*.*";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 432);
			this->ControlBox = false;
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Лабораторная работа №1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void fileLoad_button_Click(System::Object^ sender, System::EventArgs^ e) {
	fileData->Text = "";
	if (!File::Exists(fileName->Text)) {
		MessageBox::Show(
			"Файл \"" + System::IO::Path::GetFileName(fileName->Text) + "\" не найден",
			"Предупреждение",
			MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation
		);
		return;
	}
	std::freeCount = 100;
	int count = 0;
	int coll = 0;
	StreamReader^ sr = gcnew StreamReader(fileName->Text);
	String^ line = "";
	std::clear_table();
	while ((line = sr->ReadLine()) != nullptr) {
		fileData->Text += line += "\n";
		std::fill_table(msclr::interop::marshal_as<std::string>(line), coll, std::freeCount);
		count++;
	}
	MessageBox::Show(
		"Считано идентификаторов: " + count,
		"Информация",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
	collCount->Text = "Коллизий: " + System::Convert::ToString(coll);
	double x = std::round( (count - std::freeCount) / (double((sizeof(std::table) / sizeof(std::table[0])))) * 100) / 100;
	averageCollCount->Text = "В среднем коллизий: " + System::Convert::ToString(x);


	sr->Close();
}
private: System::Void fileSelect_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		fileName->Text = System::IO::Path::GetFullPath(openFileDialog1->FileName);
	}
}
private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void search_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ target = targetText->Text + "\n";
	int count = 0;
	std::searchCount++;
	searchCount->Text = "Всего поиск: " + System::Convert::ToString(std::searchCount) + " раз";
	if (std::find_text(msclr::interop::marshal_as<std::string>(target), count)) {
		searchStatus->Text = "Идентификатор найден";
	}
	else {
		searchStatus->Text = "Идентификатор не найден";
	}
	std::totalCompareCount += count;
	compareCount->Text = "Сравнений: " + System::Convert::ToString(count);
	totalCompareCount->Text = "Всего сравнений: " + System::Convert::ToString(std::totalCompareCount);
	averageCompareCount->Text = "В среднем сравнений: " + System::Convert::ToString(std::round( double(std::totalCompareCount) / double(std::searchCount) * 100 ) / 100);
}
private: System::Void targetText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (targetText->Text != "" && fileData->Text != "") {
		search_button->Enabled = true;
	}
	else {
		search_button->Enabled = false;
	}
}
private: System::Void fileData_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	targetText_TextChanged(sender, e);
}
private: System::Void statsReset_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::totalCompareCount = 0;
	std::searchCount = 0;
	searchStatus->Text = "Поиск не проводился";
	searchCount->Text = "Всего поиск: 0 раз";
	compareCount->Text = "Сравнений: 0";
	totalCompareCount->Text = "Всего сравнений: 0";
	averageCompareCount->Text = "В среднем сравнений: 0";
}
};
}
