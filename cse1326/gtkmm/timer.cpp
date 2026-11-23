#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window 
{
public:
  MyWindow() 
  {
    // 1. Repeating timer (every 500 ms)
    m_timer = Glib::signal_timeout().connect([this]() -> bool 
		    {
      			std::cout << "Tick: " << ++m_count << '\n';
      			return m_count < 5; // Stops automatically after 5 ticks
    }, 500);
#if 0
    // 2. One-shot timer (runs once after 2000 ms)
    Glib::signal_timeout().connect_once([]() {
      std::cout << "2 seconds elapsed!\n";
    }, 2000);
  }


  ~MyWindow() 
  {
    // Always disconnect if the object can be destroyed before the timer finishes
    m_timer.disconnect();
  }

private:
  sigc::connection m_timer;
  int m_count = 0;
};

