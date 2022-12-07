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
	/// Description résumée de PaymentForm
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
		/// Nettoyage des ressources utilisées.
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::Button^ btn_payment_validation;




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
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->btn_payment->Location = System::Drawing::Point(47, 238);
			this->btn_payment->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_payment->Name = L"btn_payment";
			this->btn_payment->Size = System::Drawing::Size(56, 24);
			this->btn_payment->TabIndex = 0;
			this->btn_payment->Text = L"Payer";
			this->btn_payment->UseVisualStyleBackColor = true;
			this->btn_payment->Click += gcnew System::EventHandler(this, &PaymentForm::btn_payment_Click);
			// 
			// cb_payment_method
			// 
			this->cb_payment_method->FormattingEnabled = true;
			this->cb_payment_method->Location = System::Drawing::Point(32, 197);
			this->cb_payment_method->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cb_payment_method->Name = L"cb_payment_method";
			this->cb_payment_method->Size = System::Drawing::Size(92, 21);
			this->cb_payment_method->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 182);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Type de paiement";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 136);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Montant du paiement";
			// 
			// nud_payment
			// 
			this->nud_payment->DecimalPlaces = 2;
			this->nud_payment->Location = System::Drawing::Point(25, 152);
			this->nud_payment->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->nud_payment->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nud_payment->Name = L"nud_payment";
			this->nud_payment->Size = System::Drawing::Size(109, 20);
			this->nud_payment->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 31);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Référence commande";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4
			});
			this->dataGridView1->Location = System::Drawing::Point(163, 46);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(422, 216);
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
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"id_payment";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(160, 31);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Liste paiement";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(94, 80);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(22, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"0 €";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 80);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(92, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Total commande :";
			// 
			// tb_order_reference
			// 
			this->tb_order_reference->Location = System::Drawing::Point(9, 46);
			this->tb_order_reference->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tb_order_reference->Name = L"tb_order_reference";
			this->tb_order_reference->ReadOnly = true;
			this->tb_order_reference->Size = System::Drawing::Size(126, 20);
			this->tb_order_reference->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(82, 104);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(22, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"0 €";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 104);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Reste à payer :";
			// 
			// btn_payment_validation
			// 
			this->btn_payment_validation->Location = System::Drawing::Point(271, 275);
			this->btn_payment_validation->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_payment_validation->Name = L"btn_payment_validation";
			this->btn_payment_validation->Size = System::Drawing::Size(56, 24);
			this->btn_payment_validation->TabIndex = 14;
			this->btn_payment_validation->Text = L"Valider";
			this->btn_payment_validation->UseVisualStyleBackColor = true;
			this->btn_payment_validation->Click += gcnew System::EventHandler(this, &PaymentForm::btn_payment_validation_Click);
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(598, 308);
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
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
		for (int i = data->Tables[0]->Rows->Count - 1; i >= 0; i--) {
			this->cb_payment_method->Items->Add(data->Tables[0]->Rows[i]->ItemArray[1]->ToString());
		}
		this->tb_order_reference->Text = this->order_reference;
		this->label6->Text = Convert::ToString(this->order_total + " €");
		DataSet^ data2 = payment->getPayments(db, this->id_order);
		//fill the datagridview with the payments with for loop
		for (int i = data2->Tables[0]->Rows->Count - 1; i >= 0; i--) {
			this->dataGridView1->Rows->Add(data2->Tables[0]->Rows[i]->ItemArray[0]->ToString(), data2->Tables[0]->Rows[i]->ItemArray[1]->ToString(), data2->Tables[0]->Rows[i]->ItemArray[2]->ToString(), data2->Tables[0]->Rows[i]->ItemArray[3]->ToString());
		}
		delete db;
		this->updatePayment();
		delete payment;
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
			MessageBox::Show("Le montant payé est supérieur au montant de la commande", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			total = 0;
			this->dataGridView1->Rows->RemoveAt(this->dataGridView1->Rows->Count - 1);
			this->updatePayment();
		}
		this->label4->Text = Convert::ToString(this->order_total - total) + " €";
	}
	private: System::Void btn_payment_validation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->Rows->Count > 0) {
			DataSet^ data = gcnew DataSet();
			DataTable^ table = gcnew DataTable();
			table->Columns->Add("date", DateTime::typeid);
			table->Columns->Add("amount", float::typeid);
			table->Columns->Add("payment_method", String::typeid);
			table->Columns->Add("id_payment", int::typeid);
			for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
				table->Rows->Add(this->dataGridView1->Rows[i]->Cells[0]->Value, this->dataGridView1->Rows[i]->Cells[1]->Value, this->dataGridView1->Rows[i]->Cells[2]->Value, this->dataGridView1->Rows[i]->Cells[3]->Value);
			}
			data->Tables->Add(table);
			Payment^ payment = gcnew Payment();
			payment->savePayment(this->id_order, data);
			delete payment;
			MessageBox::Show("Le paiement a bien été enregistré", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			MessageBox::Show("Veuillez effectuer un paiement pour valider", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
