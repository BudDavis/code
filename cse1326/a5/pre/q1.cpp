#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <gtkmm.h>

std::map<std::string,std::vector<std::string>>  instructorsPerCourse;

struct Button : public Gtk::Button
{
	std::string m_course;
	std::vector<std::string> m_instructorList;
	Button()
	{
		signal_clicked().connect([this](){ std::cout << m_course << std::endl; for (auto i:m_instructorList){std::cout << "  " << i << " " << std::endl;}} );
	}

};

struct ButtonWindow : public Gtk::Window 
{
	// makes a entire window, with a button for each course
	public:
	Gtk::Box m_box;
	Gtk::TextView m_text;
	// all of the buttons are in a vector !!
	std::vector<Button*> m_lblVec;
	ButtonWindow()
	{
		for ( auto [course,vecOfInstructors]:instructorsPerCourse )
		{
			Button *b = new Button();
			b->set_label(course);
			b->m_instructorList = vecOfInstructors;
			b->m_course = course;
			m_lblVec.push_back( b );
			m_box.append(*b);
		}
		set_child(m_box);
	}
};


int main(int argc, char *argv[])
{

	std::ifstream f("datafile");
	std::string line;
	while (std::getline(f,line)) 
	{
		int comma = line.find(','); 
		std::string name = line.substr(0,comma);
		std::string course = line.substr(comma+1);

		if (course.find("MATH")!=std::string::npos)
		{
			auto itr = instructorsPerCourse.find(course);
			if (itr==instructorsPerCourse.end())
			{
				std::vector<std::string> v;
				v.push_back(name);
				instructorsPerCourse.insert({course,v});
			}
			else
			{
				if (std::find( itr->second.begin(), itr->second.end(),name)==itr->second.end() )
				{
					(*itr).second.push_back(name);
				}
			}
		}
	}

 	auto app = Gtk::Application::create("org.gtkmm.example.button");
  	return app->make_window_and_run<ButtonWindow>(argc, argv);
}
