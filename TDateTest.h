
/*(1)cout << TDate::IsLeapYear(-1) << endl;false*/
/*(2)TDate::isleapyear(0);false*/
/*(3)TDate::isleapyear(20000);false*/
/*(4)TDate::isleapyear(10000);false*/
/*(5)TDate::isleapyear(9999);false*/
/*(6)TDate::isleapyear(9998);false*/
/*(7)TDate::isleapyear(8888);true*/
/*(8)TDate::isleapyear(1998);false*/
/*(9)TDate::isleapyear(1000);false*/
/*(10)TDate::isleapyear(2000);true*/
/*(11)TDate::isleapyear(2012);true*/
/*(12)TDate::isleapyear(2013);false*/

/*(1)cout << TDate::GetDaysInMonth(20000, 1) << endl;0*/
/*(2)TDate::GetDaysInMonth(10000, 1);0*/
/*(3)TDate::GetDaysInMonth(-1, 1);0*/
/*(4)TDate::GetDaysInMonth(0, 1);0*/
/*(5)TDate::GetDaysInMonth(0, 0);0*/
/*(6)TDate::GetDaysInMonth(2015, -1);0*/
/*(7)TDate::GetDaysInMonth(2015, 0);0*/
/*(8)TDate::GetDaysInMonth(2015, 13);0*/
/*(9)TDate::GetDaysInMonth(2015, 14);0*/
/*(10)TDate::GetDaysInMonth(1998, 2);28;*/
/*(11)TDate::GetDaysInMonth(4, 2);29*/
/*(12)TDate::GetDaysInMonth(1000, 2);28*/
/*(13)TDate::GetDaysInMonth(2000, 2);29*/
/*(14)TDate::GetDaysInMonth(2012, 2);29*/
/*(15)TDate::GetDaysInMonth(2013, 2);28*/
/*(16)TDate::GetDaysInMonth(9999, 2);28*/
/*(17)TDate::GetDaysInMonth(9998, 2);28*/
/*(18)TDate::GetDaysInMonth(1, 1);31*/
/*(19)TDate::GetDaysInMonth(2, 2);28*/
/*(20)TDate::GetDaysInMonth(3, 3);31*/
/*(21)TDate::GetDaysInMonth(9999, 4);30*/
/*(22)TDate::GetDaysInMonth(9998, 5);31*/
/*(23)TDate::GetDaysInMonth(9997, 6);30*/
/*(24)TDate::GetDaysInMonth(1000, 7);31*/
/*(25)TDate::GetDaysInMonth(2000, 8);31*/
/*(26)TDate::GetDaysInMonth(3000, 9);30*/
/*(27)TDate::GetDaysInMonth(4000, 10);31*/
/*(28)TDate::GetDaysInMonth(2015, 11);30*/
/*(29)TDate::GetDaysInMonth(2015, 12);31*/


/*
*TDate date;
*cout << date.ToString();
*2015-07-30
*/

/*
TDate date(20000,1,1);
if (date.IsValid())
{
cout << date.ToString()<< endl;
}
else
{
cout << date.GetErrorInfo() << endl;
}
*/
//TDate date(10000, 12, 31) wrong date
//TDate date(-1, 1, 31)  wrong date
//TDate date(0,2,28)  wrong date
//TDate date(1,-1,1)  wrong date
//TDate date(1,0,1)  wrong date
//TDate date(1,13,1)  wrong date
//TDate date(1,14,1)  wrong date
//TDate date(1,12,-1)  wrong date
//TDate date(9999,12,0)  wrong date
//TDate date(9998,12,32)  wrong date
//TDate date(1,4,31)  wrong date
//TDate date(1000,2,29)  wrong date
//TDate date(2000,2,29)  2000-02-29
//TDate date(1,1,1) 1-01-01
//TDate date(4,2,29)  4-02-29
//TDate date(9999, 12, 31)  9999-12-31
//TDate date(9998,11,30)  9998-11-30
//TDate date(2,2,2)  2-02-02


//(1)cout << (TDate(0, 0,0 ) == (TDate(1, 1, 1))) << endl;false
//(2)TDate(-1, 0, 0) != TDate(9999, 12, 31)false
//(3)TDate(1, 1, 0) > TDate(2011, 1, 1)false
//(4)TDate(1, 1, 0) < TDate(2011, 1, 1)false
//(5)TDate(1, 1, 1) >= TDate(2011, 2, 29)false
//(6)TDate(10000, 1, 1) <= TDate(9999, 12, 31)false
//(7)TDate(1, 1, 1) == TDate(2, 1, 1)false
//(8)TDate(1, 1, 1) == TDate(1, 2, 1)false
//(9)TDate(1, 1, 1) == TDate(1, 1, 2)false
//(10)TDate(1, 1, 1) == TDate(1, 1, 1)true
//(11)TDate(1, 1, 1) != TDate(2, 1, 1)true
//(12)TDate(1, 1, 1) != TDate(1, 2, 1)true
//(13)TDate(1, 1, 1) != TDate(1, 1, 2)true
//(14)TDate(1, 1, 1) != TDate(1, 1, 1)false
//(15)TDate(9999, 12, 31) > TDate(9998, 12, 31)true
//TDate(9999, 12, 31) > TDate(9999, 11, 31)false
//TDate(9999, 12, 31) > TDate(9999, 12, 30)true
//TDate(9999, 12, 31) > TDate(9999, 12, 31)false
//TDate(9998, 12, 31) < TDate(9999, 12, 31)true
//TDate(9999, 11, 31) < TDate(9999, 12, 31)false
//TDate(9999, 12, 30) < TDate(9999, 12, 31)true
//TDate(9999, 12, 31) < TDate(9999, 12, 31)false
//TDate(9999, 12, 31) >= TDate(9998, 12, 31)true
//TDate(9999, 12, 31) >= TDate(9999, 11, 31)false
//TDate(9999, 12, 31) >= TDate(9999, 12, 30)true
//TDate(9999, 12, 31) >= TDate(9999, 12, 31)true
//TDate(9998, 12, 31) <= TDate(9999, 12, 31)true
//TDate(9999, 11, 31) <= TDate(9999, 12, 31)false
//TDate(9999, 12, 30) <= TDate(9999, 12, 31)true
//TDate(9999, 12, 31) <= TDate(9999, 12, 31)true
//TDate(2012, 2, 29) > TDate(2012, 3, 1)false
//TDate(2012, 2, 29) < TDate(2012, 3, 1)true

/*(1)TDate date(0, 0, 0);date.AddDays(1);
if (date.IsValid())
{
cout << date.ToString();
}
else
{
cout << date.GetErrorInfo();
}
wrong date
*/
//(2)TDate date(10000, 1, 1); date.AddDays(-1);wrong date
//(3)TDate date(1, 1, 1); date.AddDays(-1);over range
//(4)TDate date(1, 1, 2); date.AddDays(-2);over range
//(5)TDate date(1, 1, 10); date.AddDays(-10);over range
//(6)TDate date(9999, 12, 31); date.AddDays(1);over range
//(7)TDate date(9999, 12, 30); date.AddDays(2);over range
//(8)TDate date(9999, 12, 21); date.AddDays(11);over range
//(9)TDate date(1000, 2, 28); date.AddDays(1);1000-03-01
//(10)TDate date(1000, 2, 20); date.AddDays(9);1000-03-01
//(11)TDate date(1000, 3, 1); date.AddDays(-1);1000-02-28
//(12)TDate date(1000, 3, 1); date.AddDays(-9);1000-02-20
//(13)TDate date(2012, 2, 28); date.AddDays(1);2012-02-29
//(14)TDate date(2012, 2, 20); date.AddDays(9);2012-02-29
//(15)TDate date(2012, 3, 1); date.AddDays(-1);2012-02-29
//(16)TDate date(2012, 3, 1); date.AddDays(-9);2012-02-21
//(17)TDate date(2011, 12, 31); date.AddDays(1);2012-01-01
//(18)TDate date(2011, 12, 31); date.AddDays(60);2012-02-29
//(19)TDate date(2012, 2, 29); date.AddDays(-60);2011-12-31
//(20)TDate date(2011, 12, 31); date.AddDays(61);2012-03-01
//(21)TDate date(2012, 3, 1); date.AddDays(-61);2011-12-31
//(22)TDate date(1999, 1, 1); date.AddDays(10000);2026-05-19
//(23)TDate date(2026, 5, 19); date.AddDays(-10000);1999-01-01

/*(1)TDate date(0, 0, 0); date.AddMonths(1);
if (date.IsValid())
{
cout << date.ToString() << endl;
}
else
{
cout << date.GetErrorInfo() << endl;
}
wrong date
*/
//(2)TDate date(10000, 1, 1); date.AddMonths(-1);wrong date
//(3)TDate date(1, 1, 1); date.AddMonths(-1);over range
//(4)TDate date(1, 2, 2); date.AddMonths(-2); over range
//(5)TDate date(1, 10, 10); date.AddMonths(-10); over range
//(6)TDate date(9999, 12, 31); date.AddMonths(1);over range
//(7)TDate date(9999, 11, 31); date.AddMonths(2);wrong date
//(8)TDate date(9999, 3, 31); date.AddMonths(10);over range
//(9)TDate date(1000, 1, 29); date.AddMonths(1);1000-02-28
//(10)TDate date(2000, 1, 29); date.AddMonths(1);2000-02-29
//(11)TDate date(2012, 1, 28); date.AddMonths(1);2000-02-28
//(12)TDate date(2012, 1, 29); date.AddMonths(1);2012-02-29
//(13)TDate date(1000, 3, 28); date.AddMonths(-1);1000-02-28
//(14)TDate date(1000, 3, 29); date.AddMonths(-1);1000-02-28
//(15)TDate date(2012, 3, 28); date.AddMonths(-1);2012-02-28
//(16)TDate date(2012, 3, 29); date.AddMonths(-1);2012-02-29
//(17)TDate date(2011, 12, 31); date.AddMonths(1);2012-01-31
//(18)TDate date(2011, 2, 1); date.AddMonths(60);2016-02-01
//(19)TDate date(2016, 2, 1); date.AddMonths(-60);2011-02-01
//(20)TDate date(1, 1, 1); date.AddMonths(10000);834-05-01
//(21)TDate date(834, 5, 1); date.AddMonths(-10000);1-01-01
//(22)TDate date(9999, 12, 31); date.AddMonths(0);9999-12-31

/*(1)TDate date(0, 0, 0); date.AddYears(1);
if (date.IsValid())
{
cout << date.ToString() << endl;
}
else
{
cout << date.GetErrorInfo() << endl;
}
wrong date
*/
//(2)TDate date(10000, 1, 1); date.AddYears(-1);wrong date
//(3)TDate date(1, 1, 1); date.AddYears(-1);over range
//(4)TDate date(2, 2, 2); date.AddYears(-2);over range
//(5)TDate date(10, 10, 10); date.AddYears(-10);over range
//(6)TDate date(9999, 12, 31); date.AddYears(1);over range
//(7)TDate date(9990, 12, 31); date.AddYears(10);over range
//(8)TDate date(2012, 2, 28); date.AddYears(1);2013-02-28
//(9)TDate date(2012, 2, 29); date.AddYears(1);2013-02-28
//(10)TDate date(2012, 2, 28); date.AddYears(-1);2011-02-28
//(11)TDate date(2012, 2, 29); date.AddYears(-1);2011-02-28
//(12)TDate date(2012, 2, 29); date.AddYears(12);2024-02-29
//(13)TDate date(2024, 2, 29); date.AddYears(-12);2012-02-29
//(14)TDate date(1, 1, 1); date.AddYears(9998);9999-01-01
//(15)TDate date(9999, 1, 1); date.AddYears(-9998);1-01-01
//(16)TDate date(9999, 12, 31); date.AddYears(0);9999-12-31

//(1)TDate date("") wrong date
//(2)TDate date(null)
//(3)TDate date("2015") wrong date
//(4)TDate date("201506") wrong date
//(5)TDate date("20150620") wrong date
//(6)TDate date("-") wrong date
//(7)TDate date("1-1") wrong date
//(8)TDate date("-1") wrong date
//(9)TDate date("1-") wrong date
//(10)TDate date("--") wrong date
//(11)TDate date("-1-") wrong date
//(12)TDate date("-1-1") wrong date
//(13)TDate date("1-1-") wrong date
//(14)TDate date("1--1") wrong date
//(15)TDate date("--1") wrong date
//(16)TDate date("1--") wrong date
//(17)TDate date("1-1-1-") wrong date
//(18)TDate date("-1-1-1") wrong date
//(19)TDate date("10000-1-1") wrong date
//(20)TDate date("9999-0-1") wrong date
//(21)TDate date("1-1-0") wrong date
//(22)TDate date("9999-13-1") wrong date
//(23)TDate date("1-1-32") wrong date
//(24)TDate date("1000-2-29") wrong date
//(25)TDate date("2012-2-29") 2012-02-29
//(26)TDate date("1-1-1") 1-01-01
//(27)TDate date("02-02-02") 2-02-02
//(28)TDate date("9999-12-31") 9999-12-31
//(29)TDate date("9999-1-1") 9999-01-01
//(30)TDate date("9999-12-1") 9999-12-01
//(31)TDate date("9999-1-31") 9999-01-31
