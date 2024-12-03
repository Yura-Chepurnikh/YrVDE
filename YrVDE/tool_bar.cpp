#include "./tool_bar.h"

ToolBar::ToolBar()
{
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

    QObject::connect(m_andGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<ANDGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_nandGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<NANDGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_orGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<ORGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_norGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<NORGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_xorGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<XORGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_xnorGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<XNORGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_bufferGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<BUFFERGate>::create();
        emit this->createLogicGate(m_gate);
    });

    QObject::connect(m_notGate, &QToolButton::clicked, this, [this]() {
        m_gate = LogicGateFactory<NOTGate>::create();
        emit this->createLogicGate(m_gate);
    });

}

void ToolBar::CreateButton(QToolButton*& button, const QString &icon_name, const QString &text) {
    button = new QToolButton();
    button->setIcon(QIcon("D:/YrVDE/Resources/Icons/" + icon_name + ".png"));
    button->setText(text);
    button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    button->setStyleSheet (
        "QToolButton {"
        "color: white;"
        "width: 100%;"
        "}"
        "QToolButton:hover {"
        "background-color: #333333"
        "}"
    );
}

// void ToolBar::GetWorkSpace(WorkSpace *workspace) {
//     m_workSpace = workspace;
// }


