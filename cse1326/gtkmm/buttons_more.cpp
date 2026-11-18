// g++ buttons_more.cpp -o buttons_more -std=gnu++17 -Wall -g `pkg-config --cflags --libs gtkmm-4.0`
#include <gtkmm/application.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <iostream>

class ButtonWindow : public Gtk::Window {
public:
  ButtonWindow() : m_button("Click Me!"),m_another_button("another") {
    // Configure the window
    set_title("gtkmm 4 Button Example");
    set_default_size(300, 150);

    // Add spacing around the button
    m_button.set_margin(20);

    // Connect the button's clicked signal to our handler
    m_button.signal_clicked().connect(
        sigc::mem_fun(*this, &ButtonWindow::on_button_clicked));

    m_button.signal_clicked().connect([](){std::cout << "hello" << std::endl;});
    //m_VBox(Gtk::Orientation::VERTICAL, 10);
    //m_box.set_orientation(Gtk::Orientation::HORIZONTAL);
    m_box.set_orientation(Gtk::Orientation::VERTICAL);
    // Place the button inside the window (gtkmm 4 uses set_child)
    m_box.append(m_button);
    m_box.append(m_another_button);
    Gtk::Label l("i am a text label");
    m_box.append(l);
    set_child(m_box);
  }

protected:
  // Signal handler function
  void on_button_clicked() {
    std::cout << "Button was clicked!" << std::endl;
  }

  // Child widget
  Gtk::Button m_button;
  Gtk::Button m_another_button;
  Gtk::Box m_box;
};

int main(int argc, char* argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example.button");
  return app->make_window_and_run<ButtonWindow>(argc, argv);
}

