#pragma once
#include "Jugador.h"
#include "Avion.h"
#include "Helicoptero.h"
#include "GeAliados.h"
#include "GeEnemigos.h"
namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	private:
		Rectangle r;
		Rectangle r2;

		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel2.png");
		
		
		
		
		Jugador* jugador = new Jugador(620, 400);
		Avion* avion;
		GeAliado* gA = new GeAliado();
		GeEnemigos* gE = new GeEnemigos();
		   Helicoptero* heli;
		   int contador;
	public:
		Nivel2(void)
		{
			InitializeComponent();
			Graphics^ g = this->CreateGraphics();
			//
			//TODO: Add the constructor code here
			//
			//r = Rectangle(240, 130, 800, 450);
			r = Rectangle(256, 176, 768, 432);
			r2 = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
			contador = 0;
			Random r;
			int x = r.Next(1, g->VisibleClipBounds.Width - 40);
			int y = r.Next(1, g->VisibleClipBounds.Width - 40);
			heli = new Helicoptero(x);
			avion = new Avion(r.Next(200, g->VisibleClipBounds.Width - 230), 0);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Nivel2()
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Nivel2";
			this->Text = L"Nivel2";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Nivel2::Nivel2_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (jugador->getDash() == false) {
			contador++;
			if (contador > 5) { contador = 0; jugador->setDash(true); }
		}
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);

		Rectangle area = Rectangle(0, 0, 1280, 720);
		Rectangle zoom = Rectangle(0, 0, 1280, 720);
		buffer->Graphics->DrawImage(fondo, zoom, area, GraphicsUnit::Pixel);
	

		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Orange), r);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Orange), r2);
		jugador->mover(buffer, r);
		avion->mover(buffer, r2);
		jugador->moverB(buffer, r2);
		gA->moverMono(buffer, r, r2, heli->getx(), heli->gety());
		gA->moverAvion(buffer, r, r2);
		heli->mover(buffer, r2);
		gA->sumCont();
		buffer->Render(g);




		delete buffer; delete espacioBuffer; delete g;

		/*if (jugador->getDash() == false) {
			contador++;
			if (contador > 5) { contador = 0; jugador->setDash(true); }
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
	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:jugador->setDireccion(Arriba); break;
		case Keys::A: jugador->setDireccion(Izquierda); break;
		case Keys::S: jugador->setDireccion(Abajo); break;
		case Keys::D: jugador->setDireccion(Derecha); break;
		case Keys::Space: if (jugador->getDash()) { jugador->setDireccion(Dash); jugador->setDash(false); } break;
		default:
			break;
		}
	}
	private: System::Void Nivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->setDireccion(Ninguna);
	}
	private: System::Void Nivel2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		switch (e->KeyChar.ToUpper(e->KeyChar))
		{
		case 'M': gA->crearmono(); break;
		case 'V':gA->crearAvion(); break;
		default:
			break;
		}

	}
	};
}
