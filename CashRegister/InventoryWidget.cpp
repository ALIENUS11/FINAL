#include "InventoryWidget.h"
#include "MyDataBase.h"
#include "InputDialog.h"
#include <QMessageBox>
InventoryWidget::InventoryWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::InventoryWidgetClass())
{
	ui->setupUi(this);
	
	Init();
	
}

InventoryWidget::~InventoryWidget()
{
	delete ui;
}

void InventoryWidget::Init()
{
	ui->tableWidget->setColumnCount(4);
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("名称")<< QStringLiteral("价格")<<QStringLiteral("数量");
	ui->tableWidget->setHorizontalHeaderLabels(header);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	auto list = MyDataBase::GetInstance().GetGoods();
	int row = 0;
	for (auto& good : list)
	{
		ui->tableWidget->insertRow(row);
		ui->tableWidget->setItem(row, 0, new QTableWidgetItem(good.barCode));
		ui->tableWidget->setItem(row, 1, new QTableWidgetItem(good.name));
		ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(good.price)));
		ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(good.number)));

		//居中 不可编辑
		for (int i = 0; i < 4; i++)
		{
			ui->tableWidget->item(row, i)->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->item(row, i)->setFlags(ui->tableWidget->item(row, i)->flags() & ~Qt::ItemIsEditable);
		}
	}
}

void InventoryWidget::Refresh()
{
	ui->tableWidget->setRowCount(0);
	auto list = MyDataBase::GetInstance().GetGoods();
	int row = 0;
	for (auto& good : list)
	{
		ui->tableWidget->insertRow(row);
		ui->tableWidget->setItem(row, 0, new QTableWidgetItem(good.barCode));
		ui->tableWidget->setItem(row, 1, new QTableWidgetItem(good.name));
		ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(good.price)));
		ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(good.number)));

		//居中 不可编辑
		for (int i = 0; i < 4; i++)
		{
			ui->tableWidget->item(row, i)->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->item(row, i)->setFlags(ui->tableWidget->item(row, i)->flags() & ~Qt::ItemIsEditable);
		}
	}
}

void InventoryWidget::OnDataReceived(const QByteArray& data)
{
	QString barCode = data;
	barCode.remove('\r');
	QString name = MyDataBase::GetInstance().GetGoodsName(barCode);
	if(name.isEmpty())
	{
		InputDialog* dialog = InputDialog::createInputDialog(barCode);
		if (dialog->exec() == QDialog::Accepted) {
			InputDialog::FormData formData = dialog->getFormData();
			MyDataBase::GetInstance().AddNewGoods(barCode, formData.name, formData.price, formData.quantity);
			//添加到表格,插入第一行
			ui->tableWidget->insertRow(0);
			ui->tableWidget->setItem(0, 0, new QTableWidgetItem(barCode));
			ui->tableWidget->setItem(0, 1, new QTableWidgetItem(formData.name));
			ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(formData.price)));
			ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(formData.quantity)));

			for (int i = 0; i < 4; i++)
			{
				ui->tableWidget->item(0, i)->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->item(0, i)->setFlags(ui->tableWidget->item(0, i)->flags() & ~Qt::ItemIsEditable);
			}

			QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("添加成功!"));

		}
		delete dialog;
	}
	else
	{
		//添加库存
		QuantityDialog * dialog = QuantityDialog::createQuantityDialog();
		if (dialog->exec() == QDialog::Accepted) {
			QuantityDialog::FormData formData = dialog->getFormData();
			MyDataBase::GetInstance().AddGoods(barCode, formData.quantity);
			//更新表格 先找到行
			for (int i = 0; i < ui->tableWidget->rowCount(); i++)
			{
				if (ui->tableWidget->item(i, 0)->text() == barCode)
				{
					ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(formData.quantity + ui->tableWidget->item(i, 3)->text().toInt())));
					//居中 不可编辑
					ui->tableWidget->item(i, 3)->setTextAlignment(Qt::AlignCenter);
					ui->tableWidget->item(i, 3)->setFlags(ui->tableWidget->item(i, 3)->flags() & ~Qt::ItemIsEditable);
					break;
				}
			}
			QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("添加成功!"));
		}
		delete dialog;
	}
}