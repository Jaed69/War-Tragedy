#pragma once

#include "Entorno.h"
#include "Juego.h"
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
		Juego* Jg;
		Niveles nivel = habitacionS;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Jg = new Juego();
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



	private: System::Windows::Forms::Timer^ timer1;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"War Tragedy";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		Jg->T_Evento();
		Jg->jugar(buffer);
		buffer->Render(g);
		delete buffer; delete espacioBuffer; delete g;
	}
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NTejado);
		this->timer1->Enabled = false;
		juego->ShowDialog();
		this->timer1->Enabled = true;
		delete juego;

	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NEdificio);
		this->timer1->Enabled = false;
		juego->ShowDialog();
		this->timer1->Enabled = true;
		delete juego;
	}
	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		Entorno^ juego = gcnew Entorno();
		juego->setNivel(NPrado);
		this->timer1->Enabled = false;
		juego->ShowDialog();
		this->timer1->Enabled = true;
		delete juego;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Jg->setNivel(nivel);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Jg->movJugador(true, e->KeyCode);

		if (Jg->getN1()) {
			Entorno^ juego = gcnew Entorno();
			juego->setNivel(NTejado);
			this->timer1->Enabled = false;
			juego->ShowDialog();
			Jg->setN1(false);
			this->timer1->Enabled = true;
			delete juego;
		}
		else if(Jg->getN2()) {
			Entorno^ juego = gcnew Entorno();
			juego->setNivel(NEdificio);
			this->timer1->Enabled = false;
			juego->ShowDialog();
			Jg->setN2(false);
			this->timer1->Enabled = true;
			delete juego;
		}
		else if (Jg->getN3()) {
			Entorno^ juego = gcnew Entorno();
			juego->setNivel(NPrado);
			this->timer1->Enabled = false;
			juego->ShowDialog();
			Jg->setN3(false);
			this->timer1->Enabled = true;
			delete juego;
		}




		//if (e->KeyCode == Keys::L) Jg.nivel;
	}
private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	Jg->movJugador(false, e->KeyCode);
}
};
}
