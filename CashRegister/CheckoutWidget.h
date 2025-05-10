#pragma once

#include <QWidget>
#include "ui_CheckoutWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CheckoutWidgetClass; };
QT_END_NAMESPACE


class CheckoutWidget : public QWidget
{
	Q_OBJECT

public:
	CheckoutWidget(QWidget *parent = nullptr);
	~CheckoutWidget();
	
	void Calculate();
	//更新库存
	void UpdateStock();
	//清空
	void Clear();

	bool CheckStockAvailability();

signals:
	void CheckoutFinished();
public slots:
	void OnDataReceived(const QByteArray &data);
private:
	Ui::CheckoutWidgetClass *ui;
};
