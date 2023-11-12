#pragma once
#include "Jugador.h"
#include "GeAliados.h"
namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nivel3
	/// </summary>
	public ref class Nivel3 : public System::Windows::Forms::Form
	{
	private:
		Rectangle r;
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel3.png");
		Bitmap^ pisos = gcnew Bitmap("assets/Nivel/Piso2.png");
		Bitmap^ bm = gcnew Bitmap("assets/Personaje/Personaje.png");
		Jugador* jugador = new Jugador(620, 400);
		GeAliado* gA = new GeAliado();
	private: System::Windows::Forms::Timer^ timer1;
		   int contador;
	public:
		Nivel3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			r = Rectangle(0, 0, 1280, 720);
			contador = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Nivel3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel3::timer1_Tick);
			// 
			// Nivel3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Nivel3";
			this->Text = L"Nivel3";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel3::Nivel3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel3::Nivel3_KeyUp);
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
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;
		
		/*if (jugador->getDashodisponible() == false) {
			contador++;
			if (contador > 5) { contador = 0; jugador->setDashodisponible(true); }
		}
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);

		Rectangle area = Rectangle(0, 0, 384, 216);
		Rectangle zoom = Rectangle(0, 0, 1280, 720);
		buffer->Graphics->DrawImage(fondo, zoom, area, GraphicsUnit::Pixel);


		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Orange), r);
		jugador->mover(buffer, bm, r);
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;*/
	}
	private: System::Void Nivel3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		switch (e->KeyCode)
		{
		case Keys::W:jugador->setDireccion(Arriba); break;
		case Keys::A: jugador->setDireccion(Izquierda); break;
		case Keys::S: jugador->setDireccion(Abajo); break;
		case Keys::D: jugador->setDireccion(Derecha); break;
		case Keys::Space: if (jugador->getDashodisponible()) { jugador->Dash(buffer, r); jugador->setDashodisponible(false); } break;
		default:
			break;
		}
	}
	private: System::Void Nivel3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->setDireccion(Ninguna);
	}
	
	};
}
