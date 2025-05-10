#include "CashRegister.h"
#include "CashLogWidget.h"
#include "CheckoutWidget.h"
#include "InventoryWidget.h"
#include "SerialPortManager.h"


struct CashRegister::CashRegisterPrivate
{
    CashLogWidget *cashLogWidget = new CashLogWidget;
    CheckoutWidget *checkoutWidget = new CheckoutWidget;
    InventoryWidget *inventoryWidget = new InventoryWidget;
};

CashRegister::CashRegister(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CashRegisterClass()),p(new CashRegisterPrivate)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("仓储管理系统"));
    setWindowIcon(QIcon(":/image/icon.png"));
    //清空默认的
    ui->stackedWidget->removeWidget(ui->page);
    ui->stackedWidget->removeWidget(ui->page_2);
    ui->stackedWidget->addWidget(p->inventoryWidget);
    ui->stackedWidget->addWidget(p->checkoutWidget);
    ui->stackedWidget->addWidget(p->cashLogWidget);
    
    connect(ui->pb_Intery, &QPushButton::clicked, [this]()
    {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pb_calculate, &QPushButton::clicked, [this]()
    {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pb_log, &QPushButton::clicked, [this]()
    {
        ui->stackedWidget->setCurrentIndex(2);
    });
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->stackedWidget,&QStackedWidget::currentChanged,[this]()
    {
        disconnect(SerialPortManager::getInstance(),&SerialPortManager::dataReceived, nullptr, nullptr);
        if(ui->stackedWidget->currentIndex() == 0)
		{
			connect(SerialPortManager::getInstance(), &SerialPortManager::dataReceived, p->inventoryWidget, &InventoryWidget::OnDataReceived);
		}
        else if(ui->stackedWidget->currentIndex() == 1)
		{
			connect(SerialPortManager::getInstance(), &SerialPortManager::dataReceived, p->checkoutWidget, &CheckoutWidget::OnDataReceived);
		}
    });

    connect(SerialPortManager::getInstance(), &SerialPortManager::dataReceived, p->inventoryWidget, &InventoryWidget::OnDataReceived);

    if (SerialPortManager::getInstance()->openSerialPort("COM5"))
    {
        ui->label_status->setText(QStringLiteral("已连接"));
    }
    else
    {
        ui->label_status->setText(QStringLiteral("未连接"));
    }

    connect(p->checkoutWidget, &CheckoutWidget::CheckoutFinished, p->cashLogWidget, &CashLogWidget::Refresh);
    connect(p->checkoutWidget, &CheckoutWidget::CheckoutFinished, p->inventoryWidget, &InventoryWidget::Refresh);

}

CashRegister::~CashRegister()
{
    delete ui;
    delete p;
}

void CashRegister::InitPort()
{
   
}
