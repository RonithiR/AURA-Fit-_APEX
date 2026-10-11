#pragma once
#include "CustomElixir.h"
#using <System.dll>
using namespace MySql::Data::MySqlClient;

namespace ZenBarApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	public:
		DashboardForm(void)
		{
			InitializeComponent();
			cartTotal = 0;
			cartItemCount = 0;

			products = gcnew List<Product^>();
			products->Add(gcnew CustomElixir("Matcha Cloud Latte", 950, "Ceremonial matcha with oat milk.", 2));
			products->Add(gcnew CustomElixir("Berry Bloom Smoothie", 890, "Mixed berries & plant collagen.", 1));
			products->Add(gcnew CustomElixir("Golden Glow Elixir", 820, "Turmeric, ginger & almond milk.", 1));
			products->Add(gcnew CustomElixir("Spirulina Zen Cooler", 990, "Blue spirulina & coconut water.", 0));
			products->Add(gcnew CustomElixir("Vinyasa Flow Yoga", 1500, "60 min dynamic posture session.", 0));
			products->Add(gcnew CustomElixir("Mindful Meditation", 1200, "45 min guided clarity session.", 0));

			LoadHomeView(); // Default to Home View
		}

	protected:
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Layout Panels
		Panel^ sidebarPanel;
		Panel^ headerPanel;
		Panel^ contentHost;

		// Sidebar Navigation Buttons
		Button^ btnHome;
		Button^ btnMenu;
		Button^ btnOrders;
		Button^ btnBookings;
		Button^ btnLogout;

		// Header Elements
		Label^ lblTitle;
		Label^ lblClock;
		Timer^ clockTimer;

		// Active State Helpers
		Button^ currentActiveBtn;

		// Interactive Cart Controls (Menu Tab)
		ListBox^ lstCartItems;
		Label^ lblCartTotal;
		TextBox^ txtCartCustomer;
		double cartTotal;
		int cartItemCount;
		List<Product^>^ products;
		String^ connStr = "server=localhost;database=zenbar_db;uid=root;pwd=Roni@2005,;";
		TextBox^ txtOrderCust;
		ComboBox^ cmbOrderDrink;
		ComboBox^ cmbClass;
		DataGridView^ ordersGrid;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->sidebarPanel = (gcnew Panel());
			this->headerPanel = (gcnew Panel());
			this->contentHost = (gcnew Panel());
			this->btnHome = (gcnew Button());
			this->btnMenu = (gcnew Button());
			this->btnOrders = (gcnew Button());
			this->btnBookings = (gcnew Button());
			this->btnLogout = (gcnew Button());
			this->lblTitle = (gcnew Label());
			this->lblClock = (gcnew Label());
			this->clockTimer = (gcnew Timer());

			this->SuspendLayout();

			// 
			// Form Settings
			// 
			this->ClientSize = System::Drawing::Size(1100, 680);
			this->Text = L"ZenBar Management System";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			// 
			// Sidebar Panel
			// 
			this->sidebarPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebarPanel->Size = System::Drawing::Size(220, 680);
			this->sidebarPanel->BackColor = Color::FromArgb(38, 50, 42); // Deep Sage Green

			// Brand Header
			Label^ lblBrand = gcnew Label();
			lblBrand->Text = L"ZENBAR\nCAFE & STUDIO";
			lblBrand->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblBrand->ForeColor = Color::FromArgb(235, 243, 235);
			lblBrand->Location = Point(20, 30);
			lblBrand->AutoSize = true;
			this->sidebarPanel->Controls->Add(lblBrand);

			// Sidebar Navigation
			this->btnHome = CreateNavButton(L"  Dashboard", 110);
			this->btnHome->Click += gcnew EventHandler(this, &DashboardForm::BtnHome_Click);

			this->btnMenu = CreateNavButton(L"  Menu & Catalog", 165);
			this->btnMenu->Click += gcnew EventHandler(this, &DashboardForm::BtnMenu_Click);

			this->btnOrders = CreateNavButton(L"  Orders Queue", 220);
			this->btnOrders->Click += gcnew EventHandler(this, &DashboardForm::BtnOrders_Click);

			this->btnBookings = CreateNavButton(L"  Bookings Queue", 275);
			this->btnBookings->Click += gcnew EventHandler(this, &DashboardForm::BtnBookings_Click);

			this->btnLogout = CreateNavButton(L"  Log Out", 600);
			this->btnLogout->BackColor = Color::FromArgb(58, 70, 62);
			this->btnLogout->Click += gcnew EventHandler(this, &DashboardForm::BtnLogout_Click);

			this->sidebarPanel->Controls->Add(this->btnHome);
			this->sidebarPanel->Controls->Add(this->btnMenu);
			this->sidebarPanel->Controls->Add(this->btnOrders);
			this->sidebarPanel->Controls->Add(this->btnBookings);
			this->sidebarPanel->Controls->Add(this->btnLogout);

			// 
			// Header Panel
			// 
			this->headerPanel->Location = Point(220, 0);
			this->headerPanel->Size = System::Drawing::Size(880, 70);
			this->headerPanel->BackColor = Color::White;

			this->lblTitle->Text = L"Dashboard";
			this->lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			this->lblTitle->ForeColor = Color::FromArgb(38, 50, 42);
			this->lblTitle->Location = Point(25, 20);
			this->lblTitle->AutoSize = true;

			this->lblClock->Text = L"12:00:00 PM";
			this->lblClock->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Regular);
			this->lblClock->ForeColor = Color::Gray;
			this->lblClock->Location = Point(640, 25);
			this->lblClock->AutoSize = true;

			this->headerPanel->Controls->Add(this->lblTitle);
			this->headerPanel->Controls->Add(this->lblClock);

			// Clock Timer
			this->clockTimer->Interval = 1000;
			this->clockTimer->Tick += gcnew EventHandler(this, &DashboardForm::ClockTimer_Tick);
			this->clockTimer->Start();

			// 
			// Content Host Panel
			// 
			this->contentHost->Location = Point(220, 70);
			this->contentHost->Size = System::Drawing::Size(880, 610);
			this->contentHost->BackColor = Color::FromArgb(246, 248, 245);

			// Add main panels
			this->Controls->Add(this->contentHost);
			this->Controls->Add(this->headerPanel);
			this->Controls->Add(this->sidebarPanel);

			this->ResumeLayout(false);
		}
#pragma endregion

		Button^ CreateNavButton(String^ text, int topLocation) {
			Button^ btn = gcnew Button();
			btn->Text = text;
			btn->Location = Point(10, topLocation);
			btn->Size = System::Drawing::Size(200, 45);
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->BackColor = Color::FromArgb(38, 50, 42);
			btn->ForeColor = Color::FromArgb(200, 210, 202);
			btn->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Regular);
			btn->TextAlign = ContentAlignment::MiddleLeft;
			btn->Cursor = Cursors::Hand;
			return btn;
		}

		void SetActiveButton(Button^ activeBtn) {
			if (currentActiveBtn != nullptr) {
				currentActiveBtn->BackColor = Color::FromArgb(38, 50, 42);
				currentActiveBtn->ForeColor = Color::FromArgb(200, 210, 202);
			}
			currentActiveBtn = activeBtn;
			currentActiveBtn->BackColor = Color::FromArgb(65, 96, 73);
			currentActiveBtn->ForeColor = Color::White;
		}

		void ClockTimer_Tick(Object^ sender, EventArgs^ e) {
			this->lblClock->Text = DateTime::Now.ToString("dd MMM yyyy, hh:mm:ss tt");
		}

		void RunNonQuery(String^ sql) {
			MySqlConnection^ conn = gcnew MySqlConnection(connStr);
			try {
				conn->Open();
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Database error: " + ex->Message, "ZenBar DB Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				conn->Close();
			}
		}

		void BtnAddOrder_Click(Object^ sender, EventArgs^ e) {
			if (txtOrderCust->Text == "" || cmbOrderDrink->SelectedIndex == -1) {
				MessageBox::Show("Please enter a customer name and select a drink.", "Missing Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ custName = txtOrderCust->Text;
			String^ selected = cmbOrderDrink->SelectedItem->ToString();

			// selected looks like: "Matcha Cloud Latte (Rs. 950)"
			int parenIndex = selected->IndexOf("(Rs. ");
			String^ drinkName = selected->Substring(0, parenIndex)->Trim();
			String^ priceText = selected->Substring(parenIndex + 5)->Replace(")", "")->Trim();
			double price = Double::Parse(priceText);

			String^ sql = "INSERT INTO orders (customer_name, drink_name, price) VALUES ('" +
				custName->Replace("'", "''") + "', '" +
				drinkName->Replace("'", "''") + "', " +
				price.ToString() + ")";

			RunNonQuery(sql);

			MessageBox::Show("Order added successfully!", "ZenBar", MessageBoxButtons::OK, MessageBoxIcon::Information);
			txtOrderCust->Text = "";
			LoadOrdersView(); // refresh the page to show the new row
		}

		// ==========================================
		// 1. DASHBOARD OVERVIEW
		// ==========================================
		void LoadHomeView() {
			SetActiveButton(btnHome);
			lblTitle->Text = "Dashboard Overview";
			contentHost->Controls->Clear();

			Panel^ welcomeCard = gcnew Panel();
			welcomeCard->Location = Point(30, 20);
			welcomeCard->Size = System::Drawing::Size(820, 120);
			welcomeCard->BackColor = Color::FromArgb(235, 243, 235);

			Label^ lblWelcome = gcnew Label();
			lblWelcome->Text = L"Welcome Back, Shop Owner! ✨";
			lblWelcome->Font = gcnew Drawing::Font(L"Segoe UI", 15, FontStyle::Bold);
			lblWelcome->ForeColor = Color::FromArgb(38, 50, 42);
			lblWelcome->Location = Point(25, 20);
			lblWelcome->AutoSize = true;

			Label^ lblQuote = gcnew Label();
			lblQuote->Text = L"\"Small steps count. A little care goes a long way for mind & body.\"";
			lblQuote->Font = gcnew Drawing::Font(L"Segoe UI", 9.5f, FontStyle::Italic);
			lblQuote->ForeColor = Color::FromArgb(70, 90, 75);
			lblQuote->Location = Point(25, 62);
			lblQuote->AutoSize = true;

			welcomeCard->Controls->Add(lblWelcome);
			welcomeCard->Controls->Add(lblQuote);

			Panel^ cardMenu = CreateDashboardCard(30, 155, "Menu & Interactive Shop", "Browse matcha, juices & packages, and add directly to cart.", "Open Shop →", gcnew EventHandler(this, &DashboardForm::BtnMenu_Click));
			Panel^ cardOrders = CreateDashboardCard(445, 155, "Cafe Orders POS Queue", "Manage active orders, update status or delete completed ones.", "Manage Orders →", gcnew EventHandler(this, &DashboardForm::BtnOrders_Click));
			Panel^ cardBookings = CreateDashboardCard(30, 375, "Yoga Studio Bookings", "View scheduled sessions and manage class slots.", "Manage Bookings →", gcnew EventHandler(this, &DashboardForm::BtnBookings_Click));

			contentHost->Controls->Add(welcomeCard);
			contentHost->Controls->Add(cardMenu);
			contentHost->Controls->Add(cardOrders);
			contentHost->Controls->Add(cardBookings);
		}

		Panel^ CreateDashboardCard(int x, int y, String^ title, String^ desc, String^ btnText, EventHandler^ handler) {
			Panel^ card = gcnew Panel();
			card->Location = Point(x, y);
			card->Size = System::Drawing::Size(405, 200);
			card->BackColor = Color::White;

			Label^ lblT = gcnew Label();
			lblT->Text = title;
			lblT->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblT->ForeColor = Color::FromArgb(38, 50, 42);
			lblT->Location = Point(20, 20);
			lblT->AutoSize = true;

			Label^ lblD = gcnew Label();
			lblD->Text = desc;
			lblD->Font = gcnew Drawing::Font(L"Segoe UI", 9.0f);
			lblD->ForeColor = Color::Gray;
			lblD->Location = Point(20, 52);
			lblD->Size = System::Drawing::Size(365, 45);

			Button^ btn = gcnew Button();
			btn->Text = btnText;
			btn->Location = Point(20, 125);
			btn->Size = System::Drawing::Size(160, 38);
			btn->BackColor = Color::FromArgb(65, 96, 73);
			btn->ForeColor = Color::White;
			btn->FlatStyle = FlatStyle::Flat;
			btn->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btn->Click += handler;

			card->Controls->Add(lblT);
			card->Controls->Add(lblD);
			card->Controls->Add(btn);
			return card;
		}

		// ==========================================
		// 2. INTERACTIVE MENU & LIVE CART SHOPPING
		// ==========================================
		void LoadMenuView() {
			SetActiveButton(btnMenu);
			lblTitle->Text = "ZenBar Interactive Storefront";
			contentHost->Controls->Clear();

			// Reset Cart metrics for fresh view
			cartTotal = 0;
			cartItemCount = 0;

			// Left Scrollable Panel for Product Cards Grid
			Panel^ catalogPanel = gcnew Panel();
			catalogPanel->Location = Point(20, 15);
			catalogPanel->Size = System::Drawing::Size(560, 575);
			catalogPanel->AutoScroll = true;

			Label^ lblCafeHeader = gcnew Label();
			lblCafeHeader->Text = L"🍵 Cafe Drinks & Juices";
			lblCafeHeader->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblCafeHeader->ForeColor = Color::FromArgb(38, 50, 42);
			lblCafeHeader->Location = Point(5, 5);
			lblCafeHeader->AutoSize = true;
			catalogPanel->Controls->Add(lblCafeHeader);

			// Drinks Cards
			array<Color>^ tints = gcnew array<Color>{
				Color::FromArgb(235, 243, 235), Color::FromArgb(249, 235, 238),
					Color::FromArgb(250, 240, 215), Color::FromArgb(229, 238, 247)
			};
			array<Point>^ positions = gcnew array<Point>{
				Point(5, 35), Point(280, 35), Point(5, 260), Point(280, 260)
			};
			for (int i = 0; i < 4; i++) {
				CustomElixir^ p = safe_cast<CustomElixir^>(products[i]);
				AddInteractiveCard(catalogPanel, p, positions[i].X, positions[i].Y, tints[i]);
			}

			Label^ lblStudioHeader = gcnew Label();
			lblStudioHeader->Text = L"🧘 Yoga & Meditation Packages";
			lblStudioHeader->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblStudioHeader->ForeColor = Color::FromArgb(38, 50, 42);
			lblStudioHeader->Location = Point(5, 485);
			lblStudioHeader->AutoSize = true;
			catalogPanel->Controls->Add(lblStudioHeader);

			// Yoga Cards
			CustomElixir^ yoga1 = safe_cast<CustomElixir^>(products[4]);
			CustomElixir^ yoga2 = safe_cast<CustomElixir^>(products[5]);
			AddInteractiveCard(catalogPanel, yoga1, 5, 515, Color::FromArgb(235, 243, 235));
			AddInteractiveCard(catalogPanel, yoga2, 280, 515, Color::FromArgb(229, 238, 247));

			// Right Live Cart Panel
			Panel^ cartPanel = gcnew Panel();
			cartPanel->Location = Point(595, 15);
			cartPanel->Size = System::Drawing::Size(265, 575);
			cartPanel->BackColor = Color::White;

			Label^ lblCartHeader = gcnew Label();
			lblCartHeader->Text = L"🛒 Shopping Bag";
			lblCartHeader->Font = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
			lblCartHeader->ForeColor = Color::FromArgb(38, 50, 42);
			lblCartHeader->Location = Point(15, 15);
			lblCartHeader->AutoSize = true;

			Label^ lblCustName = gcnew Label();
			lblCustName->Text = L"Customer Name:";
			lblCustName->Font = gcnew Drawing::Font(L"Segoe UI", 8.5f);
			lblCustName->Location = Point(15, 50);
			lblCustName->AutoSize = true;

			txtCartCustomer = gcnew TextBox();
			txtCartCustomer->Location = Point(15, 70);
			txtCartCustomer->Size = System::Drawing::Size(235, 25);
			txtCartCustomer->Text = L"Walk-in Customer";

			lstCartItems = gcnew ListBox();
			lstCartItems->Location = Point(15, 105);
			lstCartItems->Size = System::Drawing::Size(235, 330);
			lstCartItems->Font = gcnew Drawing::Font(L"Segoe UI", 8.5f);

			lblCartTotal = gcnew Label();
			lblCartTotal->Text = L"Total: Rs. 0.00";
			lblCartTotal->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblCartTotal->ForeColor = Color::FromArgb(65, 96, 73);
			lblCartTotal->Location = Point(15, 450);
			lblCartTotal->AutoSize = true;

			Button^ btnClear = gcnew Button();
			btnClear->Text = L"Clear Bag";
			btnClear->Location = Point(15, 485);
			btnClear->Size = System::Drawing::Size(110, 35);
			btnClear->BackColor = Color::FromArgb(180, 70, 70);
			btnClear->ForeColor = Color::White;
			btnClear->FlatStyle = FlatStyle::Flat;
			btnClear->Click += gcnew EventHandler(this, &DashboardForm::BtnClearCart_Click);

			Button^ btnCheckout = gcnew Button();
			btnCheckout->Text = L"Checkout Order";
			btnCheckout->Location = Point(130, 485);
			btnCheckout->Size = System::Drawing::Size(120, 35);
			btnCheckout->BackColor = Color::FromArgb(65, 96, 73);
			btnCheckout->ForeColor = Color::White;
			btnCheckout->FlatStyle = FlatStyle::Flat;
			btnCheckout->Font = gcnew Drawing::Font(L"Segoe UI", 8.5f, FontStyle::Bold);
			btnCheckout->Click += gcnew EventHandler(this, &DashboardForm::BtnCheckout_Click);

			cartPanel->Controls->Add(lblCartHeader);
			cartPanel->Controls->Add(lblCustName);
			cartPanel->Controls->Add(txtCartCustomer);
			cartPanel->Controls->Add(lstCartItems);
			cartPanel->Controls->Add(lblCartTotal);
			cartPanel->Controls->Add(btnClear);
			cartPanel->Controls->Add(btnCheckout);

			contentHost->Controls->Add(catalogPanel);
			contentHost->Controls->Add(cartPanel);
		}

		void AddInteractiveCard(Panel^ parent, CustomElixir^ product, int x, int y, Color tint) {
			String^ title = product->Name;
			String^ desc = product->Booster; // reused to hold the description text
			double basePrice = product->Price;
			double tax = product->CalculateTax(); // polymorphic: 8% for CustomElixir

			Panel^ card = gcnew Panel();
			card->Location = Point(x, y);
			card->Size = System::Drawing::Size(260, 215);
			card->BackColor = Color::White;
			card->BorderStyle = BorderStyle::FixedSingle;

			Panel^ imgBox = gcnew Panel();
			imgBox->Location = Point(10, 10);
			imgBox->Size = System::Drawing::Size(238, 70);
			imgBox->BackColor = tint;

			Label^ lblImgText = gcnew Label();
			lblImgText->Text = title;
			lblImgText->Font = gcnew Drawing::Font(L"Segoe UI", 9.0f, FontStyle::Bold);
			lblImgText->ForeColor = Color::FromArgb(47, 59, 49);
			lblImgText->Location = Point(5, 20);
			lblImgText->Size = System::Drawing::Size(228, 30);
			lblImgText->TextAlign = ContentAlignment::MiddleCenter;
			imgBox->Controls->Add(lblImgText);

			Label^ lblName = gcnew Label();
			lblName->Text = title;
			lblName->Font = gcnew Drawing::Font(L"Segoe UI", 9.5f, FontStyle::Bold);
			lblName->ForeColor = Color::FromArgb(47, 59, 49);
			lblName->Location = Point(10, 88);
			lblName->AutoSize = true;

			Label^ lblDesc = gcnew Label();
			lblDesc->Text = desc;
			lblDesc->Font = gcnew Drawing::Font(L"Segoe UI", 8.0f);
			lblDesc->ForeColor = Color::Gray;
			lblDesc->Location = Point(10, 110);
			lblDesc->Size = System::Drawing::Size(238, 30);

			Label^ lblPrice = gcnew Label();
			lblPrice->Text = "Rs. " + basePrice.ToString("0.00") + "\n(+tax Rs. " + tax.ToString("0.00") + ")";
			lblPrice->Font = gcnew Drawing::Font(L"Segoe UI", 8.5f, FontStyle::Bold);
			lblPrice->ForeColor = Color::FromArgb(65, 96, 73);
			lblPrice->Location = Point(10, 160);
			lblPrice->AutoSize = true;

			Button^ btnAdd = gcnew Button();
			btnAdd->Text = L"+ Add to Cart";
			btnAdd->Location = Point(130, 165);
			btnAdd->Size = System::Drawing::Size(108, 32);
			btnAdd->BackColor = Color::FromArgb(47, 59, 49);
			btnAdd->ForeColor = Color::White;
			btnAdd->FlatStyle = FlatStyle::Flat;
			btnAdd->Font = gcnew Drawing::Font(L"Segoe UI", 8.0f, FontStyle::Bold);
			btnAdd->Tag = title + "|" + (basePrice + tax).ToString();
			btnAdd->Cursor = Cursors::Hand;
			btnAdd->Click += gcnew EventHandler(this, &DashboardForm::AddToCart_Click);

			card->Controls->Add(imgBox);
			card->Controls->Add(lblName);
			card->Controls->Add(lblDesc);
			card->Controls->Add(lblPrice);
			card->Controls->Add(btnAdd);

			parent->Controls->Add(card);
		}

		void AddToCart_Click(Object^ sender, EventArgs^ e) {
			Button^ btn = safe_cast<Button^>(sender);
			String^ tag = btn->Tag->ToString();
			array<String^>^ parts = tag->Split('|');
			String^ itemName = parts[0];
			double itemPrice = Double::Parse(parts[1]);

			lstCartItems->Items->Add(itemName + " - Rs. " + itemPrice.ToString("0.00"));
			cartTotal += itemPrice;
			cartItemCount++;

			lblCartTotal->Text = "Total: Rs. " + cartTotal.ToString("0.00");
		}

		void BtnClearCart_Click(Object^ sender, EventArgs^ e) {
			lstCartItems->Items->Clear();
			cartTotal = 0;
			cartItemCount = 0;
			lblCartTotal->Text = L"Total: Rs. 0.00";
		}

		void BtnCheckout_Click(Object^ sender, EventArgs^ e) {
			if (cartItemCount == 0) {
				MessageBox::Show("Your shopping bag is empty! Add items first.", "ZenBar Store", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			MessageBox::Show("Order for " + txtCartCustomer->Text + " checked out successfully! Total: Rs. " + cartTotal.ToString() + ".00 ✨", "ZenBar POS Checkout", MessageBoxButtons::OK, MessageBoxIcon::Information);
			BtnClearCart_Click(sender, e);
		}

		// ==========================================
		// 3. ORDERS POS QUEUE VIEW
		// ==========================================
		void LoadOrdersView() {
			SetActiveButton(btnOrders);
			lblTitle->Text = "Cafe Orders POS Queue";
			contentHost->Controls->Clear();

			Panel^ formPanel = gcnew Panel();
			formPanel->Location = Point(30, 20);
			formPanel->Size = System::Drawing::Size(270, 565);
			formPanel->BackColor = Color::White;

			Label^ lblFormTitle = gcnew Label();
			lblFormTitle->Text = L"New Drink Order";
			lblFormTitle->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblFormTitle->Location = Point(15, 15);
			lblFormTitle->AutoSize = true;

			Label^ lblCust = gcnew Label();
			lblCust->Text = L"Customer Name:";
			lblCust->Location = Point(15, 55);
			lblCust->AutoSize = true;

			txtOrderCust = gcnew TextBox();
			txtOrderCust->Location = Point(15, 75);
			txtOrderCust->Size = System::Drawing::Size(235, 25);

			Label^ lblDrink = gcnew Label();
			lblDrink->Text = L"Select Item from Menu:";
			lblDrink->Location = Point(15, 115);
			lblDrink->AutoSize = true;

			cmbOrderDrink = gcnew ComboBox();
			cmbOrderDrink->Location = Point(15, 135);
			cmbOrderDrink->Size = System::Drawing::Size(235, 25);
			cmbOrderDrink->Items->Add(L"Matcha Cloud Latte (Rs. 950)");
			cmbOrderDrink->Items->Add(L"Berry Bloom Smoothie (Rs. 890)");
			cmbOrderDrink->Items->Add(L"Golden Glow Elixir (Rs. 820)");
			cmbOrderDrink->SelectedIndex = 0;

			Button^ btnAdd = gcnew Button();
			btnAdd->Text = L"+ Add Order";
			btnAdd->Location = Point(15, 200);
			btnAdd->Size = System::Drawing::Size(235, 38);
			btnAdd->BackColor = Color::FromArgb(65, 96, 73);
			btnAdd->ForeColor = Color::White;
			btnAdd->FlatStyle = FlatStyle::Flat;
			btnAdd->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);

			Button^ btnUpdate = gcnew Button();
			btnUpdate->Text = L"Update Selected";
			btnUpdate->Location = Point(15, 250);
			btnUpdate->Size = System::Drawing::Size(235, 38);
			btnUpdate->BackColor = Color::FromArgb(100, 110, 100);
			btnUpdate->ForeColor = Color::White;
			btnUpdate->FlatStyle = FlatStyle::Flat;

			Button^ btnDelete = gcnew Button();
			btnDelete->Text = L"Delete Order";
			btnDelete->Location = Point(15, 300);
			btnDelete->Size = System::Drawing::Size(235, 38);
			btnDelete->BackColor = Color::FromArgb(180, 70, 70);
			btnDelete->ForeColor = Color::White;
			btnDelete->FlatStyle = FlatStyle::Flat;

			formPanel->Controls->Add(lblFormTitle);
			formPanel->Controls->Add(lblCust);
			formPanel->Controls->Add(txtOrderCust);
			formPanel->Controls->Add(lblDrink);
			formPanel->Controls->Add(cmbOrderDrink);
			formPanel->Controls->Add(btnAdd);
			formPanel->Controls->Add(btnUpdate);
			formPanel->Controls->Add(btnDelete);
			btnAdd->Click += gcnew EventHandler(this, &DashboardForm::BtnAddOrder_Click);

			ordersGrid = gcnew DataGridView();
			ordersGrid->Location = Point(320, 20);
			ordersGrid->Size = System::Drawing::Size(530, 565);
			ordersGrid->BackgroundColor = Color::White;
			ordersGrid->ColumnCount = 4;
			ordersGrid->Columns[0]->Name = L"Order ID";
			ordersGrid->Columns[1]->Name = L"Customer";
			ordersGrid->Columns[2]->Name = L"Item Name";
			ordersGrid->Columns[3]->Name = L"Price (Rs.)";
			ordersGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			MySqlConnection^ conn = gcnew MySqlConnection(connStr);
			try {
				conn->Open();
				MySqlCommand^ cmd = gcnew MySqlCommand("SELECT order_id, customer_name, drink_name, price FROM orders", conn);
				MySqlDataReader^ reader = cmd->ExecuteReader();
				while (reader->Read()) {
					ordersGrid->Rows->Add(
						reader["order_id"]->ToString(),
						reader["customer_name"]->ToString(),
						reader["drink_name"]->ToString(),
						reader["price"]->ToString()
					);
				}
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Could not load orders: " + ex->Message, "ZenBar DB Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				conn->Close();
			}

			contentHost->Controls->Add(formPanel);
			contentHost->Controls->Add(ordersGrid);
		}

		// ==========================================
		// 4. YOGA STUDIO BOOKINGS QUEUE VIEW
		// ==========================================
		void LoadBookingsView() {
			SetActiveButton(btnBookings);
			lblTitle->Text = "Yoga & Meditation Class Bookings";
			contentHost->Controls->Clear();

			Panel^ formPanel = gcnew Panel();
			formPanel->Location = Point(30, 20);
			formPanel->Size = System::Drawing::Size(270, 565);
			formPanel->BackColor = Color::White;

			Label^ lblFormTitle = gcnew Label();
			lblFormTitle->Text = L"Book Yoga Package";
			lblFormTitle->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblFormTitle->Location = Point(15, 15);
			lblFormTitle->AutoSize = true;

			Label^ lblCust = gcnew Label();
			lblCust->Text = L"Customer Name:";
			lblCust->Location = Point(15, 55);
			lblCust->AutoSize = true;

			TextBox^ txtOrderCust = gcnew TextBox();
			txtOrderCust->Location = Point(15, 75);
			txtOrderCust->Size = System::Drawing::Size(235, 25);

			Label^ lblClass = gcnew Label();
			lblClass->Text = L"Select Studio Package:";
			lblClass->Location = Point(15, 115);
			lblClass->AutoSize = true;

			cmbClass = gcnew ComboBox();
			cmbClass->Location = Point(15, 135);
			cmbClass->Size = System::Drawing::Size(235, 25);
			cmbClass->Items->Add(L"Vinyasa Flow Yoga (Rs. 1,500)");
			cmbClass->Items->Add(L"Mindful Meditation (Rs. 1,200)");
			cmbClass->SelectedIndex = 0;

			Label^ lblTime = gcnew Label();
			lblTime->Text = L"Session Date & Time:";
			lblTime->Location = Point(15, 175);
			lblTime->AutoSize = true;

			DateTimePicker^ dtpTime = gcnew DateTimePicker();
			dtpTime->Location = Point(15, 195);
			dtpTime->Size = System::Drawing::Size(235, 25);

			Button^ btnAdd = gcnew Button();
			btnAdd->Text = L"+ Add Booking";
			btnAdd->Location = Point(15, 255);
			btnAdd->Size = System::Drawing::Size(235, 38);
			btnAdd->BackColor = Color::FromArgb(65, 96, 73);
			btnAdd->ForeColor = Color::White;
			btnAdd->FlatStyle = FlatStyle::Flat;
			btnAdd->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);

			Button^ btnUpdate = gcnew Button();
			btnUpdate->Text = L"Update Booking";
			btnUpdate->Location = Point(15, 305);
			btnUpdate->Size = System::Drawing::Size(235, 38);
			btnUpdate->BackColor = Color::FromArgb(100, 110, 100);
			btnUpdate->ForeColor = Color::White;
			btnUpdate->FlatStyle = FlatStyle::Flat;

			Button^ btnDelete = gcnew Button();
			btnDelete->Text = L"Delete Booking";
			btnDelete->Location = Point(15, 355);
			btnDelete->Size = System::Drawing::Size(235, 38);
			btnDelete->BackColor = Color::FromArgb(180, 70, 70);
			btnDelete->ForeColor = Color::White;
			btnDelete->FlatStyle = FlatStyle::Flat;

			formPanel->Controls->Add(lblFormTitle);
			formPanel->Controls->Add(lblCust);
			formPanel->Controls->Add(txtOrderCust);
			formPanel->Controls->Add(lblClass);
			formPanel->Controls->Add(cmbClass);
			formPanel->Controls->Add(lblTime);
			formPanel->Controls->Add(dtpTime);
			formPanel->Controls->Add(btnAdd);
			formPanel->Controls->Add(btnUpdate);
			formPanel->Controls->Add(btnDelete);

			DataGridView^ grid = gcnew DataGridView();
			grid->Location = Point(320, 20);
			grid->Size = System::Drawing::Size(530, 565);
			grid->BackgroundColor = Color::White;
			grid->ColumnCount = 4;
			grid->Columns[0]->Name = L"Booking ID";
			grid->Columns[1]->Name = L"Customer";
			grid->Columns[2]->Name = L"Package Session";
			grid->Columns[3]->Name = L"Date & Time";
			grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			grid->Rows->Add(L"BKG-201", L"Emma Watson", L"Vinyasa Flow Yoga", L"Sat, 10:00 AM");

			contentHost->Controls->Add(formPanel);
			contentHost->Controls->Add(grid);
		}

		// Navigation Handlers
		void BtnHome_Click(Object^ sender, EventArgs^ e) { LoadHomeView(); }
		void BtnMenu_Click(Object^ sender, EventArgs^ e) { LoadMenuView(); }
		void BtnOrders_Click(Object^ sender, EventArgs^ e) { LoadOrdersView(); }
		void BtnBookings_Click(Object^ sender, EventArgs^ e) { LoadBookingsView(); }
		void BtnLogout_Click(Object^ sender, EventArgs^ e) { this->Close(); }
	};
}