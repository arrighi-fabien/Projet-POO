#pragma once
#include "GpCustomer.h"
#include "GpItem.h"
#include "GpOrder.h"
#include <math.h>

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Description résumée de OrderForm
	/// </summary>
	public ref class OrderForm : public System::Windows::Forms::Form
	{
	public:
		OrderForm(int mode, int id_customer) {
			InitializeComponent();
			this->mode = mode;
			this->id_customer = id_customer;
			if (this->mode == 1) {
				this->Text = L"Création d'une commande";
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~OrderForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_shipping_address;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dgv_billing_address;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tb_item_ref_search;

	private: System::Windows::Forms::TextBox^ tb_item_name_search;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ btn_command_search;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: int mode;
	private: int id_customer;
	private: int id_shipping_address;
	private: int id_billing_address;
	private: GpItem^ gpItem = gcnew GpItem();
	private: GpCustomer^ gpCustomer = gcnew GpCustomer();
	private: GpOrder^ gpOrder = gcnew GpOrder();
		
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::TextBox^ tb_customer_id;
	private: System::Windows::Forms::Button^ btn_valid_order;


	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ tb_customer_lname;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ tb_customer_fname;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;



	protected:


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
		void InitializeComponent(void) {
			this->dgv_shipping_address = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dgv_billing_address = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_item_ref_search = (gcnew System::Windows::Forms::TextBox());
			this->tb_item_name_search = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_command_search = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tb_customer_id = (gcnew System::Windows::Forms::TextBox());
			this->btn_valid_order = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tb_customer_lname = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tb_customer_fname = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_shipping_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_billing_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_shipping_address
			// 
			this->dgv_shipping_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_shipping_address->Location = System::Drawing::Point(13, 177);
			this->dgv_shipping_address->Name = L"dgv_shipping_address";
			this->dgv_shipping_address->ReadOnly = true;
			this->dgv_shipping_address->RowHeadersWidth = 51;
			this->dgv_shipping_address->Size = System::Drawing::Size(657, 122);
			this->dgv_shipping_address->TabIndex = 28;
			this->dgv_shipping_address->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrderForm::dgv_shipping_address_CellContentDoubleClick);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(11, 316);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(190, 11);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Addresse de facturation";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(11, 162);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(157, 15);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Addresse de livraison";
			// 
			// dgv_billing_address
			// 
			this->dgv_billing_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_billing_address->Location = System::Drawing::Point(13, 331);
			this->dgv_billing_address->Margin = System::Windows::Forms::Padding(2);
			this->dgv_billing_address->Name = L"dgv_billing_address";
			this->dgv_billing_address->ReadOnly = true;
			this->dgv_billing_address->RowHeadersWidth = 51;
			this->dgv_billing_address->Size = System::Drawing::Size(657, 122);
			this->dgv_billing_address->TabIndex = 25;
			this->dgv_billing_address->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrderForm::dgv_billing_address_CellContentDoubleClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Date de livraison";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"d MMMM yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(16, 119);
			this->dateTimePicker1->MinDate = System::DateTime::Today;
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(162, 20);
			this->dateTimePicker1->TabIndex = 30;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9
			});
			this->dataGridView1->Location = System::Drawing::Point(714, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(643, 418);
			this->dataGridView1->TabIndex = 31;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrderForm::dataGridView1_CellEndEdit);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"id_item";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"id_item_price";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Référence";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Nom";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Prix HT";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Taux TVA";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Quantité";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Remise (%)";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"En stock";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn7";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(711, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Panier";
			// 
			// tb_item_ref_search
			// 
			this->tb_item_ref_search->Location = System::Drawing::Point(14, 518);
			this->tb_item_ref_search->Name = L"tb_item_ref_search";
			this->tb_item_ref_search->Size = System::Drawing::Size(100, 20);
			this->tb_item_ref_search->TabIndex = 33;
			// 
			// tb_item_name_search
			// 
			this->tb_item_name_search->Location = System::Drawing::Point(133, 518);
			this->tb_item_name_search->Name = L"tb_item_name_search";
			this->tb_item_name_search->Size = System::Drawing::Size(165, 20);
			this->tb_item_name_search->TabIndex = 34;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(130, 502);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 13);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Désignation article";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 502);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Référence article";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(16, 545);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(654, 124);
			this->dataGridView2->TabIndex = 37;
			this->dataGridView2->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrderForm::dataGridView2_CellContentDoubleClick);
			// 
			// btn_command_search
			// 
			this->btn_command_search->Location = System::Drawing::Point(327, 515);
			this->btn_command_search->Name = L"btn_command_search";
			this->btn_command_search->Size = System::Drawing::Size(75, 23);
			this->btn_command_search->TabIndex = 38;
			this->btn_command_search->Text = L"Recherche";
			this->btn_command_search->UseVisualStyleBackColor = true;
			this->btn_command_search->Click += gcnew System::EventHandler(this, &OrderForm::btn_command_search_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(212, 112);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(170, 26);
			this->label7->TabIndex = 39;
			this->label7->Text = L"Adresse de livraison sélectionnée :\r\nn°";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(225, 125);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 40;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(418, 125);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 42;
			this->label9->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(405, 112);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(182, 26);
			this->label10->TabIndex = 41;
			this->label10->Text = L"Adresse de facturation sélectionnée :\r\nn°";
			// 
			// tb_customer_id
			// 
			this->tb_customer_id->Location = System::Drawing::Point(14, 48);
			this->tb_customer_id->Name = L"tb_customer_id";
			this->tb_customer_id->ReadOnly = true;
			this->tb_customer_id->Size = System::Drawing::Size(100, 20);
			this->tb_customer_id->TabIndex = 43;
			// 
			// btn_valid_order
			// 
			this->btn_valid_order->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_valid_order->Location = System::Drawing::Point(1049, 545);
			this->btn_valid_order->Name = L"btn_valid_order";
			this->btn_valid_order->Size = System::Drawing::Size(182, 65);
			this->btn_valid_order->TabIndex = 46;
			this->btn_valid_order->Text = L"Passer la commande";
			this->btn_valid_order->UseVisualStyleBackColor = true;
			this->btn_valid_order->Click += gcnew System::EventHandler(this, &OrderForm::btn_valid_order_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(11, 32);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 13);
			this->label11->TabIndex = 47;
			this->label11->Text = L"Identifiant client";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(135, 32);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(57, 13);
			this->label12->TabIndex = 49;
			this->label12->Text = L"Nom client";
			// 
			// tb_customer_lname
			// 
			this->tb_customer_lname->Location = System::Drawing::Point(138, 48);
			this->tb_customer_lname->Name = L"tb_customer_lname";
			this->tb_customer_lname->ReadOnly = true;
			this->tb_customer_lname->Size = System::Drawing::Size(100, 20);
			this->tb_customer_lname->TabIndex = 48;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(256, 32);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(71, 13);
			this->label13->TabIndex = 51;
			this->label13->Text = L"Prénom client";
			// 
			// tb_customer_fname
			// 
			this->tb_customer_fname->Location = System::Drawing::Point(259, 48);
			this->tb_customer_fname->Name = L"tb_customer_fname";
			this->tb_customer_fname->ReadOnly = true;
			this->tb_customer_fname->Size = System::Drawing::Size(100, 20);
			this->tb_customer_fname->TabIndex = 50;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(710, 590);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(265, 20);
			this->label14->TabIndex = 52;
			this->label14->Text = L"Montant total de la commande TTC :";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(972, 590);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 20);
			this->label15->TabIndex = 53;
			this->label15->Text = L"0 €";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(969, 551);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 20);
			this->label16->TabIndex = 55;
			this->label16->Text = L"0 €";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(712, 551);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(261, 20);
			this->label17->TabIndex = 54;
			this->label17->Text = L"Montant total de la commande HT  :";
			// 
			// OrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1369, 681);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->tb_customer_fname);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->tb_customer_lname);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->btn_valid_order);
			this->Controls->Add(this->tb_customer_id);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btn_command_search);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_item_name_search);
			this->Controls->Add(this->tb_item_ref_search);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgv_shipping_address);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgv_billing_address);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"OrderForm";
			this->Text = L"OrderForm";
			this->Load += gcnew System::EventHandler(this, &OrderForm::OrderForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_shipping_address))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_billing_address))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		gpCustomer->selectCustomer(this->id_customer);
		this->dgv_shipping_address->DataSource = gpCustomer->getShippingAddress();
		this->dgv_shipping_address->DataMember = "CustomerShippingAddress";
		this->dgv_shipping_address->Columns[0]->Visible = false;
		this->dgv_shipping_address->Columns[4]->Visible = false;
		this->dgv_shipping_address->Columns[6]->Visible = false;
		this->dgv_shipping_address->Columns[1]->Width = 175;
		this->dgv_shipping_address->Columns[2]->Width = 175;
		this->dgv_shipping_address->Columns[3]->Width = 75;
		this->dgv_billing_address->DataSource = gpCustomer->getBillingAddress();
		this->dgv_billing_address->DataMember = "CustomerBillingAddress";
		this->dgv_billing_address->Columns[0]->Visible = false;
		this->dgv_billing_address->Columns[4]->Visible = false;
		this->dgv_billing_address->Columns[6]->Visible = false;
		this->dgv_billing_address->Columns[1]->Width = 175;
		this->dgv_billing_address->Columns[2]->Width = 175;
		this->dgv_billing_address->Columns[3]->Width = 75;
		this->tb_customer_id->Text = Convert::ToString(this->id_customer);
		this->tb_customer_lname->Text = gpCustomer->getCustomer()->getLastName();
		this->tb_customer_fname->Text = gpCustomer->getCustomer()->getFirstName();
	}
	private: System::Void btn_command_search_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView2->Columns->Clear();
		int id = 0;
		this->dataGridView2->DataSource = gpItem->itemPreview(this->tb_item_ref_search->Text, this->tb_item_name_search->Text);
		this->dataGridView2->DataMember = "Preview";
		this->dataGridView2->Columns[0]->Visible = false;
		this->dataGridView2->Columns[1]->Visible = false;
		//auto resize column of datagridview to take all place
		for (int i = 0; i < this->dataGridView2->Columns->Count; i++) {
			this->dataGridView2->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
	}
	private: System::Void dgv_shipping_address_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		this->label8->Text = Convert::ToString(this->dgv_shipping_address->CurrentRow->Index + 1);
		this->id_shipping_address = Convert::ToInt32(this->dgv_shipping_address->CurrentRow->Cells[0]->Value);
	}
	private: System::Void dgv_billing_address_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		this->label9->Text = Convert::ToString(this->dgv_billing_address->CurrentRow->Index + 1);
		this->id_billing_address = Convert::ToInt32(this->dgv_billing_address->CurrentRow->Cells[0]->Value);
	}
	private: System::Void dataGridView2_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		String^ item_ref = Convert::ToString(this->dataGridView2->CurrentRow->Cells[2]->Value);
		this->insertDgvItem(item_ref);
	}
	private: void insertDgvItem(String^ item_ref) {
		DataSet^ data = gpItem->itemPreview(item_ref, "");
		//first 4 column are read only
		this->dataGridView1->Columns[0]->Visible = false;
		this->dataGridView1->Columns[1]->Visible = false;
		this->dataGridView1->Columns[2]->ReadOnly = true;
		this->dataGridView1->Columns[3]->ReadOnly = true;
		this->dataGridView1->Columns[4]->ReadOnly = true;
		this->dataGridView1->Columns[5]->ReadOnly = true;
		this->dataGridView1->Columns[8]->Visible = false;
		//add content from data to datagridview
		this->dataGridView1->Rows->Add(data->Tables[0]->Rows[0]->ItemArray);
		int last_insert = this->dataGridView1->Rows->Count - 2;
		//take data in cells 6 and put it in cell 8
		this->dataGridView1->Rows[last_insert]->Cells[8]->Value = this->dataGridView1->Rows[last_insert]->Cells[6]->Value;
		this->dataGridView1->Rows[last_insert]->Cells[6]->Value = 0;
		this->dataGridView1->Rows[last_insert]->Cells[7]->Value = 0;
	}
	private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		float total_cart_et = 0;
		float total_cart_wt = 0;
		float quantity;
		float discount;
		for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
			//get value in column 4 and 5
			try {
				quantity = Convert::ToSingle(this->dataGridView1->Rows[i]->Cells[6]->Value);
				discount = Convert::ToSingle(this->dataGridView1->Rows[i]->Cells[7]->Value);
			}
			catch (Exception^ e) {
				this->dataGridView1->Rows[i]->Cells[6]->Value = 0;
				this->dataGridView1->Rows[i]->Cells[7]->Value = 0;
				MessageBox::Show("Please enter a valid quantity and discount", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (Regex::IsMatch(Convert::ToString(quantity), "^[0-9]{1,10}$") && Regex::IsMatch(Convert::ToString(discount), "^[0-9]{0,3}$")) {
				total_cart_et += Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[4]->Value) * Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[6]->Value) * (1 - Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[7]->Value) / 100);
			}
			else {
				this->dataGridView1->Rows[i]->Cells[6]->Value = 0;
				this->dataGridView1->Rows[i]->Cells[7]->Value = 0;
				MessageBox::Show("Please enter a valid quantity and discount", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		total_cart_et = roundf(total_cart_et * 100) / 100;
		this->label16->Text = Convert::ToString(total_cart_et + " €");
		for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
			total_cart_wt += Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[4]->Value) * (Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[5]->Value) + 1) * Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[6]->Value) * (1 - Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[7]->Value) / 100);
		}
		total_cart_wt = roundf(total_cart_wt * 100) / 100;
		this->label15->Text = Convert::ToString(total_cart_wt + " €");
	}
	private: System::Void btn_valid_order_Click(System::Object^ sender, System::EventArgs^ e) {
		//check if all field are filled
		if (this->id_shipping_address == 0 || this->id_billing_address == 0) {
			MessageBox::Show("Veuillez sélectionner une addresse de livraison et une de facturation", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		//check if first line of datagridview exist or if it's empty
		if (this->dataGridView1->Rows->Count == 1 || this->dataGridView1->Rows[0]->Cells[0]->Value == nullptr) {
			MessageBox::Show("Veuillez ajouter des articles à votre panier", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		//check if all quantity are valid
		for (int i = 0; i < this->dataGridView1->Rows->Count - 1; i++) {
			if (Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[6]->Value) == 0) {
				MessageBox::Show("Veuillez entrer une quantité valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		//check if all discount are valid
		for (int i = 0; i < this->dataGridView1->Rows->Count - 1; i++) {
			if (Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[7]->Value) > 100) {
				MessageBox::Show("Veuillez entrer une remise valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		//check if all quantity are available
		for (int i = 0; i < this->dataGridView1->Rows->Count - 1; i++) {
			if (Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[6]->Value) > Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[8]->Value)) {
				MessageBox::Show("Pas assez d'article en stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		gpOrder->setCustomer(gpCustomer);
		gpOrder->getOrder()->setDeliveryDate(this->dateTimePicker1->Value);
		//create a DataSet to put the content of the datagridview in the order
		DataSet^ ds = gcnew DataSet();
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("id_item", System::Int32::typeid);
		dt->Columns->Add("id_item_price", System::Int32::typeid);
		dt->Columns->Add("quantity", System::Int32::typeid);
		dt->Columns->Add("discount", System::Int32::typeid);
		for (int i = 0; i < this->dataGridView1->Rows->Count - 1; i++) {
			dt->Rows->Add(Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[0]->Value), Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[1]->Value), Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[6]->Value), Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[7]->Value));
		}
		ds->Tables->Add(dt);
		gpOrder->setOrderContain(ds);
		gpOrder->addOrder(this->id_shipping_address, this->id_billing_address, this->dgv_shipping_address->Rows[Convert::ToInt32(this->label8->Text) - 1]->Cells[5]->Value->ToString());
		MessageBox::Show("Commande validée", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
};
}
