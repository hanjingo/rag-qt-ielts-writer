#include "IELTSWriter.h"
#include "ui_IELTSWriter.h"

IELTSWriter::IELTSWriter(QWidget *parent)
    : ui(new Ui::IELTSWriter)
{
}

IELTSWriter::~IELTSWriter()
{
    delete ui;
}

QWidget *IELTSWriter::Init(Bus *parent)
{
    m_pBus = parent;

    // init connect
    connect(m_pBus, &Bus::SignalPing, this, &IELTSWriter::_slotPing);

    // create UI
    auto wgt = new QWidget(nullptr);
    wgt->setStyleSheet("background-color: transparent;");
    ui->setupUi(wgt);
    return wgt;
}

void IELTSWriter::_slotPing()
{
    qDebug() << "IELTSWriter received Ping signal from Bus.";
    emit m_pBus->SignalPong();
}