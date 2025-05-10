#include "CashLogWidget.h"
#include "MyDataBase.h"
CashLogWidget::CashLogWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::CashLogWidgetClass())
{
	ui->setupUi(this);
	
	ui->tableWidget->setColumnCount(5);
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("商品名称")<< QStringLiteral("数量") <<QStringLiteral("出库日期") << QStringLiteral("价格");
	ui->tableWidget->setHorizontalHeaderLabels(header);
	
	Load();
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	
}

CashLogWidget::~CashLogWidget()
{
	delete ui;
}

void CashLogWidget::Load()
{
	auto list = MyDataBase::GetInstance().GetSellRecord();
	for(auto& item : list)
	{
		ui->tableWidget->insertRow(ui->tableWidget->rowCount());
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(item.barCode));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(item.name));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::number(item.number)));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(item.time));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::number(item.price)));

		//居中
		for (int i = 0; i < 5; i++)
		{
			ui->tableWidget->item(ui->tableWidget->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);
		}
	}
}

void CashLogWidget::Refresh()
{
	ui->tableWidget->setRowCount(0);
	Load();
}
