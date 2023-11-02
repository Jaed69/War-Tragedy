#pragma once
#include "Jugador.h"
namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nivel1
	/// </summary>
	public ref class Nivel1 : public System::Windows::Forms::Form
	{
	private:
		Rectangle r;
		Bitmap^ bm = gcnew Bitmap("assets/Personaje/Personaje.png");
		Jugador* jugador = new Jugador(500, 100);
	public:
		Nivel1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			r = Rectangle(40, 40, 1060, 590);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Nivel1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel1::timer1_Tick);
			// 
			// Nivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1500, 750);
			this->Name = L"Nivel1";
			this->Text = L"Nivel1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel1::Nivel1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel1::Nivel1_KeyUp);
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Nivel1::Nivel1_PreviewKeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics(); 
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Orange), r);
		jugador->mover(buffer, bm, r);
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;
	}
	private: System::Void Nivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: jugador->setDireccion(Arriba); break;
		case Keys::A: jugador->setDireccion(Izquierda); break;
		case Keys::S: jugador->setDireccion(Abajo); break;
		case Keys::D: jugador->setDireccion(Derecha); break;
		default:
			break;
		}
	}
	private: System::Void Nivel1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->setDireccion(Ninguna);
	}
	private: System::Void Nivel1_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
		switch (e->KeyCode)
		{
		default:
			break;
		}
	}
	};
}
