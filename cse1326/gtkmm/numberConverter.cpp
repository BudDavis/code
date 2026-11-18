#include <gtkmm.h>
#include <iostream>

class Converter : public Gtk::Window 
{
	enum class direction {TO_DEG,TO_RAD};

	double degreesToRadians()
	{
		return  m_value * 180.0/3.1415;
	}

	double radiansToDegrees()
	{
		return m_value * 3.1415/180.0;
	}

	void calculate()
	{
		double value;
		double v;
	       	//v = std::strtod(std::string(m_question.get_text().c_str()));
		if (m_dir == direction::TO_DEG)
		{
			value = radiansToDegrees();
		}
		else
		{
			value = degreesToRadians();
		}
		//m_answer.set_text(std::to_string( value );
	}

	public:
		Gtk::Box m_box; // the big box
		Gtk::CheckButton m_cbox[2];
		Gtk::Box m_checkButton_box;
		Gtk::Label m_answer;
		Gtk::Text m_question;
		direction m_dir;
		double m_value;
	Converter() 
	{
		// initialize some member variables
		m_dir = direction::TO_RAD;
		m_value = 0.0;
		// title
		set_title("Angle Converter");
		set_default_size(300, 150);
		// check box
		m_cbox[0].set_group(m_cbox[1]);
		m_cbox[0].set_label("to rads");
		m_cbox[1].set_label("to degrees");
                m_cbox[0].set_active(true);
                m_cbox[1].set_active(false);
		// 
		m_checkButton_box.set_orientation(Gtk::Orientation::VERTICAL);
		m_checkButton_box.append(m_cbox[0]);
		m_checkButton_box.append(m_cbox[1]);
		// add the check button box
		m_box.append(m_checkButton_box);
                m_box.append(m_answer);
		m_box.append(m_question);
		set_child(m_box);

		m_question.set_placeholder_text("Enter your name...");
		// callbacks
		//    since these are a group, they only get one
		//    callback for any button
		m_cbox[0].signal_toggled().connect([this]()
				{
					std::cout << "in callback" << std::endl;
					calculate();
					m_answer.set_text("xxx");
				});
		m_question.signal_activate().connect([this]()
				{
					std::cout << "in number " << std::endl;
				});
	}
};

int main(int argc, char* argv[])
{

	// make a window object
	//     give it a name and a size
	//     with a text box and a radio button (checkboxes in a group)
	//       and a label for the results
	//     use a box as a container
	//
	// callbacks for the text box
	//    the textbox will call the correct function to covert the number
	//    and put the result in the label
	// callbacks for the radio button
	//   the radio box will select the function to be used for the conversion
	//
	// runtime creation of window

	auto app = Gtk::Application::create("org.gtkmm.example.button");
	return app->make_window_and_run<Converter>(argc, argv);

}
