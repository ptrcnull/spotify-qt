#pragma once

#include <QLabel>
#include <QResizeEvent>

namespace View
{
	class ArtistCover: public QLabel
	{
	public:
		explicit ArtistCover(QWidget *parent);

		void setPixmap(const QByteArray &jpeg);

	protected:
		void resizeEvent(QResizeEvent *event) override;

	private:
		static constexpr int maxHeight = 160;
		static constexpr int maxWidth = 320;

		/** Y offset, should probably be removed */
		static constexpr int offset = 80;

		QPixmap cover;

		void scaleCover(int width);
	};
}