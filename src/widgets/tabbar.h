/*
 * tabbar.h
 * Copyright (C) 2013-2014  Ivan Romanov <drizt@land.ru>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#pragma once

#include <QTabBar>

class TabBar : public QTabBar
{
	Q_OBJECT
public:
	explicit TabBar(QWidget *parent = 0);

	void layoutTabs();

	void setMultiRow(bool b);
	bool multiRow() const;

	// reimplemented
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
	QSize tabSizeHint(int index) const;
	void setTabsClosable(bool b);
	bool tabsClosable() const;
	void setCurrentIndex(int index);
	void setTabText(int index, const QString &text);
	void setTabTextColor(int index, const QColor &color);
	void setTabIcon(int index, const QIcon &icon);
	QRect tabRect(int index) const;

protected:
	// reimplemented
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void tabInserted(int index);
	void tabRemoved(int index);

private slots:
	void closeTab();

private:
	class Private;
	Private *d;
};
