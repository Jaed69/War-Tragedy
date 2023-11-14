#pragma once

#include "Entorno.h"

namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnNivel3;
	protected:

	protected:
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNivel1
			// 
			this->btnNivel1->Location = System::Drawing::Point(76, 48);
			this->btnNivel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(56, 19);
			this->btnNivel1->TabIndex = 0;
			this->btnNivel1->Text = L"Nivel1";
			this->btnNivel1->UseVisualStyleBackColor = true;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &MyForm::btnNivel1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->Location = System::Drawing::Point(76, 88);
			this->btnNivel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(56, 19);
			this->btnNivel2->TabIndex = 1;
			this->btnNivel2->Text = L"Nivel2";
			this->btnNivel2->UseVisualStyleBackColor = true;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &MyForm::btnNivel2_Click);
			// 
			// btnNivel3
			// 
			this->btnNivel3->Location = System::Drawing::Point(76, 131);
			this->btnNivel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnNivel3->Name = L"btnNivel3";
			this->btnNivel3->Size = System::Drawing::Size(56, 19);
			this->btnNivel3->TabIndex = 2;
			this->btnNivel3->Text = L"Nivel3";
			this->btnNivel3->UseVisualStyleBackColor = true;
			this->btnNivel3->Click += gcnew System::EventHandler(this, &MyForm::btnNivel3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->btnNivel3);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->btnNivel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NTejado);
		juego->ShowDialog();
		delete juego;

	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NEdificio);
		juego->ShowDialog();
		delete juego;
	}
	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NPrado);
		juego->ShowDialog();
		delete juego;
	}
	};
}
