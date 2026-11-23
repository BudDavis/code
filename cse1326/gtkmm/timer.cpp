#include <gtkmm.h>
#include <iostream>

bool TICK()
{
	std::cout << "TICK " << std::endl;
	return true;
}
class MyWindow : public Gtk::Window 
{
public:
  MyWindow() 
  {
    m_timer = Glib::signal_timeout().connect([this]() -> bool 
		    {
      			std::cout << "Tick: " << ++m_count << '\n';
      			return m_count < 5; // Stops automatically after 5 ticks
    }, 1000);
    m_timer = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MyWindow::tick), 1000);
    m_timer = Glib::signal_timeout().connect(sigc::ptr_fun(&TICK), 1000);
#if 0
    // 2. One-shot timer (runs once after 2000 ms)
    Glib::signal_timeout().connect_once([]() {
      std::cout << "2 seconds elapsed!\n";
    }, 2000);
#endif
  }


  ~MyWindow() 
  {
    // Always disconnect if the object can be destroyed before the timer finishes
    m_timer.disconnect();
  }

private:
  sigc::connection m_timer;
  int m_count = 0;
  bool tick()
  {
	  std::cout << "it is a tick" << std::endl;
	  return true;
  }
};

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create("org.gtkmm.example.button");
	app->make_window_and_run<MyWindow>(argc, argv);
	return 0;
}

