#include "TrySqlite.h"

void TrySqlite::connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("some_database.db");

    if (!db.open()) {
        qDebug() << "Error: " << db.lastError().text();
    } else {
        qDebug() << "Success 1";
    }
}

void TrySqlite::createTable() {
    QSqlQuery query;
    QString createTableQuery =

        "CREATE TABLE IF NOT EXISTS person ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL,"
        "age INTEGER NOT NULL)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "The table could not be created: " << query.lastError().text();
    } else {
        qDebug() << "Success 2";
    }
}

void TrySqlite::insertData(const QString& name, int age) {
    QSqlQuery query;
    query.prepare("INSERT INTO person (name, age) VALUES (:name, :age)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);

    if (!query.exec()) {
        qDebug() << "Error: " << query.lastError().text();
    } else {
        qDebug() << "Success 3";
    }
}

void TrySqlite::fetchData() {
    QSqlQuery query("SELECT id, name, age FROM person");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "ID: " << id << "Name: " << name << "Age: " << age;
    }
}

void TrySqlite::closeDatabase() {
    QSqlDatabase::database().close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    qDebug() << "Connection closed!!!";
}
