#ifndef IELTS_WRITER_H
#define IELTS_WRITER_H

#include <QObject>
#include <QtPlugin>
#include <QWidget>

#include "Bus.h"
#include "PluginInterface.h"

namespace Ui
{
class IELTSWriter;
}

class IELTSWriter : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "rag-qt.PluginInterface" FILE
                          "ieltswriterplugin.json")
    Q_INTERFACES(PluginInterface)

  public:
    explicit IELTSWriter(QWidget *parent = nullptr);
    ~IELTSWriter();

    QString  Id() override { return "ielts-writer-v0.0.1"; }
    QString  Name() override { return "ielts-writer"; }
    QString  Icon() override { return "IELTSWriterIcon.png"; }
    QString  Version() override { return "0.0.1"; }
    QWidget *Init(Bus *parent = nullptr) override;

  private slots:
    void _slotPing();

  private:
    Ui::IELTSWriter *ui;
    Bus             *m_pBus;
};

#endif