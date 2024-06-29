#include "AbstractRequests/abstractrequests.h"
#include <iostream>
#include <QJsonDocument>
#include <QCoreApplication>
class RequestsTest : public AbstractRequests{
public:
    RequestsTest() : AbstractRequests(std::make_shared<QNetworkAccessManager>()){}

protected:
    virtual void parceNetworkReply(QNetworkRequest &&request, QNetworkReply::NetworkError &&error, QByteArray &&reply) override
    {
        std::cout << request.url().toString().toStdString() << '\n';
        std::cout << QJsonDocument::fromJson(reply).toJson().toStdString() << '\n';
    }


public:
    void test()
    {
        sendGet("api.bybit.com", "/v5/market/delivery-price", "category=option&symbol=ETH-26DEC22-1400-C", "");
    }
};


int main(int argc, char *argv[]){

    QCoreApplication a(argc, argv);
    RequestsTest reqTest;
    reqTest.test();
    return a.exec();
}
