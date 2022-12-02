#pragma once
#include "GpCustomer.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de CustomerForm
	/// </summary>
	public ref class CustomerForm : public System::Windows::Forms::Form
	{
	public:
		CustomerForm(int mode) {
			InitializeComponent();
			this->mode = mode;
			if (this->mode == 1) {
				this->Text = L"Création d'un nouveau client";
			}
			else if (this->mode == 2) {
				this->Text = L"Affichage d'un client";
			}
			this->btn_customer_update->Hide();
			this->btn_customer_delete->Hide();
		}
		CustomerForm(int mode, int id) : CustomerForm(mode) {
			this->id = id;
			this->btn_customer_create->Hide();
			this->btn_customer_update->Show();
			this->btn_customer_delete->Show();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~CustomerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dp_customer_birth_date;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tb_customer_lname;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tb_customer_fname;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::DataGridView^ dgv_billing_address;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dp_first_purchase;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ btn_customer_delete;

	private: System::Windows::Forms::Button^ btn_customer_update;
	private: System::Windows::Forms::Button^ btn_customer_create;

	private: int mode;
	private: int id;
	private: GpCustomer^ gpCustomer = gcnew GpCustomer();
	private: System::Windows::Forms::DataGridView^ dgv_shipping_address;


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
			this->dp_customer_birth_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_customer_lname = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_customer_fname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgv_billing_address = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dp_first_purchase = (gcnew System::Windows::Forms::DateTimePicker());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btn_customer_delete = (gcnew System::Windows::Forms::Button());
			this->btn_customer_update = (gcnew System::Windows::Forms::Button());
			this->btn_customer_create = (gcnew System::Windows::Forms::Button());
			this->dgv_shipping_address = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_billing_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_shipping_address))->BeginInit();
			this->SuspendLayout();
			// 
			// dp_customer_birth_date
			// 
			this->dp_customer_birth_date->CustomFormat = L"d MMMM yyyy";
			this->dp_customer_birth_date->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dp_customer_birth_date->Location = System::Drawing::Point(32, 110);
			this->dp_customer_birth_date->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dp_customer_birth_date->MaxDate = System::DateTime(2022, 12, 2, 0, 0, 0, 0);
			this->dp_customer_birth_date->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->dp_customer_birth_date->Name = L"dp_customer_birth_date";
			this->dp_customer_birth_date->Size = System::Drawing::Size(215, 22);
			this->dp_customer_birth_date->TabIndex = 9;
			this->dp_customer_birth_date->Value = System::DateTime(2022, 12, 2, 0, 0, 0, 0);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(28, 89);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 14);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Date de naissance";
			// 
			// tb_customer_lname
			// 
			this->tb_customer_lname->Location = System::Drawing::Point(32, 43);
			this->tb_customer_lname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_customer_lname->MaxLength = 40;
			this->tb_customer_lname->Name = L"tb_customer_lname";
			this->tb_customer_lname->Size = System::Drawing::Size(132, 22);
			this->tb_customer_lname->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 25);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Nom";
			// 
			// tb_customer_fname
			// 
			this->tb_customer_fname->Location = System::Drawing::Point(195, 43);
			this->tb_customer_fname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_customer_fname->MaxLength = 40;
			this->tb_customer_fname->Name = L"tb_customer_fname";
			this->tb_customer_fname->Size = System::Drawing::Size(132, 22);
			this->tb_customer_fname->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(191, 25);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Prénom";
			// 
			// dgv_billing_address
			// 
			this->dgv_billing_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_billing_address->Location = System::Drawing::Point(387, 254);
			this->dgv_billing_address->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_billing_address->Name = L"dgv_billing_address";
			this->dgv_billing_address->RowHeadersWidth = 51;
			this->dgv_billing_address->Size = System::Drawing::Size(876, 150);
			this->dgv_billing_address->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(384, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(209, 18);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Addresse de livraison";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(384, 235);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(253, 14);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Addresse de facturation";
			// 
			// dp_first_purchase
			// 
			this->dp_first_purchase->CustomFormat = L"d MMMM yyyy";
			this->dp_first_purchase->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dp_first_purchase->Location = System::Drawing::Point(32, 171);
			this->dp_first_purchase->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dp_first_purchase->MaxDate = System::DateTime(2022, 12, 2, 0, 0, 0, 0);
			this->dp_first_purchase->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->dp_first_purchase->Name = L"dp_first_purchase";
			this->dp_first_purchase->Size = System::Drawing::Size(215, 22);
			this->dp_first_purchase->TabIndex = 15;
			this->dp_first_purchase->Value = System::DateTime(2022, 12, 2, 0, 0, 0, 0);
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(28, 151);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 16);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Date premier achat";
			// 
			// btn_customer_delete
			// 
			this->btn_customer_delete->Location = System::Drawing::Point(695, 446);
			this->btn_customer_delete->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_customer_delete->Name = L"btn_customer_delete";
			this->btn_customer_delete->Size = System::Drawing::Size(100, 28);
			this->btn_customer_delete->TabIndex = 23;
			this->btn_customer_delete->Text = L"Supprimer";
			this->btn_customer_delete->UseVisualStyleBackColor = true;
			// 
			// btn_customer_update
			// 
			this->btn_customer_update->Location = System::Drawing::Point(480, 446);
			this->btn_customer_update->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_customer_update->Name = L"btn_customer_update";
			this->btn_customer_update->Size = System::Drawing::Size(100, 28);
			this->btn_customer_update->TabIndex = 22;
			this->btn_customer_update->Text = L"Modifier";
			this->btn_customer_update->UseVisualStyleBackColor = true;
			// 
			// btn_customer_create
			// 
			this->btn_customer_create->Location = System::Drawing::Point(588, 446);
			this->btn_customer_create->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_customer_create->Name = L"btn_customer_create";
			this->btn_customer_create->Size = System::Drawing::Size(100, 28);
			this->btn_customer_create->TabIndex = 21;
			this->btn_customer_create->Text = L"Créer";
			this->btn_customer_create->UseVisualStyleBackColor = true;
			this->btn_customer_create->Click += gcnew System::EventHandler(this, &CustomerForm::btn_customer_create_Click);
			// 
			// dgv_shipping_address
			// 
			this->dgv_shipping_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_shipping_address->Location = System::Drawing::Point(387, 43);
			this->dgv_shipping_address->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_shipping_address->Name = L"dgv_shipping_address";
			this->dgv_shipping_address->RowHeadersWidth = 51;
			this->dgv_shipping_address->Size = System::Drawing::Size(876, 150);
			this->dgv_shipping_address->TabIndex = 24;
			// 
			// CustomerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1276, 485);
			this->Controls->Add(this->dgv_shipping_address);
			this->Controls->Add(this->btn_customer_delete);
			this->Controls->Add(this->btn_customer_update);
			this->Controls->Add(this->btn_customer_create);
			this->Controls->Add(this->dp_first_purchase);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgv_billing_address);
			this->Controls->Add(this->dp_customer_birth_date);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_customer_lname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_customer_fname);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CustomerForm";
			this->Text = L"CustomerForm";
			this->Load += gcnew System::EventHandler(this, &CustomerForm::CustomerForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_billing_address))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_shipping_address))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CustomerForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (this->mode == 1) {
			InitializeDataGridView();
		}
		else {
			gpCustomer->selectCustomer(this->id);
			tb_customer_lname->Text = gpCustomer->getCustomer()->getLastName();
			tb_customer_fname->Text = gpCustomer->getCustomer()->getFirstName();
			dp_customer_birth_date->Value = Convert::ToDateTime(gpCustomer->getCustomer()->getBirthDate());
			dp_first_purchase->Value = Convert::ToDateTime(gpCustomer->getCustomer()->getFirstPurchase());
			this->InitializeDataGridView();
			for (int i = 0; i < gpCustomer->getShippingAddress()->Tables[0]->Rows->Count; i++) {
				dgv_shipping_address->Rows->Add();
				dgv_shipping_address->Rows[i]->Cells[0]->Value = gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[1]->ToString();
				dgv_shipping_address->Rows[i]->Cells[1]->Value = gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[2]->ToString();
				dgv_shipping_address->Rows[i]->Cells[2]->Value = gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[3]->ToString();
				dgv_shipping_address->Rows[i]->Cells[3]->Value = gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[5]->ToString();
				dgv_shipping_address->Rows[i]->Cells[4]->Value = gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[7]->ToString();
			}
			for (int i = 0; i < gpCustomer->getBillingAddress()->Tables[0]->Rows->Count; i++) {
				dgv_billing_address->Rows->Add();
				dgv_billing_address->Rows[i]->Cells[0]->Value = gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[1]->ToString();
				dgv_billing_address->Rows[i]->Cells[1]->Value = gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[2]->ToString();
				dgv_billing_address->Rows[i]->Cells[2]->Value = gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[3]->ToString();
				dgv_billing_address->Rows[i]->Cells[3]->Value = gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[5]->ToString();
				dgv_billing_address->Rows[i]->Cells[4]->Value = gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[7]->ToString();
			}
		}
	}
	private: void InitializeDataGridView() {
		DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		column1->Name = "Adresse";
		column1->Width = 175;
		column1->MaxInputLength = 200;
		dgv_shipping_address->Columns->Add(column1);
		DataGridViewTextBoxColumn^ column2 = gcnew DataGridViewTextBoxColumn();
		column2->Name = "Adresse complémentaire";
		column2->Width = 175;
		column2->MaxInputLength = 200;
		dgv_shipping_address->Columns->Add(column2);
		DataGridViewTextBoxColumn^ column3 = gcnew DataGridViewTextBoxColumn();
		column3->Name = "Code postal";
		column3->Width = 74;
		column3->MaxInputLength = 10;
		dgv_shipping_address->Columns->Add(column3);
		DataGridViewTextBoxColumn^ column4 = gcnew DataGridViewTextBoxColumn();
		column4->Name = "Ville";
		column4->Width = 90;
		column4->MaxInputLength = 50;
		dgv_shipping_address->Columns->Add(column4);
		DataGridViewTextBoxColumn^ column5 = gcnew DataGridViewTextBoxColumn();
		column5->Name = "Pays";
		column5->Width = 90;
		column5->MaxInputLength = 50;
		dgv_shipping_address->Columns->Add(column5);

		DataGridViewTextBoxColumn^ column6 = gcnew DataGridViewTextBoxColumn();
		column6->Name = "Adresse";
		column6->Width = 175;
		column6->MaxInputLength = 200;
		dgv_billing_address->Columns->Add(column6);
		DataGridViewTextBoxColumn^ column7 = gcnew DataGridViewTextBoxColumn();
		column7->Name = "Adresse complémentaire";
		column7->Width = 175;
		column7->MaxInputLength = 200;
		dgv_billing_address->Columns->Add(column7);
		DataGridViewTextBoxColumn^ column8 = gcnew DataGridViewTextBoxColumn();
		column8->Name = "Code postal";
		column8->Width = 74;
		column8->MaxInputLength = 10;
		dgv_billing_address->Columns->Add(column8);
		DataGridViewTextBoxColumn^ column9 = gcnew DataGridViewTextBoxColumn();
		column9->Name = "Ville";
		column9->Width = 90;
		column9->MaxInputLength = 50;
		dgv_billing_address->Columns->Add(column9);
		DataGridViewTextBoxColumn^ column10 = gcnew DataGridViewTextBoxColumn();
		column10->Name = "Pays";
		column10->Width = 90;
		column10->MaxInputLength = 50;
		dgv_billing_address->Columns->Add(column10);

		delete column1;
		delete column2;
		delete column3;
		delete column4;
		delete column5;
		delete column6;
		delete column7;
		delete column8;
		delete column9;
		delete column10;
	}
	private: System::Void btn_customer_create_Click(System::Object^ sender, System::EventArgs^ e) {
		//if one textbox is empty display error
		if (tb_customer_lname->Text == "" || tb_customer_fname->Text == "" || dp_customer_birth_date->Text == "" || dgv_shipping_address->Rows->Count == 0 || dgv_billing_address->Rows->Count == 0) {
			MessageBox::Show("Veuillez remplir tous les champs", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			this->getTextBoxContent();
			gpCustomer->insertCustomer();
			MessageBox::Show("Le client a bien été ajouté", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete gpCustomer;
			this->Close();
		}
	}
	private: void getTextBoxContent() {
		gpCustomer->getCustomer()->setLastName(this->tb_customer_lname->Text);
		gpCustomer->getCustomer()->setFirstName(this->tb_customer_fname->Text);
		gpCustomer->getCustomer()->setBirthDate(this->dp_customer_birth_date->Value);
		gpCustomer->getCustomer()->setFirstPurchase(this->dp_first_purchase->Value);
		//get all the content of the datagridview and put it in the customer address dataset
		for (int i = 0; i < dgv_shipping_address->Rows->Count; i++) {
			gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[1] = dgv_shipping_address->Rows[i]->Cells[0]->Value;
			gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[2] = dgv_shipping_address->Rows[i]->Cells[1]->Value;
			gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[3] = dgv_shipping_address->Rows[i]->Cells[2]->Value;
			gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[5] = dgv_shipping_address->Rows[i]->Cells[3]->Value;
			gpCustomer->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[7] = dgv_shipping_address->Rows[i]->Cells[4]->Value;
		}
		for (int i = 0; i < dgv_billing_address->Rows->Count; i++) {
			gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[1] = dgv_billing_address->Rows[i]->Cells[0]->Value;
			gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[2] = dgv_billing_address->Rows[i]->Cells[1]->Value;
			gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[3] = dgv_billing_address->Rows[i]->Cells[2]->Value;
			gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[5] = dgv_billing_address->Rows[i]->Cells[3]->Value;
			gpCustomer->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[7] = dgv_billing_address->Rows[i]->Cells[4]->Value;
		}
	}
};
}
