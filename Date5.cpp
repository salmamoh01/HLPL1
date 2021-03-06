#include "std_lib_facilities.h"

//Drill 9 Q5

enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}
vector<string> months {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];

}

class Date {
private:
	int y;
	Month m;
	int d;
	
	bool is_valid()
	{
		if (y < 0 ||  d < 0  || d > 31)
			return false;
		else 
			return true;				
	}

public:
	Date(): y(2001), m(Month::jan), d(1) {}	//default value

	Date(int yy, Month mm, int dd): y(yy), m(mm), d(dd)
	{
		if (!is_valid()) error("Invalid date");
			
			
	}
	int get_year() const { return y; }
	Month get_month() const { return m; }
	int get_day() const { return d; }
	void set_year (int yy) 
	{ 
		if (yy < 0) error ("Invalid year");
		y = yy; 	
	}
	void set_month (Month mm) 
	{
		m = mm;
	}
	void set_day (int dd) 
	{ 
		if (dd < 0  || dd > 31) error ("Invalid day");
		d = dd; 
	}
	void add_day(int n)
	{
		d+=n;
		if (d > 31)
		{
			++m;
			d-=31;
			if (m == Month::jan)
			{
				++y;
			}
		}
	}
}; //must have ";" after class and struct


ostream& operator<<(ostream& os, const Date& date)
{
	return os << date.get_year() << " "
		  << date.get_month() << " "
		  << date.get_day() << " ";
}


int main()
try {
	const Date today (1978, Month::jun, 25);
	cout << today << endl;
	
	
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow << endl;
	
	Date invalid(2004, Month::apr, -5);
	cout << invalid << endl;
	
	

	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}




