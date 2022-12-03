#pragma once
#include "GpItem.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ItemForm
	/// </summary>
	public ref class ItemForm : public System::Windows::Forms::Form
	{
	public:
		ItemForm(int mode) {
			InitializeComponent();
			this->mode = mode;
			if (this->mode == 1) {
				this->Text = L"Création d'un article";
			}
			else if (this->mode == 2) {
				this->Text = L"Affichage d'un article";
			}
			this->btn_item_update->Hide();
			this->btn_item_delete->Hide();
		}
		ItemForm(int mode, String^ ref) : ItemForm(mode) {
			this->ref = ref;
			this->btn_item_create->Hide();
			this->btn_item_update->Show();
			this->btn_item_delete->Show();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ItemForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tb_item_ref;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tb_item_name;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ nud_item_stock;
	private: System::Windows::Forms::NumericUpDown^ nud_item_restocking;
	private: System::Windows::Forms::DataGridView^ dgv_price_history;




	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ nud_item_price;
	private: System::Windows::Forms::NumericUpDown^ nud_item_vat;



	private: GpItem^ gpItem = gcnew GpItem();
	private: int mode;
	private: String^ ref;
	private: bool price_change = false;
	private: bool is_valid = false;
		
	private: System::Windows::Forms::Button^ btn_item_delete;

	private: System::Windows::Forms::Button^ btn_item_update;
	private: System::Windows::Forms::Button^ btn_item_create;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label8;



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
			this->tb_item_ref = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_item_name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nud_item_stock = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_item_restocking = (gcnew System::Windows::Forms::NumericUpDown());
			this->dgv_price_history = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nud_item_price = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_item_vat = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_item_delete = (gcnew System::Windows::Forms::Button());
			this->btn_item_update = (gcnew System::Windows::Forms::Button());
			this->btn_item_create = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_stock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_restocking))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_price_history))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_price))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_vat))->BeginInit();
			this->SuspendLayout();
			// 
			// tb_item_ref
			// 
			this->tb_item_ref->Location = System::Drawing::Point(24, 36);
			this->tb_item_ref->MaxLength = 40;
			this->tb_item_ref->Name = L"tb_item_ref";
			this->tb_item_ref->Size = System::Drawing::Size(100, 20);
			this->tb_item_ref->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Référence";
			// 
			// tb_item_name
			// 
			this->tb_item_name->Location = System::Drawing::Point(146, 36);
			this->tb_item_name->MaxLength = 40;
			this->tb_item_name->Name = L"tb_item_name";
			this->tb_item_name->Size = System::Drawing::Size(100, 20);
			this->tb_item_name->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(143, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Désignation";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Prix HT";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(143, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Taux TVA";
			// 
			// nud_item_stock
			// 
			this->nud_item_stock->Location = System::Drawing::Point(24, 188);
			this->nud_item_stock->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->nud_item_stock->Name = L"nud_item_stock";
			this->nud_item_stock->Size = System::Drawing::Size(120, 20);
			this->nud_item_stock->TabIndex = 11;
			// 
			// nud_item_restocking
			// 
			this->nud_item_restocking->Location = System::Drawing::Point(24, 245);
			this->nud_item_restocking->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->nud_item_restocking->Name = L"nud_item_restocking";
			this->nud_item_restocking->Size = System::Drawing::Size(120, 20);
			this->nud_item_restocking->TabIndex = 12;
			// 
			// dgv_price_history
			// 
			this->dgv_price_history->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_price_history->Location = System::Drawing::Point(272, 36);
			this->dgv_price_history->Name = L"dgv_price_history";
			this->dgv_price_history->ReadOnly = true;
			this->dgv_price_history->Size = System::Drawing::Size(344, 213);
			this->dgv_price_history->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(269, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Historique prix";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 172);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"En stock";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 229);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(140, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Seuil de réaprovisionnement";
			// 
			// nud_item_price
			// 
			this->nud_item_price->DecimalPlaces = 2;
			this->nud_item_price->Location = System::Drawing::Point(24, 80);
			this->nud_item_price->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->nud_item_price->Name = L"nud_item_price";
			this->nud_item_price->Size = System::Drawing::Size(100, 20);
			this->nud_item_price->TabIndex = 17;
			// 
			// nud_item_vat
			// 
			this->nud_item_vat->DecimalPlaces = 2;
			this->nud_item_vat->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->nud_item_vat->Location = System::Drawing::Point(146, 80);
			this->nud_item_vat->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->nud_item_vat->Name = L"nud_item_vat";
			this->nud_item_vat->Size = System::Drawing::Size(100, 20);
			this->nud_item_vat->TabIndex = 18;
			// 
			// btn_item_delete
			// 
			this->btn_item_delete->Location = System::Drawing::Point(353, 277);
			this->btn_item_delete->Margin = System::Windows::Forms::Padding(2);
			this->btn_item_delete->Name = L"btn_item_delete";
			this->btn_item_delete->Size = System::Drawing::Size(82, 23);
			this->btn_item_delete->TabIndex = 23;
			this->btn_item_delete->Text = L"Supprimer";
			this->btn_item_delete->UseVisualStyleBackColor = true;
			this->btn_item_delete->Click += gcnew System::EventHandler(this, &ItemForm::btn_item_delete_Click);
			// 
			// btn_item_update
			// 
			this->btn_item_update->Location = System::Drawing::Point(192, 277);
			this->btn_item_update->Margin = System::Windows::Forms::Padding(2);
			this->btn_item_update->Name = L"btn_item_update";
			this->btn_item_update->Size = System::Drawing::Size(82, 23);
			this->btn_item_update->TabIndex = 22;
			this->btn_item_update->Text = L"Modifier";
			this->btn_item_update->UseVisualStyleBackColor = true;
			this->btn_item_update->Click += gcnew System::EventHandler(this, &ItemForm::btn_item_update_Click);
			// 
			// btn_item_create
			// 
			this->btn_item_create->Location = System::Drawing::Point(273, 277);
			this->btn_item_create->Name = L"btn_item_create";
			this->btn_item_create->Size = System::Drawing::Size(82, 23);
			this->btn_item_create->TabIndex = 21;
			this->btn_item_create->Text = L"Créer";
			this->btn_item_create->UseVisualStyleBackColor = true;
			this->btn_item_create->Click += gcnew System::EventHandler(this, &ItemForm::btn_item_create_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(24, 126);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(102, 13);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Catégorie de l\'article";
			// 
			// ItemForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 312);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->btn_item_delete);
			this->Controls->Add(this->btn_item_update);
			this->Controls->Add(this->btn_item_create);
			this->Controls->Add(this->nud_item_vat);
			this->Controls->Add(this->nud_item_price);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dgv_price_history);
			this->Controls->Add(this->nud_item_restocking);
			this->Controls->Add(this->nud_item_stock);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tb_item_ref);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_item_name);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ItemForm";
			this->Text = L"ItemForm";
			this->Load += gcnew System::EventHandler(this, &ItemForm::ItemForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_stock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_restocking))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_price_history))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_price))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_item_vat))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ItemForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//for element in gpItem->itemCategory() add to combobox
		DataSet^ data = gpItem->itemCategory();
		for (int i = data->Tables[0]->Rows->Count - 1; i >= 0; i--) {
			this->comboBox1->Items->Add(data->Tables[0]->Rows[i]->ItemArray[1]->ToString());
		}
		if (this->mode == 2) {
			gpItem->selectItem(this->ref);
			this->tb_item_ref->Text = gpItem->getItem()->getItemReference();
			this->tb_item_name->Text = gpItem->getItem()->getItemName();
			this->nud_item_price->Value = (Decimal)gpItem->getItemPrice()->getItemPriceEt();
			this->nud_item_vat->Value = (Decimal)gpItem->getItemPrice()->getVatRate();
			this->nud_item_stock->Value = gpItem->getItem()->getInStock();
			this->nud_item_restocking->Value = gpItem->getItem()->getRestockingLevel();
			this->dgv_price_history->DataSource = gpItem->priceHistory();
			this->dgv_price_history->DataMember = "ItemPriceHistory";
			
			// select the item category
			this->comboBox1->SelectedIndex = gpItem->getItem()->getIdItemCategory() - 1;
		}
	}
	private: System::Void btn_item_create_Click(System::Object^ sender, System::EventArgs^ e) {
		this->getBoxContent();
		if (this->is_valid) {
			gpItem->insertItem();
			MessageBox::Show("L'article a bien été ajouté", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete gpItem;
			this->Close();
		}
	}
	private: System::Void btn_item_update_Click(System::Object^ sender, System::EventArgs^ e) {
		this->getBoxContent();
		if (this->is_valid == true && MessageBox::Show("Voulez-vous vraiment appliquer les modifications ?", "Modification", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			gpItem->updateItem(this->price_change);
			MessageBox::Show("L'article a bien été modifié", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete gpItem;
			this->Close();
		}
	}
	private: System::Void btn_item_delete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Voulez-vous vraiment supprimer cet article ?", "Suppression", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			gpItem->deleteItem();
			MessageBox::Show("L'article a bien été supprimé", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete gpItem;
			this->Close();
		}
	}
	private: void getBoxContent() {
		price_change = false;
		if (this->tb_item_ref->Text == "") {
			MessageBox::Show("Veuillez entrer une référence", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			if (this->tb_item_name->Text == "") {
				MessageBox::Show("Veuillez entrer un nom", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				if (((float)this->nud_item_price->Value == 0) || ((float)this->nud_item_vat->Value == 0)) {
					MessageBox::Show("Le prix HT et la TVA ne peuvent pas être égale à 0", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					if (this->comboBox1->Text == "") {
						MessageBox::Show("Veuillez selectionner une catégorie", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else {
						this->is_valid = true;
						gpItem->getItem()->setItemReference(this->tb_item_ref->Text);
						gpItem->getItem()->setItemName(this->tb_item_name->Text);
						gpItem->getItem()->setItemCategoryName(this->comboBox1->Text);
						if ((gpItem->getItemPrice()->getItemPriceEt() != (float)this->nud_item_price->Value) || (gpItem->getItemPrice()->getVatRate() != (float)this->nud_item_vat->Value)) {
							price_change = true;
						}
						gpItem->getItemPrice()->setItemPriceEt((float)this->nud_item_price->Value);
						gpItem->getItemPrice()->setVatRate((float)this->nud_item_vat->Value);
						gpItem->getItem()->setInStock((int)this->nud_item_stock->Value);
						gpItem->getItem()->setRestockingLevel((int)this->nud_item_restocking->Value);
					}
				}
			}
		}
	}
};
}
