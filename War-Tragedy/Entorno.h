#pragma once

#include "Pausa.h"
#include "Juego.h"

namespace WarTragedy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Entorno
	/// </summary>
	public ref class Entorno : public System::Windows::Forms::Form
	{
	private:
		Juego* Jg = new Juego();
		Niveles nivel = NTejado;
		Niveles nivelAct;
		Pausa^ pausa;
		SoundPlayer^ abrir = gcnew SoundPlayer("assets/UI/Abrir.wav");
		SoundPlayer^ cerrar = gcnew SoundPlayer("assets/UI/Cerrar.wav");
	private: System::Windows::Forms::Timer^ Timer_Eventos;
	private: System::Windows::Forms::Timer^ Timer_Bala;

	private: System::Windows::Forms::Timer^ Timer_Juego;


		   
	public:
		void setNivel(Niveles nivel) { this->nivel = nivel; }
		void setPartida(Juego* ju) { this->Jg = ju; }

		Entorno(void)
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
		~Entorno()
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
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer_Juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer_Eventos = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Timer_Juego
			// 
			this->Timer_Juego->Enabled = true;
			this->Timer_Juego->Tick += gcnew System::EventHandler(this, &Entorno::Timer_Juego_Tick);
			// 
			// Timer_Eventos
			// 
			this->Timer_Eventos->Enabled = true;
			this->Timer_Eventos->Tick += gcnew System::EventHandler(this, &Entorno::Timer_Eventos_Tick);
			// 
			// Entorno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Entorno";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Entorno";
			this->Load += gcnew System::EventHandler(this, &Entorno::Entorno_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Entorno::Entorno_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Entorno::Entorno_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Entorno::Entorno_MouseClick);
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Entorno::Entorno_PreviewKeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Timer_Juego_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);

		nivelAct = Jg->getNivel();
		Jg->jugar(buffer);
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;
	}
	private: System::Void Entorno_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::P) {
			this->Timer_Juego->Enabled = false;
			this->Timer_Eventos->Enabled = false;
			pausa = gcnew Pausa();
			pausa->setDatos(Jg);
			abrir->Play();
			pausa->ShowDialog();
			cerrar->Play();
			if (pausa->getSalir()) this->Close();
			if (pausa->getRest()){
				delete Jg;
				Jg = new Juego();
				Jg->setNivel(nivelAct);
			}
			this->Timer_Juego->Enabled = true;
			this->Timer_Eventos->Enabled = true;
			delete pausa;
		}
		Jg->movJugador(true, e->KeyCode);
		if (Jg->movPF(e->KeyCode))this->Close();
		
	}
	private: System::Void Entorno_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Jg->movJugador(false, e->KeyCode);
	}
	private: System::Void Entorno_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
		
	}
	private: System::Void Entorno_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Jg->disparar(e->X, e->Y);
	}
	private: System::Void Entorno_Load(System::Object^ sender, System::EventArgs^ e) {
		Jg->setNivel(nivel);
	}

	private: System::Void Timer_Eventos_Tick(System::Object^ sender, System::EventArgs^ e) {
		Jg->T_Evento();
	}
	private: System::Void Timer_Bala_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
