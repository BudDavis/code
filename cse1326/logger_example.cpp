#include <iostream>
#include <fstream>
#include <string>
class logger
{
	public:
	// this is an abstraction of a logger.
	// There are actually 3 functions here,
	// the constructor, the deconstructor, and out.
	//
	virtual int out(std::string S) = 0; // {return 0;};
	logger() {};
	virtual ~logger() {};
};
class console : public logger
{
	public:
	// this flavor of logger 
	// writes to stdout
	int out (std::string S) final
	{
		std::cout << S << std::endl;
		std::cout.flush();
		return 0;
	}
	
	console ()
	{
		// since the console connection exists when the program
		// starts, we don't need to do much...
		std::cout << "console logger created" << std::endl;
	}
	~console () final
	{
		// likewise, we don't need to do anything here.
		std::cout << "console logger is destructed" << std::endl;
	}
	
};

class file : public logger
{
	private:
		// the details of the writing to a file are hidden from the user.
	std::ofstream *f = nullptr;
	public:
	int out(std::string S) final
	{
		// print this to a file
		*f << S;
		f->flush();
		return 0; // implies no error
	}
	file ()
	{
		// when the object is created, we open the file
		f = new std::ofstream("outfile");
		std::cout << "file logger is created " << std::endl;
	}
	~file() final
	{
		// when the object is destroyed, we close the file
		f->close();
		f = nullptr; // just so we can't use it anymore
		std::cout << "file logger is closed" << std::endl;
	}
};

class nullLogger : public logger
{
	public:
	nullLogger() {};
	~nullLogger() {};
	int out(std::string S) { return 0; }
};

class dog
{
	public:
		logger *l;
		std::string name;
		dog( logger *l_)
		{
			name="unknown";
			l = l_;
		}
		dog ( logger *l_, std::string n)
		{
			name = n;
			l = l_;
		}
		void bark (std::string S)
		{
			// weak idea, I admit
			l->out(name + " " + S);
		}
		~dog()
		{
		}
	
};
int main()
{
	// at the very begining, create both loggers
	logger *conLog = new console();
	logger *fileLog = new file();
	logger *noLog = new nullLogger();

	dog houseDog(conLog,"lady bird");
	dog farmDog(fileLog,"spot");
	houseDog.l = fileLog;
	houseDog.bark("woof");

	houseDog.l = conLog;
	houseDog.bark("meow");

	houseDog.l = noLog;
	houseDog.bark("meow or woof");

	// clean up
	delete conLog;
	conLog =  nullptr;
	delete fileLog;
	fileLog = nullptr;
	delete noLog;
	noLog = nullptr;

	return 0;
}
