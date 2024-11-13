/* Здесь будет вся важная информация по проекту !!!

Пока что я вижу необходимость в разделении проекта на backend часть
где будут хранится вся информация о нашей схеме, об изменения, которые
внес пользователь и естественно frontend где будет вся наша визуальная часть.

В принципея хотел использовать UML, но удобен в если писать на доске, а у меня его нету.

У нас будет базовый класс SchemeObject от которого будут наследоваться все
остальные классы которые могут быть использованы в рабочей области.

SchemeObjectFront
    LogicGateSymbol
        ORLogicGateSymbol
        XORLogicGateSymbol
        XNORLogicGateSymbol
        ANDLogicGateSymbol
        NANDLogicGateSymbol
        BufferLogicGateSymbol
        NOTLogicGateSymbol
        NORLogicGateSymbol
    BondingWire
    Other Entities*
    INPUT
    OUTPUT

И так на данный момент я хочу реализовать методы drug and drop
для класса LogicGate
*/

/*
 * И так сегодня я намерен
 * 1. Изменить структуру logic gate так чтобы он был пропорционален grid gap а также drag and drop
 * 2. Добавить в основной проект Bonding wire
 * 3. Добавить inputs и outputs
 */




