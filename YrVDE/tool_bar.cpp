#include "./tool_bar.h"

ToolBar::ToolBar(/*WorkSpace* work_space*/)
{
    // /m_workSpace = work_space;
    CreateButton(m_andGate, "and", "AND");
    CreateButton(m_nandGate, "nand", "NAND");
    CreateButton(m_orGate, "or", "OR");
    CreateButton(m_norGate, "nor", "NOR");
    CreateButton(m_bufferGate, "buffer", "BUFFER");
    CreateButton(m_notGate, "not", "NOT");
    CreateButton(m_xorGate, "xor", "XOR");
    CreateButton(m_xnorGate, "xnor", "XNOR");

    this->addWidget(m_andGate);
    this->addWidget(m_nandGate);
    this->addWidget(m_orGate);
    this->addWidget(m_norGate);
    this->addWidget(m_bufferGate);
    this->addWidget(m_notGate);
    this->addWidget(m_xorGate);
    this->addWidget(m_xnorGate);

    QObject::connect(m_orGate, &QToolButton::clicked, this, [this]() {
        qDebug() << "ToolButton triggered!";
        m_gate = CreateLogicGate("OR");

        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_andGate, &QToolButton::clicked, this, [this]() {
        qDebug() << "ToolButton triggered!";
        m_gate = CreateLogicGate("AND");

        emit this->createLogicGate(m_gate);
    });
}

void ToolBar::CreateButton(QToolButton*& button, const QString &icon_name, const QString &text) {
    button = new QToolButton();
    button->setIcon(QIcon("..//Resources//Icons" + icon_name + ".png"));
    button->setText(text);
    button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    button->setStyleSheet("color: black");
}

void ToolBar::GetWorkSpace(WorkSpace *workspace) {
    qDebug() << "get workspace";
    m_workSpace = workspace;
}

LogicGate* ToolBar::CreateLogicGate(const std::string gate_type) {
    return LogicGateFactory::CreateLogicGate(gate_type);
}

