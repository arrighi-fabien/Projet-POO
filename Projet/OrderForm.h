#pragma once
#include "GpCustomer.h"
#include "GpItem.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
				this->Text = L"Création d'un nouveau client";
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


	private: int mode;
	private: int id_customer;
	private: GpItem^ gpItem = gcnew GpItem();
	private: GpCustomer^ gpCustomer = gcnew GpCustomer();


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_item_ref_search = (gcnew System::Windows::Forms::TextBox());
			this->tb_item_name_search = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_command_search = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_shipping_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_billing_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_shipping_address
			// 
			this->dgv_shipping_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_shipping_address->Location = System::Drawing::Point(12, 92);
			this->dgv_shipping_address->Name = L"dgv_shipping_address";
			this->dgv_shipping_address->RowHeadersWidth = 51;
			this->dgv_shipping_address->Size = System::Drawing::Size(657, 122);
			this->dgv_shipping_address->TabIndex = 28;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(10, 231);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(190, 11);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Addresse de facturation";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(10, 77);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(157, 15);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Addresse de livraison";
			// 
			// dgv_billing_address
			// 
			this->dgv_billing_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_billing_address->Location = System::Drawing::Point(12, 246);
			this->dgv_billing_address->Margin = System::Windows::Forms::Padding(2);
			this->dgv_billing_address->Name = L"dgv_billing_address";
			this->dgv_billing_address->RowHeadersWidth = 51;
			this->dgv_billing_address->Size = System::Drawing::Size(657, 122);
			this->dgv_billing_address->TabIndex = 25;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Date de livraison";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"d MMMM yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(13, 35);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(162, 20);
			this->dateTimePicker1->TabIndex = 30;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(714, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(535, 553);
			this->dataGridView1->TabIndex = 31;
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
			this->tb_item_ref_search->Location = System::Drawing::Point(13, 433);
			this->tb_item_ref_search->Name = L"tb_item_ref_search";
			this->tb_item_ref_search->Size = System::Drawing::Size(100, 20);
			this->tb_item_ref_search->TabIndex = 33;
			// 
			// tb_item_name_search
			// 
			this->tb_item_name_search->Location = System::Drawing::Point(132, 433);
			this->tb_item_name_search->Name = L"tb_item_name_search";
			this->tb_item_name_search->Size = System::Drawing::Size(165, 20);
			this->tb_item_name_search->TabIndex = 34;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(129, 417);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 13);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Désignation article";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 417);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Référence article";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(15, 460);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(497, 128);
			this->dataGridView2->TabIndex = 37;
			// 
			// btn_command_search
			// 
			this->btn_command_search->Location = System::Drawing::Point(326, 430);
			this->btn_command_search->Name = L"btn_command_search";
			this->btn_command_search->Size = System::Drawing::Size(75, 23);
			this->btn_command_search->TabIndex = 38;
			this->btn_command_search->Text = L"Recherche";
			this->btn_command_search->UseVisualStyleBackColor = true;
			this->btn_command_search->Click += gcnew System::EventHandler(this, &OrderForm::btn_command_search_Click);
			// 
			// OrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1261, 600);
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
		
	}
	private: System::Void btn_command_search_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView2->Columns->Clear();
		int id = 0;
		this->dataGridView2->DataSource = gpItem->itemPreview(this->tb_item_ref_search->Text, this->tb_item_name_search->Text);
		this->dataGridView2->DataMember = "Preview";
		//auto resize column of datagridview to take all place
		for (int i = 0; i < this->dataGridView2->Columns->Count; i++) {
			this->dataGridView2->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
	}
};
}
