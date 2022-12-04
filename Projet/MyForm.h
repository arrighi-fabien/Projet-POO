#pragma once
#include "DatabaseConnection.h"
#include "StaffForm.h"
#include "GpStaff.h"
#include "CustomerForm.h"
#include "GpCustomer.h"
#include "ItemForm.h"
#include "GpItem.h"
#include "OrderForm.h"
#include "GpStat.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Description résumée de MyForm
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
		/// Nettoyage des ressources utilisées.
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
	private: System::Windows::Forms::Button^ btn_stat_commercial_value;

	private: System::Windows::Forms::Button^ btn_stat_restocking;

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
	private: GpItem^ gpItem = gcnew GpItem();
	private: GpStat^ gpStat = gcnew GpStat();
	private: int page = 0;
		
	private: System::Windows::Forms::Button^ btn_item_search;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Button^ btn_item_creation;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btn_order_create;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ tb_order_customer;




	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
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
			this->btn_item_search = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->btn_item_creation = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tb_order_customer = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_order_create = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
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
			this->btn_stat_commercial_value = (gcnew System::Windows::Forms::Button());
			this->btn_stat_restocking = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
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
			this->tabControl1->Location = System::Drawing::Point(4, 2);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(584, 171);
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
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(576, 145);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Personnels";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btn_staff_search
			// 
			this->btn_staff_search->Location = System::Drawing::Point(261, 67);
			this->btn_staff_search->Margin = System::Windows::Forms::Padding(2);
			this->btn_staff_search->Name = L"btn_staff_search";
			this->btn_staff_search->Size = System::Drawing::Size(68, 19);
			this->btn_staff_search->TabIndex = 14;
			this->btn_staff_search->Text = L"Recherche";
			this->btn_staff_search->UseVisualStyleBackColor = true;
			this->btn_staff_search->Click += gcnew System::EventHandler(this, &MyForm::btn_staff_search_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(8, 95);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Prénom";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(10, 114);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 20);
			this->textBox3->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(8, 50);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nom";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(10, 68);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 20);
			this->textBox2->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(8, 10);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Identifiant staff";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 28);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 5;
			// 
			// btn_staff_creation
			// 
			this->btn_staff_creation->Location = System::Drawing::Point(359, 64);
			this->btn_staff_creation->Margin = System::Windows::Forms::Padding(2);
			this->btn_staff_creation->Name = L"btn_staff_creation";
			this->btn_staff_creation->Size = System::Drawing::Size(169, 24);
			this->btn_staff_creation->TabIndex = 1;
			this->btn_staff_creation->Text = L"Créer un nouveau personnel";
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
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(576, 145);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Clients";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// btn_client_search
			// 
			this->btn_client_search->Location = System::Drawing::Point(261, 67);
			this->btn_client_search->Margin = System::Windows::Forms::Padding(2);
			this->btn_client_search->Name = L"btn_client_search";
			this->btn_client_search->Size = System::Drawing::Size(68, 19);
			this->btn_client_search->TabIndex = 23;
			this->btn_client_search->Text = L"Recherche";
			this->btn_client_search->UseVisualStyleBackColor = true;
			this->btn_client_search->Click += gcnew System::EventHandler(this, &MyForm::btn_client_search_Click);
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(8, 95);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(68, 16);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Prénom";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(10, 114);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(200, 20);
			this->textBox7->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(8, 50);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(68, 16);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Nom";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(10, 68);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(200, 20);
			this->textBox8->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(8, 10);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 16);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Identifiant client";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(10, 28);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(200, 20);
			this->textBox9->TabIndex = 16;
			// 
			// btn_client_creation
			// 
			this->btn_client_creation->Location = System::Drawing::Point(359, 64);
			this->btn_client_creation->Margin = System::Windows::Forms::Padding(2);
			this->btn_client_creation->Name = L"btn_client_creation";
			this->btn_client_creation->Size = System::Drawing::Size(169, 24);
			this->btn_client_creation->TabIndex = 15;
			this->btn_client_creation->Text = L"Créer un nouveau client";
			this->btn_client_creation->UseVisualStyleBackColor = true;
			this->btn_client_creation->Click += gcnew System::EventHandler(this, &MyForm::btn_client_creation_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->btn_item_search);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->textBox10);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->textBox11);
			this->tabPage3->Controls->Add(this->btn_item_creation);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(2);
			this->tabPage3->Size = System::Drawing::Size(576, 145);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Stock";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// btn_item_search
			// 
			this->btn_item_search->Location = System::Drawing::Point(261, 67);
			this->btn_item_search->Margin = System::Windows::Forms::Padding(2);
			this->btn_item_search->Name = L"btn_item_search";
			this->btn_item_search->Size = System::Drawing::Size(68, 19);
			this->btn_item_search->TabIndex = 29;
			this->btn_item_search->Text = L"Recherche";
			this->btn_item_search->UseVisualStyleBackColor = true;
			this->btn_item_search->Click += gcnew System::EventHandler(this, &MyForm::btn_item_search_Click);
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(8, 50);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(68, 16);
			this->label11->TabIndex = 28;
			this->label11->Text = L"Nom article";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(10, 68);
			this->textBox10->Margin = System::Windows::Forms::Padding(2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(200, 20);
			this->textBox10->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(8, 10);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(101, 16);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Référence article";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(10, 28);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(200, 20);
			this->textBox11->TabIndex = 25;
			// 
			// btn_item_creation
			// 
			this->btn_item_creation->Location = System::Drawing::Point(359, 64);
			this->btn_item_creation->Margin = System::Windows::Forms::Padding(2);
			this->btn_item_creation->Name = L"btn_item_creation";
			this->btn_item_creation->Size = System::Drawing::Size(169, 24);
			this->btn_item_creation->TabIndex = 24;
			this->btn_item_creation->Text = L"Créer un nouveau article";
			this->btn_item_creation->UseVisualStyleBackColor = true;
			this->btn_item_creation->Click += gcnew System::EventHandler(this, &MyForm::btn_item_creation_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label15);
			this->tabPage4->Controls->Add(this->tb_order_customer);
			this->tabPage4->Controls->Add(this->button1);
			this->tabPage4->Controls->Add(this->btn_order_create);
			this->tabPage4->Controls->Add(this->label13);
			this->tabPage4->Controls->Add(this->textBox12);
			this->tabPage4->Controls->Add(this->label14);
			this->tabPage4->Controls->Add(this->textBox13);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(2);
			this->tabPage4->Size = System::Drawing::Size(576, 145);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Commandes";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->Location = System::Drawing::Point(357, 22);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(98, 16);
			this->label15->TabIndex = 36;
			this->label15->Text = L"Identifiant client";
			// 
			// tb_order_customer
			// 
			this->tb_order_customer->Location = System::Drawing::Point(359, 40);
			this->tb_order_customer->Margin = System::Windows::Forms::Padding(2);
			this->tb_order_customer->Name = L"tb_order_customer";
			this->tb_order_customer->Size = System::Drawing::Size(169, 20);
			this->tb_order_customer->TabIndex = 35;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(261, 67);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 19);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Recherche";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// btn_order_create
			// 
			this->btn_order_create->Location = System::Drawing::Point(359, 64);
			this->btn_order_create->Margin = System::Windows::Forms::Padding(2);
			this->btn_order_create->Name = L"btn_order_create";
			this->btn_order_create->Size = System::Drawing::Size(169, 24);
			this->btn_order_create->TabIndex = 33;
			this->btn_order_create->Text = L"Créer une nouvelle commande";
			this->btn_order_create->UseVisualStyleBackColor = true;
			this->btn_order_create->Click += gcnew System::EventHandler(this, &MyForm::btn_order_create_Click);
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(8, 50);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(68, 16);
			this->label13->TabIndex = 32;
			this->label13->Text = L"Nom client";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(10, 68);
			this->textBox12->Margin = System::Windows::Forms::Padding(2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(200, 20);
			this->textBox12->TabIndex = 31;
			// 
			// label14
			// 
			this->label14->Location = System::Drawing::Point(8, 10);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(101, 16);
			this->label14->TabIndex = 30;
			this->label14->Text = L"Référence commande";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(10, 28);
			this->textBox13->Margin = System::Windows::Forms::Padding(2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(200, 20);
			this->textBox13->TabIndex = 29;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->button7);
			this->tabPage5->Controls->Add(this->textBox4);
			this->tabPage5->Controls->Add(this->label4);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Margin = System::Windows::Forms::Padding(2);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(2);
			this->tabPage5->Size = System::Drawing::Size(576, 145);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"Factures";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(166, 42);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(71, 37);
			this->button7->TabIndex = 12;
			this->button7->Text = L"Générer facture";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(4, 58);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(142, 20);
			this->textBox4->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(2, 42);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 15);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Numéro de commande";
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
			this->tabPage6->Controls->Add(this->btn_stat_commercial_value);
			this->tabPage6->Controls->Add(this->btn_stat_restocking);
			this->tabPage6->Controls->Add(this->button6);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Margin = System::Windows::Forms::Padding(2);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(2);
			this->tabPage6->Size = System::Drawing::Size(576, 145);
			this->tabPage6->TabIndex = 1;
			this->tabPage6->Text = L"Statistiques";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(12, 74);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 19);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Numéro client";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 94);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(146, 20);
			this->textBox6->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(110, 13);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 15);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Année";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(12, 12);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 15);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Mois";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(110, 30);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(76, 20);
			this->textBox5->TabIndex = 10;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Janvier", L"Février", L"Mars", L"Avril", L"Mai",
					L"Juin", L"Juillet", L"Aout", L"Septembre", L"Octobre", L"Novembre", L"Décembre"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 30);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(326, 12);
			this->button15->Margin = System::Windows::Forms::Padding(2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(84, 37);
			this->button15->TabIndex = 8;
			this->button15->Text = L"10 meilleures vente";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(192, 22);
			this->button14->Margin = System::Windows::Forms::Padding(2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(70, 34);
			this->button14->TabIndex = 7;
			this->button14->Text = L"Chiffre d\'affaires";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(162, 84);
			this->button13->Margin = System::Windows::Forms::Padding(2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(84, 39);
			this->button13->TabIndex = 6;
			this->button13->Text = L"Total achats client";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(251, 14);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(84, 37);
			this->button11->TabIndex = 4;
			this->button11->Text = L"10 pires vente";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(236, 49);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(80, 44);
			this->button10->TabIndex = 3;
			this->button10->Text = L"Valeur achat stock";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// btn_stat_commercial_value
			// 
			this->btn_stat_commercial_value->Location = System::Drawing::Point(369, 84);
			this->btn_stat_commercial_value->Margin = System::Windows::Forms::Padding(2);
			this->btn_stat_commercial_value->Name = L"btn_stat_commercial_value";
			this->btn_stat_commercial_value->Size = System::Drawing::Size(77, 51);
			this->btn_stat_commercial_value->TabIndex = 2;
			this->btn_stat_commercial_value->Text = L"Valeur commerciale stock";
			this->btn_stat_commercial_value->UseVisualStyleBackColor = true;
			this->btn_stat_commercial_value->Click += gcnew System::EventHandler(this, &MyForm::btn_stat_commercial_value_Click);
			// 
			// btn_stat_restocking
			// 
			this->btn_stat_restocking->Location = System::Drawing::Point(450, 84);
			this->btn_stat_restocking->Margin = System::Windows::Forms::Padding(2);
			this->btn_stat_restocking->Name = L"btn_stat_restocking";
			this->btn_stat_restocking->Size = System::Drawing::Size(116, 52);
			this->btn_stat_restocking->TabIndex = 1;
			this->btn_stat_restocking->Text = L"Produits sous le seuil de réapprovisionnement";
			this->btn_stat_restocking->UseVisualStyleBackColor = true;
			this->btn_stat_restocking->Click += gcnew System::EventHandler(this, &MyForm::btn_stat_restocking_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(394, 4);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(80, 41);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Panier moyen (après remise)";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(12, 180);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(566, 144);
			this->dataGridView2->TabIndex = 14;
			this->dataGridView2->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentDoubleClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 336);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
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
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
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
		if (!Regex::IsMatch(textBox1->Text, "^[0-9]{0,10}$")) {
			MessageBox::Show("Veuillez entrer un id de staff valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
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
		if (!Regex::IsMatch(textBox9->Text, "^[0-9]{0,10}$")) {
			MessageBox::Show("Veuillez entrer un id de staff valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->btn_search();
	}
	//
	// Product part
	//
	private: System::Void btn_item_creation_Click(System::Object^ sender, System::EventArgs^ e) {
		ItemForm^ itemForm = gcnew ItemForm(1);
		itemForm->ShowDialog();
	}
	private: System::Void btn_item_search_Click(System::Object^ sender, System::EventArgs^ e) {
		this->page = 3;
		if (!Regex::IsMatch(textBox11->Text, "^[0-9A-Za-z]{0,10}$")) {
			MessageBox::Show("Veuillez entrer une référence d'article valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->btn_search();
	}
	//
	// Order part
	//
	private: System::Void btn_order_create_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->tb_order_customer->Text != "") {
			OrderForm^ orderForm = gcnew OrderForm(1, Convert::ToInt32(this->tb_order_customer->Text));
			orderForm->ShowDialog();
		}
		else {
			MessageBox::Show("Veuillez entrer un id de client", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
		
	//
	// Stat part
	//
	private: System::Void btn_stat_restocking_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView2->DataSource = gpStat->getItemUnderRestockingLevel();
		this->dataGridView2->DataMember = "Stat";
		for (int i = 0; i < this->dataGridView2->Columns->Count; i++) {
			this->dataGridView2->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
	}
	private: System::Void btn_stat_commercial_value_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ commercial_value = gpStat->getStockCommercialValue();
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Commercial value");
		dt->Rows->Add(commercial_value);
		this->dataGridView2->DataSource = dt;
		for (int i = 0; i < this->dataGridView2->Columns->Count; i++) {
			this->dataGridView2->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
	}
	//
	// All part
	//
	private: void btn_search() {
		this->dataGridView2->Columns->Clear();
		int id = 0;
		switch (this->page) {
		case 1:
			if (this->textBox1->Text == "") {

			}
			else {
				id = Convert::ToInt32(this->textBox1->Text);
			}
			this->dataGridView2->DataSource = gpStaff->staffPreview(id, this->textBox2->Text, this->textBox3->Text);
			break;
		case 2:
			if (this->textBox9->Text == "") {

			}
			else {
				id = Convert::ToInt32(this->textBox9->Text);
			}
			this->dataGridView2->DataSource = gpCustomer->customerPreview(id, this->textBox8->Text, this->textBox7->Text);
			break;
		case 3:
			this->dataGridView2->DataSource = gpItem->itemPreview(this->textBox11->Text, this->textBox10->Text);
			break;
		}
		this->dataGridView2->DataMember = "Preview";
		if (this->page == 3) {
			this->dataGridView2->Columns[0]->Visible = false;
			this->dataGridView2->Columns[1]->Visible = false;
		}
		//auto resize column of datagridview to take all place
		for (int i = 0; i < this->dataGridView2->Columns->Count; i++) {
			this->dataGridView2->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
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
		else if (this->page == 3) {
			ItemForm^ itemForm = gcnew ItemForm(2, this->dataGridView2->CurrentRow->Cells[2]->Value->ToString());
			itemForm->ShowDialog();
		}
	}
};
}