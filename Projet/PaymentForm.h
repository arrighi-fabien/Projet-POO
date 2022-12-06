#pragma once
#include "Payment.h"
#include "DatabaseConnection.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PaymentForm
	/// </summary>
	public ref class PaymentForm : public System::Windows::Forms::Form {
	public:
		PaymentForm(int id_order, String^ order_reference) {
			InitializeComponent();
			this->id_order = id_order;
			this->order_reference = order_reference;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PaymentForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tb_order_reference;


	private: int id_order = 0;
	private: String^ order_reference = "";
		
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
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb_order_reference = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Payer";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(43, 232);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Type de paiement";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Montant du paiement";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Location = System::Drawing::Point(33, 176);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(145, 22);
			this->numericUpDown1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Référence commande";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(217, 57);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(395, 266);
			this->dataGridView1->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(214, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Liste paiement";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(109, 117);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"0 €";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 117);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(98, 16);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Reste à payer :";
			// 
			// tb_order_reference
			// 
			this->tb_order_reference->Location = System::Drawing::Point(12, 57);
			this->tb_order_reference->Name = L"tb_order_reference";
			this->tb_order_reference->ReadOnly = true;
			this->tb_order_reference->Size = System::Drawing::Size(166, 22);
			this->tb_order_reference->TabIndex = 11;
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 335);
			this->Controls->Add(this->tb_order_reference);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Name = L"PaymentForm";
			this->Text = L"PaymentForm";
			this->Load += gcnew System::EventHandler(this, &PaymentForm::PaymentForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PaymentForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Payment^ payment = gcnew Payment();
		DatabaseConnection^ db = gcnew DatabaseConnection();
		DataSet^ data = payment->getPaymentMethods(db);
		delete db;
		for (int i = data->Tables[0]->Rows->Count - 1; i >= 0; i--) {
			this->comboBox1->Items->Add(data->Tables[0]->Rows[i]->ItemArray[1]->ToString());
		}
		this->tb_order_reference->Text = this->order_reference;
	}
};
}
