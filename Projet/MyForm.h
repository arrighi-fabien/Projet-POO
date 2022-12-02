#pragma once
#include "DatabaseConnection.h"
#include "StaffForm.h"
#include "GpStaff.h"
#include "CustomerForm.h"
#include "GpCustomer.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Description r�sum�e de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;



	private: System::Windows::Forms::Button^ btn_staff_creation;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button13;

	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::Button^ btn_staff_search;
	private: System::Windows::Forms::Button^ btn_client_search;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ btn_client_creation;
	private: System::Windows::Forms::DataGridView^ dataGridView2;

		
	private: GpStaff^ gpStaff = gcnew GpStaff();
	private: GpCustomer^ gpCustomer = gcnew GpCustomer();
	private: int page = 0;
	private: int id = 0;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Button^ button2;


	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btn_staff_search = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btn_staff_creation = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btn_client_search = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->btn_client_creation = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Location = System::Drawing::Point(5, 2);
			this->tabControl1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(779, 210);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btn_staff_search);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->btn_staff_creation);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Size = System::Drawing::Size(771, 181);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Personnels";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btn_staff_search
			// 
			this->btn_staff_search->Location = System::Drawing::Point(348, 82);
			this->btn_staff_search->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_staff_search->Name = L"btn_staff_search";
			this->btn_staff_search->Size = System::Drawing::Size(91, 23);
			this->btn_staff_search->TabIndex = 14;
			this->btn_staff_search->Text = L"Recherche";
			this->btn_staff_search->UseVisualStyleBackColor = true;
			this->btn_staff_search->Click += gcnew System::EventHandler(this, &MyForm::btn_staff_search_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Pr�nom";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(13, 140);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(265, 22);
			this->textBox3->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nom";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 84);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(265, 22);
			this->textBox2->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(11, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Identifiant staff";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 34);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(265, 22);
			this->textBox1->TabIndex = 5;
			// 
			// btn_staff_creation
			// 
			this->btn_staff_creation->Location = System::Drawing::Point(479, 79);
			this->btn_staff_creation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_staff_creation->Name = L"btn_staff_creation";
			this->btn_staff_creation->Size = System::Drawing::Size(225, 30);
			this->btn_staff_creation->TabIndex = 1;
			this->btn_staff_creation->Text = L"Cr�er un nouveau personnel";
			this->btn_staff_creation->UseVisualStyleBackColor = true;
			this->btn_staff_creation->Click += gcnew System::EventHandler(this, &MyForm::btn_staff_creation_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->btn_client_search);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->textBox7);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->textBox8);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->textBox9);
			this->tabPage2->Controls->Add(this->btn_client_creation);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Size = System::Drawing::Size(771, 181);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Clients";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// btn_client_search
			// 
			this->btn_client_search->Location = System::Drawing::Point(348, 82);
			this->btn_client_search->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_client_search->Name = L"btn_client_search";
			this->btn_client_search->Size = System::Drawing::Size(91, 23);
			this->btn_client_search->TabIndex = 23;
			this->btn_client_search->Text = L"Recherche";
			this->btn_client_search->UseVisualStyleBackColor = true;
			this->btn_client_search->Click += gcnew System::EventHandler(this, &MyForm::btn_client_search_Click);
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(11, 117);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(91, 20);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Pr�nom";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(13, 140);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(265, 22);
			this->textBox7->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(11, 62);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(91, 20);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Nom";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(13, 84);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(265, 22);
			this->textBox8->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(11, 12);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(117, 20);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Identifiant client";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(13, 34);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(265, 22);
			this->textBox9->TabIndex = 16;
			// 
			// btn_client_creation
			// 
			this->btn_client_creation->Location = System::Drawing::Point(479, 79);
			this->btn_client_creation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_client_creation->Name = L"btn_client_creation";
			this->btn_client_creation->Size = System::Drawing::Size(225, 30);
			this->btn_client_creation->TabIndex = 15;
			this->btn_client_creation->Text = L"Cr�er un nouveau client";
			this->btn_client_creation->UseVisualStyleBackColor = true;
			this->btn_client_creation->Click += gcnew System::EventHandler(this, &MyForm::btn_client_creation_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button1);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->textBox10);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->textBox11);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage3->Size = System::Drawing::Size(771, 181);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Stock";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage4->Size = System::Drawing::Size(771, 181);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Commandes";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->button7);
			this->tabPage5->Controls->Add(this->textBox4);
			this->tabPage5->Controls->Add(this->label4);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage5->Size = System::Drawing::Size(771, 181);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"Factures";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(221, 52);
			this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(95, 46);
			this->button7->TabIndex = 12;
			this->button7->Text = L"G�n�rer facture";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(5, 71);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(188, 22);
			this->textBox4->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(3, 52);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 18);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Num�ro de commande";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->label7);
			this->tabPage6->Controls->Add(this->textBox6);
			this->tabPage6->Controls->Add(this->label6);
			this->tabPage6->Controls->Add(this->label5);
			this->tabPage6->Controls->Add(this->textBox5);
			this->tabPage6->Controls->Add(this->comboBox1);
			this->tabPage6->Controls->Add(this->button15);
			this->tabPage6->Controls->Add(this->button14);
			this->tabPage6->Controls->Add(this->button13);
			this->tabPage6->Controls->Add(this->button11);
			this->tabPage6->Controls->Add(this->button10);
			this->tabPage6->Controls->Add(this->button9);
			this->tabPage6->Controls->Add(this->button8);
			this->tabPage6->Controls->Add(this->button6);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage6->Size = System::Drawing::Size(771, 181);
			this->tabPage6->TabIndex = 1;
			this->tabPage6->Text = L"Statistiques";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(16, 91);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 23);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Num�ro client";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(16, 116);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(193, 22);
			this->textBox6->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(147, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 18);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Ann�e";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(16, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 18);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Mois";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(147, 37);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 10;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Janvier", L"F�vrier", L"Mars", L"Avril", L"Mai",
					L"Juin", L"Juillet", L"Aout", L"Septembre", L"Octobre", L"Novembre", L"D�cembre"
			});
			this->comboBox1->Location = System::Drawing::Point(16, 37);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 9;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(513, 37);
			this->button15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(112, 46);
			this->button15->TabIndex = 8;
			this->button15->Text = L"10 meilleures vente";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(256, 27);
			this->button14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(93, 42);
			this->button14->TabIndex = 7;
			this->button14->Text = L"Chiffre d\'affaires";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(216, 103);
			this->button13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(112, 48);
			this->button13->TabIndex = 6;
			this->button13->Text = L"Total achats client";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(380, 27);
			this->button11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(112, 46);
			this->button11->TabIndex = 4;
			this->button11->Text = L"10 pires vente";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(380, 97);
			this->button10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(107, 54);
			this->button10->TabIndex = 3;
			this->button10->Text = L"Valeur achat stock";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(492, 96);
			this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(103, 63);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Valeur commerciale stock";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(583, 95);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(155, 64);
			this->button8->TabIndex = 1;
			this->button8->Text = L"Produits sous le seuil de r�approvisionnement";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(631, 25);
			this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(107, 50);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Panier moyen (apr�s remise)";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(16, 222);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(755, 177);
			this->dataGridView2->TabIndex = 14;
			this->dataGridView2->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentDoubleClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(348, 82);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 23);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Recherche";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(11, 62);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(91, 20);
			this->label11->TabIndex = 28;
			this->label11->Text = L"Nom article";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(13, 84);
			this->textBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(265, 22);
			this->textBox10->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(11, 12);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(117, 20);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Identifiant article";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(13, 34);
			this->textBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(265, 22);
			this->textBox11->TabIndex = 25;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(479, 79);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(225, 30);
			this->button2->TabIndex = 24;
			this->button2->Text = L"Cr�er un nouveau article";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 414);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	//
	// Staff part
	//
	private: System::Void btn_staff_creation_Click(System::Object^ sender, System::EventArgs^ e) {
		StaffForm^ staffForm = gcnew StaffForm(1);
		staffForm->ShowDialog();
	}
	private: System::Void btn_staff_search_Click(System::Object^ sender, System::EventArgs^ e) {
		this->page = 1;
		this->btn_search();
	}
	//
	// Customer part
	//
	private: System::Void btn_client_creation_Click(System::Object^ sender, System::EventArgs^ e) {
		CustomerForm^ customerForm = gcnew CustomerForm(1);
		customerForm->ShowDialog();
	}
	private: System::Void btn_client_search_Click(System::Object^ sender, System::EventArgs^ e) {
		this->page = 2;
		this->btn_search();
	}
	//
	// Both part
	//
	private: void btn_search() {
		if (!Regex::IsMatch(textBox1->Text, "^[0-9]{0,10}$") || !Regex::IsMatch(textBox9->Text, "^[0-9]{0,10}$")) {
			MessageBox::Show("Veuillez entrer un id de staff valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->dataGridView2->Columns->Clear();
		int id = 0;
		switch (this->page) {
		case 1:
			if (this->textBox1->Text == "") {

			}
			else {
				this->id = Convert::ToInt32(this->textBox1->Text);
			}
			this->dataGridView2->DataSource = gpStaff->staffPreview(this->id, this->textBox2->Text, this->textBox3->Text);
			break;
		case 2:
			if (this->textBox9->Text == "") {

			}
			else {
				this->id = Convert::ToInt32(this->textBox9->Text);
			}
			this->dataGridView2->DataSource = gpCustomer->customerPreview(this->id, this->textBox8->Text, this->textBox7->Text);
			break;
		}
		this->dataGridView2->DataMember = "Preview";
	}
	private: System::Void dataGridView2_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (this->page == 1) {
			StaffForm^ staffForm = gcnew StaffForm(2, Convert::ToInt32(this->dataGridView2->CurrentRow->Cells[0]->Value));
			staffForm->ShowDialog();
		}
		else if (this->page == 2) {
			CustomerForm^ customerForm = gcnew CustomerForm(2, Convert::ToInt32(this->dataGridView2->CurrentRow->Cells[0]->Value));
			customerForm->ShowDialog();
		}
	}
};
}