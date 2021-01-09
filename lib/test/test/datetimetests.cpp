#include "lib/datetime.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "thirdparty/doctest.h"

TEST_CASE("date_time tests")
{
	lib::date_time date_time;

	auto validate_date = [&date_time](int year, int month, int day,
		int hour = 0, int minute = 0, int second = 0)
	{
		CHECK(date_time.is_valid());

		CHECK_EQ(year, date_time.get_year());
		CHECK_EQ(month, date_time.get_month());
		CHECK_EQ(day, date_time.get_day());
		CHECK_EQ(hour, date_time.get_hour());
		CHECK_EQ(minute, date_time.get_minute());
		CHECK_EQ(second, date_time.get_second());
	};

	SUBCASE("can get now")
	{
		date_time = lib::date_time::now();

		// We can't really make sure it's valid, but it should be after 2021-01-01
		CHECK(date_time.is_valid());
		CHECK(date_time.get_year() >= 2021);
		CHECK(date_time.get_month() >= 1);
		CHECK(date_time.get_day() >= 1);
	}

	SUBCASE("can get now utc")
	{
		date_time = lib::date_time::now_utc();

		// Similar issue like with now
		CHECK(date_time.is_valid());
		CHECK(date_time.get_year() >= 2021);
		CHECK(date_time.get_month() >= 1);
		CHECK(date_time.get_day() >= 1);
	}

	SUBCASE("can parse iso date time")
	{
		date_time = lib::date_time::parse("2001-02-03T14:15:16Z");
		validate_date(2001, 02, 03, 14, 15, 16);
	}

	SUBCASE("can parse iso date")
	{
		date_time = lib::date_time::parse("2002-03-04");
		validate_date(2002, 03, 04);
	}
}
