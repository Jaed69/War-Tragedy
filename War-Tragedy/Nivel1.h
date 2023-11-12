#pragma once
#include "Jugador.h"
#include "Bala.h"
#include "Recursos.h"

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
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");
		Bitmap^ pisos = gcnew Bitmap("assets/Nivel/Piso2.png");
		Bitmap^ bm = gcnew Bitmap("assets/Personaje/Personaje.png");
		Jugador* jugador = new Jugador(620, 400);
		int contador;

	public:
		Nivel1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			r = Rectangle(256, 144, 768, 432);
			contador = 0;
			jugador->setRxRy(5, 5);
			jugador->setRnRl(20, 20);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Nivel1";
			this->Text = L"Nivel1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel1::Nivel1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel1::Nivel1_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Nivel1::Nivel1_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (jugador->getDashodisponible() == false) {
			contador++;
			if (contador > 5) { contador = 0; jugador->setDashodisponible(true); }
		}
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);

		Rectangle area = Rectangle(0, 0, 1280, 720);
		Rectangle zoom = Rectangle(0, 0, 1280, 720);
		buffer->Graphics->DrawImage(fondo, zoom, area, GraphicsUnit::Pixel);

		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Orange), r);
		jugador->mover(buffer, bm, r);
		jugador->moverB(buffer, bm, r);
		
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;
	}
	private: System::Void Nivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		//if (e->KeyCode == Keys::W) {
		//	if (e->KeyCode == Keys::A)
		//		jugador->setDireccion(ArrIzq);
		//	else if (e->KeyCode == Keys::D)
		//		jugador->setDireccion(ArrDer);
		//	else
		//		jugador->setDireccion(Arriba);
		//}
		//if (e->KeyCode == Keys::S) {
		//	if (e->KeyCode == Keys::A)
		//		jugador->setDireccion(AbIzq);
		//	else if (e->KeyCode == Keys::D)
		//		jugador->setDireccion(AbDer);
		//	else
		//		jugador->setDireccion(Abajo);
		//}
		//if (e->KeyCode == Keys::A)
		//	jugador->setDireccion(Izquierda);
		//if (e->KeyCode == Keys::D)
		//	jugador->setDireccion(Derecha);
		switch (e->KeyCode)
		{
		case Keys::I:jugador->disparar(100, 100); break;

		case Keys::W:jugador->setDireccion(Arriba); break;
		case Keys::A: jugador->setDireccion(Izquierda); break;
		case Keys::S: jugador->setDireccion(Abajo); break;
		case Keys::D: jugador->setDireccion(Derecha); break;
		case Keys::Space: if (jugador->getDashodisponible()) { jugador->Dash(buffer, r); jugador->setDashodisponible(false); } break;
		default:
			break;
		}
	}
	private: System::Void Nivel1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->setDireccion(Ninguna);
	}
	private: System::Void Nivel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		
		jugador->disparar(e->X, e->Y);

	}
};
}


void Dibpiso(BufferedGraphics^ bf) {

}