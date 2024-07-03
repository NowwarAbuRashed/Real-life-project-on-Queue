#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include<ctime>
#include<vector>
#include<string>
#include"clsString.h"
using namespace std;


class clsDate
{
private:


	short _Days;
	short _Month;
	short _Year;


protected:





public:


	static enum enCompardates { Befor = -1, Equal = 0, After = 1 };
	static enCompardates CompareDates(clsDate Date1, clsDate Date2)
	{
		if (CheckIfDate1IsLessThanDate2(Date1, Date2))
		{
			return enCompardates::Befor;
		}
		if (CheckIfDate1IsEqualsThanDate2(Date1, Date2))
		{
			return enCompardates::Equal;
		}
		return enCompardates::After;
	}

	clsDate()
	{
		GetsystemTime(_Days, _Month, _Year);
	}
	clsDate(string Date)
	{
		*this = StringToDate(Date);
	}
	clsDate(short Days, short Month, short Year)
	{
		_Days = Days;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short Days, short Year)
	{
		_Year = Year;
		_Month = 1;
		_Days = 1;
		IncreaseByXDay(Days);
	}
	void SetDays(short Days)
	{
		_Days = Days;
	}
	short GetDays()
	{
		return _Days;
	}
	__declspec(property(get = GetDays, put = SetDays))short Days;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear))short Year;



	static bool CheakIfYearIsLeapYearOrNot(short _Year)
	{
		return(_Year % 400 == 0 || (_Year % 4 == 0 && _Year % 100 != 0));
	}
	bool CheakIfYearIsLeapYearOrNot()
	{
		return CheakIfYearIsLeapYearOrNot(_Year);
	}

	static short NumberOfDaysInYear(short _Year)
	{
		return 365 + CheakIfYearIsLeapYearOrNot(_Year);
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}


	static short NumberOfHoursInYear(short _Year)
	{
		return NumberOfDaysInYear(_Year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}


	static int NumberOfMuintesInYear(short _Year)
	{
		return NumberOfHoursInYear(_Year) * 60;
	}
	int NumberOfMuintesInYear()
	{
		return NumberOfMuintesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short _Year)
	{
		return NumberOfMuintesInYear(_Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}


	static short NumberOfDaysInMonth(short _Month, short _Year)
	{
		short arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return((_Month < 1 || _Month>12) ? 0 : (_Month == 2) ? arr[_Month] + CheakIfYearIsLeapYearOrNot(_Year) : arr[_Month]);
	}
	short NumberOfDaysInMonth()
	{
		return  NumberOfDaysInMonth(_Month, _Year);
	}


	static short NumberOfHoursInMonth(short _Month, short _Year)
	{
		return NumberOfDaysInMonth(_Month, _Year) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}


	static int NumberOfMuintesInMonth(short _Month, short _Year)
	{
		return NumberOfHoursInMonth(_Month, _Year) * 60;
	}
	int NumberOfMuintesInMonth()
	{
		return  NumberOfMuintesInMonth(_Month, _Year);
	}


	static int NumberOfSecondsInMonth(short _Month, short _Year)
	{
		return NumberOfMuintesInMonth(_Month, _Year) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}


	static string DayShortName(short _Days)
	{
		string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[_Days];
	}
	string DayShortName()
	{
		return DayShortName(_Days);
	}

	static short DayOfWeakOrder(short _Days, short _Month, short _Year)
	{
		short A = (14 - _Month) / 12,
			y = _Year - A,
			m = _Month + (12 * A) - 2;
		return (_Days + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeakOrder()
	{
		return  DayOfWeakOrder(_Days, _Month, _Year);
	}

	static string MonthShortName(short _Month)
	{
		string arr[] = { "","Jan","Fep","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arr[_Month];
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short _Month, short _Year)
	{

		short FirstMonthInWeak = DayOfWeakOrder(1, _Month, _Year);
		short NumberDaysInThisMonth = NumberOfDaysInMonth(_Month, _Year);

		cout << "\n________________" << MonthShortName(_Month) << "________________\n\n";

		for (short i = 0; i < 7; i++)
		{
			cout << "  " << DayShortName(i);
		}
		cout << "\n";
		short i = 0;

		for (i = 0; i < FirstMonthInWeak; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= NumberDaysInThisMonth; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		cout << "\n___________________________________\n";

	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short _Year)
	{
		cout << "\n\n  _________________________________\n";

		printf("\n\t  Calendar - %d", _Year);

		cout << "\n  _________________________________\n";

		for (short i = 1; i <= 12; i++)
			PrintMonthCalendar(i, _Year);

	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short NumbersOfDaysFromBeginingOftheYear(short _Days, short _Month, short _Year)
	{
		short NumberDays = 0;
		for (int i = 1; i < _Month; i++)
		{
			NumberDays += NumberOfDaysInMonth(i, _Year);
		}
		NumberDays += _Days;

		return NumberDays;
	}
	short NumbersOfDaysFromBeginingOftheYear()
	{
		return NumbersOfDaysFromBeginingOftheYear(_Days, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short TotalDays, short _Year)
	{
		clsDate Date;
		Date._Year = _Year;
		Date._Month = 1;
		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date._Month, _Year);

			if (TotalDays > MonthDays)
			{
				TotalDays -= NumberOfDaysInMonth(Date._Month, _Year);
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}
			}
			else
			{
				Date._Days = TotalDays;
				break;
			}
		}

		return Date;
	}
	void GetDateFromDayOrderInYear()
	{
		*this = GetDateFromDayOrderInYear(NumbersOfDaysFromBeginingOftheYear(_Days, _Month, _Year), _Year);
	}

	static clsDate DateAddDays(clsDate Date, short AddDays)
	{
		short TotalDays = AddDays + NumbersOfDaysFromBeginingOftheYear(Date._Days, Date._Month, Date._Year);
		short MonthDays = 0;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date._Month, Date._Year);
			if (TotalDays > MonthDays)
			{

				TotalDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}
			}
			else
			{
				Date._Days = TotalDays;
				break;
			}

		}

		return Date;
	}
	void AddDays(short AddDays)
	{
		*this = DateAddDays(*this, AddDays);
	}

	static bool CheckIfDate1IsLessThanDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year == Date2._Year)
		{
			if (Date1._Month == Date2._Month)
			{
				return (Date1._Days < Date2._Days);
			}
			else
			{
				return (Date1._Month < Date2._Month) ? true : false;
			}
		}
		else
		{
			return (Date1._Year < Date2._Year) ? true : false;
		}
	}
	bool CheckIfDateIsLessThanDate2(clsDate Date2)
	{
		return CheckIfDate1IsLessThanDate2(*this, Date2);
	}

	static bool CheckIfDate1IsEqualsThanDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year != Date2._Year) ? false : (Date1._Month != Date2._Month) ? false : Date1._Days == Date2._Days;
	}
	bool CheckIfDateIsEqualsThanDate2(clsDate Date2)
	{
		return CheckIfDate1IsEqualsThanDate2(*this, Date2);
	}

	static bool CheakDayIslastDayInMonth(short _Days, short _Month, short _Year)
	{
		return (_Days == NumberOfDaysInMonth(_Month, _Year));
	}
	bool CheakDayIslastDayInMonth()
	{
		return CheakDayIslastDayInMonth(_Days, _Month, _Year);
	}

	static bool CheakMonthIslastDayInYear(short _Month)
	{
		return (_Month == 12);
	}
	bool CheakMonthIslastDayInYear()
	{
		return CheakMonthIslastDayInYear(_Month);
	}


	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (CheakDayIslastDayInMonth(Date._Days, Date._Month, Date._Year))
		{
			if (CheakMonthIslastDayInYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
				Date._Days = 1;
			}
			else
			{
				Date._Days = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Days++;
		}
		return Date;
	}
	void IncreaseByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludingEndDays = false)
	{
		bool Date1LessDate2 = CheckIfDate1IsLessThanDate2(Date1, Date2);

		if (!Date1LessDate2)
		{
			swap(Date1, Date2);
		}
		int SumDays = 0 + IncludingEndDays;

		while (Date1._Year < Date2._Year)
		{
			SumDays += NumberOfDaysInYear(Date1._Year);
			Date1._Year++;
		}
		if (Date1LessDate2)
		{
			return (SumDays + NumbersOfDaysFromBeginingOftheYear(Date2._Days, Date2._Month, Date2._Year) - NumbersOfDaysFromBeginingOftheYear(Date1._Days, Date1._Month, Date1._Year));
		}
		else
		{
			return -1 * (SumDays + NumbersOfDaysFromBeginingOftheYear(Date2._Days, Date2._Month, Date2._Year) - NumbersOfDaysFromBeginingOftheYear(Date1._Days, Date1._Month, Date1._Year));
		}
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludingEndDays = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludingEndDays);
	}

	static void GetsystemTime(short& Days, short& Month, short& Year)
	{
		time_t T = time(0);
		tm* Now = localtime(&T);
		Days = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;
	}

	static clsDate IncreaseDateByXDay(short Days, clsDate Date)
	{

		Date._Days += Days;

		while (Date._Days > NumberOfDaysInMonth(Date._Month, Date._Year))
		{

			Date._Days -= NumberOfDaysInMonth(Date._Month, Date._Year);

			if (CheakMonthIslastDayInYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 0;
			}

			Date._Month++;

		}
		return Date;
	}
	void IncreaseByXDay(short Days)
	{
		*this = IncreaseDateByXDay(Days, *this);

	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		Date = IncreaseDateByXDay(7, Date);
		return Date;
	}
	void IncreaseByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		Date = IncreaseDateByXDay((Weeks * 7), Date);
		return Date;
	}
	void IncreaseByXWeeks(short Weeks)
	{
		*this = IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		Date._Month++;
		if (Date._Month > 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		short NumberOfDaysInThisMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Days > NumberOfDaysInThisMonth);
		{
			Date._Days = NumberOfDaysInThisMonth;
		}
		return Date;
	}
	void IncreaseByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		Date._Month += Months;
		while (Date._Month > 12)
		{
			Date._Month -= 12;
			Date._Year++;
		}
		short NumberOfDaysInThisMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Days > NumberOfDaysInThisMonth);
		{
			Date._Days = NumberOfDaysInThisMonth;
		}
		return Date;
	}
	void IncreaseByXMonths(short Months)
	{
		*this = IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}
	void IncreaseByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		Date._Year += Years;
		return Date;
	}
	void IncreaseByXYears(short AddYears)
	{
		*this = IncreaseDateByXYears(AddYears, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date._Year += 10;
		return Date;
	}
	void IncreaseByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decades, clsDate Date)
	{
		Date._Year += (Decades * 10);
		return Date;
	}
	void IncreaseByXDecades(short Decades)
	{
		*this = IncreaseDateByXDecades(Decades, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;
		return Date;

	}
	void IncreaseByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}
	void IncreaseByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}



	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		Date._Days--;

		if (Date._Days < 1)
		{
			Date._Month--;

			if (Date._Month < 1)
			{
				Date._Year--;
				Date._Month = 12;
			}

			Date._Days = NumberOfDaysInMonth(Date._Month, Date._Year);
		}
		return Date;
	}
	void DecreaseByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDay(short Days, clsDate Date)
	{
		Date._Days -= Days;

		while (Date._Days < 1)
		{
			Date._Days += NumberOfDaysInMonth(Date._Month, Date._Year);
			Date._Month--;

			if (Date._Month < 1)
			{
				Date._Year--;
				Date._Month = 12;
			}
		}
		return Date;
	}
	void DecreaseByXDay(short Days)
	{
		*this = DecreaseDateByXDay(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		Date = DecreaseDateByXDay(7, Date);
		return Date;
	}
	void DecreaseByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		Date = DecreaseDateByXDay((Weeks * 7), Date);
		return Date;
	}
	void DecreaseByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks, *this);
	}


	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		Date._Month--;
		if (Date._Month < 1)
		{
			Date._Year--;
			Date._Month = 12;
		}
		short NumberOfDaysInThisMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Days > NumberOfDaysInThisMonth)
		{
			Date._Days = NumberOfDaysInThisMonth;
		}

		return Date;
	}
	void DecreaseByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}


	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		Date._Month -= Months;

		while (Date._Month < 1)
		{
			Date._Month += 12;
			Date._Year++;
		}
		short NumberOfDaysInThisMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Days > NumberOfDaysInThisMonth)
		{
			Date._Days = NumberOfDaysInThisMonth;
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months, *this);
	}


	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}
	void DecreaseByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}


	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		Date._Year -= Years;
		return Date;
	}
	void DecreaseByXYears(short Years)
	{
		*this = DecreaseDateByXYears(Years, *this);
	}


	static clsDate DecreaseByOneDecade(clsDate Date)
	{
		Date._Year -= 10;
		return Date;
	}
	void DecreaseByOneDecade()
	{
		*this = DecreaseByOneDecade(*this);
	}


	static clsDate DecreaseDateByXDecades(short Decades, clsDate Date)
	{
		Date._Year -= (Decades * 10);
		return Date;
	}
	void DecreaseByXDecades(short Decades)
	{
		*this = DecreaseDateByXDecades(Decades, *this);
	}


	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;

	}
	void DecreaseByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}


	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;

	}
	void DecreaseByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}





	static short DayOfWeakOrder(clsDate Date)
	{
		return DayOfWeakOrder(Date._Days, Date._Month, Date._Year);
	}
	short DayOfWeakOrder2()
	{
		return DayOfWeakOrder(*this);
	}


	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeakOrder(Date) == 6);
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}


	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndx = DayOfWeakOrder(Date);
		return (DayIndx == 5) || (DayIndx == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return (6 - (DayOfWeakOrder(Date)));
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		return (NumberOfDaysInMonth(Date._Month, Date._Year) + 1 - Date._Days);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		return   NumberOfDaysInYear(Date._Year) + 1 - NumbersOfDaysFromBeginingOftheYear(Date._Days, Date._Month, Date._Year);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculatVacationPeriod(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;


		while (CheckIfDate1IsLessThanDate2(DateFrom, DateTo))
		{

			if (!IsWeekEnd(DateFrom))
			{
				DaysCount++;
			}
			DateFrom = IncreaseDateByOneDay(DateFrom);

		}
		return DaysCount;
	}
	short CalculatVacationPeriod(clsDate DateTo)
	{
		return CalculatVacationPeriod(*this, DateTo);
	}

	static clsDate CalculatVacationPeriod(clsDate Date, short NumberOfVacatioDays)
	{
		do
		{
			if (!IsWeekEnd(Date))
			{
				NumberOfVacatioDays--;
			}
			Date = IncreaseDateByOneDay(Date);

		} while (NumberOfVacatioDays);

		return Date;
	}
	void CalculatVacationPeriod(short NumberOfVacatioDays)
	{
		*this = CalculatVacationPeriod(*this, NumberOfVacatioDays);
	}


	static bool CheckIfDate1IsAfterThanDate2(clsDate Date1, clsDate Date2)
	{
		return (!CheckIfDate1IsLessThanDate2(Date1, Date2) && !CheckIfDate1IsEqualsThanDate2(Date1, Date2));
	}
	bool CheckIfDateIsAfterThanDate2(clsDate Date2)
	{
		return CheckIfDate1IsAfterThanDate2(*this, Date2);
	}

	static bool CheckIfTheyOverlapOrNot(clsDate StartDate1, clsDate EndDate1, clsDate StartDate2, clsDate EndDate2)
	{
		return!(CompareDates(EndDate2, StartDate1) == enCompardates::Befor
			|| CompareDates(StartDate2, EndDate1) == enCompardates::After);
	}

	static short CalculatePeriodLengthInDays(clsDate StartDate, clsDate EndDate, bool IncludingEndDate = false)
	{
		return GetDifferenceInDays(StartDate, EndDate, IncludingEndDate);
	}
	short CalculatePeriodLengthInDays(clsDate EndDate, bool IncludingEndDate = false)
	{
		return CalculatePeriodLengthInDays(*this, EndDate, IncludingEndDate);
	}

	static bool CheckDateIsWithinPeriodOrNot(clsDate StartDate, clsDate EndDate, clsDate Date)
	{
		return !((CompareDates(Date, StartDate) == enCompardates::Befor) || (CompareDates(Date, EndDate) == enCompardates::After));
	}

	/*short CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Lingth = CalculatePeriodLengthInDays(Period1, true);
		int Period2Lingth = CalculatePeriodLengthInDays(Period2, true);
		int OverLapDays = 0;

		if (!CheckIfTheyOverlapOrNot(Period1, Period2))
			return 0;


		if (Period1Lingth < Period2Lingth)
		{
			while (CheckIfDate1IsBeforeThanDate2(Period1.StartDate, Period1.EndDate))
			{

				if (CheckDateIsWithinPeriodOrNot(Period2, Period1.StartDate))
				{
					OverLapDays++;
				}
				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (CheckIfDate1IsBeforeThanDate2(Period2.StartDate, Period2.EndDate))
			{

				if (CheckDateIsWithinPeriodOrNot(Period1, Period2.StartDate))
				{
					OverLapDays++;
				}
				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}
		return OverLapDays;

	}*/

	static bool IsValidateThisDate(clsDate Date)
	{
		return (Date._Days >= 1 && Date._Days <= NumberOfDaysInMonth(Date._Month, Date._Year)) ? (Date._Month >= 1 && Date._Month <= 12) : false;
	}
	bool IsValid()
	{
		return IsValidateThisDate(*this);
	}

	static clsDate StringToDate(string S1, string dump = "/")
	{
		vector<string>DateString = clsString::Split(S1, dump);

		clsDate Date;
		Date._Days = stoi(DateString[0]);
		Date._Month = stoi(DateString[1]);
		Date._Year = stoi(DateString[2]);
		return Date;
	}
	void StringTo(string S1, string dump = "/")
	{
		*this = StringToDate(S1, dump);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Days) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}



	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{

		string FormattedDateString = "";
		FormattedDateString = clsString::ReplaceWordsMatsh(DateFormat, "dd", to_string(Date._Days));
		FormattedDateString = clsString::ReplaceWordsMatsh(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = clsString::ReplaceWordsMatsh(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}
	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}

	void Print()
	{
		cout << DateToString(*this) << endl;
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);
		short Days, Month, Year, hour, minute, second;
		Days = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;
		hour = Now->tm_hour;
		minute = Now->tm_min;
		second = Now->tm_sec;

		return to_string(Days) + "/" + to_string(Month) + "/" + to_string(Year) +
			" - " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);

	}




};

