#include "CheckoutWidget.h"
#include "MyDataBase.h"
#include <QMessageBox>
#include "SpinBoxDelegate.h"
#include <QMenu>
CheckoutWidget::CheckoutWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::CheckoutWidgetClass())
{
	ui->setupUi(this);

	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("商品名称") << QStringLiteral("单价") << QStringLiteral("数量") << QStringLiteral("价格");
	ui->tableWidget->setColumnCount(5);
	ui->tableWidget->setHorizontalHeaderLabels(header);

	//设置自适应列宽
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	//双击数量一列可以修改数量
	ui->tableWidget->setItemDelegateForColumn(3, new SpinBoxDelegate(this));


	//总价
	ui->label_price->setText("0");


	//右键菜单删除
	ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, [this](const QPoint& pos)
		{
			QMenu menu(this);
			QAction* deleteAction = menu.addAction(QStringLiteral("删除"));
			QAction* action = menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));
			if (action == deleteAction)
			{
				int row = ui->tableWidget->currentRow();
				ui->tableWidget->removeRow(row);
				Calculate();
			}
		});

	//结算按钮
	connect(ui->pushButton, &QPushButton::clicked, [this]()
		{
			if (ui->tableWidget->rowCount() > 0)
			{
				if (!CheckStockAvailability()) // 检查库存
					return; // 库存不足，终止结算

				UpdateStock(); // 此时库存已确认足够

				// 保存出售记录
				for (int i = 0; i < ui->tableWidget->rowCount(); i++)
				{
					MyDataBase::GetInstance().AddSellRecord(
						ui->tableWidget->item(i, 0)->text(),
						ui->tableWidget->item(i, 3)->text().toInt(),
						ui->tableWidget->item(i, 4)->text().toDouble()
					);
				}

				QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("出库成功"));
				Clear();
				emit CheckoutFinished();
			}
			else
			{
				QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("没有商品"));
			}
		});

	connect(ui->tableWidget->model(), &QAbstractItemModel::dataChanged,
		[this](const QModelIndex& topLeft, const QModelIndex& bottomRight)
		{
			if (topLeft.column() <= 3 && bottomRight.column() >= 3) {
				//只计算当前行的价格
				int row = topLeft.row();
				double price = ui->tableWidget->item(row, 2)->text().toDouble() * ui->tableWidget->item(row, 3)->text().toDouble();
				if(ui->tableWidget->item(row, 4))
					ui->tableWidget->item(row, 4)->setText(QString::number(price));
				Calculate();
			}
		});

	ui->label->hide();
	ui->label_price->hide();
}

CheckoutWidget::~CheckoutWidget()
{
	delete ui;
}

void CheckoutWidget::Calculate()
{
	double sum = 0;
	for (int i = 0; i < ui->tableWidget->rowCount(); i++)
	{
		if(ui->tableWidget->item(i, 4))
			sum += ui->tableWidget->item(i, 4)->text().toDouble();
	}
	ui->label_price->setText(QString::number(sum));
}

void CheckoutWidget::UpdateStock()
{
	if (!CheckStockAvailability()) // 先检查库存
		return; // 库存不足，不执行更新

	for (int i = 0; i < ui->tableWidget->rowCount(); i++)
	{
		MyDataBase::GetInstance().ReduceGoods(
			ui->tableWidget->item(i, 0)->text(),
			ui->tableWidget->item(i, 3)->text().toInt()
		);
	}
}

void CheckoutWidget::Clear()
{
	ui->tableWidget->clearContents();
	ui->tableWidget->setRowCount(0);
	ui->label_price->setText("0");

}


void CheckoutWidget::OnDataReceived(const QByteArray& data)
{
	QString barCode = data;
	barCode.remove('\r');
	Good g = MyDataBase::GetInstance().GetGoods(barCode);
	if (g.barCode != "")
	{
		ui->tableWidget->insertRow(ui->tableWidget->rowCount());
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(g.barCode));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(g.name));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::number(g.price)));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem("1"));
		ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::number(g.price)));

	    
		//居中
		for (int i = 0; i < 5; i++)
		{
			ui->tableWidget->item(ui->tableWidget->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);
			//除了数量 都不可编辑
			if (i != 3)
			{
				ui->tableWidget->item(ui->tableWidget->rowCount() - 1, i)->setFlags(ui->tableWidget->item(ui->tableWidget->rowCount() - 1, i)->flags() & ~Qt::ItemIsEditable);
			}
		}

		Calculate();
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("错误"), QStringLiteral("仓库中不含有这种商品，请先入库!"));
	}
}

bool CheckoutWidget::CheckStockAvailability()
{
	for (int i = 0; i < ui->tableWidget->rowCount(); i++)
	{
		QString barCode = ui->tableWidget->item(i, 0)->text();
		int requestedQuantity = ui->tableWidget->item(i, 3)->text().toInt();
		int currentStock = MyDataBase::GetInstance().GetGoodsQuantity(barCode);

		if (currentStock < requestedQuantity)
		{
			QString goodsName = MyDataBase::GetInstance().GetGoodsName(barCode);
			QMessageBox::warning(this, QStringLiteral("库存不足"),
				QStringLiteral("商品 '%1' 库存不足，当前库存: %2，请求数量: %3")
				.arg(goodsName).arg(currentStock).arg(requestedQuantity));
			return false;
		}
	}
	return true;
}

