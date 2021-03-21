#include "dateutils.hpp"

#define SECS_IN_YEAR 31557600
#define SECS_IN_MONTH 2629800
#define SECS_IN_WEEK 604800
#define SECS_IN_DAY 86400
#define SECS_IN_HOUR 3600
#define SECS_IN_MINUTE 60

QString DateUtils::toRelative(const QDateTime &date)
{
	auto amount = date.secsTo(QDateTime::currentDateTimeUtc());
	QString unit = "second";

	if (amount >= SECS_IN_YEAR)
	{
		amount /= SECS_IN_YEAR;
		unit = "year";
	}
	else if (amount >= SECS_IN_MONTH)
	{
		amount /= SECS_IN_MONTH;
		unit = "month";
	}
	else if (amount >= SECS_IN_WEEK)
	{
		amount /= SECS_IN_WEEK;
		unit = "week";
	}
	else if (amount >= SECS_IN_DAY)
	{
		amount /= SECS_IN_DAY;
		unit = "day";
	}
	else if (amount >= SECS_IN_HOUR)
	{
		amount /= SECS_IN_HOUR;
		unit = "hour";
	}
	else if (amount >= SECS_IN_MINUTE)
	{
		amount /= SECS_IN_MINUTE;
		unit = "minute";
	}

	return QString("%1 %2%3 ago")
		.arg(amount)
		.arg(unit)
		.arg(amount == 1 ? "" : "s");
}

bool DateUtils::isEmpty(const QDateTime &date)
{
	return date.toSecsSinceEpoch() <= 0;
}

QDateTime DateUtils::fromIso(const QString &date)
{
	return QDateTime::fromString(date, Qt::ISODate);
}

QDateTime DateUtils::fromIso(const std::string &date)
{
	return fromIso(QString::fromStdString(date));
}
