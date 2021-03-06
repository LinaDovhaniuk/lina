#include "dialogadddevice.h"
#include "ui_dialogadddevice.h"
#include <QDebug>

DialogAddDevice::DialogAddDevice(int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDevice)
{
    ui->setupUi(this);

    /* Метода для инициализации модели,
     * из которой будут транслироваться данные
     * */
    setupModel();

    /* Если строка не задана, то есть равна -1,
     * тогда диалог работает по принципу создания новой записи.
     * А именно, в модель вставляется новая строка и работа ведётся с ней.
     * */
    if(row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
    /* В противном случае диалог настраивается на заданную запись
     * */
    } else {
        mapper->setCurrentModelIndex(model->index(row,0));
    }

    createUI();
}

DialogAddDevice::~DialogAddDevice()
{
    delete ui;
}

/* Метод настройки модели данных и mapper
 * */
void DialogAddDevice::setupModel()
{
    /* Инициализируем модель и делаем выборку из неё
     * */
    model = new QSqlTableModel(this);
    model->setTable(COACH);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    /* Инициализируем mapper и привязываем
     * поля данных к объектам LineEdit
     * */
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->SURNAMELineEdit, 1);
    mapper->addMapping(ui->NAMELineEdit, 2);
    mapper->addMapping(ui->BIRTHDAYLineEdit, 3);
    mapper->addMapping(ui->PHONELineEdit, 4);
    /* Ручное подтверждение изменения данных
     * через mapper
     * */
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    qDebug() << ui->SURNAMELineEdit->text();
    /* Подключаем коннекты от кнопок пролистывания
     * к прилистыванию модели данных в mapper
     * */
    connect(ui->previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(ui->nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    /* При изменении индекса в mapper изменяем состояние кнопок
     * */
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
}

/* Метод для установки валидатора на поле ввода IP и MAC адресов
 * */
void DialogAddDevice::createUI()
{
    QString birthRange = "(?:[0-1]?[0-1]?[0-4])";
    QRegExp birthRegex ("^" + birthRange
                     + "\\." + birthRange
                     + "\\." + birthRange + "$");
    QRegExpValidator *birthValidator = new QRegExpValidator(birthRegex, this);
    ui->BIRTHDAYLineEdit->setValidator(birthValidator);

    QString phoneRange = "(?:[0-2]?[0-2]?[0-4])";
    QRegExp phoneRegex ("^" + phoneRange
                      + "\\-" + phoneRange
                      + "\\-" + phoneRange + "$");
    QRegExpValidator *phoneValidator = new QRegExpValidator(phoneRegex, this);
    ui->PHONELineEdit->setValidator(phoneValidator);
}

void DialogAddDevice::on_buttonBox_accepted()
{
    /* SQL-запрос для проверки существования записи
     * с такими же учетными данными.
     * Если запись не существует или находится лишь индекс
     * редактируемой в данный момент записи,
     * то диалог позволяет вставку записи в таблицу данных
     * */
    QSqlQuery query;
    QString str = QString("SELECT EXISTS (SELECT FROM " COACH
               " WHERE ( " SURNAME " = '%1' "
               " AND " NAME " = '%2' )"
               " AND id NOT LIKE '%3' )")
            .arg(ui->SURNAMELineEdit->text(),
                 ui->NAMELineEdit->text(),
                 model->data(model->index(mapper->currentIndex(),0), Qt::DisplayRole).toString());

    query.prepare(str);
    query.exec();
    query.next();

    /* Если запись существует, то диалог вызывает
     * предупредительное сообщение
     * */
    if(query.value(0) != 0){
        QMessageBox::information(this, trUtf8("Ошибка"),
                                 trUtf8("Клиент с такой фамилией и именем уже существует"));
    /* В противном случае производится вставка новых данных в таблицу
     * и диалог завершается с передачей сигнала для обновления
     * таблицы в главном окне
     * */
    } else {
        mapper->submit();
        model->submitAll();
        emit signalReady();
        this->close();
    }
}

void DialogAddDevice::accept()
{
qDebug() << ui->SURNAMELineEdit->text();
}

/* Метод изменения состояния активности кнопок пролистывания
 * */
void DialogAddDevice::updateButtons(int row)
{
    /* В том случае, если мы достигаем одного из крайних (самый первый или
     * самый последний) из индексов в таблице данных,
     * то мы изменяем состояние соответствующей кнопки на
     * состояние неактивна
     * */
    ui->previousButton->setEnabled(row > 0);
    ui->nextButton->setEnabled(row < model->rowCount() - 1);
}
