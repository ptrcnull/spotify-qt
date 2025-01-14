#include "util/url.hpp"

void Url::open(const QString &url, LinkType linkType, QWidget *parent)
{
	if (!QDesktopServices::openUrl(QUrl(url)))
	{
		Dialog::OpenLink(url, linkType, parent).exec();
	}
}

void Url::open(const std::string &url, LinkType linkType, QWidget *parent)
{
	open(QString::fromStdString(url), linkType, parent);
}
