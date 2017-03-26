#include <iostream>

#include <iomanip>

using namespace std;

//----------------------------

class Data

{

	private:

		int year,month,day;

		void init();

	public:

		Data(const string& s);

		Data(int y = 2000,int m = 1,int d = 1);

		bool isLeapYear() const;

		friend ostream& operator<<(ostream& o,const Data& d);

		friend Data operator+(const Data& d,int t);

		friend int operator-(const Data& a,const Data& b);

};

//------------------------------------------------------------------------

void Data::init()

{

	if(year>5000||year<1||month<1||month>12||day<1||day>31)

	{

		cout<<"bad data\n";
		exit(1);

	}

}

//----------------------------------------------------

Data::Data( const string& s)

{

	year = atoi(s.substr(0,4).c_str());

	month = atoi(s.substr(5,2).c_str());

	day = atoi(s.substr(8,2).c_str());

	init();

}

//--------------------------------------------------------

Data::Data(int y,int m,int d)
{

	year = y;

	month = m;

	day = d;

	init();

}

//--------------------------------------------------------

bool Data::isLeapYear()const

{

	return (year % 4==0 && year % 100 ) || year % 400==0;

}

//--------------------------------------------------------------

ostream& operator<<(ostream& o,const Data& d)

{

	o<<setfill('0')<<setw(4)<<d.year<<'-'<<setw(2)<<d.month<<'-';

	return o<<setw(2)<<d.day<<'\n'<<setfill(' ');

}

//------------------------------------------------------------------------
Data operator+(const Data& d,int t)
{
    int countmonth = d.month;
    int countyear = d.year;
    int countday = t+d.day;
    countmonth += countday/30;
    countyear += countmonth/12;
    countday = countday%30;
    countmonth = countmonth%12;
    Data temp( countyear , countmonth , countday );
    return temp;
}
//------------------------------------------------------------------------
int operator-(const Data& a,const Data& b)
{
	int minusyear = a.year-b.year;
	int minusmonth = a.month-b.month;
	int minusday = a.day-b.day;
	minusday += (minusmonth*30+minusyear*365);
	return minusday;
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class WData : public Data
{
    private:
    enum Week{Monday,Tuseday,Wenseday,Thrusday,Friday,Saturday,Sunday} week;
    public:
    WData();
    friend ostream& operator<<(ostream& o,const WData& s);

};
//--------------------------------------------------------------------------
int main()

{

	Data c("2005-12-28");

	Data d(2003,12,6);

	Data e(2002);

	Data f(2002,12);

	Data g(d+300);

	cout<<c<<d<<e<<f<<g<<(g-d);

	return 0;

}
