#pragma once
#include "Juego.h"
#include "Archivo.h"

namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Pausa
	/// </summary>
	public ref class Pausa : public System::Windows::Forms::Form
	{
	private:
		Juego* ju;
		Archivo* arch = new Archivo;
		bool salir = false;

		   bool restart = false;

	public:
		void setDatos(Juego* jg) { ju = jg; }
		bool getSalir() { return salir; }
		bool getRest() { return restart; }

		Pausa(void)
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
		~Pausa()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Restart;
	private: System::Windows::Forms::Button^ Exit;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pausa::typeid));
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Restart = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Save
			// 
			this->Save->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Save->BackColor = System::Drawing::Color::Transparent;
			this->Save->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save.BackgroundImage")));
			this->Save->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Save->Location = System::Drawing::Point(52, 52);
			this->Save->Margin = System::Windows::Forms::Padding(0);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(40, 40);
			this->Save->TabIndex = 0;
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Pausa::Save_Click);
			// 
			// Restart
			// 
			this->Restart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Restart.BackgroundImage")));
			this->Restart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Restart->Location = System::Drawing::Point(52, 105);
			this->Restart->Name = L"Restart";
			this->Restart->Size = System::Drawing::Size(40, 40);
			this->Restart->TabIndex = 1;
			this->Restart->UseVisualStyleBackColor = true;
			this->Restart->Click += gcnew System::EventHandler(this, &Pausa::Restart_Click);
			// 
			// Exit
			// 
			this->Exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Exit.BackgroundImage")));
			this->Exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Exit->Location = System::Drawing::Point(52, 158);
			this->Exit->Margin = System::Windows::Forms::Padding(0);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(40, 40);
			this->Exit->TabIndex = 2;
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &Pausa::Exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(98, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 38);
			this->label1->TabIndex = 3;
			this->label1->Text = L"GUARDAR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(98, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 38);
			this->label2->TabIndex = 4;
			this->label2->Text = L"REINICIAR";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Black", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(124, 160);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 38);
			this->label3->TabIndex = 5;
			this->label3->Text = L"SALIR";
			// 
			// Pausa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->Restart);
			this->Controls->Add(this->Save);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Pausa";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pausa";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Restart_Click(System::Object^ sender, System::EventArgs^ e) {
		restart = true;
		this->Close();
	}
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
		arch->save(ju);
	}
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
		salir = true;
		this->Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	arch->load(ju);
}
};
}
