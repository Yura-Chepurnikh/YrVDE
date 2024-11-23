#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include <QObject>
#include <string>
#include <QToolBar>
#include <QToolButton>
#include "./logic_gate_factory.h"
#include "./workspace.h"

class ToolBar : public QToolBar {
    Q_OBJECT

public:
    ToolBar(/*WorkSpace* work_space*/);
    ~ToolBar() = default;
    LogicGate* CreateLogicGate(const std::string gate_type);
    LogicGate* m_gate;

public slots:
    void GetWorkSpace(WorkSpace* workspace);

signals:
    void createLogicGate(LogicGate* gate);

private:
    void CreateButton(QToolButton*& button, const QString& icon_name, const QString& text);
    QGraphicsScene* m_scene;

    WorkSpace* m_workSpace;

    QToolButton* m_andGate, *m_nandGate,
        *m_orGate, *m_norGate,
        *m_bufferGate, *m_notGate,
        *m_xorGate, *m_xnorGate;
};

#endif // TOOL_BAR_H
