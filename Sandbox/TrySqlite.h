#ifndef TRYSQLITE_H
#define TRYSQLITE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class TrySqlite {
public:
    void connectToDatabase();
    void createTable();
    void insertData(const QString& name, int age);
    void fetchData();
    void closeDatabase();
private:
};

#endif // TRYSQLITE_H
