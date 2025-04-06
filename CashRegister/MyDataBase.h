#pragma once

#include <QObject>
#include <QSqlDatabase>

struct Good
{
    QString barCode;
    QString name;
    double price;
    int number;
};

struct SellRecord
{
    QString name;
    QString barCode;
    int number;
    double price;
    QString time;
};

class MyDataBase: public QObject
{
    Q_OBJECT
public:
    static MyDataBase& GetInstance()
    {
            static MyDataBase instance;
            return instance;
    }
    MyDataBase();
    ~MyDataBase();
     
    QString GetGoodsName(const QString & barCode);
    //获取商品价格
    double GetGoodsPrice(const QString & barCode);
    Good GetGoods(const QString & barCode);
    //加入新商品 
    void AddNewGoods(const QString & barCode, const QString & Name, const double & price,const int & number);
    //已有商品添加数量
    void AddGoods(const QString & barCode, const int & number);
    //已有商品减少数量
    void ReduceGoods(const QString & barCode, const int & number);
    //添加商品出售记录
    void AddSellRecord(const QString & barCode, const int & number, const double & price);
    //获取出售记录
    QList<SellRecord> GetSellRecord();
    //获取库存信息
    QList<Good> GetGoods();
signals:
    void error(const QString &error);
private:
    QSqlDatabase db;
};

