#include <gtkmm.h>
#include <iostream>

class ExampleWindow : public Gtk::Window 
{
	int m_count;
public:
  ExampleWindow() 
  {
	m_count = 0;
       	m_conn = Glib::signal_idle().connect(sigc::mem_fun(*this, &ExampleWindow::on_idle));
  }

  ~ExampleWindow() 
  {
    	m_conn.disconnect();
  }

private:
  bool on_idle() 
  {
	std::cout << m_count << std::endl;
	m_count++;
	return m_count<25;
  }

  sigc::connection m_conn;
};


int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}

