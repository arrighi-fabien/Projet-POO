#pragma once
#include "Payment.h"
#include "DatabaseConnection.h"
#include <math.h>

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de PaymentForm
	/// </summary>
	public ref class PaymentForm : public System::Windows::Forms::Form {
	public:
		PaymentForm(int id_order, String^ order_reference, float order_total) {
			InitializeComponent();
			this->id_order = id_order;
			this->order_reference = order_reference;
			this->order_total = order_total;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~PaymentForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_payment;
	private: System::Windows::Forms::ComboBox^ cb_payment_method;
	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ nud_payment;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tb_order_reference;


	private: int id_order = 0;
	private: String^ order_reference = "";
	private: float order_total = 0.0f;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::Button^ btn_payment_validation;




	protected:

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
			this->btn_payment = (gcnew System::Windows::Forms::Button());
			this->cb_payment_method = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nud_payment = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb_order_reference = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btn_payment_validation = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_payment))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_payment
			// 
			this->btn_payment->Location = System::Drawing::Point(63, 293);
			this->btn_payment->Name = L"btn_payment";
			this->btn_payment->Size = System::Drawing::Size(75, 23);
			this->btn_payment->TabIndex = 0;
			this->btn_payment->Text = L"Payer";
			this->btn_payment->UseVisualStyleBackColor = true;
			this->btn_payment->Click += gcnew System::EventHandler(this, &PaymentForm::btn_payment_Click);
			// 
			// cb_payment_method
			// 
			this->cb_payment_method->FormattingEnabled = true;
			this->cb_payment_method->Location = System::Drawing::Point(43, 243);
			this->cb_payment_method->Name = L"cb_payment_method";
			this->cb_payment_method->Size = System::Drawing::Size(121, 24);
			this->cb_payment_method->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 224);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Type de paiement";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Montant du paiement";
			// 
			// nud_payment
			// 
			this->nud_payment->DecimalPlaces = 2;
			this->nud_payment->Location = System::Drawing::Point(33, 187);
			this->nud_payment->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nud_payment->Name = L"nud_payment";
			this->nud_payment->Size = System::Drawing::Size(145, 22);
			this->nud_payment->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"R�f�rence commande";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridView1->Location = System::Drawing::Point(217, 57);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(562, 266);
			this->dataGridView1->TabIndex = 7;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Date";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Montant";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Moyen de paiement";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 125;
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
			this->label6->Location = System::Drawing::Point(126, 99);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"0 �";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(115, 16);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Total commande :";
			// 
			// tb_order_reference
			// 
			this->tb_order_reference->Location = System::Drawing::Point(12, 57);
			this->tb_order_reference->Name = L"tb_order_reference";
			this->tb_order_reference->ReadOnly = true;
			this->tb_order_reference->Size = System::Drawing::Size(166, 22);
			this->tb_order_reference->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(109, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"0 �";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 128);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 16);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Reste � payer :";
			// 
			// btn_payment_validation
			// 
			this->btn_payment_validation->Location = System::Drawing::Point(361, 344);
			this->btn_payment_validation->Name = L"btn_payment_validation";
			this->btn_payment_validation->Size = System::Drawing::Size(75, 23);
			this->btn_payment_validation->TabIndex = 14;
			this->btn_payment_validation->Text = L"Valider";
			this->btn_payment_validation->UseVisualStyleBackColor = true;
			this->btn_payment_validation->Click += gcnew System::EventHandler(this, &PaymentForm::btn_payment_validation_Click);
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 379);
			this->Controls->Add(this->btn_payment_validation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tb_order_reference);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nud_payment);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cb_payment_method);
			this->Controls->Add(this->btn_payment);
			this->Name = L"PaymentForm";
			this->Text = L"PaymentForm";
			this->Load += gcnew System::EventHandler(this, &PaymentForm::PaymentForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_payment))->EndInit();
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
			this->cb_payment_method->Items->Add(data->Tables[0]->Rows[i]->ItemArray[1]->ToString());
		}
		this->tb_order_reference->Text = this->order_reference;
		this->label6->Text = Convert::ToString(this->order_total + " �");
		this->updatePayment();
	}
	private: System::Void btn_payment_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->nud_payment->Value > 0 && this->cb_payment_method->Text != "") {
			this->dataGridView1->Rows->Add(DateTime::Now, this->nud_payment->Value, this->cb_payment_method->Text);
		}
		else {
			MessageBox::Show("Veuillez remplir tous les champs", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->updatePayment();
	}
	private: void updatePayment() {
		//get the total of the payment
		float total = 0;
		for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
			total += Convert::ToSingle(this->dataGridView1->Rows[i]->Cells[1]->Value);
		}
		total = roundf(total * 100) / 100;
		if (this->order_total - total < 0) {
			MessageBox::Show("Le montant pay� est sup�rieur au montant de la commande", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			total = 0;
			this->dataGridView1->Rows->RemoveAt(this->dataGridView1->Rows->Count - 1);
			this->updatePayment();
		}
		this->label4->Text = Convert::ToString(this->order_total - total) + " �";
	}
	private: System::Void btn_payment_validation_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
