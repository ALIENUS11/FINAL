#include "MyDataBase.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlError>
#include <QVariant>
#include <QCoreApplication>
MyDataBase::MyDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( QCoreApplication::applicationDirPath() +  "/myDataBase.db");
    if (!db.open())
    {
        emit error(db.lastError().text());
        return;
    }
    
    //创建表   有 条形码ID  商品名称   商品价格  商品数量
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS goods (barcode TEXT, name TEXT, price REAL, quantity INTEGER)"))
    {
        emit error(query.lastError().text());
    }
    
    //创建表   有 条形码ID  售出数量 售出时间  
    if(!query.exec("CREATE TABLE IF NOT EXISTS sales (barcode TEXT,quantity INTEGER, saleTime TEXT)"))
    {
        emit error(query.lastError().text());
    }
    
}

MyDataBase::~MyDataBase()
{
    db.close();
}

QString MyDataBase::GetGoodsName(const QString& barCode)
{
    QSqlQuery query;
    if(!query.exec(QString("SELECT name FROM goods WHERE barcode = '%1'").arg(barCode)))
    {
        emit error(query.lastError().text());
    }
    if(query.next())
    {
        return query.value(0).toString();
    }
    return QString();
}

double MyDataBase::GetGoodsPrice(const QString& barCode)
{
    QSqlQuery query;
    if(!query.exec(QString("SELECT price FROM goods WHERE barcode = '%1'").arg(barCode)))
    {
        emit error(query.lastError().text());  
    }
    if(query.next())
    {
        return query.value(0).toDouble();
    }
    return 0.0;
}

Good MyDataBase::GetGoods(const QString& barCode)
{
    QSqlQuery query;
    if(!query.exec(QString("SELECT * FROM goods WHERE barcode = '%1'").arg(barCode)))
    {
        emit error(query.lastError().text());
    }
    if(query.next())
    {
        Good good;
        good.barCode = query.value(0).toString();
        good.name = query.value(1).toString();
        good.price = query.value(2).toDouble();
        good.number = query.value(3).toInt();
        return good;
    }
    return Good();
}

void MyDataBase::AddNewGoods(const QString& barCode, const QString& Name, const double& price, const int& number)
{
    QSqlQuery query;
    if(!query.exec(QString("INSERT INTO goods (barcode, name, price, quantity) VALUES ('%1', '%2', %3, %4)").arg(barCode).arg(Name).arg(price).arg(number)))
    {
        emit error(query.lastError().text());
    }
}

void MyDataBase::AddGoods(const QString& barCode, const int& number)
{
    QSqlQuery query;
    if(!query.exec(QString("UPDATE goods SET quantity = quantity + %1 WHERE barcode = '%2'").arg(number).arg(barCode)))
    {
        emit error(query.lastError().text());
    }
}

void MyDataBase::ReduceGoods(const QString& barCode, const int& number)
{
    QSqlQuery query;
    if(!query.exec(QString("UPDATE goods SET quantity = quantity - %1 WHERE barcode = '%2'").arg(number).arg(barCode)))
    {
        emit error(query.lastError().text());
    }
}

void MyDataBase::AddSellRecord(const QString& barCode, const int& number, const double& price)
{
    QSqlQuery query;
    if(!query.exec(QString("INSERT INTO sales (barcode, quantity, saleTime) VALUES ('%1', %2, '%3')").arg(barCode).arg(number).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))))
    {
        emit error(query.lastError().text());
    }
}

QList<SellRecord> MyDataBase::GetSellRecord()
{
    QList<SellRecord> list;
    QSqlQuery query;
    if(!query.exec("SELECT * FROM sales"))
    {
        emit error(query.lastError().text());
        return list;
    }
    while(query.next())
    {
        SellRecord record;
        record.barCode = query.value(0).toString();
        record.number = query.value(1).toInt();
        record.time = query.value(2).toString();
        record.price = GetGoodsPrice(record.barCode) * record.number;
        record.name = GetGoodsName(record.barCode);
        list.append(record);
    }
    return list;
}

QList<Good> MyDataBase::GetGoods()
{
    QList<Good> list;
    QSqlQuery query;
    if(!query.exec("SELECT * FROM goods"))
    {
        emit error(query.lastError().text());
        return list;
    }
    while(query.next())
    {
        Good good;
        good.barCode = query.value(0).toString();
        good.name = query.value(1).toString();
        good.price = query.value(2).toDouble();
        good.number = query.value(3).toInt();
        list.append(good);
    }
    return list;
}

int MyDataBase::GetGoodsQuantity(const QString& barCode)
{
    QSqlQuery query;
    if (!query.exec(QString("SELECT quantity FROM goods WHERE barcode = '%1'").arg(barCode)))
    {
        emit error(query.lastError().text());
        return 0;
    }
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}

