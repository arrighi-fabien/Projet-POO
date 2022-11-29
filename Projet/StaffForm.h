#pragma once
#include "DatabaseConnection.h"
#include "Staff.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Description résumée de StaffForm
	/// </summary>
	public ref class StaffForm : public System::Windows::Forms::Form
	{
	public:
		StaffForm(int mode) {
			InitializeComponent();
			this->mode = mode;
			if (this->mode == 1) {
				this->Text = L"Création d'un nouveau membre du personnel";
			}
			else if (this->mode == 2) {
				this->Text = L"Affichage d'un membre du personnel";
			}
			this->btn_staff_update->Hide();
			this->btn_staff_delete->Hide();
		}
		StaffForm(int mode, int id) : StaffForm(mode) {
			this->id = id;
			this->btn_staff_create->Hide();
			this->btn_staff_update->Show();
			this->btn_staff_delete->Show();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~StaffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_staff_fname;
	protected:

	private: System::Windows::Forms::TextBox^ tb_staff_lname;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tb_staff_address_o;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tb_staff_postal_code;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tb_staff_address;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tb_staff_city;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tb_staff_country;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DateTimePicker^ dp_staff_hiring_date;
	private: System::Windows::Forms::Button^ btn_staff_create;


	private: System::Windows::Forms::TextBox^ tb_manager;
	private: System::Windows::Forms::Label^ label9;

	private: Staff^ staff = gcnew Staff();
	private: int mode;
	private: int id;
	private: System::Windows::Forms::Button^ btn_staff_update;

	private: System::Windows::Forms::Button^ btn_staff_delete;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_fname = (gcnew System::Windows::Forms::TextBox());
			this->tb_staff_lname = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_address_o = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_postal_code = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_address = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_city = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb_staff_country = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dp_staff_hiring_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->btn_staff_create = (gcnew System::Windows::Forms::Button());
			this->tb_manager = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->btn_staff_update = (gcnew System::Windows::Forms::Button());
			this->btn_staff_delete = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(143, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Prénom";
			// 
			// tb_staff_fname
			// 
			this->tb_staff_fname->Location = System::Drawing::Point(146, 36);
			this->tb_staff_fname->MaxLength = 40;
			this->tb_staff_fname->Name = L"tb_staff_fname";
			this->tb_staff_fname->Size = System::Drawing::Size(100, 20);
			this->tb_staff_fname->TabIndex = 2;
			// 
			// tb_staff_lname
			// 
			this->tb_staff_lname->Location = System::Drawing::Point(24, 36);
			this->tb_staff_lname->MaxLength = 40;
			this->tb_staff_lname->Name = L"tb_staff_lname";
			this->tb_staff_lname->Size = System::Drawing::Size(100, 20);
			this->tb_staff_lname->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nom";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Date d\'embauche";
			// 
			// tb_staff_address_o
			// 
			this->tb_staff_address_o->Location = System::Drawing::Point(275, 76);
			this->tb_staff_address_o->MaxLength = 200;
			this->tb_staff_address_o->Name = L"tb_staff_address_o";
			this->tb_staff_address_o->Size = System::Drawing::Size(222, 20);
			this->tb_staff_address_o->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(272, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(157, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Complément adresse (optionnel)";
			// 
			// tb_staff_postal_code
			// 
			this->tb_staff_postal_code->Location = System::Drawing::Point(397, 118);
			this->tb_staff_postal_code->MaxLength = 10;
			this->tb_staff_postal_code->Name = L"tb_staff_postal_code";
			this->tb_staff_postal_code->Size = System::Drawing::Size(100, 20);
			this->tb_staff_postal_code->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(394, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Code postal";
			// 
			// tb_staff_address
			// 
			this->tb_staff_address->Location = System::Drawing::Point(275, 35);
			this->tb_staff_address->MaxLength = 200;
			this->tb_staff_address->Name = L"tb_staff_address";
			this->tb_staff_address->Size = System::Drawing::Size(222, 20);
			this->tb_staff_address->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(272, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Adresse";
			// 
			// tb_staff_city
			// 
			this->tb_staff_city->Location = System::Drawing::Point(275, 118);
			this->tb_staff_city->MaxLength = 50;
			this->tb_staff_city->Name = L"tb_staff_city";
			this->tb_staff_city->Size = System::Drawing::Size(100, 20);
			this->tb_staff_city->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(272, 102);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Ville";
			// 
			// tb_staff_country
			// 
			this->tb_staff_country->Location = System::Drawing::Point(275, 164);
			this->tb_staff_country->MaxLength = 50;
			this->tb_staff_country->Name = L"tb_staff_country";
			this->tb_staff_country->Size = System::Drawing::Size(100, 20);
			this->tb_staff_country->TabIndex = 9;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(272, 148);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Pays";
			// 
			// dp_staff_hiring_date
			// 
			this->dp_staff_hiring_date->CustomFormat = L"d MMMM yyyy";
			this->dp_staff_hiring_date->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dp_staff_hiring_date->Location = System::Drawing::Point(24, 89);
			this->dp_staff_hiring_date->MaxDate = System::DateTime(2050, 12, 31, 0, 0, 0, 0);
			this->dp_staff_hiring_date->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->dp_staff_hiring_date->Name = L"dp_staff_hiring_date";
			this->dp_staff_hiring_date->Size = System::Drawing::Size(162, 20);
			this->dp_staff_hiring_date->TabIndex = 3;
			// 
			// btn_staff_create
			// 
			this->btn_staff_create->Location = System::Drawing::Point(223, 212);
			this->btn_staff_create->Name = L"btn_staff_create";
			this->btn_staff_create->Size = System::Drawing::Size(75, 23);
			this->btn_staff_create->TabIndex = 10;
			this->btn_staff_create->Text = L"Créer";
			this->btn_staff_create->UseVisualStyleBackColor = true;
			this->btn_staff_create->Click += gcnew System::EventHandler(this, &StaffForm::btn_staff_create_Click);
			// 
			// tb_manager
			// 
			this->tb_manager->Location = System::Drawing::Point(24, 141);
			this->tb_manager->MaxLength = 40;
			this->tb_manager->Name = L"tb_manager";
			this->tb_manager->Size = System::Drawing::Size(100, 20);
			this->tb_manager->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(21, 125);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(113, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Supérieur hiérarchique";
			// 
			// btn_staff_update
			// 
			this->btn_staff_update->Location = System::Drawing::Point(142, 212);
			this->btn_staff_update->Margin = System::Windows::Forms::Padding(2);
			this->btn_staff_update->Name = L"btn_staff_update";
			this->btn_staff_update->Size = System::Drawing::Size(75, 23);
			this->btn_staff_update->TabIndex = 19;
			this->btn_staff_update->Text = L"Modifier";
			this->btn_staff_update->UseVisualStyleBackColor = true;
			this->btn_staff_update->Click += gcnew System::EventHandler(this, &StaffForm::btn_staff_update_Click);
			// 
			// btn_staff_delete
			// 
			this->btn_staff_delete->Location = System::Drawing::Point(303, 212);
			this->btn_staff_delete->Margin = System::Windows::Forms::Padding(2);
			this->btn_staff_delete->Name = L"btn_staff_delete";
			this->btn_staff_delete->Size = System::Drawing::Size(75, 23);
			this->btn_staff_delete->TabIndex = 20;
			this->btn_staff_delete->Text = L"Supprimer";
			this->btn_staff_delete->UseVisualStyleBackColor = true;
			this->btn_staff_delete->Click += gcnew System::EventHandler(this, &StaffForm::btn_staff_delete_Click);
			// 
			// StaffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 247);
			this->Controls->Add(this->btn_staff_delete);
			this->Controls->Add(this->btn_staff_update);
			this->Controls->Add(this->tb_manager);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->btn_staff_create);
			this->Controls->Add(this->dp_staff_hiring_date);
			this->Controls->Add(this->tb_staff_country);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tb_staff_city);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tb_staff_address);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tb_staff_postal_code);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tb_staff_address_o);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_staff_lname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_staff_fname);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StaffForm";
			this->Load += gcnew System::EventHandler(this, &StaffForm::StaffForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StaffForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (this->mode == 2) {
			staff->selectStaff(this->id);
			tb_staff_lname->Text = staff->getLastName();
			tb_staff_fname->Text = staff->getFirstName();
			dp_staff_hiring_date->Value = Convert::ToDateTime(staff->getHiringDate());
			tb_manager->Text = Convert::ToString(staff->getIdManager());
			tb_staff_address->Text = staff->getAddress();
			tb_staff_address_o->Text = staff->getAddressO();
			tb_staff_postal_code->Text = staff->getPostalCode();
			tb_staff_city->Text = staff->getCity();
			tb_staff_country->Text = staff->getCountry();
		}
	}
	private: System::Void btn_staff_create_Click(System::Object^ sender, System::EventArgs^ e) {
		//if one textbox is empty display error
		if (tb_staff_lname->Text == "" || tb_staff_fname->Text == "" || tb_staff_address->Text == "" || tb_staff_postal_code->Text == "" || tb_staff_city->Text == "" || tb_staff_country->Text == "") {
			MessageBox::Show("Veuillez remplir tous les champs", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			//if the date is not valid display error
			if (dp_staff_hiring_date->Value > DateTime::Now) {
				MessageBox::Show("La date d'embauche n\'est pas valide", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				//if the postal code is not valid display error
				if (!Regex::IsMatch(tb_staff_postal_code->Text, "^[0-9]{5}$")) {
					MessageBox::Show("Le code postal n\'est pas valide", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					//if the city is not valid display error
					if (!Regex::IsMatch(tb_staff_city->Text, "^[a-zA-Z]+$")) {
						MessageBox::Show("La ville n\'est pas valide", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else {
						//if the country is not valid display error
						if (!Regex::IsMatch(tb_staff_country->Text, "^[a-zA-Z]+$")) {
							MessageBox::Show("Le pays n\'est pas valide", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
						else {
							//if all the fields are valid create the staff
							this->getTextBoxContent();
							staff->insertStaff();
							MessageBox::Show("Le personnel a bien été ajouté", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
							delete staff;
							this->Close();
						}
					}
				}
			}
		}
	}
	private: System::Void btn_staff_update_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Voulez-vous vraiment appliquer les modifications ?", "Modification", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->getTextBoxContent();
			staff->updateStaff();
			MessageBox::Show("Le personnel a bien été modifié", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete staff;
			this->Close();
		}
	}
	private: System::Void btn_staff_delete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Voulez-vous vraiment supprimer ce personnel ?", "Suppression", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			staff->deleteStaff();
			MessageBox::Show("Le personnel a bien été supprimé", "Succès", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete staff;
			this->Close();
		}
	}
	void getTextBoxContent() {
		staff->setLastName(tb_staff_lname->Text);
		staff->setFirstName(tb_staff_fname->Text);
		staff->setHiringDate(dp_staff_hiring_date->Value);
		if (tb_manager->Text != "") {
			staff->setIdManager(Convert::ToInt32(tb_manager->Text));
		}
		else {
			staff->setIdManager(0);
		}
		staff->setAddress(tb_staff_address->Text);
		staff->setAddressO(tb_staff_address_o->Text);
		staff->setPostalCode(tb_staff_postal_code->Text);
		staff->setCity(tb_staff_city->Text);
		staff->setCountry(tb_staff_country->Text);
	}
};
}