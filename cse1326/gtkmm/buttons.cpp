// g++ buttons.cpp -o buttons -std=gnu++17 -Wall -g `pkg-config --cflags --libs gtkmm-4.0`
#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <iostream>

class ButtonWindow : public Gtk::Window {
public:
  ButtonWindow() : m_button("Click Me!") {
    // Configure the window
    set_title("gtkmm 4 Button Example");
    set_default_size(300, 150);

    // Add spacing around the button
    m_button.set_margin(20);

    // Connect the button's clicked signal to our handler
    m_button.signal_clicked().connect(
        sigc::mem_fun(*this, &ButtonWindow::on_button_clicked));

    // Place the button inside the window (gtkmm 4 uses set_child)
    set_child(m_button);
  }

protected:
  // Signal handler function
  void on_button_clicked() {
    std::cout << "Button was clicked!" << std::endl;
  }

  // Child widget
  Gtk::Button m_button;
};

int main(int argc, char* argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example.button");
  return app->make_window_and_run<ButtonWindow>(argc, argv);
}

